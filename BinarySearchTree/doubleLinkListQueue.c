#include "doubleLinkListQueue.h"
#include "doubleLinkList.h"

/* 队列初始化 */
int doubleLinkListQueueInit(doubleLinkListQueue **pQueue)
{
    return doubleLinkListInit(pQueue);
}

/* 队列入队 */
int doubleLinkListQueuePush(doubleLinkListQueue *pQueue, ELEMENTTYPE *val)
{
    return doubleLinkListTailInsert(pQueue, val);
}

/* 队头元素 */
int doubleLinkListQueueTop(doubleLinkListQueue *pQueue, ELEMENTTYPE *val)
{
    return doubleLinkListGetHeadVal(pQueue, val);
}

/* 队尾元素 */
int doubleLinkListQueueRear(doubleLinkListQueue *pQueue, ELEMENTTYPE *val)
{
    return doubleLinkListGetTailVal(pQueue, val);
}

/* 队列出列 */
int doubleLinkListQueuePop(doubleLinkListQueue *pQueue)
{
    return doubleLinkListTailDel(pQueue);
}

/* 队列大小 */
int doubleLinkListQueueGetSize(doubleLinkListQueue *pQueue, int *pSize)
{
    return doubleLinkListGetLength(pQueue, pSize);
}

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty(doubleLinkListQueue *pQueue)
{
    int size = 0;
    doubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1: 0;
}

/* 队列销毁 */
int doubleLinkListQueueDestroy(doubleLinkListQueue *pQueue)
{
    return doubleLinkListDestory(pQueue);
}