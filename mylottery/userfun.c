#include "userfun.h"
//打印用户信息
void printUser(char user[])
{
    system("reset");
    User* node = u_list->head;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            printf("用户名：%s\n余额：%.1f\n",node->user,node->balance);
            break;
        }
        else
        {
            node = node->next;
        }
    }
}

//修改用户信息
void alterUser(char user[])
{
    system("reset");
    User* node = u_list->head;
    char pw[16]="";
    char pw0[16]="";
    int ret = 0;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            int i = 0;
            while(i<3)
            {                   
                printf("请输入用户密码(输错三次退出）：\n");
                scanf("%s",pw);
                while(getchar() != '\n');
                ret=judgePassword(user,pw,1);

                if(ret == 1)
                {
                    while(1)
                    { 
                        system("reset");
                        memset(pw,0,sizeof(pw));
                        printf("请输入新密码:\n");
                        scanf("%s",pw);
                        while(getchar() != '\n');
                        memset(pw0,0,sizeof(pw0));
                        printf("请再次输入：\n");
                        scanf("%s",pw0);
                        while(getchar() != '\n');

                        if(strcmp(pw0,pw) == 0)                    
                        {
                            strcpy(node->pw,pw);
                            printf("修改成功！按回车键继续\n");
                            while(getchar() != '\n');
                            userView(user);
                        }
                        else
                        {   
                            system("reset");                         
                            printf("两次输入不同(按回车继续)\n");
                            while(getchar() != '\n');
                        }  
                    }
                }
                else
                {
                    int ret = 3-i-1;
			        memset(pw,0,sizeof(pw));
			        if(ret == 0)
			        {
                        printf("三次全部错误！按回车键返回\n");
                        while(getchar() != '\n');
				        break;
			        }
                    system("clear");
			        printf("密码错误，还有%d次机会\n",ret);
                }
                i++;
            }
            break;
        }
        else
        {
            node = node->next;
        }
    }
}

//删除链表中用户信息
void deleteUser(char user[])
{
    char choose = '\0';
    system("reset");
    
    while(1)
    {
        printf("您确定要注销您的账户吗？y/n:");
        scanf("%c",&choose);
        while(getchar() != '\n');
        if(choose == 'y')
        {
            User* pre = u_list->head;
            User* cur = pre;
            while(NULL != cur)
            {
                if(strcmp(cur->user,user) == 0)
                {
                    if(cur == u_list->head)
                    {
                       u_list->head = cur->next;
                    }
                    else
                    {
                       pre->next = cur->next;                       
                    }
                    free(cur);
                    cur = NULL;
                    printf("\n注销成功！");
                    break;
                }
                else
                {
                    pre = pre->next;
                    cur = pre->next;
                }
            }
        }
        else if(choose == 'n')
        {
            printf("\n按回车键返回上一界面");
            while(getchar() != '\n');
            userView(user);
            break;
        }
        else
        {
            continue;
        }
        break;
    }
}

//给用户账户充值
void recharge(char user[])
{
    system("reset");
    User* node = u_list->head;

    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            float money = 0.0;
            while(1)
            {
                printf("请输入充值金额：\n");
                scanf("%f",&money);
                if('\n'!= getchar())
                {
                    while(getchar() != '\n');
                }
                else
                {
                    printf("确认充值%.1f元？（按回车确定）",money);
                    break;
                }
                
                printf("错误输入\n\n");   
            }
            while(getchar() != '\n');
            node->balance = node->balance + money;
            printf("\n充值成功！充值%.1f元\n账户余额：%.1f\n按回车返回上一界面",money,node->balance);
            while(getchar() != '\n');
            break;
        }
        else
        {
            node = node->next;
        }
    }
}

//彩票购买
void buyLottery(char user[])
{
    if(strcmp(v_list->head->condition,"run") == 0)
    {
        printf("本期号码以开奖,敬请期待！\n");
        return;
    }
    int n = 0;
    while(1)
    {
        printf("请输入你要打的注数(每张彩票至多5注)");
        if(!scanf("%d",&n))
        {
            system("clear");
            printf("输入错误\n");
            while(getchar() != '\n');
            continue;
        }
        if(n > 5 || n < 1)
        {
            system("clear");
            printf("输入错误\n");
            while(getchar() != '\n');
            continue;
        }
        else
        {
            break;
        } 
    }

    int num[7];
    int i = 0;
    int j = 0;
    printf("请输入你要买的彩票号码(前5注号码1～35，后两注号码1~12)\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < 7;j++)
        {
            scanf("%d",num+j);
        }

        Lottery* node = mkLotteryNode();
        node->vol = v_list->head->vol;
        node->id = node->vol*1000 + v_list->head->sumLottery + 1;
        v_list->head->sumLottery += n;
        strcpy(node->user,user);
        node->sum = n;

        lotteryInsert(l_list,node);
        l_list->len++;
    }
}

// //查询中奖记录
// void judgeBonus(char user[])
// {
//     Lottery* node = l_list->head;
//     while(NULL != node)
//     {
//         if(strcmp(node->user,user) == 0 && strcmp(node->condition,"win") == 0)
//         {
//             printf("%d\t%ld\t%d\n",node->vol,node->id,node->bonus);//打印中奖彩票期号，ID，中奖金额，中奖号码；
//         }
//         node = node->next;
//     }

// }

//查询购票记录
void lotteryRecord(char user[])
{
    int i = 0;
    int j = 0;
    Lottery* node = l_list->head;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0)
        {
            printf("期号：%d ID:%ld\n",node->vol,node->id);
            for(i = 0;i < node->sum;i++)
            {
                for(j = 0;j < 7;j++)
                {
                    printf("%d ",node->num[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
}

// //判断是否中奖
// void judegeBonus()
// {
    
// }