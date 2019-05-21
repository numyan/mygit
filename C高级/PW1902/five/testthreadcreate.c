#include <pthread.h>

#include <stdio.h>

void *ThreadFunc(void *pv);
int main(int argc,char *argv[])
{
	pthread_t tid;
	int ret = 0;
	int i = 0;
	void *pvRet = NULL;
	
	ret = pthread_create(
							&tid,
							NULL,
							ThreadFunc,
							(void *)123
						);
	if(ret != 0)
	{
		printf("pthread_create failed in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	for(i = 0;i < 30;i++)
	{
		printf("I am in main thread %d....\n",i);
	}
	ret = pthread_join(tid,&pvRet);
	if(ret != 0)
	{
		printf("pthread_join failed,in %s at %d\n",__FILE__,__LINE__);
		return 1;
	}
	
	printf("pvRet = %ld \n",(long)pvRet);

	//pthread_exit(NULL);
	return 0;
}

void *ThreadFunc(void *pv)
{
	int i = 0;
	long x = (long)pv;
	for(i = 0;i < 30;i++)
	{
		printf("I am in new thread %d x=%ld ....\n",i,x);
	}

	pthread_exit((void *)789);
	//....
	return (void *)456;
}










