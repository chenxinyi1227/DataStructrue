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
        INVALID_ACCESS,       //非法访问
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

    list->len = 0;                  //链表的长度为0

    *pList = list;                  // 二级指针 
    return ret;
}

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMENTYPE val)
{

}

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMENTYPE val)
{

}

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList**pList, int pos, ELEMENTYPE val)
{

}

/* 链表头删 */
int LinkListHeadDel(LinkList *pList)
{

}

/* 链表尾删 */
int LinkListTailDel(LinkList *pList)
{

}

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos)
{

}

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList *pList, ELEMENTYPE val)
{

}

/* 获取链表的长度 */
int LinkListGetLength(LinkList *pList, int *pSize)
{

}

/* 链表的销毁 */
int LinkListDestory(LinkList *pList)
{

}

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList)
{

}