#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mydata.h"

#define PIPE_NAME "/tmp/myfifo"
int main(int argc,char *argv[])
{
	int ret = 0;
	int rfd = 0;
	int size = 0;
	struct MyData *pst = NULL;

	if(access(PIPE_NAME,F_OK))
	{
		ret = mkfifo(PIPE_NAME,0666);
		if(ret < 0)
		{
			printf("mkfifo failed in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
	}
	
	printf("read process before open\n");
	rfd = open(PIPE_NAME,O_RDONLY);
	printf("read process after open\n");
	if(rfd < 0)
	{
		printf("open fifo failed in %s at %d\n",__FILE__,__LINE__);
		return 2;
	}

	while(1)
	{
		read(rfd,&size,sizeof(int));
		pst = malloc(size + sizeof(int));
		if(NULL == pst)
		{
			printf("Malloc Failed in %s at %d\n",__FILE__,__LINE__);
			break;
		}
		memset(pst,0,size + sizeof(int));
		pst->len = size;

		read(rfd,pst->buf,size);
		printf("The content is %s\n",pst->buf);
		if(strcmp(pst->buf,"quit") == 0)
		{
			free(pst);
			pst = NULL;
			break;
		}
		free(pst);
		pst = NULL;
	}

	close(rfd);
	rfd = -1;
	return 0;
}
