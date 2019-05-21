#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* MyGetString(char* pbuf,int size);

struct MyData
{
    int len;
    char buf[1];
};

int main(int argc,char* argv[])
{
    struct MyData* data = NULL;
    struct sockaddr_in servaddr;;
    int n = 0;
    int sockfd = -1;
    int ret = 0;
    char buf[32] = "";
    while(1)
    {
        sockfd = socket(AF_INET,SOCK_STREAM,0);//建立套接

        bzero(&servaddr,sizeof(servaddr));//memset(&servaddr,0,sizeof(servaddr))；
        servaddr.sin_family = AF_INET;//设定地址族
        servaddr.sin_port = htons(2345);//设定端口
        inet_aton("127.0.0.1",&servaddr.sin_addr);//设置IP地址

        ret = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
        if(ret < 0)
        {
            printf("connect failed in %s at %d\n",__FILE__,__LINE__);
            return 1;
        }

        printf("Please input content:\n");
        MyGetString(buf,32);
        if(strcmp(buf,"quit") == 0)
        {
            n = 0;
            write(sockfd,&n,4);
            return 0;
        }

        n = strlen(buf);
        data = (struct MyData*)malloc(n+4);
        if(NULL == data)
        {
            printf("malloc failed in %s at %d\n",__FILE__,__LINE__);
            return 2;
        }
        memset(data,0,n+4);

        data->len = n;
        strcpy(data->buf,buf);

        write(sockfd,data,n+4);
        memset(buf,0,sizeof(buf));
        read(sockfd,buf,24);
        printf("%s\n",buf);
        memset(buf,0,sizeof(buf));

        free(data);
        data = NULL;
        close(sockfd);
        sockfd = -1;
        close(sockfd);
        sockfd = -1;
    }

    return 0;
}

char* MyGetString(char* pbuf,int size)
{
    char* p = NULL;
    int len = 0;
    p = fgets(pbuf,size,stdin);

    len = strlen(pbuf);
    if(len == 0)
    {
        return NULL;
    }

    if(*(pbuf+len-1) == '\n')
    {
        *(pbuf+len-1) = '\0';
    }
    else
    {
        while(getchar() != '\n');
    }
    
    return p;
}