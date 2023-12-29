#include "balanceBinarySearchTree.h"
#include "doubleLinkListQueue.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 状态码 */
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS  //非法访问
};

#define true 1
#define false 0
/* 静态函数前置声明 */
#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);
static int visit(AVLTreeNode *parentNode);
#endif
/* 创建节点 */
static AVLTreeNode *createAVLTreeNewNode(ELEMENTTYPE val, AVLTreeNode *parentNode);
/* 根据指定的值获取二叉搜索树的结点  */
static AVLTreeNode * baseAppointValGetBSTreeNode(balanceBinarySearchTree *pAvltree, ELEMENTTYPE val);
/* 二叉搜索树删除指定的结点 */
static int balanceBinarySearchTreeDeleteNode(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 判断二叉搜索树度为2 */
static int balanceBinarySearchTreeNodeHasTwochilds(AVLTreeNode *node);
/* 判断二叉搜索树度为1 */
static int balanceBinarySearchTreeNodeHasOnechilds(AVLTreeNode *node);
/* 判断二叉搜索树度为0 */
static int balanceBinarySearchTreeNodeIsLeft(AVLTreeNode *node);
/* 前序遍历 */
static int preOrderTraverse(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 中序遍历 */
static int midOrderTraverse(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 后序遍历*/
static int posOrderTree(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 获取当前结点的的前驱结点 */
static AVLTreeNode *bstreeNodePreDecessor(AVLTreeNode *node);
/* 获取当前结点的的后驱结点 */
static AVLTreeNode *bstreeNodeSucDecessor(AVLTreeNode *node);
/* 添加结点之后的操作 */
static int insertNodeAfter(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 更新结点高度 */
static int AVLTreeNodeUpdateHeight(AVLTreeNode *node);
/* 添加结点之后的操作 */
static int insertNodeAfter(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 删除结点之后要做的事 */
static int removeNodeAfter(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 计算结点的平衡因子 */
static int AVLTreeNodeIsBalanceFactor(AVLTreeNode *node);
/* 判断结果是否平衡 */
static int AVLTreeNodeIsBalanced(AVLTreeNode *node);
/* AVL树调整结点平衡 */
static int AVLTreeNodeAdjustBalance(balanceBinarySearchTree *pAvltree, AVLTreeNode *node);
/* 获取AVL结点较高的子结点 */
static AVLTreeNode *AVLTreeNodeGetChildTaller(AVLTreeNode *node);
/* 当前结点是父节点的左子树 */
static int AVLTreeCurrentNodeIsLeft(AVLTreeNode *node);
/* 当前结点是父节点的左子树 */
static int AVLTreeCurrentNodeIsRight(AVLTreeNode *node);
/* LL 左旋 */
static int AVLTreeCurrentNodeRotateLeft(balanceBinarySearchTree *pAvltree, AVLTreeNode *grand);
/* LL 右旋 */
static int AVLTreeCurrentNodeRotateRight(balanceBinarySearchTree *pAvltree, AVLTreeNode *grand);
/* 维护父结点 */
static int AVLTreeNodeRotate(balanceBinarySearchTree *pAvltree,AVLTreeNode *grand, AVLTreeNode *parent,AVLTreeNode *child);

/* 二叉搜索树的初始化 */
int balanceBinarySearchTreeInit(balanceBinarySearchTree **pAvltree, int(*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), int (*visit)(ELEMENTTYPE val))
{
    int ret = 0;
    balanceBinarySearchTree * bstree = (balanceBinarySearchTree *)malloc(sizeof(balanceBinarySearchTree));
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
        bstree->visit = visit;
    }
    #if 0
    /* 分配根结点 */
    bstree->root = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
    if(bstree->root = NULL)
    {
        return MALLOC_ERROR;
    }
    memset(bstree->root, 0, sizeof(AVLTreeNode));
 
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
    bstree->root = createAVLTreeNewNode(0, NULL);//根结点的父节点为NULL
    *pAvltree = bstree;
}
#if 0
static compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    return val1 - val2;
}
#endif

/* 计算结点的平衡因子 */
static int AVLTreeNodeIsBalanceFactor(AVLTreeNode *node)
{
    /* 左子树高度 */
    int leftHeight = node->left == NULL ? 0 : node->left->height;
    /* 右子树高度 */
    int rightHeight = node->right == NULL ? 0 : node->right->height;
    return leftHeight - rightHeight;
}

/* 判断结果是否平衡 */
static int AVLTreeNodeIsBalanced(AVLTreeNode *node)
{
    int nodeFactor = abs(AVLTreeNodeIsBalanceFactor(node));
    if(nodeFactor <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

static int tmpMax(int val1, int val2)
{
    return val1 - val2 >= 0 ? val1 : val2;
}
/* 更新结点高度 */
static int AVLTreeNodeUpdateHeight(AVLTreeNode *node)
{
    int ret = 0;
    #if 1
     /* 左子树高度 */
    int leftHeight = node->left == NULL ? 0 : node->left->height;
    /* 右子树高度 */
    int rightHeight = node->right == NULL ? 0 : node->right->height;
    node->height =  1 + tmpMax(leftHeight, rightHeight);//不应该return
    #else
    AVLTreeNodeIsBalanceFactor(node) >= 0 ? 1 + node->left->height : node->right->height;
    #endif
    return ret;
}

/* 获取AVL结点较高的子结点 */
static AVLTreeNode *AVLTreeNodeGetChildTaller(AVLTreeNode *node)
{
    int leftHeight = node->left == NULL ? 0 : node->left->height;//左子树高度
    int rightHeight= node->right == NULL ? 0 : node->right->height;//右子树高度
    if(leftHeight > rightHeight)
    {
        return node->left;
    }
    else if(leftHeight < rightHeight)
    {
        return node->right;
    }
    else
    {
        /* leftHeight = rightHeight */
        if(AVLTreeCurrentNodeIsLeft(node))
        {
            return node->left;
        } 
        else if(AVLTreeCurrentNodeIsRight(node))
        {
            return node->right;
        }
    }
}

/* 当前结点是父结点的左子树 */
static int  AVLTreeCurrentNodeIsLeft(AVLTreeNode *node)
{
    return (node->parent != NULL) && (node == node->parent->left);
}
/* 当前结点是父结点的左子树 */
static int AVLTreeCurrentNodeIsRight(AVLTreeNode *node)
{
    return (node->parent != NULL) && (node == node->parent->right);
}

/* 维护父结点 */
static int AVLTreeNodeRotate(balanceBinarySearchTree *pAvltree,AVLTreeNode *grand, AVLTreeNode *parent,AVLTreeNode *child)
{
    int ret = 0;
    parent->parent = grand->parent;//parent成为新的根结点  //3
    if(AVLTreeCurrentNodeIsLeft(grand))
    {
        grand->parent->left = parent;     //4
    }
    else if(AVLTreeCurrentNodeIsRight(grand))
    {
        grand->parent->right = parent;   //4
    }
    else
    {
        pAvltree->root = parent;         //4
    }
    grand->parent = parent;              //5

    if(child)
    {
        child->parent = grand;          //6
    }
    /* 跟新高度 */
    /* 先更新低的结点 */
    AVLTreeNodeUpdateHeight(grand);
    AVLTreeNodeUpdateHeight(parent); 
    return ret;
}

/* RR 左旋 */
static int AVLTreeCurrentNodeRotateLeft(balanceBinarySearchTree *pAvltree,AVLTreeNode *grand)
{
    int ret = 0;
    AVLTreeNode *parent = grand->right;
    AVLTreeNode *child = parent->left;

    grand->right = child;           //1
    parent->left = grand;           //2
   //parent成为新的结点  //3
    /* 维护父结点 */
    #if 0
    if(AVLTreeCurrentNodeIsLeft(grand))
    {
        //grand->parent = parent->left;
        grand->parent->left = parent; //4
    }
    else if(AVLTreeCurrentNodeIsRight(grand))
    {
       // grand->parent = parent->right;
        grand->parent->right = parent;   //4
    }
    else
    {
        pAvltree->root = parent;            //4
    }
    grand->parent = parent;                 //5

    if(child)
    {
        child->parent = grand;//6
    }
    /* 跟新高度 */
    /* 先更新低的结点 */
    AVLTreeNodeUpdateHeight(grand);
    AVLTreeNodeUpdateHeight(parent);
#endif
    AVLTreeNodeRotate(pAvltree, grand, parent, child);
    return ret;
    
}

/* LL 右旋 */
static int AVLTreeCurrentNodeRotateRight(balanceBinarySearchTree *pAvltree, AVLTreeNode *grand)
{
    int ret = 0;
    AVLTreeNode * parent = grand->left;
    AVLTreeNode * child = grand->right;

    grand->left = child;                    //1
    parent->right = grand;                  //2
    /* p成为新的根节点 */
    #if 0
    parent->parent = grand->parent;         //3
    if(AVLTreeCurrentNodeIsLeft(grand))
    {
        grand->parent->left = parent;       //4
    }
    else if(AVLTreeCurrentNodeIsRight(grand))
    {
        grand->parent->right = parent;       //4
    }
    else
    {
        /* p成为树的根结点 */
        pAvltree->root = parent;            //4
    }
    grand->parent = parent;                 //5
    if(child != NULL)
    {
        child->parent = grand;              //6
    }
    /* 更新高度 */
    /* 先更新低的结点 */
    AVLTreeNodeUpdateHeight(grand);
    AVLTreeNodeUpdateHeight(parent);
    #endif
    AVLTreeNodeRotate(pAvltree, grand, parent, child);
    return ret;
}

/* AVL树调整结点平衡 */
/* node一定是最低的不平衡结点 */
static int AVLTreeNodeAdjustBalance(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
    /* LL LR RL RR */
    AVLTreeNode *parent =  AVLTreeNodeGetChildTaller(node);
    AVLTreeNode * child = AVLTreeNodeGetChildTaller(parent);
  
    if(AVLTreeCurrentNodeIsLeft(parent))  /* L */
    {   
        if(AVLTreeCurrentNodeIsLeft(child))
        {
            /* LL 右旋*/
            AVLTreeCurrentNodeRotateRight(pAvltree,node);

        }
        else if(AVLTreeCurrentNodeIsRight(child))
        {
            /* LR */
            AVLTreeCurrentNodeRotateLeft(pAvltree, parent);
            AVLTreeCurrentNodeRotateRight(pAvltree, node);
        }
    }
    else /* R */
    {
        if(AVLTreeCurrentNodeIsLeft(child))
        {
            /* RL */
            AVLTreeCurrentNodeRotateRight(pAvltree, parent);
            AVLTreeCurrentNodeRotateLeft(pAvltree, node);

        }
        else if(AVLTreeCurrentNodeIsRight(child))
        {
            /* RR */
            AVLTreeCurrentNodeRotateLeft(pAvltree, node);
        }
    }
}
/* 删除结点之后要做的事 */
static int removeNodeAfter(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
    int ret = 0;
    /* 时间复杂度是O(nlogN) */
    while((node = node->parent) != NULL)
    {
        /* 程序执行到这里，一定不止一个结点 */
        if(AVLTreeNodeIsBalanced(node))
        {
            /* 如果节点是平衡的，更新高度 */
            AVLTreeNodeUpdateHeight(node);
        }
        else
        {
            /* node是最低不平衡点 */
            /* 开始更新平衡 */
            AVLTreeNodeAdjustBalance(pAvltree, node);
        }
    }
    return ret;
}
/* 添加结点之后的操作 */
/* 新添加的结点一定是叶子结点 */
static int insertNodeAfter(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{   
    int ret = 0;
    while((node = node->parent) != NULL)
    {
        /* 程序执行到这里，一定不止一个结点 */
        if(AVLTreeNodeIsBalanced(node))
        {
            /* 如果节点是平衡的，更新高度 */
            AVLTreeNodeUpdateHeight(node);
        }
        else
        {
            /* node是最低不平衡点 */
            /* 开始更新平衡 */
            AVLTreeNodeAdjustBalance(pAvltree, node);
        }
    }
    return ret;
}

/* 判断二叉搜索树度为2 */
static int balanceBinarySearchTreeNodeHasTwochilds(AVLTreeNode *node)
{
    return node->left != NULL && node->right != NULL;
}
/* 判断二叉搜索树度为1 */
static int balanceBinarySearchTreeNodeHasOnechilds(AVLTreeNode *node)
{
    return ((node->left != NULL) && (node->right != NULL)) || ((node->left != NULL) && (node->right == NULL));
}
/* 判断二叉搜索树度为0 */
static int balanceBinarySearchTreeNodeIsLeft(AVLTreeNode *node)
{
    return (node->left == NULL) && (node->right == NULL);
}

/* 获取当前结点的的前驱结点 */
/* 中序遍历到节点的前一个结点 */
static AVLTreeNode *bstreeNodePreDecessor(AVLTreeNode *node)
{
    if(node->left != NULL)
    {
        /* 前驱节点是在左子树的右子树上... */
        AVLTreeNode * travelNode = node->left;
        while(travelNode->right != NULL)
        {
            travelNode = travelNode->right;
        }
        return travelNode;
    }
    /* 程序到这个地方 说明一定没有左子树，那就需要向父结点找 */
    while(node->parent != NULL && node == node->parent->left)
    {
        node = node->parent;
    }
    /* node->parent == NULL
       node == node->parent->right */
    return node->parent;
}

/* 获取当前结点的的后继结点 */
static AVLTreeNode *bstreeNodeSucDecessor(AVLTreeNode *node)
{
    if(node->right != NULL)
    {
        /* 前驱节点是在右子树的左子树的左子树的左子树上... */
        AVLTreeNode * travelNode = node->right;
        while(travelNode->left != NULL)
        {
            travelNode = travelNode->left;
        }
        return travelNode;
    }
    /* 程序到这个地方 说明一定没有右子树，那就需要向父结点找 */
    while(node->parent != NULL && node == node->parent->right)
    {
        node = node->parent;
    }
    /* node->parent == NULL
       node == node->parent->left */
    return node->parent;
}

/* 创建结点 */
static AVLTreeNode *createAVLTreeNewNode(ELEMENTTYPE val, AVLTreeNode *parentNode)//在上一个父节点后添加节点
{
    AVLTreeNode *newAVLNode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
    if(newAVLNode == NULL)
    {
        return NULL;//not malloc error!
    }
    memset(newAVLNode, 0, sizeof(AVLTreeNode));

    /* 初始化根结点 */
    {
        newAVLNode->data = 0;
        newAVLNode->height = 1;//结点的高度为1
        newAVLNode->left = NULL;
        newAVLNode->right = NULL;
        newAVLNode->parent = NULL;
    }
    newAVLNode->data = val;
    newAVLNode->parent = parentNode;
    return newAVLNode;
}

/* 二叉搜索树的插入 */
int balanceBinarySearchTreeInsert(balanceBinarySearchTree *pAvltree, ELEMENTTYPE val)
{
    int ret = 0;
    if(pAvltree->size == 0)//空树
    {
        pAvltree->size++;//更新树的结点
        pAvltree->root->data = val;
        insertNodeAfter(pAvltree, pAvltree->root);
        return ret;
    }
    /* travelNode 指向根结点 */
    AVLTreeNode * travelNode = pAvltree->root;
    AVLTreeNode * parentNode = pAvltree->root;

    int cmp = 0;/* 确定符号：到底放在在左边还是右边 */
    while(travelNode != NULL)
    {
        parentNode = travelNode;/* 标记父结点 */
        cmp = pAvltree->cpmpareFunc(val, travelNode->data);//结构体内的比较函数

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
    AVLTreeNode * newAVLNode = (AVLTreeNode *)malloc(sizeof(AVLTreeNode));
    if(newAVLNode = NULL)
    {
        return MALLOC_ERROR;
    }
    memset(newAVLNode, 0, sizeof(AVLTreeNode));
    /* 初始化根结点 */
    {
        newAVLNode->data = 0;
        newAVLNode->left = NULL;
        newAVLNode->right = NULL;
        newAVLNode->parent = NULL;
    }
#endif
    AVLTreeNode * newAVLNode = createAVLTreeNewNode(val, parentNode);
    /* 挂在左子树 */
    if(cmp < 0)
    {
        parentNode->left = newAVLNode;
    }
    else/* 挂在右子树 */
    {
        parentNode->right = newAVLNode;
    }
    /* 添加之后的调整 */
    insertNodeAfter(pAvltree, newAVLNode);
    
#if 0
    /* 新节点的parent指针赋值 */
    newAVLNode->parent = parentNode;
#endif
    pAvltree->size++;
    return ret;
}
/* 根据指定的值获取二叉搜索树的节点 */
static AVLTreeNode * baseAppointValGetBSTreeNode(balanceBinarySearchTree *pAvltree,ELEMENTTYPE val)
{
    AVLTreeNode *travelNode = pAvltree->root;
    int cmp = 0;
    while(travelNode != NULL)
    {
        cmp = pAvltree->cpmpareFunc(val, travelNode->data);
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
int balanceBinarySearchTreeIsContainAppointVal(balanceBinarySearchTree *pAvltree, ELEMENTTYPE val)
{
    return baseAppointValGetBSTreeNode(pAvltree, val) == NULL ? 0 : 1;
}

/* 前序遍历：根结点->左子树->右子树 */
static int preOrderTraverse(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 根结点 */
    pAvltree->visit(node->data);
    /* 左子树 */
    preOrderTraverse(pAvltree, node->left);
    /* 右子树 */
    preOrderTraverse(pAvltree, node->right);
}

/* 二叉树前序遍历 */
int balanceBinarySearchTreePreOrderTraverse(balanceBinarySearchTree *pAvltree)
{
    int ret = 0;
    preOrderTraverse(pAvltree, pAvltree->root);
    return ret;
}

/* 中序遍历:左子树->根结点->右子树 */
static int midOrderTraverse(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    midOrderTraverse(pAvltree, node->left);
    /* 根结点 */
    pAvltree->visit(node->data);
    /* 右子树 */
    midOrderTraverse(pAvltree, node->right);
}

/* 二叉树中序遍历 */
int balanceBinarySearchTreeMidOrderTraverse(balanceBinarySearchTree *pAvltree)
{
    int ret = 0;
    midOrderTraverse(pAvltree, pAvltree->root);
    return ret;
}

/* 后序遍历 :左子树->右子树->根结点*/
static int posOrderTree(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
    int ret = 0;
    if(node == NULL)
    {
        return ret;
    }
    /* 左子树 */
    posOrderTree(pAvltree, node->left);
    /* 右子树 */
    posOrderTree(pAvltree, node->right);
    /* 根结点 */
    pAvltree->visit(node->data);
}

/* 二叉树后序遍历 */
int balanceBinarySearchTreePosOrderTraverse(balanceBinarySearchTree *pAvltree)
{
    int ret = 0;
    posOrderTree(pAvltree, pAvltree->root);
    return ret;
}

/* 二叉树层序遍历*/
int balanceBinarySearchTreeLevelOrderTraverse(balanceBinarySearchTree *pAvltree)
{
    int ret = 0;
    /*算法: 使用队列 
        1. 将根结点入队
        2. 循环执行以下操作, 直到队列为空
            2.1 将队头结点(A)出队,并访问
            2.2 将(A)的左子节点入队
            2.3 将(A)的右子节点入队
    */
    doubleLinkListQueue *pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);

    doubleLinkListQueuePush(pQueue, pAvltree->root);//根结点入队

    /* 判断队列是否为空 */
    AVLTreeNode * nodeVal = NULL;
    /* 当队列不为空 */
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&nodeVal);
        #if 0
        printf("data:%d\n", nodeVal->data);
        #else
        pAvltree->visit(nodeVal->data);
        #endif
        doubleLinkListQueuePop(pQueue);

        /* 当左子树存在时，将左子树添加到队列中 */
        if(nodeVal->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, nodeVal->left);
        }

        if(nodeVal->right != NULL)//右子树入队
        {
            doubleLinkListQueuePush(pQueue, nodeVal->right);
        }
    }
    doubleLinkListQueueDestroy(pQueue);
    return ret;
}

/* 获取二叉搜索树的节点个数 */
int balanceBinarySearchTreeGetNodeSize(balanceBinarySearchTree *pAvltree, int *pSize)
{
    if(pAvltree == NULL)
    {
        return 0;
    }
    
    if(pSize)
    {
        *pSize = pAvltree->size;
    }
    return pAvltree->size;
}

/* 获取二叉树的高度 */
/* 层序遍历的思路 */
int balanceBinarySearchTreeGetHeight(balanceBinarySearchTree *pAvltree, int *pHeight)
{
    int ret = 0;
    if(pAvltree == NULL)
    {
        return NULL_PTR;//应该返回0
    }
    #if 0
    if(pAvltree->size == NULL)
    {
        return 0;
    }
    *pHeight = pAvltree->root->height;
    return pAvltree->root->height;
    #else
    if(pAvltree->size == 0)//空树
    {
        return 0;
    }
    doubleLinkListQueue *pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    doubleLinkListQueuePush(pQueue, pAvltree->root);//入队 节点
    int height= 0;//树的高度 （根结点入队高度为）
    int levelSize = 1; //树每一层的节点数量
    AVLTreeNode *travelNode = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))//
    {
        doubleLinkListQueueTop(pQueue, (void **)&travelNode);
        doubleLinkListQueuePop(pQueue);
        levelSize--;

        /* 左子树不为空 */
        if(travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }
        /* 右子树不为空 */
        if(travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue,travelNode->right);
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
    #endif
    return ret;
}

/* 删除节点 */
static int balanceBinarySearchTreeDeleteNode(balanceBinarySearchTree *pAvltree, AVLTreeNode *node)
{
/* 算法
 * 删除度为0的结点: 要么是叶子结点,要么是只有唯一一个结点的树。这种情况下直接释放free结点即可
 * 删除度为1的结点: 
 *      当要删除的结点有父结点的时候,修改要删除结点的父结点和子结点的指向关系,再释放free结点.
 *      当要删除的结点没有父结点的时候, 直接改变根结点的指向即可。
 * 删除度为2的结点:
 *      找到前驱结点和后继结点,前驱结点或者后继结点的值替换掉当前要删除结点的值
 *      再删除前驱结点或者后继结点。(度为2结点的前驱结点或者后继结点的度一定是1或者0)
 *      再按照上面删除度为0还是度为1的逻辑操作即可.
 * */ 
    int ret = 0;
    if(node == NULL)
    {
        return ret;  
    }

    /* 树的结点减一 */
    pAvltree->size--;

    if(balanceBinarySearchTreeNodeHasTwochilds(node))
    {
        AVLTreeNode * preNode = bstreeNodePreDecessor(node);//找到前驱结点
        node->data = preNode->data;
        node = preNode;//node是要删除的结点
    }
    /* 程序执行到这里，要么是度为1要么是度为0 */
    #if 0
    if(balanceBinarySearchTreeNodeHasOnechilds(node))
    {
        AVLTreeNode * preNode = bstreeNodePreDecessor(node);
        node->data = preNode->data;
        node = preNode;
    }
    if(balanceBinarySearchTreeNodeIsLeft(node))
    {
        if(node->data == node->parent->left)
        {
            node->parent->left = NULL;
        }
        else
        {
            node->parent->right = NULL;
        }   
    }
#endif
    /* 假设nod结点是度为1，他的child 要没事是左要么是右 */
    /* 假设node的结点是度为0的 */
    AVLTreeNode * child =node->left != NULL ? node->left : node->right;

    AVLTreeNode * delNode = NULL;
    if(child)
    {
        /* 度为1 */
        child->parent = node->parent; 
        if(node->parent == NULL)
        {
            /* 它是根结点 */
            pAvltree->root = child;
            delNode = node;
            /* 删除的结点 */
            removeNodeAfter(pAvltree,delNode);
        }
        else
        {
            if(node == node->parent->left)
            {
                node->parent->left = child;
            }
            else if(node == node->parent->right)
            {
                node->parent->right = child;
            }
            /* 释放节点 */
            delNode = node;
              /* 删除的结点 */
            removeNodeAfter(pAvltree,delNode);
            #if 0
            if(node)
            {
                free(node);
                node= NULL;
            }
            #endif
        }   
    }
    else
    {
        /* 度为0 */
        if(node->parent == NULL)
        {
            /* 度为0，且是根结点 */
            delNode = node;
            /* 删除的结点 */
            removeNodeAfter(pAvltree,delNode);
            #if 0
            if(node)
            {
                free(node);
                node = NULL;
            } 
            #endif
        }
        else
        {
            if(node == node->parent->left)
            {
                node->parent->left = NULL;
            }
            else
            {
                node->parent->right = NULL;
            }
            delNode = node;
            /* 删除的结点 */
            removeNodeAfter(pAvltree,delNode);
            #if 0
            if(node)
            {
                free(node);
                node = NULL;
            }  
            #endif
        }   
    }
    if(delNode)
    {
        free(delNode);
        delNode = NULL;
    }
    return ret;
}

/* 二叉树的删除 */
int balanceBinarySearchTreeDelete(balanceBinarySearchTree *pAvltree, ELEMENTTYPE val)
{
    /* 算法：
    度为2 结点的前驱/后继 结点的度一定为1和0
    删除度为2的结点
    1、找到前驱/后继结点的值
    2、复制前驱结点的value 到 要删除的节点
    3、删除前驱/后继结点*/  
    /*
    删除度为2的结点
    1、找到前驱结点的值
    2、复制前驱结点的value 到 要删除的结点
    3、删除前驱结点
    删除度为0的结点：
    直接删除结点，并且将父节点的指针（left/right)置为NULL
    删除度为1的结点：
    说明一定有孩子(要么是left要么是right)
    1、让孩子的parent指针指向delNode->parent
    2、然delNode->parent(left/right)指向delNode的孩子
    */
    int ret= 0;
    #if 0
    AVLTreeNode *delNode = baseAppointValGetBSTreeNode(pAvltree,val);
    balanceBinarySearchTreeDeleteNode(pAvltree, delNode);
    #else
    return balanceBinarySearchTreeDeleteNode(pAvltree, baseAppointValGetBSTreeNode(pAvltree,val));
    #endif
    return ret;
}

/* 二叉树的销毁 */
int balanceBinarySearchTreeDestroy(balanceBinarySearchTree *pAvltree)
{
    int ret = 0;
    if(pAvltree == NULL)
    {
        return NULL_PTR;
    }
    doubleLinkListQueue *pQueue = NULL;
    doubleLinkListQueueInit(&pQueue);
    /* 将根结点入队 */
    doubleLinkListQueuePush(pQueue, pAvltree->root);
    AVLTreeNode * travelNode = NULL;
    while(!doubleLinkListQueueIsEmpty(pQueue))
    {
        doubleLinkListQueueTop(pQueue, (void **)&travelNode);
        doubleLinkListQueuePop(pQueue);

        if(travelNode->left != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->left);
        }

        if(travelNode->right != NULL)
        {
            doubleLinkListQueuePush(pQueue, travelNode->right);
        }
        /* 最后释放 */
         if(travelNode)
        {
            free(travelNode);
            travelNode = NULL;
        }
        /* 释放队列 */
        doubleLinkListQueueDestroy(pQueue);
        /* 释放树 */
        if(pAvltree)
        {
            free(pAvltree);
            pAvltree = NULL;
        }
    }
    return ret;
}