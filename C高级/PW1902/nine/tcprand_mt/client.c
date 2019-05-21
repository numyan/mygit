#include <time.h>

#include "mydata.h"

int main(int argc,char *argv[])
{
	struct sockaddr_in servaddr;
	int sockfd = -1;
	int ret = 0;
	struct MyData *pst = NULL;
	int i = 0;
	int n = 0;

	srand(time(NULL));

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP,&servaddr.sin_addr);

	ret = connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	if(ret != 0)
	{
		ClientPrintf("connect server failed\n");
		return 1;
	}

	while(1)
	{
		printf("Please input a number:\n");
		scanf("%d",&n);
		if(n < 0)
		{
			ClientPrintf("User Input is invalid\n");
			continue;
		}
		pst = (struct MyData *)malloc((n+1)*sizeof(int));
		if(NULL == pst)
		{
			ClientPrintf("Malloc Failed\n");
			continue;
		}
		memset(pst,0,sizeof(int) * (n + 1));

		pst->count = n;
		for(i = 0;i < n;i++)
		{
			*(((int *)pst->buf) + i)= rand() % 50;
		}
		write(sockfd,pst,(n+1)*sizeof(int));
		free(pst);
		pst = NULL;
		if(n == 0)
		{
			break;
		}
	}

	close(sockfd);
	sockfd = -1;
	return 0;
}
