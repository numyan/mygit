#include <pthread.h>

#include "head.h"

//创建链表
struct StudentList* CreateStudentListHead();
//创建节点
struct StudentNode* CreateStudentNode();
//插入节点
void InsertNode(struct StudentList* list,struct StudentNode* node);
//打印链表
void DisplayList1(struct StudentList* list);
//打印链表
void DisplayList2(struct StudentList* list);
//子线程函数
void* ThreadFunc(void* pv);

static pthread_rwlock_t lock;

//创建节点结构体
struct StudentNode
{
    char cName[12];
    struct StudentNode* pstNext;
}; 

//创建链表结构体
struct StudentList
{
    int count;
    struct StudentNode* pstFrist;
};


//创建链表
struct StudentList* CreateStudentListHead()
{
    struct StudentList* pstHead = (struct StudentList*)malloc(sizeof(struct StudentList));

    if(NULL == pstHead)
    {
        printf("Malloc failed in %s at %d\n",__FILE__,__LINE__);
        return NULL;
    }
    memset(pstHead,0,sizeof(struct StudentList));

    return pstHead;
}

//创建节点
struct StudentNode* CreateStudentNode()
{
    struct StudentNode* pstNode = NULL;
    pstNode = (struct StudentNode*)malloc(sizeof(struct StudentNode));
    if(NULL == pstNode)
    {
        printf("Create node failed in %s at %d\n",__FILE__,__LINE__);
        return NULL;
    }
    memset(pstNode,0,sizeof(struct StudentNode));

    return pstNode;
}

//插入节点
void InsertNode(struct StudentList* list,struct StudentNode* node)
{
    if(NULL == list || NULL == node)
    {
        printf("Insert node failed in %s at %d\n",__FILE__,__LINE__);
        return;
    }
    node->pstNext = list->pstFrist;
    list->pstFrist = node;
    list->count++;
}

//打印链表
void DisplayList1(struct StudentList* list)
{
    if(NULL == list)
    {
        printf("Dispay list failed in %s at %d\n",__FILE__,__LINE__);
    }

    struct StudentNode* node = list->pstFrist;
    while(NULL != node)
    {
        printf("read from main %s\n",node->cName);
        node = node->pstNext;
    }

    return;
}

//打印链表
void DisplayList2(struct StudentList* list)
{
    if(NULL == list)
    {
        printf("Dispay list failed in %s at %d\n",__FILE__,__LINE__);
    }

    struct StudentNode* node = list->pstFrist;
    while(NULL != node)
    {
        printf("read from subside %s\n",node->cName);
        node = node->pstNext;
    }

    return;
}

int main(int argc,char* argv[])
{
    int ret = 0,i = 0;
    pthread_t tid;

    struct StudentList* list = CreateStudentListHead();
    
    pthread_rwlock_init(&lock,NULL);

    ret = pthread_create(&tid,NULL,ThreadFunc,NULL);
    if(ret != 0)
    {
        printf("pthread failed in %s at %d\n",__FILE__,__LINE__);
        pthread_rwlock_destroy(&lock);
        return 1;
    }

    for(i = 0;i < 3;i++)
    {
        sleep(1);
        pthread_rwlock_wrlock(&lock);//写锁
        struct StudentNode* node = CreateStudentNode();
        printf("Please input name from main：\n");
        scanf("%s",node->cName);
        getchar();
        InsertNode(list,node);
        pthread_rwlock_unlock(&lock);//释放锁
        
        pthread_rwlock_rdlock(&lock);//读锁
        DisplayList1(list);
        pthread_rwlock_unlock(&lock);//释放锁
    }

    pthread_join(tid,NULL);
    printf("After join\n");
    pthread_rwlock_destroy(&lock);
    return 0;
}

void* ThreadFunc(void* pv)
{
    struct StudentList* list = CreateStudentListHead();
    int i = 0;

    for(i = 0;i < 3;i++)
    {
        pthread_rwlock_rdlock(&lock);//读锁
        DisplayList2(list);
        pthread_rwlock_unlock(&lock);//释放锁

        sleep(1);
        pthread_rwlock_wrlock(&lock);//写锁
        struct StudentNode* node = CreateStudentNode();
        printf("Please input from sub：\n");
        scanf("%s",node->cName);
        getchar();
        InsertNode(list,node);
        pthread_rwlock_unlock(&lock);//释放锁
    }

    return NULL;
}