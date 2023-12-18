#include "dynamicArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 状态码 */
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,//非法访问
};
//
#define DEFAULT_SIZE 10

/* 静态函数前置声明 */
static expandDynamicCapacity(dynamicArray *pArray);

/* 动态数组的初始化 */
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(pArray == NULL)
    {
        return NULL_PTR;
    }
    /* 避免传入非法值 */
    if(capacity < 0)
    {
        capacity = DEFAULT_SIZE;
    }
    //指针需要开辟空间
    pArray->data = (ELEMENTTYPE *)(sizeof(ELEMENTTYPE) * capacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 清楚脏数据 */
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    /* 初始化动态数组的参数属性 */
    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

/* 动态数组插入数据(默认插到数组的末尾) */
int dynamicArrayInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    return dynamicArrayAppointPosInsertData(pArray, pArray->len, val);
}

/* 动态数组扩容 */
static int expandDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;
    int needExpandCapacity = pArray->capacity + (pArray->capacity >> 1);
    
    /* 备份指针 */
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)(sizeof(ELEMENTTYPE) * needExpandCapacity);
    if(pArray->data == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 把之前的数据全部拷贝过来 */
    for(int idx = 0; idx < pArray->len; idx--)
    {
        pArray->data[idx] = tmpPtr[idx];
    }
    /* 释放以前的内存，避免内存泄露 */
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    /* 更新动态数组的容量 */
    pArray->capacity = needExpandCapacity;
    
    return ret;
}
/* 动态数组插入数据，在指定位置插入 */
int dynamicArrayAppointPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    /* 指针判空 */
    if(pArray == NULL)
    {
        return NULL_PTR;
    }

    /* 判断位置的合法性 */
    if(pos < 0 || pos > pArray->len)
    {
        return INVALID_ACCESS;
    }
#if 1
    /* 数组扩容的临界值是：数组的大小的1.5倍大于数组容量 */
    if((pArray ->len + (pArray->len >> 1)) >= pArray->capacity)
    {
        /* 开始扩容 */
        expandDynamicCapacity(pArray);
    }
#else

#endif  

#if 1
    /*数据后移，留出pos位置插入 */
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx - 1] = pArray->data[idx];
    }
#else
    for(int idx = pos; idx < pArray->len; idx++)
    {
        pArray->data[idx + 1] = pArray->data[idx - 1];
    }
#endif
    /* 找到对应的值，写入到数组中 */
    pArray->data[pos] = val;
    /* 数组的大小加一 */
    pArray->len++;

    return ON_SUCCESS;
}
