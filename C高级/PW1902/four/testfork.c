#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>

int gInt = 16;
int main(int argc,char *argv[])
{
	int lInt = 66;
	pid_t pid;

	pid = fork();
	if(pid < 0)
	{
		printf("fork failed, in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	if(pid > 0)
	{
		printf("gInt = %d,lInt = %d in %d process,it is parent\n",
				gInt,
				lInt,				
				(int)getpid());
	}
	else
	{//pid == 0
		gInt += 2;
		lInt += 3;
		printf("gInt = %d,lInt = %d in %d process,it is child\n",
				gInt,
				lInt,
				(int)getpid());
	}

	printf("I will exit,pid = %d\n",(int)getpid());

	return 9;
}
