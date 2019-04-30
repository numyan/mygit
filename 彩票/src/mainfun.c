#include "../lib/mainfun.h"

//
int getch()  
{  
		int c=0;  
		struct termios org_opts, new_opts;  
		int res=0;  

		res=tcgetattr(STDIN_FILENO, &org_opts);  
		assert(res==0);  
		memcpy(&new_opts, &org_opts, sizeof(new_opts));  
		new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT     | ECHOKE | ICRNL);  
		tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);  
		c=getchar();  
		res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);  
		assert(res==0);  
		return c;  
}  

void getPassword(char *pcPWD)
{
		int ch=0;

		int i=0;

		for(i=0;i<16;)
		{
				ch=getch();
				if(ch==-1)//当无键入时，跳出当前循环继续下一个循环
				{
						continue;
				}
				//127在键盘上是delete  8代表退格键backspace
				if((ch == 127 || ch == 8) && i>0)//当有键入时，按键delete或backspace时，删除一位
				{
						putchar('\b');	//这里是删除一个，通过输出回撤符 /b，回撤一格，
						putchar(' ');	//再显示空格符把刚才的*给盖住，
						putchar('\b');	//然后再 回撤一格等待录入。
						i--;			//减少一位
				}
				//10在键盘上代表换行(LF)，13代表回车(CR)
				//3.在不同平台，输入回车，getch()将返回不同数值，而getchar()统一返回10(即\n)
				//1)windows平台下ENTER键会产生两个转义字符 \r\n，因此getch返回13(\r)。
				//2)unix、 linux系统中ENTER键只产生 \n ，因此getch返回10(\n)。
				//3)MAC OS中ENTER键将产生 \r ，因此getch返回13(\r)。
				else if(ch==10 || ch == 13)//当键入的为换行时
				{
						pcPWD[i]='\0';//将字符串以'\0'结尾
						putchar('\n');
						return;
				}
				else if(i==0&&(ch==127 ||ch == 8))//当无键入时，按键delete或backspace时，产生警报
				{
						printf("\a");
				}
				else if(i<15)//当键入的数少于19位时每键入一个数打印一个星号覆盖
				{
						pcPWD[i]=(char)ch;
						putchar('*');
						i++;
				}
				else//当键入的数超过19位时，再次键入产生响铃
				{
						printf("\a");//响铃
				}
		}
}

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
		getPassword(pw);
		identifyingCode();
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
			
			printf("用户名不存在或密码错误(输错三次退出，还有%d次机会)\n按任意键+回车继续,ESC+回车返回\n",ret);
			if(getch() == '\e')
			{
				while(getchar() != '\n');
				return;
			}
            while(getchar() != '\n');
			system("clear");
		}
		i++;		
	}
	 
}

//注册用户
void lotteryRegister()
{
    int ret = 1;
	User* node = mkUserNode();
	char pw0[16]="";

	
    while(1)
    {
		printf("请输入注册的用户名：\n");
        scanf("%s",node->user);
        while(getchar() != '\n');
        ret = judgeUser(node->user);
        if(ret == 0)
        {
            break;
        }
        else
        {
            printf("该用户名已存在，请重新输入(按任意键+回车继续,ESC+回车返回)：\n");
			if(getch() == '\e')
			{
				while(getchar() != '\n');
				return;
			}
            while(getchar() != '\n');
            memset(node->user,0,sizeof(node->user));
			system("clear");
        }   
    }
		
    while(1)
	{
		printf("请输入注册密码：\n");
		getPassword(node->pw);
	    printf("请再次输入：\n");
		getPassword(pw0);
        if(strcmp(node->pw,pw0) == 0)
	    {
			identifyingCode();
			printf("注册成功！按回车键返回\n");
            while(getchar() != '\n');
		    break;
	    }
        else
        {
            printf("两次输入不同(按任意键+回车继续,ESC+回车返回)\n");
			if(getch() == '\e')
			{
				while(getchar() != '\n');
				break;
			}
            while(getchar() != '\n');
		    memset(node->pw,0,sizeof(node->pw));
		    memset(pw0,0,sizeof(pw0));
			system("clear");
        }
    }
	
    insert(u_list,node);    
}

//验证码函数
void identifyingCode()
{
	char array[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";//种子
	char a[5] = "";
	char b[5] = "";
	while(1)
	{
		//得到验证码
		srand(time(NULL));
		a[0] = array[rand() % 26];
		a[1] = array[rand() % 26 + 26];
		a[2] = array[rand() % 10 + 52];
		a[3] = array[rand() % 10 + 52];
		a[4] = '\0';

		sleep(1);
		system("clear");
		printf("验证码：");
		printf("%s\n",a);
		printf("请输入验证码：");
		scanf("%s",b);

		if(strcmp(a,b) != 0)
		{
			printf("验证码输入错误，请重新输入！\n");
			continue;
		}
		break;
	}
}
