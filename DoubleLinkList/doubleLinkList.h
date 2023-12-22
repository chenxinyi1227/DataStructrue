#ifndef _DOUBLELISTLINK_H_
#define _DOUBLELISTLINK_H_

#define ELEMENTTYPE void*

/* 链表节点取别名 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;                //数据域：存储节点数据信息
    struct DoubleLinkNode *prev;    //指向前一节点
    struct DoubleLinkNode *next;    //指针域：存储直接后继节点的地址 （指向下一个结点的指针  指针的类型为什么是节点？)
}DoubleLinkNode;

typedef struct DoubleLinkList
{
    DoubleLinkNode * head;            //链表的虚拟头节点：1、数据域无意义 2、只使用指针域
    DoubleLinkNode * tail;            //为什么尾指针不需要分配空间？
    int len;                    //链表的长度
}DoubleLinkList;

/* 链表初始化 */
int DoubleLinkListInit(DoubleLinkList **pList);

/* 链表头插 */
int DoubleLinkListHeadInsert(DoubleLinkList *pList, ELEMENTTYPE val);

/* 链表尾插 */
int DoubleLinkListTailInsert(DoubleLinkList *pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int DoubleLinkListAppointPosInsert(DoubleLinkList *pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int DoubleLinkListHeadDel(DoubleLinkList *pList);

/* 链表尾删 */
int DoubleLinkListTailDel(DoubleLinkList *pList);

/* 链表指定位置删除 */
int DoubleLinkListDelAppointPos(DoubleLinkList *pList, int pos);

/* 链表删除指定数据 */
int DoubleLinkListDelAppointData(DoubleLinkList *pList, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE,ELEMENTTYPE));

/* 获取链表的长度 */
int DoubleLinkListGetLength(DoubleLinkList *pList, int *pSize);

/* 链表的销毁 */
int DoubleLinkListDestory(DoubleLinkList *pList);

/* 链表遍历接口 */
int DoubleLinkListForeach(DoubleLinkList *pList, int(*printFunc)(ELEMENTTYPE));
#endif