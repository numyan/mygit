#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyData
{
    int n;
    int num[1];
};

int main(int argc,char* argv[])
{
    struct sockaddr_in  servaddr;
    int servfd = -1;
    int datafd = -1;
    int ret = 0;

    int i = 0;
    int j = 0;
    int tmp = 0;
    int n = 0;
    struct MyData* data = NULL;

    servfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(2345);
    inet_aton("127.0.0.1",&servaddr.sin_addr);

    ret = bind(servfd,(struct sockaddr *)&servaddr,sizeof(servaddr));//绑定端口和地址
    ret += listen(servfd,5);
    if(ret < 0)
    {
        printf("bind or listen failed in %s at %d\n",__FILE__,__LINE__);
    }

    while(1)
    {
        datafd = accept(servfd,NULL,NULL);

        read(datafd,&n,4);
        data = (struct MyData*)malloc((n+1)*sizeof(int));
        if(NULL == data)
        {
            printf("malloc failed in %s at %d\n",__FILE__,__LINE__);
        }
        memset(data,0,(n+1)*sizeof(int));

        data->n = n;
        read(datafd,data->num,sizeof(int)*n);

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

        free(data);
        data = NULL;
        close(datafd);
        datafd = -1;
    }

    close(servfd);
    servfd = -1;
    return 0;
}
