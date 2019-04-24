#include "vol.h"

char* pathVol = "vol.txt";//创建一个全局调用的彩票文件路径

//创建彩票链表节点
Vol* mkVolNode()
{
    Vol* node = (Vol*)malloc(sizeof(Vol));
    if(NULL == node)
    {
        exit(EXIT_FAILURE);
    }

    memset(node,0,sizeof(Vol));
    return node;
}

//创建彩票链表
vList* mkVolList()
{
    vList* list = (vList*)malloc(sizeof(vList));
    if(NULL == list)
    {
        exit(EXIT_FAILURE);
    }

    memset(list,0,sizeof(vList));
    return list;
}

//将节点插入彩票链表
void volInsert(vList* list,Vol* node)
{
    if(NULL == list || NULL == node)
    {
        exit(EXIT_FAILURE);
    }

    node->next = list->head;
    list->head = node;
    list->len++;
}

//从文件中读取每期信息
void volFileRead()
{
    FILE* file = fopen(pathVol,"r");
    if(NULL == file)
    {
        printf("找不到文件\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        Vol* node = mkVolNode();
        int ret1 = fscanf(file,"%d%d%s%d%d",&node->vol,&node->price,node->condition,&node->sumLottery,&node->bonusPool);
        int ret2 = 0;
        int i = 0;
        
        if(EOF == ret1 )
        {
            free(node);
            node = NULL;
            break;
        }
        for(i = 0;i < 7;i++)
        {
            ret2 = fscanf(file,"%d",&node->num[i]);
            if(EOF == ret2)
            {
                break;
            }
        }
        node->next = NULL;
        volInsert(v_list,node);
    }
}

//把每期信息存入文件
void volFileWrite()
{
    FILE* file = fopen(pathVol,"w");
    if(NULL == file)
    {
        printf("存入用户信息失败\n");
        exit(EXIT_FAILURE);
    }

    Vol* node = v_list->head;
    while(NULL != node)
    {
        int i = 0;
        fprintf(file,"%d %d %s %d %d",node->vol,node->price,node->condition,node->sumLottery,node->bonusPool);
        for(i = 0;i < 7;i++)
        {
            fprintf(file," %d",node->num[i]);
        }
        fprintf(file,"\n");
        node = node->next;
    }
	fclose(file);
}