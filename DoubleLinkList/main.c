#include "doubleLinkList.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE    3


typedef struct stuInfo
{
    int age;
    char sex;
} stuInfo; 


/* 自定义打印 */
int printStruct(void *arg)
{
    stuInfo *info = (stuInfo*)arg;
    printf("age:%d\t, sex:%c\n", info->age, info->sex);
}

int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\t", data);
}

int compareData(void *arg1, void *arg2)
{
    int data1 = *(int *)arg1;
    int data2 = *(int *)arg2;

    return data1 - data2;
}

int main()
{
    doubleLinkList *list = NULL;
    /* 初始化链表 */
    doubleLinkListInit(&list);

    
#if 1
    int buffer[BUFFER_SIZE] = {1, 2, 3};
    /* 插入数据 - 头插 */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }

    /* 插入数据 - 尾插 */
    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        doubleLinkListTailInsert(list, (void *)&buffer[idx]);
    }
    
    /* 获取链表的长度 */
    int size = 0;
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);

    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    /* 在指定位置插入元素 */
    int insertNum = 777;
    doubleLinkListAppointPosInsert(list, 3, &insertNum);
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    /* 删除指定位置的元素 */
    doubleLinkListDelAppointPos(list, 0);
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    /* 删除指定位置的元素 */
    doubleLinkListDelAppointPos(list, 2);
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    doubleLinkListTailDel(list);//尾删有问题
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    doubleLinkListHeadDel(list);
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");

    printf("==================\n");
    /* 删除指定的值 */
    int delNum = 1;
    doubleLinkListDelAppointData(list, (void *)&delNum, compareData);
    doubleLinkListGetLength(list, &size);
    printf("size:%d\n", size);
    /* 遍历 */
    doubleLinkListForeach(list, printBasicData);
    printf("\n");
   
    /* 释放链表 */
    doubleLinkListDestroy(list);
#elif 0
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for (int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, (void *)&buffer[idx]);
    }
    
    /* 获取链表的长度 */
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);

    /* 遍历 */
    LinkListForeach(list, printStruct);
#endif
    return 0;
}