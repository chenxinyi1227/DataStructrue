#ifndef _LISTLINK_H_
#define _LISTLINK_H_

#define ELEMENTYPE int

/* 链表节点取别名 */
typedef struct LinkNode
{
    ELEMENTYPE data;
    struct LinkNode *next;      //指向下一个结点的指针 / 指针的类型为什么是节点？
}LinkNode;

typedef struct LinkList
{
    LinkNode * head;            //链表的虚拟头节点：1、数据域无意义 2、只使用指针域
    int len;                    //链表的长度
};

/* 链表初始化 */
int LinkListInit();

/* 链表头插 */
int LinkListHeadInsert();

/* 链表尾插 */
int LinkListTailInsert();

/* 链表指定位置插入 */
int LinkListAppointPosInsert();

/* 链表头删 */
int LinkListHeadDel();

/* 链表尾删 */
int LinkListTailDel();

/* 链表指定位置删除 */
int LinkListDelAppointPos();

/* 链表删除指定数据 */
int LinkListDelAppointData();

/* 获取链表的长度 */
int LinkListGetLength();

/* 链表的销毁 */
int LinkListDestory();


#endif