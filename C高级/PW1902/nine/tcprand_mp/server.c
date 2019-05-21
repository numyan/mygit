#include "mydata.h"

int IntCmp(const void *pv1,const void *pv2);
void *HandleClient(void *pv);
int main(int argc,char *argv[])
{
	struct sockaddr_in servaddr;
	int servfd = -1;
	int ret = 0;
	int datafd = -1;
	pid_t cpid;
	pid_t gpid;

	servfd = socket(AF_INET,SOCK_STREAM,0);
	
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);
	inet_aton(SERVER_IP,&servaddr.sin_addr);

	ret = bind(servfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	ret += listen(servfd,6);
	
	while(1)
	{
		datafd = accept(servfd,NULL,NULL);
		cpid = fork();
		if(cpid < 0)
		{
			ServerPrintf("fork failed\n");
			close(datafd);
			datafd = -1;
		}
		if(cpid > 0)
		{//parent process
			close(datafd);
			datafd = -1;
			wait(NULL);
		}
		else
		{//child process
			close(servfd);
			servfd = -1;
			gpid = fork();
			if(gpid < 0)
			{
				ServerPrintf("fork grandson process failed\n");
				close(datafd);
				datafd = -1;
				return 1;
			}
			if(gpid > 0)
			{
				close(datafd);
				datafd = -1;
				return 0;
			}
			else
			{//grandson process
				HandleClient((void *)(long)datafd);	
				return 0;
			}
		}
	}
	return 0;
}

void *HandleClient(void *pv)
{
	int datafd = (int)((long)pv);
	struct MyData *pst = NULL;
	int n = 0;
	int ret = 0;
	int i = 0;
	
	while(1)
	{
		ret = read(datafd,&n,sizeof(int));
		if(ret <= 0)
		{
			ServerPrintf("Read error\n");
			break;
		}

		pst = (struct MyData *)malloc((n+1) * sizeof(int));
		if(NULL == pst)
		{
			ServerPrintf("Malloc Failed\n");
			break;
		}
		memset(pst,0,(n+1)*sizeof(int));

		pst->count = n;
		ret = read(datafd,pst->buf,n * sizeof(int));
		if(ret <= 0)
		{
			ServerPrintf("Read error\n");
			break;
		}
		
		qsort(pst->buf,n,sizeof(int),IntCmp);
		for(i = 0;i < n;i++)
		{
			printf("%d ",*(((int*)pst->buf) + i));
		}
		printf("\n");

		free(pst);
		pst = NULL;
	}
	
	close(datafd);
	datafd = -1;
	return NULL;
}

int IntCmp(const void *pv1,const void *pv2)
{
	return *(int *)pv1 - *(int *)pv2;
}



