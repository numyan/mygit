#include "head.h"

int HandleClient(int datafd);
int Intcmp(const void *pv1,const void *pv2);

int main(int argc,char* argv[])
{
    struct sockaddr_in servaddr;
    pid_t cpid;
    pid_t gpid;
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
        cpid = fork();
        if(cpid < 0)
        {
            printf("fork failed in %s at %d\n",__FILE__,__LINE__);
            close(datafd);
            datafd = -1;
            continue;
        }
        else if(cpid > 0)
        {
            close(datafd);
            datafd = -1;
            wait(NULL);
        }
        else
        {
            close(servfd);
            servfd = -1;
            gpid = fork();
            if(gpid < 0)
            {
                printf("fork failed in %s at %d\n",__FILE__,__LINE__);
                close(datafd);
                datafd = -1;
                return 1;
            }
            else if(gpid > 0)
            {
                close(datafd);
                datafd =-1;
                return 0;
            }
            else
            {
                HandleClient(datafd);
                return 0;
            }
        }
        
    } 

    close(servfd);
    servfd = -1;
    return 0;
}

int HandleClient(int datafd)
{
    struct MyData* data = NULL;
    int n = 0;
    int ret = -1;
    int i = 0;

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
            return 1;
        }
        memset(data,0,(n+1)*sizeof(int));

        read(datafd,data->num,n*sizeof(int));
        qsort(data->num,n,sizeof(int),Intcmp);
        for(i=0;i<n;i++)
        {
            printf("%d\n",data->num[i]);
        }
        free(data);
        data = NULL;
    }

    close(datafd);
    datafd = -1;
    return 0;
}

int Intcmp(const void *pv1,const void *pv2)
{
    return *(int*)pv1 - *(int*)pv2;
}