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
    ON_SUCCESS
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

static cpmpare(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}

/* 二叉搜索树的插入 */
int binarysearchTreeInsert(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    int ret = 0;
    if(pBstree->size == 0)//空树
    {
        pBstree->size++;//更新树的结点
        pBstree->root->data = val;
        return ret;
    }
    /* travelNode 指向根结点 */
    BSTreeNode * travelNode = pBstree->root;
    BSTreeNode * parentNode = pBstree->root;

    int cmp = 0;/* 确定符号：到底放在在左边还是右边 */
    while(travelNode != NULL)
    {
        parentNode = travelNode;/* 标记父结点 */
        cmp = cpmpare(val, travelNode->data);

        if(cmp < 0) /* 插入元素 < 遍历到的节点  左子树*/
        {
            travelNode = travelNode->left;
        }
        else if(cmp > 0)/* 插入元素 > 遍历到的节点 右子树 */ 
        {
            travelNode = travelNode->right;
        }
        else    /* 插入元素 = 遍历到的节点 右子树 */ 
        {
            
            return ret;
        }
    }
    /* 分配根结点 */
    BSTreeNode * newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    if(newBstNode = NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newBstNode, 0, sizeof(BSTreeNode));
    /* 初始化根结点 */
    {
        newBstNode->data = 0;
        newBstNode->left = NULL;
        newBstNode->right = NULL;
        newBstNode->parent = NULL;
    }
    /* 挂在左子树 */
    if(cmp < 0)
    {
        parentNode->left = newBstNode;
    }
    else/* 挂在右子树 */
    {
        parentNode->right = newBstNode;
    }
    /* 新节点的parent */
    newBstNode->parent = parentNode;

    pBstree->size++;
    return ret;
}