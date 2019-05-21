#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid;

	pid = fork();
	if(pid < 0)
	{
		printf("fork failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}

	if(pid > 0)
	{//
		wait(NULL);
		printf("Parent exiting....\n");	
	}
	else
	{
		execl("./test","./test","abc","def",(char *)0);
	}
	return 0;
}
