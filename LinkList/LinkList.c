#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
        ON_SUCCESS,
        NULL_PTR,
        MALLOC_ERROR,
        INVALID_ACCESS,    //非法访问
};

/* 链表初始化 */
int LinkListInit(LinkList **pList)
{
    int ret = 0;
    LinkList *list = (LinkList *)(sizeof(LinkList) * 1);
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
    memset(list->head, 0, sizeof(LinkNode *));  //清空脏数据
    list->head->data = 0;
    list->head->next = NULL;
    list->tail->next = list->head;  //尾指针初始化时,尾指针 = 头指针

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
    return LinkListDelAppointPos(pList, 1);
}

/* 链表尾删 */
int LinkListTailDel(LinkList *pList)
{
    return LinkListDelAppointPos(pList, pList->len);
}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos)
{
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
    LinkNode * travelNode = pList->head;
#else
LinkNode * travelNode = pList->head->next;
#endif
    while(--pos)
    {
        travelNode = travelNode->next;//向后移动位置
        // pos--;
    }
    /* 跳出循环的是哪一个节点 */
    LinkNode * needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    /* 释放内存 */
    if(needDelNode != NULL)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    pList->len--;                   //链表长度减一
    return 0;
}

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList *pList, ELEMENTYPE val)
{
   
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
    return ret;
}

/* 链表的销毁 */
int LinkListDestory(LinkList *pList)
{

}

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList)
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
    LinkNode * travelNode = pList->head->next;  //travelNOde 指向链表第一个元素 
    while(travelNode != NULL)
    {
        printf("travelNode->data:%d\n", travelNode->data);
        travelNode = travelNode->next;
    }
#endif    
  
    return ret;
}