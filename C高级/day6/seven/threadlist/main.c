#include "mylist.h"

void *ThreadFunc(void *pv);
int main(int argc,char *argv[])
{
	struct MyListHead *pstHead = NULL;
	pthread_t tid;
	int ret = 0;
	int i = 0;
	struct MyListNode *pstNode = NULL;

	pstHead = CreateMyListHead();
	
	ret = pthread_create(&tid,NULL,ThreadFunc,pstHead);
	if(ret != 0)
	{
		printf("pthread_create failed in %s at %d\n",__FILE__,__LINE__);		DestroyMyListHead(pstHead);
		return 1;
	}

	for(i = 1;i < 6;i+=2)
	{
		pstNode = CreateMyListNode(i);
		InsertNodeAtFirst(pstHead,pstNode);
		sleep(1);
	}

	sleep(1);
	pstNode = RemoveNodeAtFirst(pstHead);
	printf("In main thread %d is removed\n",pstNode->x);
	DestroyMyListNode(pstNode);
	
	pthread_join(tid,NULL);
	PrintAllNode(pstHead);

	DestroyMyListHead(pstHead);
	return 0;
}

void *ThreadFunc(void *pv)
{
	struct MyListHead *pstHead = (struct MyListHead *)pv;
	int i = 0;
	struct MyListNode *pstNode = NULL;
	
	for(i = 0;i < 6;i+=2)
	{
		pstNode = CreateMyListNode(i);
		InsertNodeAtFirst(pstHead,pstNode);
		sleep(1);
	}

	sleep(1);
	pstNode = RemoveNodeAtFirst(pstHead);
	printf("In main thread %d is removed\n",pstNode->x);
	DestroyMyListNode(pstNode);

	return NULL;
}
