#include <mySet.h>
#include <stdio.h>

#define BUFFER_SIZE 5

/* 测试二叉搜索树 */
int compareBasicFunc(void * arg1, void * arg2)
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
    set * SET;
    AVLTreeInit(&SET, compareBasicFunc, printBasicData);
    int buffer[BUFFER_SIZE] = {11, 11, 22, 33,22};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        setInsert(SET, (void *)&buffer[idx]);
    }
    /* 获取集合个数 */
    int size = 0;
    setGetSize(SET, &size);
    printf("size:%d\n", size);

 

    /* 层序遍历 */
    printf("集合遍历\n");
    setTraverse(SET);
    printf("\n");
    /* 包含特定元素 */
    int val = 21;
    printf("是否包含特定元素:%d\n", val);
    int fd= setIsContainAppointVal(SET, (void *)&val);
    if(fd)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    int delVal = 11;
    setDelAppointVal(SET, (void*)&delVal);
    printf("删除指定元素:%d\n", delVal);
    setTraverse(SET);
    printf("\n");

#if 0
    /* 中序遍历 */
    printf("中序遍历\n");
    AVLTreeMidOrderTraverse(SET);
    printf("\n");

{
    /* 删除度为2 */
    int delVal = 56;
    AVLTreeDelete(SET, &delVal);
    printf("\n");

    /* 获取二叉搜索树的节点个数 */
    int size = 0;
    AVLTreeGetNodeSize(SET, &size);
    printf("size:%d\n", size);

    /* 获取二叉搜索树的高度 */
    int height = 0;
    AVLTreeGetHeight(SET,&height);
    printf("height:%d\n", height);

     /* 层序遍历 */
    printf("层序遍历\n");
    AVLTreeLevelOrderTraverse(SET);
    printf("\n");
}
#endif

    
    return 0;
}