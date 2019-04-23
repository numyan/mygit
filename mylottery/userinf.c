#include "userinf.h"

char* pathc="user.txt";
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



