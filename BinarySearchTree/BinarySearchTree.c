#include "BinarySearchTree.h"
#include <stdlib.h>
#include <string.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,    //非法访问
};

/* 二叉搜索树的初始化 */
int binarysearchTreeInit(binarySearchTree **pBstree)
{
    int ret = 0;
    binarySearchTree * bstree = (binarySearchTree *)malloc(sizeof(binarySearchTree));
    if(bstree == NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree, 0, sizeof(bstree));//清除脏数据
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
    }
    #if 1
    /* 分配根结点 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    if(bstree->root = NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(BSTreeNode));
    #endif
    /* 初始化根结点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
    *pBstree = bstree;
}

/* 二叉搜索树的插入 */
int binarysearchTreeInsert(binarySearchTree **pBstree, ELEMENTTYPE val)
{

}