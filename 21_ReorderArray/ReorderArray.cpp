/*************************************************************************
	> File Name: ReorderArray.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 22时38分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 只完成基本功能的解法，仅适用于初级程序员

void result(int *arr,int len)
{
    if( arr == NULL || len<= 0 )
        return;
   
    int i,j;
    for(i = 0;i<len;i++)
    {
        // 判断 arr[i] 是否是奇数
        // 如果是偶数的话，所有数字向前移动一个位置，把 arr[i]  放在数组的最后面
        if((arr[i] & 0x1) == 0)
        {
            int temp = arr[i];
            for(j = i;j<len-1;j++)
            {
                arr[j] = arr[j+1];
            }
            // 最后把 temp 放到数组的后面
            arr[j] = temp;
        }

    }
}

// 进阶算法

void ReorderOddEven(int *pData,int length)
{
    if( pData == NULL || length == 0 )
        return;
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    
    while(pBegin<pEnd)
    {
       // 向后移动，直到他指向偶数
        while( pBegin<pEnd && (*pBegin & 0x1) != 0 )
            pBegin++; 

       // 向前移动，直到他指向奇数
        while( pBegin<pEnd && (*pBegin & 0x1) == 0 )
            pEnd--;

        if(pBegin<pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;

        }
    }

}

// 考虑扩展，能秒杀 Offer
// 使用函数指针来实现不同需求
void ReorderOddEven(int *pData,int length,bool (*func)(int))
{
   if( pData == NULL || length == 0 ) 
        return;

    int *pBegin = pData;
    int *pEnd = pData + length -1;

    while(pBegin < pEnd)
    {
       while( pBegin< pEnd && !func(*pBegin) )
            pBegin++;
       
        while(pBegin<pEnd && func(*pEnd))
            pEnd--; 

        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}

bool isEven(int num)
{
    return ((num & 0x1) == 0);
}

void print(int *arr,int len)
{
   for(int i =0;i<len;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}


int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(arr) / sizeof(arr[0]);

    print(arr,len);
    result(arr,len); 
    print(arr,len);

    ReorderOddEven(arr,len);
    print(arr,len);

    return 0;
}
