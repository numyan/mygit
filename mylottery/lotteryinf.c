#include "lotteryinf.h"

char* pathLottery = "lottery";//创建一个全局调用的彩票文件路径

//创建彩票链表节点
Lottery* mkLotteryNode()
{
    Lottery* node = (Lottery*)malloc(sizeof(Lottery));
    if(NULL == node)
    {
        exit(EXIT_FAILURE);
    }

    memset(node,0,sizeof(Lottery));
    return node;
}

//创建彩票链表
lList* mkLotteryList()
{
    lList* list = (lList*)malloc(sizeof(lList));
    if(NULL == list)
    {
        exit(EXIT_FAILURE);
    }

    memset(list,0,sizeof(lList));
    return list;
}

//将节点插入彩票链表
void lotteryInsert(lList* list,Lottery* node)
{
    if(NULL == list || NULL == node)
    {
        exit(EXIT_FAILURE);
    }

    node->next = list->head;
    list->head = node;
    list->len++;
}

//从文件中读取彩票信息
void lotteryFileRead()
{
    FILE* file = fopen(pathLottery,"rb");
    if(NULL == file)
    {
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        Lottery* node = mkLotteryNode();
        int ret = fread(node,sizeof(Lottery),1,file);
        if(0 == ret)
        {
            free(node);
            node = NULL;
            if(feof(file))
            {
                fclose(file);
			    break;
            }
            else
            {
                fclose(file);
                printf("打开文件失败\n");
                exit(EXIT_FAILURE);
            }
        }
        node->next = NULL;
        lotteryInsert(l_list,node);
    }
}

//把彩票信息存入文件
void lotteryFileWrite()
{
    FILE* file = fopen(pathLottery,"wb");
    if(NULL == file)
    {
        printf("存入用户信息失败\n");
        exit(EXIT_FAILURE);
    }

    Lottery* node = l_list->head;
    while(NULL != node)
    {
        fwrite(node,sizeof(Lottery),1,file);
        node = node->next;
    }
	fclose(file);
}
// //
// void displayLottery(lList* l_list)
// {
//     if(NULL == l_list)
//     {
//         exit(EXIT_FAILURE);
//     }
//     Lottery* node = l_list->head;

//     if(NULL != node)
//     {
//         printf("",,,,);
//         node = node->next;
//     }
// }