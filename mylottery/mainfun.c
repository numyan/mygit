#include "mainfun.h"


//判断用户是否存在(返回值为0用户不存在)
int judgeUser(char user[])
{
    int ret = 0;
    User* node = u_list->head;
    if(strcmp(user,"admin") == 0)
    {
        return ret + 2;
    }
    if(strcmp(user,"worker") == 0)
    {
        return ret + 3;
    }
	while(node != NULL)
	{
		if(strcmp(user,node->user) == 0 )
		{
			return ret + 1;
		}
		else
		{
			node = node->next;
		}
	}

    return ret;
}

//判断密码是否错误
int judgePassword(char user[],char pw[],int a)
{
	int ret = 0;
	if(a == 0)
	{
		return ret;
	}
	if(a == 2 && strcmp(pw,"12345") == 0)
	{
		return ret + 2;
	}
	if(a == 3 && strcmp(pw,"12345") == 0)
	{
		return ret + 3;
	}
	User* node = u_list->head;
	while(NULL != node)
	{
		if(strcmp(node->user,user)==0 && strcmp(node->pw,pw)==0)
		{
			return ret + 1;
		}
		else
		{
			node = node->next;
		}
	}
	return ret;
}

//用户登录
void lotteryLoad()
{
	int i = 0;
	char user[16]="";
	char pw[16]="";
	int ret1,ret2;
	while(i<3)
	{	
		printf("请输入用户名：\n");
		scanf("%s",user);
		while(getchar() != '\n');
		printf("请输入用户密码：\n");
		scanf("%s",pw);
    	while(getchar() != '\n');
		ret1=judgeUser(user);
		ret2=judgePassword(user,pw,ret1);
		if(ret2 == 1)
		{
			userView(user);
		}
		else if(ret2 == 2)
		{	
			adminView();
		}
		else if(ret2 == 3)
		{
			workerView();
		}
		else
		{ 
			int ret = 3-i-1;
			memset(user,0,sizeof(user));
			memset(pw,0,sizeof(pw));
			if(ret == 0)
			{
				printf("三次全部错误！按回车键返回\n");
                while(getchar() != '\n');
				break;
			}
			system("reset");
			printf("用户名不存在或密码错误(输错三次退出)，还有%d次机会)\n",ret);
		}
		i++;		
	}
	 loadView();
}

//注册用户
void lotteryRegister()
{
    int ret = 1;
	User* node = mkUserNode();
	char pw0[16]="";

	printf("请输入注册的用户名：\n");
    while(1)
    {
        scanf("%s",node->user);
        while(getchar() != '\n');
        ret = judgeUser(node->user);
        if(ret == 0)
        {
            break;
        }
        else
        {
			system("clear");
            printf("该用户名已存在，请重新输入：\n");
            memset(node->user,0,sizeof(node->user));
        }   
    }
		
    while(1)
	{
		printf("请输入注册密码：\n");
        scanf("%s",node->pw);
        while(getchar() != '\n');
	    printf("请再次输入：\n");
	    scanf("%s",pw0);
        while(getchar() != '\n');
        if(strcmp(node->pw,pw0) == 0)
	    {
			printf("注册成功！按回车键返回\n");
            while(getchar() != '\n');
		    break;
	    }
        else
        {
			system("clear");
            printf("两次输入不同(按回车继续)\n");
            while(getchar() != '\n');
		    memset(node->pw,0,sizeof(node->pw));
		    memset(pw0,0,sizeof(pw0));
        }
    }
    insert(u_list,node);
    loadView();
}
