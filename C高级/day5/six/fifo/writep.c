#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#define PIPE_NAME "/tmp/myfifo"
int main(int argc,char *argv[])
{
	int ret = 0;
	int wfd = 0;

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

	write(wfd,"Hello",6);
	
	close(wfd);
	wfd = -1;
	return 0;
}
