#include "dyArray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEAULIT_SIZE 10
#define ISNULL(pArray)          if(pArray == NULL)                return NULL_PTR
#define ISINVALID(pArray,pos)   if(pos < 0 || pos > pArray->len)  return INVALID_ACCESS
#define ISINVALID1(pArray,pos)  if(pos < 0 || pos >= pArray->len) return INVALID_ACCESS

enum STATUS__CODE
{
    NULL_PTR,
    ON_SUCCESS,
    MALLOC_ERROR,
    INVALID_ACCESS
};

static int expandCapacity(dyArray *pArray);
static int shrinkCapacity(dyArray *pArray);

int dyInit(dyArray *pArray, int capacity)
{
    ISNULL(pArray);

    if(capacity < 0)
    {
        capacity = DEAULIT_SIZE;
    }
    /* 指针需要开辟空间 */
    pArray->space = (ELEMENTYPE *)malloc(sizeof(ELEMENTYPE) * capacity);
    /* case1 */
    if(pArray->space == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(pArray->space, 0, sizeof(ELEMENTYPE) * capacity);

    pArray->capacity = capacity;
    pArray->len = 0;
    return ON_SUCCESS;
}

int dyInsert(dyArray *pArray, ELEMENTYPE val)
{
    return dyInsertByPos(pArray, pArray->len, val);//pArray->len是末尾位置
}
/* 扩容 */
static int expandCapacity(dyArray *pArray)
{
    int ret = 0;
    int newCapacity = pArray->capacity + (pArray->capacity >> 1);
    /* 备份指针 */
    ELEMENTYPE *tmpPtr = pArray->space;
    /* case2：原空间扩容 */
    pArray->space = (ELEMENTYPE *)malloc(sizeof(ELEMENTYPE) * newCapacity);
    if(pArray->space == NULL)
    {
        return MALLOC_ERROR;
    }

    /* 复制数据 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->space[idx] = tmpPtr[idx];
    }

    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }
    
    pArray->capacity = newCapacity;
    return ret;
}

int dyInsertByPos(dyArray *pArray, int pos, ELEMENTYPE val)
{
    ISNULL(pArray);
    ISINVALID(pArray, pos);

    /* 扩容 */
    if(pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        expandCapacity(pArray);
    }

    /* 数据后移 */
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->space[idx] = pArray->space[idx - 1];
    }

    pArray->space[pos] = val;
    pArray->len++;
    return ON_SUCCESS;
}

int ModifyArrayByPos(dyArray *pArray, int pos, ELEMENTYPE val)
{
    ISNULL(pArray);
    ISINVALID1(pArray, pos);
    pArray->space[pos] = val;
    return ON_SUCCESS;
}

int dyDeleteElementype(dyArray *pArray)
{
  dyDeleteByPos(pArray, pArray->len - 1);/* 取不到末尾 */
}

/* 缩容 */
static int shrinkCapacity(dyArray *pArray)
{
    int newCapacity = pArray->capacity -(pArray->capacity >> 1);

    ELEMENTYPE *tmpPtr = pArray->space;
    pArray->space = (ELEMENTYPE *)malloc(sizeof(ELEMENTYPE) * newCapacity);
    if(pArray->space == NULL)
    {
        return MALLOC_ERROR;
    }
    /* 拷贝数据 */
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->space[idx] = tmpPtr[idx];
    }
    if(tmpPtr != NULL)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    pArray->capacity = newCapacity;
    return ON_SUCCESS;
}

int dyDeleteByPos(dyArray *pArray, int pos)
{
    ISNULL(pArray);
    ISINVALID1(pArray,pos);
    /* 缩容 */
    if(pArray->len  < pArray->capacity >> 1)
    {
        shrinkCapacity(pArray);
    }
    /* 数据前移 */
    for(int idx = pos; idx < pArray->len; idx++)
    {
        pArray->space[idx] = pArray->space[idx + 1];
    }  
    pArray->len--;
    return ON_SUCCESS;
}

int dyDeleteByElementype(dyArray *pArray, ELEMENTYPE val)
{
   int pos = 0;
   for(int idx = 0; idx < pArray->len - 1; idx++)
   {
        if(pArray->space[idx] = val)
        {
            pos = idx;
        }
   }
   dyDeleteByPos(pArray, pos);
   return ON_SUCCESS;
}

int dyDestory(dyArray *pArray)
{
    ISNULL(pArray);
    if(pArray->space != NULL)
    {
        free(pArray->space);
        pArray->space = NULL;
    }
   return ON_SUCCESS;
}

int dyGetSize(dyArray *pArray, int *pSize)
{
    ISNULL(pArray);
    if(pSize != NULL)
    {
        *pSize = pArray->len;
    }
    return ON_SUCCESS;
}

int dyGetCapacity(dyArray *pArray, int *pCapacity)
{
    ISNULL(pArray);
    if(pCapacity != NULL)
    {
        *pCapacity = pArray->capacity;
    }
    return ON_SUCCESS;
}

int dyGetElementypeByPos(dyArray *pArray, int pos, ELEMENTYPE *val)
{
    ISNULL(pArray);
    ISINVALID1(pArray, pos);
    if(val)
    {
        *val = pArray->space[pos];
    }
    return ON_SUCCESS;
}
