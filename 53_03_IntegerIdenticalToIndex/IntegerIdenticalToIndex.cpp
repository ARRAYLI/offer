/*************************************************************************
	> File Name: IntegerIdenticalToIndex.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月11日 星期三 20时02分39秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int GetNumberSameAsIndex(int *numbers,int length)
{
    if(numbers == NULL || length<0)
        return -1;
    
    int left = 0;
    int right = length - 1;
    
    while(left <= length)
    {
        int middle = (left + right) / 2;
        if( numbers[middle] == middle )  
            return middle;
        else if(numbers[middle] > middle)
            right = middle -1 ;
        else
            left = middle + 1;
    }
    
    return -1;
}

// 测试用例

void test()
{
    int data[] = {-3,-1,1,3,5};
    
    int len = sizeof(data) / sizeof(data[0]);

    int ret = GetNumberSameAsIndex(data,len);
    
    if( ret == -1 )
        return;
    
    else
        printf("数组中数字和下标相等的元素是：%d\n",ret); 
}

int main()
{
    test();
    return 0;
}
