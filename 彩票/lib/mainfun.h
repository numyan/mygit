#ifndef MAINFUN_H
#define MAINFUN_H

#include "mainview.h"
int getch();
//输入密码并显示为*号
void getPassword(char *pcPWD);
//判断用户是否存在(返回值为0用户不存在)
int judgeUser();
//判断密码是否错误
int judgePassword();
// //用户登录
void lotteryLoad();
//注册用户
void lotteryRegister();
//验证码功能
void identifyingCode();

#endif