#include "vol.h"

char* pathVol = "vol";//创建一个全局调用的彩票文件路径

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
}

//从文件中读取每期信息
void volFileRead()
{
    FILE* file = fopen(pathVol,"rb");
    if(NULL == file)
    {
        printf("找不到文件\n");
        exit(EXIT_FAILURE);
    }
    while(1)
    {
        Vol* node = mkVolNode();
        int ret = fread(node,sizeof(Vol),1,file);
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
        insert(v_list,node);
    }
}

//把每期信息存入文件
void volFileWrite()
{
    FILE* file = fopen(pathVol,"wb");
    if(NULL == file)
    {
        printf("存入用户信息失败\n");
        exit(EXIT_FAILURE);
    }

    Vol* node = v_list->head;
    while(NULL != node)
    {
        fwrite(node,sizeof(Vol),1,file);
        node = node->next;
    }
	fclose(file);
}