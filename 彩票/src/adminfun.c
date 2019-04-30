#include "../lib/adminfun.h"

//打印链表
void display(uList* list)
{
    if(NULL == list)
    {
        return;
    }
    User* node = list->head->next;
    printf("用户名\t\t余额\n");
    while(NULL != node)
    {
        printf("%s\t\t%.1f\n",node->user,node->balance);
        node = node ->next;
    }
}

//对每期链表按期号从大到小进行排序
void sortVol()
{
    int i = 0,j = 0;
    Vol* pre = NULL;
    Vol* cur = NULL;
    for(i=0;i < v_list->len-1;i++)
    {
        pre = v_list->head;
        cur = pre;
        for(j = 0;j<v_list->len - i -1;j++)
        {
            if(cur->vol < cur->next->vol)
            {
                if(cur == v_list->head)
                {
                    v_list->head = cur->next;
                    cur->next = cur->next->next;
                    v_list->head->next = cur;
                    pre = v_list->head;
                }
                else
                {
                    pre->next = cur->next;
                    cur->next = cur->next->next;
                    pre->next->next = cur;
                    pre = pre->next;
                }
            }
            else
            {
                pre = cur;
                cur = pre->next;
            }
            
        }
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
        node->bonusPool = v_list->head->bonusPool;

        strcpy(node->condition,"sell");
        node->price = 2;
        node->vol = v_list->head->vol + 1;   
        volInsert(v_list,node);
        printf("发行成功！\n%d期\n奖池金额:%d\n",node->vol,node->bonusPool);
    }
    volFileWrite();
}

//查询用户
void userSearch()
{
    char user[16] = "";
    printf("请输入用户名:");
    scanf("%s",user);
    while(getchar() != '\n');
    User* node = u_list->head;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            printf("查询成功！");
            printf("\n密码：%s\t余额：%.1f\n",node->pw,node->balance);
            return;
        }
        node = node->next;
    }
    printf("此用户不存在\n");
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