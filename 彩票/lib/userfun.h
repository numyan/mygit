#ifndef USERFUN_H
#define USERFUN_H

#include "mainfun.h"


//打印用户信息
void printUser(char user[]);
//修改用户信息
void alterUser(char user[]);
//删除链表中用户信息
void deleteUser(char user[]);
//给用户账户充值
void recharge(char user[]);
//彩票购买
void buyLottery(char user[]);
//查询中奖记录
void judgeBonus(char user[]);
//查询购票记录
void lotteryRecord(char user[]);

#endif