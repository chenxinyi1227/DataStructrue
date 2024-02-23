#include <myQueue.h>
#include <stdio.h>

#define BUFFER_ZIZE 5
int main()
{
    doubleLinkListQueue *myQueue = NULL;
    doubleLinkListQueueInit(&myQueue);
    
    int buffer[BUFFER_ZIZE] = {1,2, 3, 4, 5};
    for(int idx = 0; idx < BUFFER_ZIZE; idx++)
    {
        doubleLinkListQueuePush(myQueue, (void*)&buffer[idx]);
    }
    int size = 0;
    doubleLinkListQueueGetSize(myQueue, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while(!doubleLinkListQueueIsEmpty(myQueue))
    {
        doubleLinkListQueueTop(myQueue, (void **)&val);
        printf("val:%d\n", *val);
        doubleLinkListQueuePop(myQueue);
    } 
    return 0;
}