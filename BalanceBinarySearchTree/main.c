#include <myAVLTree.h>
#include <stdio.h>

#define BUFFER_SIZE 3

/* 测试二叉搜索树 */
int compareBasicDataFunc(void * arg1, void *arg2)
{
    int val1 = *(int *)arg1;
    int val2 = *(int *)arg2;

    return val1 - val2;
}

/* 打印基础数据 */
int printBasicData(void *arg)
{
    int ret = 0;
    int val = *(int *)arg;
    printf("val:%d\t", val);

    return ret;
}

int main()
{
    AVLTree * AVL;
    AVLTreeInit(&AVL, compareBasicDataFunc, printBasicData);

    int buffer[] = {13, 14, 15, 12, 11, 17, 16, 8, 9, 1};

    for (int idx = 0; idx < sizeof(buffer) /sizeof(buffer[0]); idx++)
    {   
        AVLTreeInsert(AVL, (void *)&buffer[idx]);
    }
    /* 获取二叉搜索树的结点个数 */
    int size = 0;
    AVLTreeGetNodeSize(AVL, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度 */
    int height = 0;
    AVLTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    AVLTreeLevelOrderTraverse(AVL);
    printf("\n");


    int delVal1 = 11;
    AVLTreeDelete(AVL, &delVal1);

    int delVal2 = 12;
    AVLTreeDelete(AVL, &delVal2);

    int delVal3 = 13;
    AVLTreeDelete(AVL, &delVal3);


    /* 获取二叉搜索树的高度 */
    height = 0;
    AVLTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    AVLTreeLevelOrderTraverse(AVL);
    printf("\n");

    /* 销毁 */
    AVLTreeDestroy(AVL);
#if 0
    /* 中序遍历 */
    AVLTreeInOrderTravel(AVL);
    printf("\n");


    /* 层序遍历 */
    AVLTreeLevelOrderTravel(AVL);
    printf("\n");


    /* 删除 度为2. 值为56 */
    int delVal = 56;
    AVLTreeDelete(AVL, &delVal);

    /* 获取二叉搜索树的结点个数 */
    size = 0;
    AVLTreeGetNodeSize(AVL, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度 */
    height = 0;
    AVLTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    AVLTreeLevelOrderTravel(AVL);
    printf("\n");




    /* 删除 度为1. 值为56 */
    delVal = 7;
    AVLTreeDelete(AVL, &delVal);

    /* 获取二叉搜索树的结点个数 */
    size = 0;
    AVLTreeGetNodeSize(AVL, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度 */
    height = 0;
    AVLTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    AVLTreeLevelOrderTravel(AVL);
    printf("\n");


    /* 删除 度为0. 值为12 */
    delVal = 12;
    AVLTreeDelete(AVL, &delVal);

    /* 获取二叉搜索树的结点个数 */
    size = 0;
    AVLTreeGetNodeSize(AVL, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度 */
    height = 0;
    AVLTreeGetHeight(AVL, &height);
    printf("height:%d\n", height);

    /* 层序遍历 */
    AVLTreeLevelOrderTravel(AVL);
    printf("\n");
#endif


    return 0;
}