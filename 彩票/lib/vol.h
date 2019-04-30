#ifndef _VOL_H_
#define _VOL_H_

#include "head.h" 

typedef struct vol
{
    int vol;
    int price;
    char condition[16];
    int num[7];
    int sumLottery;
    int bonusPool;
    struct vol* next;
}Vol;

typedef struct vList
{
    int len;
    Vol* head;
}vList;

vList* v_list;//定义一个全局的彩票链表

//创建彩票链表
vList* mkVolList();
//创建彩票链表节点
Vol* mkVolNode();
//将节点插入彩票链表
void volInsert(vList* l_list,Vol* node);
//从文件中读取每期信息
void volFileRead();
//把每期信息存入文件
void _volFileWrite();

#endif