#include "adminfun.h"

//打印链表
void display(uList* list)
{
    if(NULL == list)
    {
        return;
    }
    User* node = list->head;
    printf("用户名\t\t余额\n");
    while(NULL != node)
    {
        printf("%s\t\t%.1f\n",node->user,node->balance);
        node = node ->next;
    }
}

//彩票发行
void lotterySell()
{
    if(strcmp(v_list->head->condition,"run") != 0 )
    {
        printf("当期未开奖，不能发行下期\n");
        return;
    }
    else
    {
        Vol* node = mkVolNode();
        strcpy(node->condition,"sell");
        node->price = 2;
        if(v_list->head->bonusPool < 100000000)
        {
            node->bonusPool = 100000000;
        }
        else
        {
            node->bonusPool = v_list->head->bonusPool;
        }
        node->vol = 1900 + v_list->len + 1;
        volInsert(v_list,node);
        v_list->len++;
        printf("发行成功！\n%d期\n奖池金额:%d\n",node->vol,node->bonusPool);
        volFileWrite();
    }
}

//查询用户
void userSearch()
{
    char user[16] = "";
    printf("请输入用户名:");
    scanf("%s",user);
    User* node = u_list->head;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            printf("\n密码：%s余额：%.1f\n",node->pw,node->balance);
            break;
        }
        node = node->next;
    }
}

//按余额大小对链表排序
void userSort(uList* list,int len)
{
    User user[len];
    int i = 0,j = 0;
    memset(user,0,len*sizeof(User));

    User* node = list->head;
    while(NULL != node)
    {
        user[i] = *node;
        node = node->next;
        i++;
    }
    for(i = 0;i < len - 1;i++)
    {
        for(j = 0;j < len - i -1;j++)
        {
            if(user[j].balance < user[j+1].balance)
            {
                User temp = user[j];
                user[j] = user[j+1];
                user[j+1] = temp;
            }
        }
    }
    printf("用户名\t\t金额\n");
    for(i = 0;i < len;i++)
    {
        printf("%s\t\t%.1f\n",user[i].user,user[i].balance);
    }
}