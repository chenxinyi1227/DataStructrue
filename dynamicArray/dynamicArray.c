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
};
//
#define DEFAULT_SIZE 10

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
