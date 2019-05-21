#include "head.h"

int CreateRandomNumber(int n,int sockfd);

int main(int argc,char* argv[])
{
    struct sockaddr_in sockaddr;
    int sockfd = -1;
    int ret = -1;
    int n = 0;

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    bzero(&sockaddr,sizeof(sockaddr));
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(2345);
    inet_aton("127.0.0.1",&sockaddr.sin_addr);

    ret = connect(sockfd,(struct sockaddr*)&sockaddr,sizeof(sockaddr));
    if(ret < 0)
    {
        printf("connect failed in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }

    while(1)
    {
        printf("Please input number of random\n");
        while(!scanf("%d",&n))
        {
            printf("Please input number of random\n");
            while(getchar() != '\n');
        }
        if(0 == n)
        {
            printf("client will exit\n");
            break;
        }

        CreateRandomNumber(n,sockfd);
    }

    close(sockfd);
    sockfd = -1;
    return 0;
}

int CreateRandomNumber(int n,int sockfd)
{
    struct MyData* data = NULL;
    int i = 0;
    
    data = (struct MyData*)malloc((n+1)*sizeof(int));
    if(NULL == data)
    {
        printf("Malloc failed in %s at %d\n",__FILE__,__LINE__);
        return 1;
    }
    memset(data,0,(n+1)*sizeof(int));

    data->n = n;
    srand(time(NULL));
    for(i=0;i<n;i++)
    {
        data->num[i] = rand() % 50;
    }

    write(sockfd,data,(n+1)*sizeof(int));

    return 0;
}

