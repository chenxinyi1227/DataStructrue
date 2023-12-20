#ifndef _DYARRAY_H_
#define _DYARRAY_H_

#define ELEMENTYPE void *

typedef struct dyArray
{
    ELEMENTYPE *space;
    int len;
    int capacity;
}dyArray;

/* 1初始化 */
int dyInit(dyArray *pArray, int capacity);
/* 2插入 */
int dyInsert(dyArray *pArray, ELEMENTYPE val);
/* 3指定位置插入 */
int dyInsertByPos(dyArray *pArray, int pos, ELEMENTYPE val);
/* 4更改指定位置数据 */
int ModifyArrayByPos(dyArray *pArray, int pos, ELEMENTYPE val);
/*5 删除数据 */
int dyDeleteElementype(dyArray *pArray);
/* 6删除指定位置数据 */
int dyDeleteByPos(dyArray *pArray, int pos);
/* 7删除指定元素 */
int dyDeleteByElementype(dyArray *pArray, ELEMENTYPE val);
/* 8销毁 */
int dyDestory(dyArray *pArray);
/* 9获取大小 */
int dyGetSize(dyArray *pArray, int *pSize);
/* 10获取容量 */
int dyGetCapacity(dyArray *pArray, int *pCapacity);
/* 11指定位置的元素数据*/ 
int dyGetElementypeByPos(dyArray *pArray, int pos, ELEMENTYPE *val);

#endif