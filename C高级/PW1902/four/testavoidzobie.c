#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t cpid;
	pid_t spid;

	cpid = fork();
	if(cpid < 0)
	{
		printf("fork failed,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}	

	if(cpid > 0)
	{
		printf("In parent process pid=%d\n",getpid());
		wait(NULL);	
	}
	else
	{
		spid = fork(); 	
		if(spid < 0)
		{
			printf("fork failed,in %s at %d\n",__FILE__,__LINE__);
			return 1;
		}
		if(spid > 0)
		{//child process
			printf("In child process pid=%d\n",getpid());
			return 0;
		}
		else
		{//grandson process
			printf("In grandson process pid=%d\n",getpid());
			printf("doing something ....\n");
			sleep(60);
			return 0;
		}
	
	}

	return 0;
}











