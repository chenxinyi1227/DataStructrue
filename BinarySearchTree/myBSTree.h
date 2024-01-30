#ifndef _BINARY_SEARCH_TREE__H
#define _BINARY_SEARCH_TREE__H
#include <myQueue.h>
// #define ELEMENTTYPE int

typedef struct BSTreeNode
{
    ELEMENTTYPE data;
    struct  BSTreeNode * left;//左子树
    struct  BSTreeNode * right;//右子树
    #if 1
    struct BSTreeNode * parent;//父结点
    #endif
}BSTreeNode;

/* 二叉搜索树 */
typedef struct BSTree
{
    BSTreeNode * root;//根结点
    int size; //树的结点个数
    int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);//钩子函数比较器,放到结构体内部
    int (*visit)(ELEMENTTYPE val);/* 钩子函数 包装器实现自定义打印函数接口 */
#if 0
    doubleLinkListQueue *pQueue;
#endif
}BSTree;

/* 二叉搜索树的初始化 */
int binarysearchTreeInit(BSTree **pBstree, int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*visit)(ELEMENTTYPE val));

/* 二叉搜索树的插入 */
int binarysearchTreeInsert(BSTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树是否包含指定元素 */
int BSTreeIsContainAppointVal(BSTree *pBstree, ELEMENTTYPE val);

/* 二叉树先序遍历 */
int BSTreePreOrderTraverse(BSTree *pBstree);

/* 二叉树中序遍历 */
int BSTreeMidOrderTraverse(BSTree *pBstree);

/* 二叉树后序遍历 */
int BSTreePosOrderTraverse(BSTree *pBstree);

/* 二叉树层序遍历 */
int BSTreeLevelOrderTraverse(BSTree *pBstree);

/* 获取二叉搜索树的节点个数 */
int BSTreeGetNodeSize(BSTree *pBstree, int *pSize);

/* 获取二叉树的高度:需要记录每一层的结点树->每一层的节点数技术完成，就是树的高度加1 */
int BSTreeGetHeight(BSTree *pBstree, int *pHeight);

/* 二叉树的删除 */
int BSTreeDelete(BSTree *pBstree, ELEMENTTYPE val);

/* 二叉树的销毁 */
int BSTreeDestroy(BSTree *pBstree);
#endif