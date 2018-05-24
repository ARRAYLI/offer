/*************************************************************************
	> File Name: NumberOfK.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月11日 星期三 18时09分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 算法思想：1.在排序数组中利用二分法找到，要查找数字。
//           2.如果找到的数字是重复数字中的第一个，则直接返回该数字的下标；若不是，则继续使用二分法直到找到要查找数字的第一个即可
//           3.在数组中，查找最后一个要查找的数字。若找到，直接返回下标。若不是，继续查找，直到找到为止
//           4.通过第一个重复数字的下标和最后一个重复数字下标，可以计算出一共有几个重复的数字 k

// 获取重复数字 k 的第一个下标

int GetFirstK(int *data,int length,int k,int start,int end)
{
    while(start <= end )
    {
        int midIndex = (start + end) /2;

        int midData = data[midIndex];

        // 如果找到重复数字 k
        if(midData == k)
        {
            // 判断它是不是第一个，如果它的下标为0 或者它的前一个数字不是 K,则证明它就是第一个；否则继续查找
            if( midIndex >0 && data[midIndex-1] != k || midIndex == 0 )        
                 return midIndex;
            else
                   end = midIndex - 1;
        }
        else if( midData  > k )
            end = midIndex-1;
        else 
            start = midIndex + 1;
    }
    //return GetFirstK(data,length,k,start,end);
}

// 获取最后一个重复的数字 k

int GetLastK(int *data,int length,int k,int start,int end)
{
    while( start <= end ) 
    {
        int midIndex = (start + end) /2;
        int midData = data[midIndex];

        // 如果找重复数字 k , 判断它是不是最后一个重复数字
        if( midData == k )
        {
            if(midIndex<length -1 && data[midIndex+1] != k || midIndex == length-1)
                return midIndex;
            else
                 start = midIndex + 1;
        }
        else if( midData > k )
        {
            end = midIndex - 1;
        }
        else
        {
            start = midIndex + 1; 
        }
    } 
}

// 根据第一个重复数字的下标和最后一个重复数字的下标来获取重复数字的个数

int GetNumberOfK(int *data,int length,int k)
{
   int number = 0;
    if( data != NULL && length>0 )
    {
        int first = GetFirstK(data,length,k,0,length-1);
        int end = GetLastK(data,length,k,0,length-1);

        printf("first = %d,end = %d\n",first,end);
        // 判断获取的第一个和最后一个重复的数字是否合法
        if( first > -1 && end > -1 )
            number = end - first + 1;

    }

    return number;
}

// 测试用例

void test()
{
    int data[] = {1,2,3,3,3,3,4,5,6,6,7,7,7,7,8,8,8};
    int len = sizeof(data) / sizeof(data[0]);

    int num;
    
    printf("请输入要查找的重复的数字:\n");
    scanf("%d",&num);
    int count = GetNumberOfK(data,len,num);
    
    printf("%d 在数组中总共有 %d 个重复的数字\n",num,count);
}

int main(void)
{
    test();
    return 0;
}
