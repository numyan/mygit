#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mydata.h"
char *MyGetString(char *pout,int size);

int main(int argc,char *argv[])
{
	struct sockaddr_in servaddr;
	int sockfd = -1;
	int ret = 0;
	char buf[64] = "";

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	//memset(&servaddr,0,sizeof(servaddr))
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(2345);
	inet_aton("127.0.0.1",&servaddr.sin_addr);
	
	ret = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));	if(ret < 0)
	{
		printf("connect failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	{
		int len = 0;
		struct MyData *pstData = NULL;
		printf("Please input your content:\n");
		MyGetString(buf,64);
		len = strlen(buf)+1;
	
		pstData = (struct MyData *)malloc(len+sizeof(int));
		if(NULL == pstData)
		{
			printf("Malloc Failed \n");
			close(sockfd);
			sockfd = -1;
			return 3;
		}
		memset(pstData,0,len+sizeof(int));
		pstData->len = len;
		strcpy(pstData->buf,buf);

		write(sockfd,pstData,len+sizeof(int));
		free(pstData);
		pstData = NULL;
	}
	close(sockfd);
	sockfd = -1;
	return 0;
}

char *MyGetString(char *pout,int size)
{
	char *p = NULL;
	int len = 0;

	p = fgets(pout,size,stdin);
	len = strlen(pout);
	if(*(p+len-1) == '\n')
	{
		*(p+len-1) = '\0';
	}
	else
	{
		while(getchar()!='\n')
		{
		}
	}
	return p;
}
