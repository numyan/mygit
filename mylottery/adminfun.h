#ifndef _ADMINFUN_H_
#define _ADMINFUN_H_

#include "userfun.h"
//打印链表
void display(uList* list);
//按余额大小对链表排序
void userSort(uList* list,int len);
//查询用户
void userSearch();
//按余额大小对链表排序
void userSort(uList* list,int len);
//彩票发行
void lotterySell();
//对每期链表按期号从大到小进行排序
void sortVol();

#endif