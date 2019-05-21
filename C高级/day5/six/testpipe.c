#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <stdio.h>

int main()
{
	int arrfd[2] = {-1,-1};
	pid_t cpid;
	
	pipe(arrfd);

	cpid = fork();
	if(cpid < 0)
	{
		printf("Fork failed in %s at %d\n",__FILE__,__LINE__);
		close(arrfd[0]);
		close(arrfd[1]);
		return 1;
	}

	if(cpid > 0)
	{
		close(arrfd[0]);
		write(arrfd[1],"Hello",6);
		wait(NULL);
		close(arrfd[1]);
	}
	else
	{//child process
		char buf[8] = "";
		close(arrfd[1]);
		read(arrfd[0],buf,8);
		printf("In child process buf=%s\n",buf);
		close(arrfd[0]);
	}
	return 0;
}
