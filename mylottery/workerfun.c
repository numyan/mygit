#include "workerfun.h"

//开奖
void runLottery()
{
    //int array[100] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};
    int a[7] = {0};
        srand(time(NULL));
        a[0] = rand() % 35;
        a[2] = rand() % 35;
        a[3] = rand() % 35;
        a[4] = rand() % 35;
        a[5] = rand() % 35;
        a[6] = rand() % 16;
        a[7] = rand() % 16;

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
}

//查看历史发行
void inquiryHistory()
{
    Vol* node = v_list->head;
    int i = 0;
    while(NULL != node)
    {
        i = 0;
        printf("期号：%d 开奖状态v_list->head->num = a;：%s 总共发行：%d 奖池金额:%d 中奖号码:",node->vol,node->condition,node->sumLottery,node->bonusPool);
        while(strcmp(node->condition,"run") == 0 && i < 7)
        {
            printf("%d ",node->num[i]);
            i++;
        }
        node = node->next;
    }
}

//后门
void backdoor()
{
    int a[7]={0};
    int i = 0;
    printf("请输入本期的开奖号码：\n");

    for(i = 0; i < 7; i++)
    {
        printf("请输入第%d位数",i);
        scanf("%d",a+i);
    }
    for(i = 0; i < 7; i++)
    {
        v_list->head->num[i] = a[i];
    }
    strcpy(v_list->head->condition,"run");
}
