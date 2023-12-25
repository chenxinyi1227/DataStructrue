#ifndef _BINARY_SEARCH_TREE__H
#define _BINARY_SEARCH_TREE__H

#define ELEMENTTYPE int

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
typedef struct binarySearchTree
{
    BSTreeNode * root;//根结点
    int size; //树的结点个数
}binarySearchTree;


void PrintNode(int node);

/* 二叉搜索树的初始化 */
int binarysearchTreeInit(binarySearchTree **pBstree);

/* 二叉搜索树的插入 */
int binarysearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val, int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2));

/* 二叉树先序遍历 */
int binarySearchTreePreOrderTraverse(binarySearchTree * root, void(*visit)(int));

/* 二叉树中序遍历 */
int binarySearchTreeMidOrderTraverse(binarySearchTree * root, void(*visit)(int));

/* 二叉树后序遍历 */
int binarySearchTreePosOrderTraverse(binarySearchTree * root, void(*visit)(int));
/* 二叉树层序遍历 */
int binarySearchTreeLevelOrderTraverse(binarySearchTree * root, void(*visit)(int));
#endif