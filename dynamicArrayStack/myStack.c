#include "myStack.h"

#define DEFAULT_SIZE 10
/* 栈的初始化 */
int stackInit(stack *pStack)
{
    return dynamicArrayInit(pStack, DEFAULT_SIZE);
}

/* 压栈 */
int stackPush(stack *pStack, ELEMENTTYPE val)
{
    /* 调用动态数组的尾插 */
    return dynamicArrayInsertData(pStack, val);
}

/* 查看栈顶元素 */
int stackTop(stack *pStack, ELEMENTTYPE *pVal)
{
    /* 获取指定位置的的元素（数组最后的位置 */
    return dynamicArrayGetAppointPosVal(pStack, pStack->len - 1, pVal);//pStack->len 有段错误
    }

/* 出栈 */
int stackPop(stack *pStack)
{
    return dynamicArrayDeleteData(pStack);
}

/* 栈是否为空 */
int stackIsEmpty(stack *pStack)
{
    int size = 0;
    dynamicArrayGetSize(pStack, &size);

    return size == 0 ? 1: 0;
}

/* 获取栈的大小 */
int stackGetSize(stack *pStack, int *pSize)
{
    #if 1
    return dynamicArrayGetSize(pStack, pSize);
    #else
    dynamicArrayGetSize(pStack, pSize);
    if(pSize)
    {
        return *pSize;
    }
    #endif
}

/* 栈的销毁 */
int stackDestroy(stack *pStack)
{
    return dynamicArrayDestroy(pStack);
}