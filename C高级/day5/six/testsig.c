#include <signal.h>

#include <stdio.h>

void MyActFunction(int signo);
int main()
{
	struct sigaction myact;

	myact.sa_flags = 0;
	sigemptyset(&myact.sa_mask);
	myact.sa_handler = MyActFunction;

	sigaction(2,&myact,NULL);

	while(1)
	{
		
	}

	return 0;
}

void MyActFunction(int signo)
{
	printf("Call MyActFunction signo is %d\n",signo);
}
