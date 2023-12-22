#include "LinkList.h"
#include <stdio.h>  
#include <string.h>

#define BUFFER_SIZE 3

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

/* 自定义打印 */
int printStruct(void *arg)
{
    stuInfo *info= (stuInfo*)arg;
    printf("age:%d\tsex:%c\n", info->age, info->sex);
}

int printBasicData(void *arg)
{
    int data = *(int *)arg;
    printf("data:%d\n", data);
}

int main()
{

#if 1

    LinkList *list = NULL;
    LinkListInit(&list);    //初始化链表

#if 1
    int buffer[BUFFER_SIZE] = {1, 2, 3};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)//插入数据
    {
        LinkListHeadInsert(list, (void *)&buffer[idx]);
    }
    int size = 0;
    LinkListGetLength(list,&size);//获取链表的长度
    printf("size:%d\n", size);
    LinkListForeach(list, printBasicData);
    printf("\n");

    {
        int pos = 1;
        LinkListDelAppointPos(list, pos);//指定位置删除
        LinkListForeach(list, printBasicData);
        printf("\n");
    }
    
    {
        LinkListTailDel(list);
        LinkListForeach(list, printBasicData);
        printf("\n");
        LinkListHeadDel(list);
        LinkListForeach(list, printBasicData);
        printf("\n");
    }

    {
        int val = 4;
        int val1 = 7;
        LinkListAppointPosInsert(list, 1, &val);//按指定位置插入
        LinkListTailInsert(list, &val1);
        LinkListForeach(list, printBasicData);
        printf("\n");
    }

    {
        LinkListDestory(list);
        LinkListForeach(list, printBasicData);

    }
#else
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));
    

    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex ='m';
    
    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, (void *)&buffer[idx]);
    }
 
     int size = 0;
    LinkListGetLength(list,&size);//获取链表的长度
    printf("size:%d\n", size);

    LinkListForeach(list, printStruct);      //遍历

//     stuInfo *info = NULL;  //二级指针 
//    // memset(&info, 0, sizeof(info));
//     for(int idx = 0; idx < BUFFER_SIZE; idx++)
//     {
//         dynamicArrayGetAppointPosVal(list, idx, (void *)&info);
//         printf("info.age:%d\tinfo.sex:%c\n", info->age, info->sex);
//     }
    #endif


#endif
   
    return 0;
}