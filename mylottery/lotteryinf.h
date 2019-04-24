#ifndef _LOTTERYINF_H_
#define _LOTTERYINF_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct lottery
{
    int vol;
    long int id;
    int num[5][7];
    char user[16];
    int sum;
    char condition[32];
    int bonus;
    struct lottery* next;
}Lottery;

typedef struct lList
{
    int len;
    Lottery* head;
}lList;

lList* l_list;//定义一个全局的彩票链表

//创建彩票链表
lList* mkLotteryList();
//创建彩票链表节点
Lottery* mkLotteryNode();
//将节点插入彩票链表
void lotteryInsert(lList* l_list,Lottery* node);
//从文件中读取彩票信息
void lotteryFileRead();
//把彩票信息存入文件
void lotteryFileWrite();

#endif