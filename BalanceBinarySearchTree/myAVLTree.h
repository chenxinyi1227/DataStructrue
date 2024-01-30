#ifndef _BALANCE_BINARY_SEARCH_TREE__H
#define _BALANCE_BINARY_SEARCH_TREE__H
#include <myQueue.h>
// #define ELEMENTTYPE int

typedef struct AVLTreeNode
{
    ELEMENTTYPE data;
    int height;//维护一个节点高度
    struct  AVLTreeNode * left;//左子树
    struct  AVLTreeNode * right;//右子树
    #if 1
    struct AVLTreeNode * parent;//父结点
    #endif
}AVLTreeNode;

/* 二叉搜索树 */
typedef struct AVLTree
{
    AVLTreeNode * root;//根结点
    int size; //树的结点个数
    int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);//钩子函数比较器,放到结构体内部
    int (*visit)(ELEMENTTYPE val);/* 钩子函数 包装器实现自定义打印函数接口 */
#if 0
    doubleLinkListQueue *pQueue;
#endif
}AVLTree;

/* 二叉搜索树的初始化 */
int AVLTreeInit(AVLTree **pAvltree, int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*visit)(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int AVLTreeInsert(AVLTree *pAvltree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定元素 */
int AVLTreeIsContainAppointVal(AVLTree *pAvltree, ELEMENTTYPE val);

/* 二叉树先序遍历 */
int AVLTreePreOrderTraverse(AVLTree *pAvltree);

/* 二叉树中序遍历 */
int AVLTreeMidOrderTraverse(AVLTree *pAvltree);

/* 二叉树后序遍历 */
int AVLTreePosOrderTraverse(AVLTree *pAvltree);

/* 二叉树层序遍历 */
int AVLTreeLevelOrderTraverse(AVLTree *pAvltree);

/* 获取二叉搜索树的节点个数 */
int AVLTreeGetNodeSize(AVLTree *pAvltree, int *pSize);

/* 获取二叉树的高度:需要记录每一层的结点树->每一层的节点数技术完成，就是树的高度加1 */
int AVLTreeGetHeight(AVLTree *pAvltree, int *pHeight);

/* 二叉树的删除 */
int AVLTreeDelete(AVLTree *pAvltree, ELEMENTTYPE val);

/* 二叉树的销毁 */
int AVLTreeDestroy(AVLTree *pAvltree);
#endif