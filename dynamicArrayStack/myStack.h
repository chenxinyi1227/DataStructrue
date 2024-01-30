#include <myArray.h>
#ifndef _DYNAMIC_ARRAY_STACK_H_
#define _DYNAMIC_ARRAY_STACK_H_

typedef dynamicArray stack;

/* 栈的初始化 */
int stackInit(stack *pStack);

/* 压栈 */
int stackPush(stack *pStack, ELEMENTTYPE val);

/* 查看栈顶元素 */
int stackTop(stack *pStack, ELEMENTTYPE *pVal);

/* 出栈 */
int stackPop(stack *pStack);

/* 栈是否为空 */
int stackIsEmpty(stack *pStack);

/* 获取栈的大小 */
int stackGetSize(stack *pStack, int *pSize);

/* 栈的销毁 */
int stackDestroy(stack *pStack);

#endif