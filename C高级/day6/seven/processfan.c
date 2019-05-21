#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid1;
	pid_t pid2;
	pid_t pid3;

	pid1 = fork();
	if(pid1 < 0)
	{
		printf("Fork Failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	if(pid1 > 0)
	{
		pid2 = fork();
		if(pid2 < 0)
		{
			printf("Fork Failed in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
		if(pid2 > 0)
		{
			pid3 = fork();
			if(pid3 < 0)
			{
				printf("Fork Failed in %s at %d\n",__FILE__,__LINE__);
				return 1;
			}
			if(pid3 > 0)
			{
				int i = 0;
				for(i = 0;i < 3;i++)
				{
					wait(NULL);
				}
			}
			else
			{
				printf("Child pid is %d,ppid is %d\n",getpid(),getppid());
			}
		}
		else
		{
			printf("Child pid is %d,ppid is %d\n",getpid(),getppid());
		}
	}
	else
	{
		printf("Child pid is %d,ppid is %d\n",getpid(),getppid());
	}
	return 0;
}
