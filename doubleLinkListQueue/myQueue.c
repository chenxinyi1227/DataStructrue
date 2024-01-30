#include "myQueue.h"

/* 队列初始化 */
int queueInit(queue **pQueue)
{
    return doubleLinkListInit(pQueue);
}

/* 队列入队 */
int queuePush(queue *pQueue, ELEMENTTYPE val)
{
    return doubleLinkListTailInsert(pQueue, val);
}

/* 队头元素 */
int queueTop(queue *pQueue, ELEMENTTYPE *val)
{
    return doubleLinkListGetHeadVal(pQueue, val);
}

/* 队尾元素 */
int queueRear(queue *pQueue, ELEMENTTYPE *val)
{
    return doubleLinkListGetTailVal(pQueue, val);
}

/* 队列出列 */
int queuePop(queue *pQueue)
{
    return doubleLinkListHeadDel(pQueue);
}

/* 队列大小 */
int queueGetSize(queue *pQueue, int *pSize)
{
    return doubleLinkListGetLength(pQueue, pSize);
}

/* 队列是否为空 */
int queueIsEmpty(queue *pQueue)
{
    int size = 0;
    doubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1: 0;
}

/* 队列销毁 */
int queueDestroy(queue *pQueue)
{
    return doubleLinkListDestroy(pQueue);
}