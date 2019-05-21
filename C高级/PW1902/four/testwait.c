#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if(pid < 0)
	{
		printf("fork error,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	switch(pid)
	{
		case 0:
			printf("In child process,pid=%d\n",getpid());
			sleep(3);
			return 13;
		default:
			printf("In parent process,pid=%d\n",getpid());
			wait(&status);
			printf("Child return %d\n",WEXITSTATUS(status));	
			printf("Parent continue....\n");
			while(1)
			{
			}
			break;
	}
	return 0;
}
