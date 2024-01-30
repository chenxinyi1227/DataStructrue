#ifndef _SET_H_
#define _SET_H_

#include <myAVLTree.h>

typedef AVLTree set;
/* 集合初始化 */
set setInit(set **setTree, int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*visit)(ELEMENTTYPE val));
/* 集合添加元素 */
set setInsert(set *setTree, ELEMENTTYPE val);
/* 集合删除指定元素*/
set setDelAppointVal(set *setTree, ELEMENTTYPE val);
/* 集合更改指定元素*/
set setModifyAppointVal(set *setTree, ELEMENTTYPE val);
/* 集合包含判断：是否包含某个特定元素 */
int setIsContainAppointVal(set *setTree, ELEMENTTYPE val);
/* 获取集合长度 ：获取集合中元素的数量*/
set setGetSize(set *setTree, int *pSize);
/* 集合遍历 */
set setTraverse(set *setTree);
/* 删除集合 */
set setDestory(set *setTree);

#endif