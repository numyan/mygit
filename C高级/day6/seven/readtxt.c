#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	int fd = -1;
	char ch = '\0';
	int ret = 0;

	if(argc < 2)
	{
		printf("Argument too few!in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		printf("open %s failed!in %s at %d\n",argv[1],__FILE__,__LINE__);
		return 2;
	}

	ret = read(fd,&ch,1);
	while(ret == 1)
	{
		write(1,&ch,1);
		ret = read(fd,&ch,1);
	}
	close(fd);
	return 0;
}
