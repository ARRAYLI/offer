/*************************************************************************
	> File Name: MinNumberInRotatedAray.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月15日 星期四 07时10分14秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int MinInOrder(int *numbers,int index1,int index2);

// 解法二
// 二分法查找
int Min(int *numbers,int length)
{
    if(numbers == NULL || length<=0)
    {
        printf("\n");
        return -1;
    }
    
    int index1 = 0;
    int index2 = length-1;
    int indexMid = index1;
    
    while(numbers[index1] >= numbers[index2])
    {
        // 如果 index1 和 index2 指向相邻的两个数，则 index1 指向第一个递增数组的最后一个数字， index2 指向第二个
        // 子数组的第一个数字，特就是数组中的最小数字。

       if(index2-index1 == 1)
        {
            indexMid = index2;
            break;
        }

        // 缩小查找范围
        indexMid = (index1 + index2) / 2;
       
        // 如果下标为 index1 、index2、indexMid 指向的三个数字相等，则只能顺序查找
        if(numbers[index1] == numbers[index2] && numbers[index2] == numbers[indexMid])
        {
            return MinInOrder(numbers,index1,index2);
        }
        // 说明中间下标 indexMid 还在第一个数组中
        if(numbers[indexMid] >= numbers[index1])
        {
            index1 = indexMid;
        }
        else if(numbers[indexMid] <= numbers[index1])
        {
           index2 = indexMid; 
        }
    }

    return numbers[indexMid];
}

// 顺序查找

int MinInOrder(int *numbers,int index1,int index2)
{
   int result = numbers[index1];
    
    for(int i = index1+1;i<= index2;i++)
    {
        if(result>numbers[i])
        result = numbers[i];
    }

    return result;
}


int main(void)
{
    int res,len;    
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    len = sizeof(array1) / sizeof(array1[0]);
    res = Min(array1,len);
    printf("res = %d\n",res);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    len = sizeof(array2) / sizeof(array2[0]);
    res = Min(array2,len);
    printf("res = %d\n",res);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    len = sizeof(array3) / sizeof(array3[0]);
    res = Min(array3,len);
    printf("res = %d\n",res);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    len = sizeof(array4) / sizeof(array4[0]);
    res = Min(array4,len);
    printf("res = %d\n",res);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    len = sizeof(array5) / sizeof(array5[0]);
    res = Min(array5,len);
    printf("res = %d\n",res);

    // 数组中只有一个数字
    int array6[] = { 2 };
    len = sizeof(array6) / sizeof(array6[0]);
    res = Min(array6,len);
    printf("res = %d\n",res);

    // 输入nullptr
    res = Min(NULL,0);
    printf("res = %d\n",res);
    return 0;
}

#if 0
#include<iostream>
#include<stdio.h>
using namespace std;

// 解法一
// 二分法查找
int Min(int *numbers,int length)
{
    if(numbers == NULL || length<=0)
    {
        printf("\n");
        return -1;
    }
    
    int index1 = 0;
    int index2 = length-1;
    int indexMid = index1;
    
    while(numbers[index1] >= numbers[index2])
    {
        // 如果 index1 和 index2 指向相邻的两个数，则 index1 指向第一个递增数组的最后一个数字， index2 指向第二个
        // 子数组的第一个数字，特就是数组中的最小数字。

       if(index2-index1 == 1)
        {
            indexMid = index2;
            break;
        }

        // 缩小查找范围
        indexMid = (index1 + index2) / 2;
        // 说明中间下标 indexMid 还在第一个数组中
        if(numbers[indexMid] >= numbers[index1])
        {
            index1 = indexMid;
        }
        else if(numbers[indexMid] <= numbers[index1])
        {
           index2 = indexMid; 
        }
    }

    return numbers[indexMid];
}


int main(void)
{
    int res,len;    
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    len = sizeof(array1) / sizeof(array1[0]);
    res = Min(array1,len);
    printf("res = %d\n",res);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    len = sizeof(array2) / sizeof(array2[0]);
    res = Min(array2,len);
    printf("res = %d\n",res);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    len = sizeof(array3) / sizeof(array3[0]);
    res = Min(array3,len);
    printf("res = %d\n",res);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    len = sizeof(array4) / sizeof(array4[0]);
    res = Min(array4,len);
    printf("res = %d\n",res);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    len = sizeof(array5) / sizeof(array5[0]);
    res = Min(array5,len);
    printf("res = %d\n",res);

    // 数组中只有一个数字
    int array6[] = { 2 };
    len = sizeof(array6) / sizeof(array6[0]);
    res = Min(array6,len);
    printf("res = %d\n",res);

    // 输入nullptr
    res = Min(NULL,0);
    printf("res = %d\n",res);
    return 0;
}
#endif
