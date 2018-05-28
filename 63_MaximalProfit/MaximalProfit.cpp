/*************************************************************************
	> File Name: MaximalProfit.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月22日 星期日 11时54分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int MaxDiff(int *numbers,int length)
{
    if(numbers == NULL || length<2)
        return -1;
   
    //初始化两个数对中的最大值和最小值
    int min = numbers[0];
    int maxDiff = numbers[1] - min;
    
    for(int i=2;i<length;i++)
    {
        if(numbers[i-1] < min) 
            min = numbers[i-1];

        int currDiff = numbers[i] - min;
        if( currDiff > maxDiff )
            maxDiff = currDiff;
    }
    
    return maxDiff;
}

// 测试用例：

void test()
{
    int numbers[] = {9,11,8,5,7,12,16,14};    
    int length = sizeof(numbers) / sizeof(numbers[0]);
    
    int ret = MaxDiff(numbers,length);
    if( ret == -1 )
    {
        printf("数组不存在或数组元素小于两个\n");
    }
    else
    {
        printf("股票的最大利润是：%d\n",ret);
    }
}

int main(void)
{
    test();

    return 0;
}
