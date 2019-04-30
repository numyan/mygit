#ifndef MAINVIEW_H
#define MAINVIEW_H

#include "userinf.h"
#include "lotteryinf.h"
#include "vol.h"

//登录界面
void loadView();
//用户界面
void userView(char user[]) ;
//管理员界面
void adminView();
//公证人员界面
void workerView(); 

#endif