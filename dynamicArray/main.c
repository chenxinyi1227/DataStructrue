#include "dynamicArray.h"
#include <stdio.h>
#include <string.h>

#define BUFFER_SZIE 20
#define DEFAULT_NUM 5

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

void printfArray(dynamicArray array)
{
    int size = 0;
    int capacity = 0;
    dynamicArrayGetSize(&array, &size);
    dynamicArrayGetCapacity(&array, &capacity);
    printf("size:%d\n", size);
    printf("capacity:%d\n", capacity);
    int *val = NULL;
    for(int idx= 0 ; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val:%d\t", *val);
    }
    printf("\n"); 
}

int compareData(void *arg1, void *arg2)
{
    int num1 = *(int *)arg1;
    int num2 = *(int *)arg2;

    return num1 == num2 ? 1 : 0;
}
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
        for(int idx = 0; idx < DEFAULT_NUM; idx++)
        {
            dynamicArrayInsertData(&array, idx);
        } 
    }
    /* 模块化 */
    { 
        /* 获取动态数组的大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size:%d\n", size);
        int capacity = 0;
        dynamicArrayGetCapacity(&array, &capacity);
        printf("capacity:%d\n", capacity);
    
        int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
            dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val:%d\t", val);
        }
        printf("\n");
    }

    {
        /* 删除指定位置的元素 */
        int pos = 0;
        dynamicArrayDeleteAppointPosData(&array, pos);

        /* 获取动态数组大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size:%d\n", size);
        int capacity = 0;
        dynamicArrayGetCapacity(&array, &capacity);
        printf("capacity:%d\n", capacity);

        int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
            dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val:%d\t", val);
        }
        printf("\n");

       
    }
        
    {
        /* 更改指定位置的元素 */
        int pos = 0;
        ELEMENTTYPE num1 = 66;
        dynamicArrayModifyAppointPosData(&array, pos, num1);

        /* 获取动态数组大小 */
        int size = 0;
        dynamicArrayGetSize(&array, &size);
        printf("size:%d\n", size);

        int val = 0;
        for(int idx = 0; idx < size; idx++)
        {
            dynamicArrayGetAppointPosVal(&array, idx, &val);
            printf("val:%d\t", val);
        }
        printf("\n");
    }

    {
        /* 获取指定位置的元素 */
        int pos = 2;
        int pval = 0;
        dynamicArrayGetAppointPosVal(&array, pos, &pval);
        printf("pos:%d\tpval:%d\n", pos, pval);
    }


#elif 0
    int buffer[BUFFER_SZIE] = {1, 2, 3, 4, 5};
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        /* 插入数据 */
        dynamicArrayInsertData(&array, (void *)&buffer[idx]); 
    }

    {
        printfArray(array);
    }
    
    {
        /* 删除指定位置的数据 */
        int pos = 1;
        dynamicArrayDeleteAppointPosData(&array, pos);
        printfArray(array);
    }

    {
        /* 修改指定位置的数据 */
        int pos = 0;
        int pval = 88;
        dynamicArrayModifyAppointPosData(&array, pos, &pval);
        printfArray(array);
    }

    {
        /* 获取指定位置的元素 */
        int pos = 1;
        int *pval = array.data[0];
        dynamicArrayGetAppointPosVal(&array, pos,(void *) &pval);
        printf("pos:%d\tpval:%d\n", pos, *pval);
    }
#elif 0 
    int idx = 0;
    for(idx; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&idx);
    }

    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n",size);

    int *val = NULL;
    for(int idx= 0 ; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&val);
        printf("val:%d\n", *val);
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

    // dynamicArrayInsertData(&array, (void *)(&stu1));
    // dynamicArrayInsertData(&array, (void *)(&stu2));
    // dynamicArrayInsertData(&array, (void *)(&stu3));

    stuInfo buffer[DEFAULT_NUM] = {stu1, stu2, stu3};
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, (void *)&buffer[idx]);
    }
 
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);

    stuInfo *info = NULL;  //二级指针 
   // memset(&info, 0, sizeof(info));
    for(int idx = 0; idx < DEFAULT_NUM; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, (void *)&info);
        printf("info.age:%d\tinfo.sex:%c\n", info->age, info->sex);
    }
#endif
    return 0;
}