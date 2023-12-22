#include "doubleLinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,    //非法访问
};

/* 静态函数只给本源文件（.c)的函数使用 */
/* 静态前置声明 */
static int DoubleLinkListAccordingApppointValGetPos(DoubleLinkList *pList, ELEMENTTYPE val, int *pPos, int(*compareFunc)(ELEMENTTYPE,ELEMENTTYPE));
/* 新建新节点封装成函数 */
static DoubleLinkNode *createDoubleLinkList(ELEMENTTYPE val);

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList **pList)
{
    int ret = 0;
    DoubleLinkList *list = (DoubleLinkList *)malloc(sizeof(DoubleLinkList) * 1);
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(DoubleLinkList) * 1);      //清空脏数据

    list->head = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode) * 1); //为head分配空间
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(DoubleLinkNode *));  //清空脏数据
    list->head->data = 0;
    list->head->next = NULL;
    list->tail = list->head;  //尾指针初始化时,尾指针 = 头指针
    list->head->next->prev = NULL;//?
    list->len = 0;                  //链表的长度为0

    *pList = list;                  // 二级指针 
    return ret;
}

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val)
{
    return DoubleLinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val)
{
    /* todo... */
    return DoubleLinkListAppointPosInsert(pList, pList->len, val);
}

/* 新建新节点封装成函数 */
static DoubleLinkNode *createDoubleLinkList(ELEMENTTYPE val)
{
    /* 封装节点 */
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode *) * 1);
    if(newNode == NULL)
    {
        return NULL;
    }
    memset(newNode, 0 , sizeof(DoubleLinkNode *) * 1);//清除脏数据
#if 1
    newNode->data = 0;
    newNode->next = NULL;
    newNode->prev = NULL;
#endif
    newNode->data = val;                        //赋值
    return newNode;//返回新阶段
}

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    /* 新建新节点封装成函数 */
    DoubleLinkNode * newNode = createDoubleLinkList(val);
#if 0
    /* 封装结点 */
    DoubleLinkNode * newNode = (DoubleLinkNode *)malloc(sizeof(DoubleLinkNode *) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0 , sizeof(DoubleLinkNode *) * 1);//清除脏数据
#if 1
    newNode->data = 0;
    newNode->next = NULL;
#endif
    newNode->data = val;                        //赋值
#endif

#if 1
    DoubleLinkNode * travelNode = pList->head;        //从虚拟头结点开始遍历
#else
    DoubleLinkNode * travelNode = pList->head->next;
#endif
    int flag = 0;
    if(pos == pList->len)                       //这种情况下需要更改尾指针
    {
        travelNode = pList->tail;               // 修改节点指向
#if 0
        // newNode->next == travelNode->next;  
        // travelNode->next = newNode;
#endif
        flag = 1;
    }
    else
    {
        while(pos)
        {
            travelNode = travelNode->next;
            pos--;
        }
    }
    newNode->next = travelNode->next;  //1
    newNode->prev = travelNode;        //2
    travelNode->next->prev = newNode;  //3
    travelNode = newNode;              //4
    if(flag)
    {
        pList->tail = newNode;  //尾指针更新为位置
    }

    (pList->len)++;             //更新链表长度
    return ret;
}

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList *pList)
{
    return DoubleLinkListDelAppointPos(pList, 1);
}

/* 链表尾删 */
int DoubleLinkListTailDel(DoubleLinkList *pList)
{
    return DoubleLinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    /* todo...          */
    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

#if 1
    DoubleLinkNode * travelNode = pList->head;
#else
DoubleLinkNode * travelNode = pList->head->next;
#endif
    int flag = 0;
    /* 需要修改尾指针 */
    if(pos == pList->len)
    {
        flag = 1;
    }

    DoubleLinkNode * needDelNode = NULL;
    while(--pos)
    {
        travelNode = travelNode->next;//向后移动位置
    }
    /* 跳出循环的是哪一个节点 */
    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    if(flag)
    {
        pList->tail = travelNode;    //调整尾指针
    }

    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    pList->len--;      //链表长度减一
    return ret;
}

/* 根据指定的元素得到在链表中所在的位置 */
static int DoubleLinkListAccordingApppointValGetPos(DoubleLinkList *pList, ELEMENTTYPE val, int *pPos, int(*compareFunc)(ELEMENTTYPE,ELEMENTTYPE))
{
    /* 静态函数只给本源文件的函数使用，不需要判断合法性 */
    int ret;
#if 0
    DoubleLinkNode * travelNode = pList->head;
#else
    int pos = 1;
    DoubleLinkNode *travelNode = pList->head->next;
#endif
    int cmp = 0;
    while(travelNode != NULL)
    {
        #if 0
        if(travelNode->data == val)
        {
            *pPos = pos;//解引用
            return pos;
        }
        #else
       cmp = compareFunc(val, travelNode->data);
       if(cmp == 0)
       {
            *pPos = pos;//解引用
            return pos;
       }
       #endif
        travelNode = travelNode->next;
        pos++;
       
    }
    /* 解除解引用 */
    *pPos = NOT_FIND;
    return NOT_FIND;
}

/* 链表删除指定数据 */ 
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE,ELEMENTTYPE))//??
{
    int ret = 0;
    int pos = 0;        //元素在链表中的位置
    int size = 0;       //链表的长度
    while(DoubleLinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        /* 根据指定的元素得到在链表中所在的位置 */    
        DoubleLinkListAccordingApppointValGetPos(pList, val, &pos, compareFunc);
        DoubleLinkListDelAppointPos(pList, pos);
    }
    return ret;
}

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }

    if(pSize)
    {
        *pSize = pList->len;
    }
    return pList->len; //返回链表长度
}

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList *pList)
{
    int ret = 0;
    /* 头删释放链表 */
    int size = 0;
    while(DoubleLinkListGetLength(pList, &size))
    {
        DoubleLinkListHeadDel(pList);
    }

    if(pList->head != NULL)
    {
        free(pList->head);
        /* 指针置为NULL */
        pList->head = NULL;
        pList->tail = NULL;
    }
    return ret;
}

/* 链表遍历接口 */
int DoubleLinkListForeach(DoubleLinkList *pList, int(*printFunc)(ELEMENTTYPE))
{

    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    DoubleLinkNode * travelNode = pList->head;        // travelNode指向虚拟头节点 
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    DoubleLinkNode * travelNode = pList->head->next;  //travelNde 指向链表第一个元素 
    while(travelNode != NULL)
    {
        #if 0
        printf("travelNode->data:%d\n", travelNode->data);//travelNode->data放的是地址
        #else
        /* 包装器（C++) 钩子函数-回调函数（C) */
        printFunc(travelNode->data);
        #endif
        travelNode = travelNode->next;
    }
#endif    
    return ret;
}