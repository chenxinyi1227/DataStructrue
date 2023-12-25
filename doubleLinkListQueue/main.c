#include "doubleLinkListQueue.h"
#include "doubleLinkList.h"
#include <stdio.h>
#define BUFFER_ZIZE 5
int main()
{
    doubleLinkListQueue *queue = NULL;
    doubleLinkListQueueInit(&queue);

    int buffer[BUFFER_ZIZE] = {1,2, 3, 4, 5};
    for(int idx = 0; idx < BUFFER_ZIZE; idx++)
    {
        doubleLinkListQueuePush(queue, (void*)&buffer[idx]);
    }
    int size = 0;
    doubleLinkListQueueGetSize(queue, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while(!doubleLinkListQueueIsEmpty(queue))
    {
        doubleLinkListQueueTop(queue, (void **)&val);
        printf("val:%d\n", *val);
        doubleLinkListQueuePop(queue);
    } 
    return 0;
}