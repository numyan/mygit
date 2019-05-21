#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#define PIPE_NAME "/tmp/myfifo"
int main(int argc,char *argv[])
{
	int ret = 0;
	int rfd = 0;
	char buf[8] = "";

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

	read(rfd,buf,8);

	printf("The buf is %s\n",buf);
	close(rfd);
	rfd = -1;
	return 0;
}
