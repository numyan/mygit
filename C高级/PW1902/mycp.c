#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	int rfd = -1;
	int wfd = -1;
	unsigned char ch = 0;
	int ret = 0;

	if(argc < 3)
	{
		printf("argument too few,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	rfd = open(argv[1],O_RDONLY);
	if(rfd < 0)
	{
		printf("open file %s failed,in %s at %d\n",argv[1],__FILE__,__LINE__);
		return 2;
	}

	wfd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(wfd < 0)
	{
		printf("open file %s failed,in %s at %d\n",argv[3],__FILE__,__LINE__);
		return 3;
	}
	
	ret = read(rfd,&ch,1);
	while(ret == 1)
	{
		write(wfd,&ch,1);
		ret = read(rfd,&ch,1);
	}

	close(rfd);
	close(wfd);
	rfd = wfd = -1;
	return 0;
}
