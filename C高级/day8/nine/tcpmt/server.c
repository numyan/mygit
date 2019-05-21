#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <strings.h>
#include <sys/wait.h>

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mydata.h"

void * HandleClient(void *pv);
int main(int argc,char *argv[])
{
	int servfd = -1;
	struct sockaddr_in servaddr;
	int ret = 0;
	int datafd = -1;
	pthread_t tid;

	servfd = socket(AF_INET,SOCK_STREAM,0);	
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(2345);
	inet_aton("127.0.0.1",&servaddr.sin_addr);

	ret = bind(servfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	ret += listen(servfd,5);
	/*
		变主动套接字(插头)为被动套接字（插排）
		该函数并不负责客户端的连接请求,可以认为系统的TCP协议在处理连接请求，因此listen并不阻塞等待连接请求
	*/
	if(ret < 0)
	{
		printf("bind or listen failed in %s at %d\n",__FILE__,__LINE__);
	}

	while(1)
	{
		datafd = accept(servfd,NULL,NULL);
		ret = pthread_create(&tid,NULL,HandleClient,(void *)((long)datafd));
		if(ret != 0)
		{
			printf("pthread_create failed\n");
			close(datafd);
			datafd = -1;
			continue;
		}
		pthread_detach(tid);
	}

	close(servfd);
	servfd = -1;
	return 0;
}

void * HandleClient(void *pv)
{
	int datafd = (int)((long)pv);
	int len = 0;
	struct MyData *pstData = NULL;
	int ret = 0;
	
	while(1)
	{
		ret = read(datafd,&len,sizeof(len));
		if(ret <= 0)
		{
			printf("read error or client disconnect\n");
			break;
		}
		pstData = (struct MyData *)malloc(len+sizeof(len));
		if(NULL == pstData)
		{
			printf("Malloc Failed\n");
			break;
		}
		memset(pstData,0,len + sizeof(len));
			
		pstData->len = len;
		ret = read(datafd,pstData->buf,len);
		if(ret <= 0)
		{
			printf("read error or client disconnect\n");
			break;
		}
		printf("In server buf=%s\n",pstData->buf);
		if(strcmp(pstData->buf,"quit") == 0)
		{
			printf("This service thread will quit\n");
			break;
		}
		free(pstData);
		pstData = NULL;
	}//end while(1)

	close(datafd);
	datafd = -1;

	return NULL;
}

