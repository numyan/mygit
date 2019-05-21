#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PIPE_NAME "/tmp/myfifo"
char *MyGetString(char *pbuf,int size);
int main(int argc,char *argv[])
{
	int ret = 0;
	int wfd = 0;
	char buf[64] = "";
	int size = 0;

	if(access(PIPE_NAME,F_OK))
	{
		ret = mkfifo(PIPE_NAME,0666);
		if(ret < 0)
		{
			printf("mkfifo failed in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
	}
	
	printf("write process before open\n");
	wfd = open(PIPE_NAME,O_WRONLY);
	printf("write process after open\n");
	if(wfd < 0)
	{
		printf("open fifo failed in %s at %d\n",__FILE__,__LINE__);
		return 2;
	}

	while(1)
	{
		memset(buf,0,64);
		printf("Please your content:\n");
		MyGetString(buf,64);

		size = strlen(buf) + 1;
		write(wfd,&size,sizeof(int));
		write(wfd,buf,size);
		if(strcmp(buf,"quit") == 0)	
		{
			break;
		}	
	}
	
	close(wfd);
	wfd = -1;
	return 0;
}

char *MyGetString(char *pbuf,int size)
{
	char *p = NULL;
	int len = 0;
	p = fgets(pbuf,size,stdin);
	if(NULL == p)
	{
		return NULL;
	}
	/*判断用户本次输入有剩余*/
	len = strlen(pbuf);
	if(*(pbuf + len - 1) == '\n')
	{
		*(pbuf+len-1) = '\0';
	}
	else
	{
		while(getchar()!='\n')
		{
		}
/*		char ch;
		ch = getchar();
		while(ch != '\n')
		{
			ch = getchar();
		}
*/
	}
	return p;
}
