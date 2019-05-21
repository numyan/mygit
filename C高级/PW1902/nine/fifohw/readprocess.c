#include "mydata.h"

int IntCmp(const void *pv1,const void *pv2);
int main(int argc,char *argv[])
{
	int ret = 0;
	int rfd = -1;
	struct MyData *pst = NULL;
	int n = -1;
	int i = 0;

	if(access(FIFO_NAME,F_OK) != 0)
	{
		ret = mkfifo(FIFO_NAME,0666);
		if(ret != 0)
		{
			MYPrintf("mkfifo failed\n");
			return 1;
		}
	}

	rfd = open(FIFO_NAME,O_RDONLY);
	if(rfd < 0)
	{
		MYPrintf("open fifo failed\n");
		return 2;
	}

	while(1)
	{
		read(rfd,&n,sizeof(int));
		if(n <= 0)
		{
			break;
		}
		pst = (struct MyData *)malloc((n+1)*sizeof(int));
		if(NULL == pst)
		{
			MYPrintf("Malloc Failed\n");
			break;
		}
		memset(pst,0,(n+1)*sizeof(int));

		pst->count = n;
		read(rfd,pst->buf,n*sizeof(int));
		
		qsort(pst->buf,n,sizeof(int),IntCmp);
		for(i = 0;i < n;i++)
		{
			printf("%d ",*(((int *)pst->buf)+i));
		}
		printf("\n");
	
		free(pst);	
		pst = NULL;
	}

	close(rfd);
	rfd = -1;
	return 0;
}

int IntCmp(const void *pv1,const void *pv2)
{
	return *(int *)pv1 - *(int *)pv2;
}
