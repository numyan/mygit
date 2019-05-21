#include "mylist.h"

struct MyListHead *CreateMyListHead()
{
	struct MyListHead *pstHead = NULL;

	pstHead = (struct MyListHead *)malloc(sizeof(struct MyListHead));
	if(NULL == pstHead)
	{
		printf("Malloc Failed in %s at %d\n",__FILE__,__LINE__);
		return NULL;
	}
	memset(pstHead,0,sizeof(struct MyListHead));

	pthread_rwlock_init(&pstHead->rwlock,NULL);
	return pstHead;
}

int DestroyMyListHead(struct MyListHead *pstHead)
{
	struct MyListNode *pstNode = NULL;
	struct MyListNode *pstNext = NULL;

	if(NULL == pstHead)
	{
		printf("Input Param is invalid in %s at %d\n",__FILE__,__LINE__);
		return -1;
	}

	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		pstNext = pstNode->pstNext;
		DestroyMyListNode(pstNode);
		pstNode = pstNext;
	}

	pthread_rwlock_destroy(&pstHead->rwlock);

	free(pstHead);
	return 0;
}

struct MyListNode *CreateMyListNode(int y)
{
	struct MyListNode *pstNode = NULL;

	pstNode = (struct MyListNode *)malloc(sizeof(struct MyListNode));
	if(NULL == pstNode)
	{
		printf("Malloc Failed in %s at %d\n",__FILE__,__LINE__);
		return NULL;
	}
	memset(pstNode,0,sizeof(struct MyListNode));

	pstNode->x = y;
	return pstNode;
}

int DestroyMyListNode(struct MyListNode *pstNode)
{
	if(pstNode != NULL)
	{
		free(pstNode);
	}

	return 0;
}


int InsertNodeAtFirst(struct MyListHead *pstHead,
                      struct MyListNode *pstNewNode)
{
	if(NULL == pstHead || NULL == pstNewNode)
	{
		printf("Input Param is invalid in %s at %d\n",__FILE__,__LINE__);
		return -1;
	}
	
	pthread_rwlock_wrlock(&pstHead->rwlock);
	
	pstNewNode->pstNext = pstHead->pstFirst;
	pstHead->pstFirst = pstNewNode;

	pstHead->count++;

	pthread_rwlock_unlock(&pstHead->rwlock);
	return 0;
}

struct MyListNode *RemoveNodeAtFirst(struct MyListHead *pstHead)
{
	struct MyListNode *pstNode = NULL;

	if(NULL == pstHead)
	{
		printf("Input Param is invalid in %s at %d\n",__FILE__,__LINE__);
		return NULL;
	}

	pthread_rwlock_wrlock(&pstHead->rwlock);
	
	pstNode = pstHead->pstFirst;
	if(pstNode != NULL)
	{
		pstHead->pstFirst = pstNode->pstNext;
		pstNode->pstNext = NULL;
		pstHead->count--;
	}

	pthread_rwlock_unlock(&pstHead->rwlock);
	return pstNode;	
}

struct MyListNode *SearchNodeByNum(struct MyListHead *pstHead,
                                   int num)
{
	struct MyListNode *pstNode = NULL;
	if(NULL == pstHead)
	{
		printf("Input Param is invalid in %s at %d\n",__FILE__,__LINE__);
		return NULL;
	}

	pthread_rwlock_rdlock(&pstHead->rwlock);

	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		if(pstNode->x == num)
		{
			break;
		}
		pstNode = pstNode->pstNext;
	}
	
	pthread_rwlock_unlock(&pstHead->rwlock);

	return pstNode;
}

int PrintAllNode(struct MyListHead *pstHead)
{
	struct MyListNode *pstNode = NULL;
	int i = 0;
	if(NULL == pstHead)
	{
		printf("Input Param is invalid in %s at %d\n",__FILE__,__LINE__);
		return -1;
	}

	pthread_rwlock_rdlock(&pstHead->rwlock);

	printf("Len of List is %d\n",pstHead->count);
	pstNode = pstHead->pstFirst;
	while(pstNode != NULL)
	{
		printf("%d------%d\n",++i,pstNode->x);
		pstNode = pstNode->pstNext;
	}
	
	pthread_rwlock_unlock(&pstHead->rwlock);

	return 0;
}

