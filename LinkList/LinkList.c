#include "LinkList.h"
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
static int LinkListAccordingApppointValGetPos(LinkList *pList, ELEMENTYPE val, int *pPos, int(*compareFunc)(ELEMENTYPE,ELEMENTYPE));

/* 链表初始化 */
int LinkListInit(LinkList **pList)
{
    int ret = 0;
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);
    if(list == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list, 0, sizeof(LinkList) * 1);      //清空脏数据

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1); //为head分配空间
    if(list->head == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(list->head, 0, sizeof(LinkNode));  //清空脏数据
    list->head->data = 0;
    list->head->next = NULL;
    list->tail = list->head;  //尾指针初始化时,尾指针 = 头指针

    list->len = 0;                  //链表的长度为0

    *pList = list;                  // 二级指针 
    return ret;
}

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMENTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMENTYPE val)
{
    /* todo... */
    return LinkListAppointPosInsert(pList, pList->len, val);
}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTYPE val)
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
    /* 封装结点 */
    LinkNode * newNode = (LinkNode *)malloc(sizeof(LinkNode *) * 1);
    if(newNode == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0 , sizeof(LinkNode *) * 1);//清除脏数据
#if 1
    newNode->data = 0;
    newNode->next = NULL;
#endif
    newNode->data = val;                        //赋值
#if 1
    LinkNode * travelNode = pList->head;        //从虚拟头结点开始遍历
#else
    LinkNode * travelNode = pList->head->next;
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
    newNode->next = travelNode->next;  
    travelNode->next = newNode;
    if(flag)
    {
        pList->tail = newNode;  //尾指针更新为位置
    }

    (pList->len)++;             //更新链表长度
    return ret;
}

/* 链表头删 */
int LinkListHeadDel(LinkList *pList)
{
    return LinkListDelAppointPos(pList, 0);
}

/* 链表尾删 */
int LinkListTailDel(LinkList *pList)
{
    return LinkListDelAppointPos(pList, pList->len - 1);
}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos)
{
    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
    /* todo...          */
    if(pos < 0 || pos >= pList->len)//pos = 0 空指针进不了以下循环
    {
        return INVALID_ACCESS;
    }

#if 1
    LinkNode * travelNode = pList->head;
#else
LinkNode * travelNode = pList->head->next;
#endif
    int flag = 0;
    /* 需要修改尾指针 */
    if(pos == pList->len)
    {
        flag = 1;
    }

    LinkNode * needDelNode = NULL;
    while(pos--)
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
static int LinkListAccordingApppointValGetPos(LinkList *pList, ELEMENTYPE val, int *pPos, int(*compareFunc)(ELEMENTYPE,ELEMENTYPE))
{
    /* 静态函数只给本源文件的函数使用，不需要判断合法性 */
    int ret;
#if 0
    LinkNode * travelNode = pList->head;
#else
    int pos = 0;
    LinkNode *travelNode = pList->head->next;
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
int LinkListDelAppointData(LinkList *pList, ELEMENTYPE val, int (*compareFunc)(ELEMENTYPE,ELEMENTYPE))
{
    int ret = 0;
    int pos = 0;        //元素在链表中的位置
    int size = 0;       //链表的长度
    // while(LinkListGetLength(pList, &size) && pos != NOT_FIND)
    /* 根据指定的元素得到在链表中所在的位置 */    
    while(LinkListAccordingApppointValGetPos(pList, val, &pos, compareFunc) != NOT_FIND)
    {
        /* 根据指定的元素得到在链表中所在的位置 */    
        // LinkListAccordingApppointValGetPos(pList, val, &pos, compareFunc);
        LinkListDelAppointPos(pList, pos);
    }
    return ret;
}

/* 获取链表的长度 */
int LinkListGetLength(LinkList *pList, int *pSize)
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
int LinkListDestory(LinkList *pList)
{
    int ret = 0;
    /* 头删释放链表 */
    int size = 0;
    while(LinkListGetLength(pList, &size))
    {
        LinkListHeadDel(pList);
    }

    if(pList->head != NULL)
    {
        free(pList->head);
        /* 指针置为NULL */
        pList->head = NULL;
        pList->tail = NULL;
    }

    /* 释放链表 */
    if(pList != NULL)
    {
        free(pList);
        pList = NULL;
    }
    return ret;
}

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList, int(*printFunc)(ELEMENTYPE))
{

    int ret = 0;
    if(pList == NULL)
    {
        return NULL_PTR;
    }
#if 0
    LinkNode * travelNode = pList->head;        // travelNode指向虚拟头节点 
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data:%d\n", travelNode->data);
    }
#else
    LinkNode * travelNode = pList->head->next;  //travelNde 指向链表第一个元素 
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