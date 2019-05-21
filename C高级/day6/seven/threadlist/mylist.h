#ifndef _MY_LIST_H
#define _MY_LIST_H

#include <unistd.h>

#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MyListNode
{
	int x;

	struct MyListNode *pstNext;
};

struct MyListHead
{
	int count;
	pthread_rwlock_t rwlock;

	struct MyListNode *pstFirst;
};

struct MyListHead *CreateMyListHead();
int DestroyMyListHead(struct MyListHead *pstHead);
struct MyListNode *CreateMyListNode(int y);
int DestroyMyListNode(struct MyListNode *pstNode);


int InsertNodeAtFirst(struct MyListHead *pstHead,
                      struct MyListNode *pstNewNode);
struct MyListNode *RemoveNodeAtFirst(struct MyListHead *pstHead);
struct MyListNode *SearchNodeByNum(struct MyListHead *pstHead,int num);
int PrintAllNode(struct MyListHead *pstHead);

#endif
