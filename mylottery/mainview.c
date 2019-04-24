#include "mainview.h"

void loadView()
{
    filewrite();
    system("clear");

	int choose=3;
	printf("*********************\n");
	printf("*       1.登录      *\n");
	printf("*       2.注册      *\n");
	printf("*       0.退出      *\n");
	printf("*********************\n");
	
	while(1)
	{
		if(choose !=1 && choose !=2 && choose!=0)
		{
			printf("请输入你的选择：");
			if(!scanf("%d",&choose))
			{
				while(getchar() != '\n');
				continue;
			}
		}
		else
		{
			break;
		}	
	}

	if(choose == 1)
	{
		system("clear");
		lotteryLoad();
	}
	else if(choose == 2)
	{
		system("clear");
		lotteryRegister();
	}
	else
	{
		system("clear");
		exit(EXIT_SUCCESS);
	}
}

//用户界面
void userView(char user[]) 
{
	filewrite();
    system("clear");
    printf("欢迎进入用户界面\n");
	printf("1:	查看个人信息\n");
	printf("2:	修改个人密码\n");
	printf("3:	注销个人信息\n");
	printf("4:	充        值\n");
	printf("5:	查询中奖记录\n");
	printf("6:	买        票\n");
	printf("7:	查询购票记录\n");
	printf("8:	猜拳游戏\n");
	printf("0:	返回上一级\n");

	int choose = 9;
	while(1)
	{
		if(choose != 1 && choose != 2 && choose != 3 && 
		   choose != 4 && choose != 5 && choose != 6 &&
		   choose != 7 && choose != 8 && choose != 0)
		{
			printf("请输入你的选择：");
			if(!scanf("%d",&choose))
			{
				while(getchar() != '\n');
				continue;
			}
		}
		else
		{
			break;
		}	
	}

	while(getchar() != '\n');
	switch(choose)
	{
		case 1:
			printUser(user);
			printf("\n按回车返回上一界面");
			while(getchar() != '\n');
			userView(user);
			break;
		case 2:
			alterUser(user);
			loadView(user);
			break;
		case 3:
			deleteUser(user);
			printf("\n按回车返回上一界面");
			while(getchar() != '\n');
			loadView();
			break;
		case 4:
			recharge(user);
			userView(user);
			break;
		case 5:
			system("clear");
			judgeBonus(user);
			printf("\n按回车返回上一界面");
			while(getchar() != '\n');
			break;
		case 6:
		    system("clear");
			buyLottery(user);
			printf("\n按回车返回上一界面");
			while(getchar() != '\n');
			break;
		case 7:
		    system("clear");
			lotteryRecord(user);
			printf("\n按回车返回上一界面");
			while(getchar() != '\n');
			break;
		// case 8:

		case 0:
			loadView();
			break;
		default:break;
	}
	userView(user);
}

//管理员界面
void adminView()
{
	system("clear");
    printf("欢迎进入管理员界面\n");
	printf("1:	发行彩票\n");
	printf("2:	按用户帐号查询\n");
	printf("3:	按用户余额查询\n");
	printf("0:	返回上一级菜单\n");

	int choose = 4;
	while(1)
	{
		if(choose != 1 && choose != 2 && choose != 3 && choose != 0)
		{
			printf("请输入你的选择：");
			if(!scanf("%d",&choose))
			{
				while(getchar() != '\n');
				continue;
			}
		}
		else
		{
			break;
		}	
	}

	while(getchar() != '\n');
	switch(choose)
	{
		case 1:
			system("clear");
			lotterySell();
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			adminView();
			break;
		case 2:
			system("clear");
			userSearch();
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			adminView();
			break;
		case 3:
			system("clear");
			userSort(u_list,u_list->len);
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			adminView();
			break;
		case 0:
			loadView();
			break;
		default:break;
	}
}

//公证员界面
void workerView()
{
	system("clear");
    printf("欢迎进入公证员界面\n");
	printf("1:	开奖\n");
	printf("2:	查看历史发行\n");
	printf("0:	返回上一级菜单\n");

	int choose = 4;
	while(1)
	{
		if(choose != 1 && choose != 2 && choose != 3 && choose != 0)
		{
			printf("请输入你的选择：");
			if(!scanf("%d",&choose))
			{
				while(getchar() != '\n');
				continue;
			}
		}
		else
		{
			break;
		}	
	}

	while(getchar() != '\n');
	switch(choose)
	{
		case 1:
			system("clear");
			runLottery();
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			workerView();
			break;
		case 2:
			system("clear");
			inquiryHistory();
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			workerView();
			break;
		case 3:
			system("clear");
			backDoor();
			printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
			workerView();
			break;
		case 0:
			loadView();
			break;
		default:break;
	}
}