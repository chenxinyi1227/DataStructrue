#include "doubleLinkList.h"
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
    printf("data:%d\t", data);
}

int compare(void *pvData1, void *pvData2)
{
    int num1 = *(int *)pvData1;
    int num2 = *(int *)pvData2;
    return num1 == num2 ? 0 : 1;
}

int main()
{

#if 1
    doubleLinkList *list = NULL;
    doubleLinkListInit(&list);    //初始化链表

#if 1
    int buffer[BUFFER_SIZE] = {1, 2, 3};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)//插入数据
    {
        doubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }
    int size = 0;
    doubleLinkListGetLength(list,&size);//获取链表的长度
    printf("size:%d\n", size);
    doubleLinkListForeach(list, printBasicData);

    {
        printf("\n测试按指定位置插入\n");
        int val = 4;
        doubleLinkListAppointPosInsert(list, 0, &val);//按指定位置插入
        doubleLinkListForeach(list, printBasicData);
        printf("\n测试尾插\n");
        int val1 = 7;
        doubleLinkListTailInsert(list, &val1);//尾插
        doubleLinkListForeach(list, printBasicData);
        printf("\n逆序遍历\n");
        doubleLinkListReverseForeach(list, printBasicData);
    }


    {
        int pos = 1;
        printf("\n测试指定位置%d删除\n", pos);
        doubleLinkListDelAppointPos(list, pos);//指定位置删除
        doubleLinkListForeach(list, printBasicData);
        printf("\n测试尾删\n");
        doubleLinkListTailDel(list);
        doubleLinkListForeach(list, printBasicData);
        printf("\n测试头删\n");
        doubleLinkListHeadDel(list);//头删
        doubleLinkListForeach(list, printBasicData);
        
    }

    {
        int val = 1;
        printf("\n测试链表删除指定数据:%d\n", val);
        doubleLinkListDelAppointData(list, &val, compare);
        doubleLinkListForeach(list, printBasicData);
        printf("\n");
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
        doubleLinkListHeadInsert(list, (void *)&buffer[idx]);
    }
 
     int size = 0;
    doubleLinkListGetLength(list,&size);//获取链表的长度
    printf("size:%d\n", size);

    doubleLinkListForeach(list, printStruct);      //遍历

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