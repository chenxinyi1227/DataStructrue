#ifndef _LISTLINK_H_
#define _LISTLINK_H_

#define ELEMENTYPE void*

/* 链表节点取别名 */
typedef struct LinkNode
{
    ELEMENTYPE data;            //数据域：存储节点数据信息
    struct LinkNode *next;      //指针域：存储直接后继节点的地址 （指向下一个结点的指针  指针的类型为什么是节点？)
}LinkNode;

typedef struct LinkList
{
    LinkNode * head;            //链表的虚拟头节点：1、数据域无意义 2、只使用指针域
    LinkNode * tail;            //为什么尾指针不需要分配空间？
    int len;                    //链表的长度
}LinkList;

/* 链表初始化 */
int LinkListInit(LinkList **pList);

/* 链表头插 */
int LinkListHeadInsert(LinkList *pList, ELEMENTYPE val);

/* 链表尾插 */
int LinkListTailInsert(LinkList *pList, ELEMENTYPE val);

/* 链表指定位置插入 */
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTYPE val);

/* 链表头删 */
int LinkListHeadDel(LinkList *pList);

/* 链表尾删 */
int LinkListTailDel(LinkList *pList);

/* 链表指定位置删除 */
int LinkListDelAppointPos(LinkList *pList, int pos);

/* 链表删除指定数据 */
int LinkListDelAppointData(LinkList *pList, ELEMENTYPE val);

/* 获取链表的长度 */
int LinkListGetLength(LinkList *pList, int *pSize);

/* 链表的销毁 */
int LinkListDestory(LinkList *pList);

/* 链表遍历接口 */
int LinkListForeach(LinkList *pList, int(*printFunc)(ELEMENTYPE));
#endif