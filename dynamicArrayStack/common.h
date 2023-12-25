#ifndef _COMMON_H_
#define _COMMON_H_

#if 1
#define ELEMENTTYPE void * 
#else
typedef int ELEMENTTYPE;
#endif

typedef struct dynamicArray
{
    ELEMENTTYPE *data;  /* 数组的空间 | 动态数组指针 */
    int len;            /* 数组的大小 | 长度*/
    int capacity;       /* 数组的容量*/
}dynamicArray;
#endif