#include "head.h"

int main(int argc,char* argv[])
{
    struct sockaddr_in servaddr;
    pthread_t tid;
    int servfd = -1;
    int datafd = -1;
    int ret = -1;

    servfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2345);
    inet_aton("127.0.0.1",&servaddr.sin_addr);

    ret = bind(servfd,(struct sockaddr*)&servaddr,sizeof(servaddr));
    ret += listen(servfd,5);
    if(ret < 0)
    {
        printf("bind or listen failed in %s at %d\n",__FILE__,__LINE__);
    }

    while(1)
    {
        datafd = accept(servfd,NULL,NULL);
        ret = pthread_create(&tid,NULL,HandleClient,(void*)((long)datafd));
        if(ret != 0)
        {
            printf("create pthread failed\n");
            close(datafd);
            datafd = -1;
            continue;
        }
        pthread_detach(tid);
    }

    return 0;
}

void* HandleClient(void* pv)
{
    int datafd = (int)((long)pv);
    struct MyData* data = NULL;
    int n = 0;
    int ret = -1;
    int i = 0,j = 0;
    int tmp = 0;

    while(1)
    {
        ret = read(datafd,&n,sizeof(int));
        if(ret <= 0)//等于0时未连接
        {
            printf("read failed or client disconnect\n");
            break;
        }

        if(0 == n)
        {
            printf("This service process will quit\n");
            break;
        }

        data = (struct MyData*)malloc((n+1)*sizeof(int));
        if(NULL == data)
        {
            printf("Malloc failed in %s at %d\n",__FILE__,__LINE__);
            break;
        }
        memset(data,0,(n+1)*sizeof(int));

        read(datafd,data->num,n*sizeof(int));
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(data->num[j] > data->num[j+1])
                {
                    tmp = data->num[j];
                    data->num[j] = data->num[j+1];
                    data->num[j+1] = tmp;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d\n",data->num[i]);
        }
        printf("\n");
    }

    close(datafd);
    datafd = -1;
    return NULL;
}