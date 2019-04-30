#ifndef _USERINF_H
#define _USERINF_H

#include "head.h"


//用户结构体
typedef struct User
{
	char user[16];
	char pw[16];
	float balance;
	struct User* next;
}User;

// 用户链表结构体
typedef struct userList
{
	int len;
	User* head;
}uList;

uList* u_list;//定义一个全局调用的链表

/*
    函数声明
*/
//创建用户链表d节点
User* mkUserNode();
// //创建用户链表
uList* mkUserList();
//// 将节点插入用户链表
void insert(uList* list,User* node);
//从文件中读取用户信息
void fileread();
//把用户信息存入文件
void filewrite();

#endif