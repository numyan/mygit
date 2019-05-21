#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid1;
	pid_t pid2;

	pid1 = fork();
	if(pid1 < 0)
	{
		printf("Fork Failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	if(pid1 == 0)
	{
		pid2 = fork();
		if(pid2 < 0)
		{
			printf("Fork Failed in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
		if(pid2 > 0)
		{
			printf("Child pid is %d,ppid is %d\n",getpid(),getppid());
			wait(NULL);
		}
		else
		{
			printf("Grandson pid is %d,ppid is %d\n",getpid(),getppid());
		}
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
