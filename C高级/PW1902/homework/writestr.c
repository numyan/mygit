#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct T
{
	int a;
	float b;
	char c;
};

int main(int argc,char *argv[])
{
	struct T t = {0}; 
	char buf[64] = "";
	int fd = -1;

	if(argc < 2)
	{
		printf("argument too few,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	printf("Please input int & float & char:\n");
	scanf("%d%f%c",&t.a,&t.b,&t.c);

	sprintf(buf,"%d@%.2f@%c\n",t.a,t.b,t.c);	
	
	fd = open(argv[1],O_WRONLY | O_CREAT | O_TRUNC,0666);
	if(fd < 0)
	{
		printf("open %s failed,in %s at %d\n",
				argv[1],
				__FILE__,
				__LINE__);
		return 2;
	}

	write(fd,buf,strlen(buf));

	close(fd);
	fd = -1;
	return 0;
}








