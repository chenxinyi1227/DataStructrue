#include <myLinkList.h>
#ifndef _DOUBLELISTLINK_QUEUE_H_
#define _DOUBLELISTLINK_QUEUE_H_

typedef doubleLinkList queue;

/* 队列初始化 */
int queueInit(queue **pQueue);

/* 队列入队 */
int queuePush(queue *pQueue, ELEMENTTYPE val);

/* 队头元素 */
int queueTop(queue *pQueue, ELEMENTTYPE *val);

/* 队尾元素 */
int queueRear(queue *pQueue, ELEMENTTYPE *val);

/* 队列出列 */
int queuePop(queue *pQueue);

/* 队列大小 */
int queueGetSize(queue *pQueue, int *pSize);

/* 队列是否为空 */
int queueIsEmpty(queue *pQueue);

/* 队列销毁 */
int queueDestroy(queue *pQueue);
#endif