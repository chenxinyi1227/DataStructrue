#include <myStack.h>
#include <stdio.h>
/* 怎么解决套壳问题 */
#define BUFFER_SIZE 5
int main()
{
    stack mystack;
    stackInit(&mystack);
    int buffer[BUFFER_SIZE] = {1, 2, 3, 4, 5};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        stackPush(&mystack, &buffer[idx]);
    }
    int size = 0;
    stackGetSize(&mystack, &size);
    printf("size:%d\n", size);

    printf("栈的出栈\n");
    int *val = NULL;
    while(!stackIsEmpty(&mystack))//栈不为空
    {
        /* todo... */
        stackTop(&mystack, (void**)&val);//（void **）强转  (void *)也可以实现
        printf("val:%d\n", *val);
        stackPop(&mystack);
    }
    /* 栈的销毁 */
    printf("栈的销毁\n");
    stackDestroy(&mystack);
    size = 0;
    stackGetSize(&mystack, &size);
    printf("size:%d\n", size);

    return 0;
}