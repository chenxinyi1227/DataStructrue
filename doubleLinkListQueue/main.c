#include <myQueue.h>
#include <stdio.h>

#define BUFFER_ZIZE 5
int main()
{
    queue *myQueue = NULL;
    queueInit(&myQueue);

    int buffer[BUFFER_ZIZE] = {1,2, 3, 4, 5};
    for(int idx = 0; idx < BUFFER_ZIZE; idx++)
    {
        queuePush(myQueue, (void*)&buffer[idx]);
    }
    int size = 0;
    queueGetSize(myQueue, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while(!queueIsEmpty(myQueue))
    {
        queueTop(myQueue, (void **)&val);
        printf("val:%d\n", *val);
        queuePop(myQueue);
    } 
    return 0;
}