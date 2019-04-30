#include "../lib/userfun.h"

//打印用户信息
void printUser(char user[])
{
    system("clear");
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
    system("clear");
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
                getPassword(pw);
                identifyingCode();
                getchar();
                ret=judgePassword(user,pw,1);

                if(ret == 1)
                {
                    while(1)
                    { 
                        system("clear");
                        memset(pw,0,sizeof(pw));
                        printf("请输入新密码:\n");
                        getPassword(pw);
                        memset(pw0,0,sizeof(pw0));
                        printf("请再次输入：\n");
                        getPassword(pw0);

                        if(strcmp(pw0,pw) == 0)                    
                        {
                            strcpy(node->pw,pw);
                            printf("修改成功！请重新登录（按回车继续）\n");
                            while(getchar() != '\n');
                            return;
                        }
                        else
                        {   
                                                     
                            printf("两次输入不同(按任意键+回车继续，按ESC+回车返回用户界面)\n");
                            if(getch() == '\e')
                            {
                                while(getchar() != '\n');
                                userView(user);
                            }
                            while(getchar() != '\n');
                            system("clear");
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
                    
			        printf("密码错误，还有%d次机会(按任意键+回车继续，按ESC+回车返回)\n",ret);
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
    system("clear");
    
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
    system("clear");
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
                    continue;
                }
                else
                {
                    printf("确认充值%.1f元？（按任意键+回车确定，ESC+回车取消）",money);
                    if(getch() == '\e')
                    {
                        while(getchar() != '\n');
                        return;
                    }
                    while(getchar() != '\n');
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
    return;
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
        printf("请输入你要打的注数(每张彩票至多5注):\n");
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

    User* uNode = u_list->head;
    while(uNode != NULL)
    {
        if(strcmp(uNode->user,user) == 0)
        {
            uNode->balance -= 2*n;
        }
        uNode = uNode->next;
    }

    system("clear");

    printf("1：    机选随机\n");
    printf("2:    手动手输入\n");
    int choose = 4;
    int num[7];
    int i = 0;
    int j = 0;
	while(1)
	{
		if(choose != 1 && choose != 2)
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
    Lottery* node = mkLotteryNode();
    if(choose == 1)
    {
        for(i = 0; i < n;i++)
        {
            for(j = 0;j < 5;j++)
            {
                //srand(time(NULL));
                node->num[i][j] = rand() % 35 + 1;
            }
            for(;j < 7;j++)
            {
                //srand(time(NULL));
                node->num[i][j] = rand() % 16 + 1;
            }
        }
    }
    else    
    {        
        printf("请输入你要买的彩票号码(前5注号码1～35，后两注号码1~12)\n");
        for(i = 0;i < n;i++)
        {
            system("clear");
            printf("第%d注:\n",i+1);
            for(j = 0;j < 5;j++)
            {
                while(1)
                {
                    printf("请输入前区第%d个数:",j+1);
                    if(!scanf("%d",&node->num[i][j]))
                    {
                        while(getchar() != '\n');
                        continue;
                    }
                    else if(node->num[i][j] <= 0 || node->num[i][j] >= 35)
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }                          
                }
                while(getchar() != '\n');
            }
            for(;j < 7;j++)
            {
                while(1)
                {
                    printf("请输入后区第%d个数:",j-4);
                    if(!scanf("%d",&node->num[i][j]))
                    {
                        while(getchar() != '\n');
                        continue;
                    }
                    else if(node->num[i][j] <= 0 || node->num[i][j] >= 16)
                    {
                        while(getchar() != '\n');
                        continue;
                    }
                    else
                    {
                        break;
                    }            
                }
                while(getchar() != '\n');
            }           
        }
    }
   
    node->vol = v_list->head->vol;
    node->id = node->vol*1000 + v_list->head->sumLottery + 1;
    v_list->head->sumLottery += n;
    memset(node->user,0,16);
    strcpy(node->user,user);
    strcpy(node->condition,"miss");
    node->sum = n;
    
    lotteryInsert(l_list,node);
    lotteryFileWrite();

    system("clear");
    
    for(i=0;i<n;i++)
    {
        printf("第%d注：",i+1);
        for(j=0;j<7;j++)
        {
            printf("%d ",node->num[i][j]);
        }
        printf("\n");
    }
    printf("\n购买成功！\n消费%d元\n",2*n);
}

//查询中奖记录
void judgeBonus(char user[])
{
    int i = 0,j = 0;
    int n = 0;
    Lottery* node = l_list->head;
    Vol* vNode = v_list->head;
    while(NULL != node)
    {
        if(strcmp(node->user,user) == 0 && strcmp(node->condition,"win") == 0)
        {            
            printf("\n第%d期 ID：%ld 彩票中奖金额：%d\n",node->vol,node->id,node->bonus);//打印中奖彩票期号，ID，
            //判断中奖金额
            while(vNode != NULL)
            {
                if(node->vol == vNode->vol)
                {
                    break;
                }
                vNode = vNode->next; 
            }

            for(i = 0;i < node->sum;i++)
            {
                n = 0;
                for(j = 0;j < 7;j++)
                {
                    if(node->num[i][j] == vNode->num[j])
                    {
                        n++;
                    }
                }
                if(n >= 3)
                {
                    switch (n)
                    {
                        case 3:
                            printf("第%d注中%d等奖，奖金%d元\n",i+1,8-n,5);
                            break;
                        case 4:
                            printf("第%d注中%d等奖，奖金%d元\n",i+1,8-n,200);
                            break;
                        case 5:
                            printf("第%d注中%d等奖，奖金%d元\n",i+1,8-n,2000);
                            break;
                        case 6:
                            printf("第%d注中%d等奖，奖金%d元\n",i+1,8-n,600000);
                            break;
                        case 7:
                            printf("第%d注中%d等奖，奖金%d元\n",i+1,8-n,5000000);
                            break;
                        default:break;
                    }
                    
                }
            }

        }
        node = node->next;
    }

}

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
            printf("期号：%d ID:%ld 注数：%d\n",node->vol,node->id,node->sum);
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
        node = node ->next;
    }
}
