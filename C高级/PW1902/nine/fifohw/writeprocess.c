#include <time.h>

#include "mydata.h"

int main(int argc,char *argv[])
{
	int ret = 0;
	int wfd = -1;
	struct MyData *pst=NULL;
	int n = 0;
	int i = 0;
	int *pi = NULL;

	srand(time(NULL));
	if(access(FIFO_NAME,F_OK) != 0)
	{
		ret = mkfifo(FIFO_NAME,0666);
		if(ret != 0)
		{
			printf("mkfifo failed in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
	}

	wfd = open(FIFO_NAME,O_WRONLY);
	if(wfd < 0)
	{
		printf("open fifo failed in %s at %d\n",__FILE__,__LINE__);
		return 2;
	}

	while(1)
	{
		
		printf("Please input a number:\n");
		scanf("%d",&n);
		
		if(n < 0)
		{
			printf("malloc failed in %s at %d\n",__FILE__,__LINE__);
			break;
		}
	
		pst = (struct MyData *)malloc((n+1)*sizeof(int));
		if(pst == NULL)
		{
			printf("malloc failed in %s at %d\n",__FILE__,__LINE__);
			break;
		}
		memset(pst,0,sizeof(int) * (n+1));

		pst->count = n;
		pi = (int *)pst->buf;
		for(i = 0;i < n;i++)
		{
			*(pi+i) = rand() % 50;
		}

		write(wfd,pst,(n+1) * sizeof(int));
		free(pst);
		pst = NULL;

		if(n == 0)
		{
			break;
		}
	}
		
	close(wfd);
	wfd = -1;
	return 0;
}







