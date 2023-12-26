#ifndef _DOUBLECIECLELISTLINK_H_
#define _DOUBLECLRCLELISTLINK_H_

#define ELEMENTTYPE void*

/* 链表节点取别名 */
typedef struct doubleLinkNode
{
    ELEMENTTYPE data;                //数据域：存储节点数据信息
    struct doubleLinkNode *prev;    //指向前一节点
    struct doubleLinkNode *next;    //指针域：存储直接后继节点的地址 （指向下一个结点的指针  指针的类型为什么是节点？)
}doubleLinkNode;

typedef struct doubleLinkList
{
    doubleLinkNode * head;            //链表的虚拟头节点：1、数据域无意义 2、只使用指针域
    doubleLinkNode * tail;            //为什么尾指针不需要分配空间？
    int len;                    //链表的长度
}doubleLinkList;

/* 链表初始化 */
int doubleLinkListInit(doubleLinkList **pList);

/* 链表头插 */
int doubleLinkListHeadInsert(doubleLinkList *pList, ELEMENTTYPE val);

/* 链表尾插 */
int doubleLinkListTailInsert(doubleLinkList *pList, ELEMENTTYPE val);

/* 链表指定位置插入 */
int doubleLinkListAppointPosInsert(doubleLinkList *pList, int pos, ELEMENTTYPE val);

/* 链表头删 */
int doubleLinkListHeadDel(doubleLinkList *pList);

/* 链表尾删 */
int doubleLinkListTailDel(doubleLinkList *pList);

/* 链表指定位置删除 */
int doubleLinkListDelAppointPos(doubleLinkList *pList, int pos);

/* 链表删除指定数据 */
int doubleLinkListDelAppointData(doubleLinkList *pList, ELEMENTTYPE val, int(*compareFunc)(ELEMENTTYPE,ELEMENTTYPE));

/* 获取链表的长度 */
int doubleLinkListGetLength(doubleLinkList *pList, int *pSize);

/* 链表的销毁 */
int doubleLinkListDestory(doubleLinkList *pList);

/* 链表遍历接口 */
int doubleLinkListForeach(doubleLinkList *pList, int(*printFunc)(ELEMENTTYPE));

/* 链表逆序遍历接口 */
int doubleLinkListReverseForeach(doubleLinkList *pList, int(*printFunc)(ELEMENTTYPE));

/* 获取链表头位置的值 */
int doubleLinkListGetHeadVal(doubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表尾位置的值 */
int doubleLinkListGetTailVal(doubleLinkList *pList, ELEMENTTYPE *pVal);

/* 获取链表指定的值 */
int doubleLinkListGetAppointPosVal(doubleLinkList *pList, int pos, ELEMENTTYPE *pVal);
#endif