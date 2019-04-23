#include "head.h"

char* pathc="user.txt";
//用户结构体
typedef struct User
{
	char user[16];
	char pw[16];
	float balance;
	struct User* next;
}User;

//链表结构体
typedef struct userList
{
	int len;
	User* head;
}uList;

uList* u_list;//定义一个全局调用的链表

//函数声明：
//创建用户链表d节点
User* mkUserNode();
// //创建用户链表
uList* mkUserList();
//// 将节点插入用户链表
void insert();
// //用户登录
void lotteryLoad();
//注册用户
void lotteryRegister();
//登录界面
void loadView();
//从文件中读取用户信息
void fileread();
//把用户信息存入文件
void filewrite();



//创建用户链表的节点
User* mkUserNode()
{
	User* node = (User*)malloc(sizeof(User));
	if(NULL == node)
	{
		exit(EXIT_FAILURE);
	}
	memset(node,0,sizeof(User));

	return node;
}

//创建用户链表
uList* mkUserList()
{
	uList* list = (uList*)malloc(sizeof(uList));
	if(NULL == list)
	{
		exit(EXIT_FAILURE);
	}
	memset(list,0,sizeof(uList));

	return list;
}

//将节点插入用户链表
void insert(uList* list,User* node)
{
	if(NULL == list || NULL == node)
	{
		exit(EXIT_FAILURE);
	}
    
	node->next = list->head;
	list->head = node;
	list->len++;
}

void display(uList* list)
{
    if(NULL == list)
    {
        return;
    }
    User* node = list->head;
    while(NULL != node)
    {
        printf("%s\t%s\t%.1f\n",node->user,
                                node->pw,
                                node->balance);
        node = node ->next;
    }
}

//判断用户是否存在(返回值为1用户存在，返回值为0用户不存在)
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

//
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

//从文件中读取用户信息
void fileread()
{
    FILE* file = fopen(pathc,"r");
    if(NULL == file)
    {
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        User* node = mkUserNode();
        int ret = fscanf(file,"%s%s%f",node->user,node->pw,&node->balance);
        if(ret == EOF)
        {
            free(node);
            node = NULL;
            fclose(file);
			break;
        }
        insert(u_list,node);
    }
}

//把用户信息存入文件
void filewrite()
{
    FILE* file = fopen(pathc,"w");
    if(NULL == file)
    {
        printf("存入用户信息失败\n");
        exit(EXIT_FAILURE);
    }

    User* node = u_list->head;
    while(NULL != node)
    {
        fprintf(file,"%s\t%s\t%f\n",node->user,node->pw,node->balance);
        node = node->next;
    }
	fclose(file);
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
		printf("请输入用户名：");
		scanf("%s",user);
		while(getchar() != '\n');
		printf("请输入用户密码：");
		scanf("%s",pw);
    	while(getchar() != '\n');
		ret1=judgeUser(user);
		ret2=judgePassword(user,pw,ret1);
		if(ret2 == 1)
		{
			//userView();
		}
		else if(ret2 == 2)
		{
			//workerView();
		}
		else if(ret2 == 3)
		{
			//adminView();
		}
		else
		{
			printf("用户名不存在或密码错误\n");
			memset(user,0,sizeof(user));
			memset(pw,0,sizeof(pw));
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
            printf("该用户名已存在，请重新输入：\n");
            memset(node->user,0,sizeof(node->user));
        }   
    }
	
	printf("请输入注册密码：\n");
    while(1)
	{
        scanf("%s",node->pw);
        while(getchar() != '\n');
	    printf("请再次输入：\n");
	    scanf("%s",pw0);
        while(getchar() != '\n');
        if(strcmp(node->pw,pw0) == 0)
	    {
		    break;
	    }
        else
        {
            printf("两次密码不相同，请重新输入");
		    memset(node->pw,0,sizeof(node->pw));
		    memset(pw0,0,sizeof(pw0));
        }
    }
    insert(u_list,node);
    loadView();
}

void loadView()
{
    system("reset");
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
		lotteryLoad();
	}
	else if(choose == 2)
	{
		lotteryRegister();
	}
	else
	{
        filewrite();
		system("reset");
		exit(EXIT_SUCCESS);
	}
}

int main()
{
	u_list = mkUserList();
    fileread();
	
	loadView();
    return 0;
}