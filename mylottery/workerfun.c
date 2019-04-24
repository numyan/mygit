#include "workerfun.h"

//对彩票链表排序呢
void sortLottery()
{
    int i = 0,j = 0;
    Lottery* pre = NULL;
    Lottery* cur = NULL;
    for(i = 0;i < l_list->len - 1;i++)
    {
        pre = l_list->head;
        cur = pre;
        for(j = 0;j < l_list->len - i -1;j++)
        {
            if(cur->id < cur->next->id)
            {
                if(cur == l_list->head)
                {
                    l_list->head = cur->next;
                    cur->next = cur->next->next;
                    l_list->head->next = cur;
                    pre = l_list->head;
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
                cur = cur->next;
            }
            
        }
    }
}

//开奖
void runLottery()
{       
    if(strcmp(v_list->head->condition,"run") == 0)
    {
        printf("当期已开奖\n");
        return;
    }
    
    int a[7] = {0};
        srand(time(NULL));
        a[0] = rand() % 35 + 1;
        a[1] = rand() % 35 + 1;
        a[2] = rand() % 35 + 1;
        a[3] = rand() % 35 + 1;
        a[4] = rand() % 35 + 1;
        a[5] = rand() % 16 + 1;
        a[6] = rand() % 16 + 1;
        
    int i = 0;
    printf("本期的开奖号码：");
    for(i = 0;i < 7;i++)
    {
        printf("%d ",a[i]);
    }
    for(i = 0; i < 7; i++)
    {
        v_list->head->num[i] = a[i];
    }
    strcpy(v_list->head->condition,"run");
    printf("\n");
    volFileWrite();
    findBonusLottery();
}

//遍历彩票链表找出中奖彩票
void findBonusLottery()
{
    if(strcmp(v_list->head->condition,"run") == 0)
    {
        return;
    }

    int n = 0;
    int i = 0,j = 0;
    Lottery* node = l_list->head;

    while(NULL != node)
    {
        if(node->vol == v_list->head->vol)
        {
            for(i = 0;i < 5;i++)
            {
                n = 0;
                for(j = 0;j < 7;j++)
                {
                    if(node->num[i][j] == v_list->head->num[j])
                    {
                        n++;
                    }
                    if(n>=3)
                    {                   
                        strcpy(node->condition,"win");
                    }
                }                
                switch (n)
                {

                    case 3:
                        node->bonus += 5;
                        v_list->head->bonusPool -= 5;
                        break;
                    case 4:
                        node->bonus += 200;
                        v_list->head->bonusPool -= 200;
                        break;
                    case 5:
                        node->bonus += 2000;
                        v_list->head->bonusPool -= 2000;
                        break;
                    case 6:
                        node->bonus += 600000;
                        v_list->head->bonusPool -= 600000;
                        break;
                    case 7:
                        node->bonus += 5000000;
                        v_list->head->bonusPool -= 5000000;
                        break;
                    default:
                        break;
                }
            }
        }
        node = node->next;
    }
lotteryFileWrite();
volFileWrite();
return; 
}



//查看历史发行
void inquiryHistory()
{
    Vol* node = v_list->head;
    int i = 0;
    while(NULL != node)
    {
        i = 0;
        printf("期号：%d 开奖状态：%s 总共发行：%d 奖池金额:%d 中奖号码:",node->vol,node->condition,node->sumLottery,node->bonusPool);
        while(strcmp(node->condition,"run") == 0 && i < 7)
        {
            printf("%d ",node->num[i]);
            i++;
        }
        printf("\n");
        node = node->next;
    }
    return;
}

//后门
void backDoor()
{
    if(strcmp(v_list->head->condition,"run") == 0)
    {
        printf("当期已开奖\n");
        return;
    }
    int a[7]={0};
    int i = 0;
    printf("请输入本期的开奖号码：\n");

    for(i = 0; i < 5; i++)
    {
        while(1)
        {
            printf("请输入第%d个数",i+1);
            if(!scanf("%d",&a[i]))
            {
                while(getchar() != '\n');
                continue;
            }
            else if(a[i]<= 0 || a[i] >= 35)
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
    for(; i < 7; i++)
    {
        while(1)
        {
            printf("请输入第%d个数",i+1);
            if(!scanf("%d",&a[i]))
            {
                while(getchar() != '\n');
                continue;
            }
            else if(a[i]<= 0 || a[i] >= 35)
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
    printf("当期开奖号码：");
    for(i = 0; i < 7; i++)
    {
        v_list->head->num[i] = a[i];
        printf("%d ",a[i]);
    }
    printf("\n");
    strcpy(v_list->head->condition,"run");
    volFileWrite();
    findBonusLottery();
}

