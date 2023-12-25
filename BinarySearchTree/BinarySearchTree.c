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
/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parentNode);
static BSTreeNode * baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTYPE val);

/* 二叉搜索树的初始化 */
int binarysearchTreeInit(binarySearchTree **pBstree, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
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
        /* 钩子函数在这边赋值 */
        bstree->cpmpareFunc = compareFunc;
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
#if 0
static compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}
#endif

static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parentNode)//在上一个父节点后添加节点
{
    BSTreeNode *newBstNode = (BSTreeNode *)malloc(sizeof(BSTreeNode));
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
    newBstNode->data = val;
    newBstNode->parent = parentNode;
    return newBstNode;
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
        cmp = pBstree->cpmpareFunc(val, travelNode->data);//结构体内的比较函数

        if(cmp < 0) /* 插入元素 < 遍历到的节点  左子树 */
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

 #if 0
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
#endif
    BSTreeNode * newBstNode = createBSTreeNewNode(val, parentNode);
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
/* 根据指定的值获取二叉搜索树的节点 */
static BSTreeNode * baseAppointValGetBSTreeNode(binarySearchTree *pBstree,ELEMENTTYPE val)
{
    BSTreeNode *travelNode = pBstree->root;
    int cmp = 0;
    while(travelNode != NULL)
    {
        cmp = pBstree->cpmpareFunc(val, travelNode->data);
        if(cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if(cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            return travelNode;//找到了
        }
    }
    return NULL;
}

/* 二叉搜索树是否包含指定元素 */
int binarySearchTreeContainAppointVal(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    baseAppointValGetBSTreeNode(pBstree, val);
}

/* 二叉树前序遍历 */
int binarySearchTreePreOrderTraverse(binarySearchTree *pBstree, void(*visit)(int))
{

}

/* 二叉树中序遍历 */
int binarySearchTreeMidOrderTraverse(binarySearchTree *pBstree, void(*visit)(int))
{

}

/* 二叉树后序遍历 */
int binarySearchTreePosOrderTraverse(binarySearchTree *pBstree, void(*visit)(int))
{

}
/* 二叉树层序遍历 */
int binarySearchTreeLevelOrderTraverse(binarySearchTree *pBstree, void(*visit)(int))
{

}