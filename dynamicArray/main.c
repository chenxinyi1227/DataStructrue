#include "dynamicArray.h"
#include <stdio.h>

#define BUFFER_SZIE 20
#define DEFAULT_NUM 5

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

int main()
{
    /*静态数组
    Q1:不够灵活
    Q2：可能会浪费空间*/

    dynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array, BUFFER_SZIE);
#if 0
    /* 模块化 */
    {
        /* 插入数据 */
        dynamicArrayInsertData(&array, 3);
        for(int idx = 0; idx < DEFAULT_NUM; idx++)
        {
            dynamicArrayInsertData(&array, 21);
        } 
    }
    /* 模块化 */
    { 
        /* 获取动态数组的大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size:%d\n", size);
    }

    {
        int val = 0;
        for(int idx = 0; idx < DEFAULT_NUM; idx++)
        {
            dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val:%d\n", val);
        }
    }

    int size = 0;
    /* 删除指定位置的元素 */
    int pos = 1;
    dynamicArrayDeleteAppointPosData(&array, pos);

    /* 获取动态数组大小 */
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    int val = 0;
    for(int idx = 0; idx < size; idx++)
    {
         dynamicArrayGetAppointPosVal(&array, idx, &val);
         printf("val:%d\n", val);
    }


#else
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));
    

    stu1.age = 10;
    stu1.sex = 'm';

    stu1.age = 20;
    stu1.sex = 'f';

    stu1.age = 30;
    stu1.sex ='m';

//     dynamicArrayInsertData(&array, stu1);
//     dynamicArrayInsertData(&array, stu2);
//     dynamicArrayInsertData(&array, stu3);
// #endif
    return 0;
}