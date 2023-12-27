#include "BinarySearchTree.h"
#include "doubleLinkListQueue.h"
#include "common.h"
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
static int printFunc(BSTreeNode *parentNode);
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parentNode);
static BSTreeNode * baseAppointValGetBSTreeNode(binarySearchTree *pBstree, ELEMENTTYPE val);

/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochilds(BSTreeNode *node);
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechilds(BSTreeNode *node);
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeft(BSTreeNode *node);
/* 获取当前结点的的前驱结点 */
static BSTreeNode *bstreeNodePreDecessor(BSTreeNode *node);
/* 获取当前结点的的后驱结点 */
static BSTreeNode *bstreeNodeSucDecessor(BSTreeNode *node);

/* 二叉搜索树的初始化 */
int binarysearchTreeInit(binarySearchTree **pBstree, int(*cpmpareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*visit)(ELEMENTTYPE val))
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
        bstree->visit = printFunc;
    }
    #if 0
    /* 分配根结点 */
    bstree->root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
    if(bstree->root = NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(BSTreeNode));
 
    /* 初始化根结点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
       #endif
    #if 0
    doubleLinkListQueueInit(&(bstree->pQueue));
    #endif
    bstree->root = createBSTreeNewNode(0, NULL);//根结点的父节点为NULL
    *pBstree = bstree;
}
#if 0
static compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}
#endif

/* 判断二叉搜索树度为2 */
static int binarySearchTreeNodeHasTwochilds(BSTreeNode *node)
{
    return node->left != NULL && node->right != NULL;
}
/* 判断二叉搜索树度为1 */
static int binarySearchTreeNodeHasOnechilds(BSTreeNode *node)
{
    return ((node->left != NULL) && (node->right != NULL)) || ((node->left != NULL) && (node->right == NULL));
}
/* 判断二叉搜索树度为0 */
static int binarySearchTreeNodeIsLeft(BSTreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

/* 获取当前结点的的前驱结点 */
static BSTreeNode *bstreeNodePreDecessor(BSTreeNode *node)
{
    /* 度为2 */
    if(binarySearchTreeNodeHasTwochilds(node))
    {
        /*  */
        BSTreeNode * travelNode = node->left;
        while(travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    /* 程序到这个地方一定是度为1 或者 度为0 */
    
    /* 度为1 */

    /* 度为0 */

}
/* 获取当前结点的的后驱结点 */
static BSTreeNode *bstreeNodeSucDecessor(BSTreeNode *node)
{
    
}

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
#if 0
    /* 新节点的parent指针赋值 */
    newBstNode->parent = parentNode;
#endif
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
int binarySearchTreeIsContainAppointVal(binarySearchTree *pBstree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pBstree, val) == NULL ? 0 : 1;
}

/* 前序遍历：根结点->左子树->右子树 */
static int preOrderTraverse(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 根结点 */
    pBstree->visit(node->data);
    /* 左子树 */
    preOrderTraverse(pBstree, node->left);
    /* 右子树 */
    preOrderTraverse(pBstree, node->right);
}

/* 二叉树前序遍历 */
int binarySearchTreePreOrderTraverse(binarySearchTree *pBstree)
{
    int ret = 0;
    preOrderTraverse(pBstree, pBstree->root);
    return ret;
}

/* 中序遍历:左子树->根结点->右子树 */
static int midOrderTraverse(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    midOrderTraverse(pBstree, node->left);
    /* 根结点 */
    pBstree->visit(node->data);
    /* 右子树 */
    midOrderTraverse(pBstree, node->right);
}

/* 二叉树中序遍历 */
int binarySearchTreeMidOrderTraverse(binarySearchTree *pBstree)
{
    int ret = 0;
    midOrderTraverse(pBstree, pBstree->root);
    return ret;
}

/* 后序遍历 :左子树->右子树->根结点*/
static int posOrderTree(binarySearchTree *pBstree, BSTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    posOrderTree(pBstree, node->left);
    /* 右子树 */
    posOrderTree(pBstree, node->right);
    /* 根结点 */
    pBstree->visit(node->data);
}

/* 二叉树后序遍历 */
int binarySearchTreePosOrderTraverse(binarySearchTree *pBstree)
{
    int ret = 0;
    posOrderTree(pBstree, pBstree->root);
    return ret;
}

/* 二叉树层序遍历 */
int binarySearchTreeLevelOrderTraverse(binarySearchTree *pBstree)
{
    int ret = 0;
    doubleLinkListQueue *pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    doubleLinkListQueuePush(pQueue,pBstree->root);//根结点入队

    /* 判断队列是否为空 */
    BSTreeNode * nodeVal = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);

        printf("data:%d\n", nodeVal->data);
        doubleLinkListQueuePop(pQueue);

        if(nodeVal->left != NULL)//左子树入队
        {
            doubleLinkListQueuePush(pQueue, nodeVal->data);
        }

        if(nodeVal->right != NULL)//右子树入队
        {
            doubleLinkListQueuePush(pQueue, nodeVal->right);
        }
    }
    return ret;
}

/* 获取二叉树的高度 */
int binarySearchTreeGetHeight(binarySearchTree *pBstree, int *pHeight)
{
    int ret = 0;
    if(pBstree == NULL)
    {
        return NULL_PTR;//应该返回0
    }
    int height= 0;//树的高度 根结点入队高度为
    if(pBstree->size == 0)//空树
    {
        return height;
    }
    doubleLinkListQueue *pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    doubleLinkListQueuePush(pQueue, pBstree->root);//入队 节点
    
    int levelSize = 1; //树每一层的节点数量
    BSTreeNode *travelNode = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))//
    {
        doubleLinkListQueueTop(pQueue, (void *)&travelNode);
        doubleLinkListQueuePop(pQueue);
        levelSize--;

        /* 左子树不为空 */
        if(travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }
        /* 右子树不为空 */
        if(travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }
        /* 树的当前节点遍历结束 */
        if(levelSize == 0)
        {
            height++;
            doubleLinkListQueueGetSize(pQueue, &levelSize);
        }
    }
    *pHeight = height;//解引用
    /* 释放队列 */
    doubleLinkListQueueDestroy(pQueue);
    return ret;
}
