#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("argument too few,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	if(access(argv[1],F_OK))
	{
		printf("The file %s is not exist\n",argv[1]);
	}
	else
	{
		printf("The file %s is exist\n",argv[1]);
	}

	return 0;
}
