#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	int fd = -1;
	char ch = '\0';

	fd = open("c.txt",O_RDONLY);
	if(fd < 0)
	{
		printf("Open %s failed,in %s at %d\n","c.txt",__FILE__,__LINE__);
		return 1;
	}
	
	lseek(fd,9,SEEK_SET);
	if(read(fd,&ch,1) != 1)
	{
		printf("read error,in %s at %d\n",__FILE__,__LINE__);
		close(fd);
		fd = -1;
		return 2;
	}
	
	printf("ch=%c\n",ch);

	close(fd);
	fd = -1;
	return 0;
}
