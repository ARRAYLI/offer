/*************************************************************************
	> File Name: UglyNumber.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年05月06日 星期日 10时11分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 解法一：逐个判断每个整数是不是抽数的解法，直观但不够高效

bool IsUgly(int number)
{
    while( number % 2 == 0 )
        number /= 2;

    while( number % 3 == 0 )
        number /= 3;

    while( number % 5 == 0 )
        number /= 5;

    return (number == 1) ? true:false;
}

int GetUglyNumber(int index)
{
    if( index <= 0 )    
    {
        return 0;
    }
    
    int number = 0;
    int uglyFound = 0;

    while(uglyFound < index)
    {
       ++number; 
        if( IsUgly(number) )
        {
            ++uglyFound;
        }
    }
    
    return number;
}

// 解法二：创建数组保存已经找到的丑数，用时间换空间

// 获取三个数中最小的数字
int Min(int num1,int num2,int num3)
{
    int min = num1 < num2 ? num1:num2;
    min = min < num3 ? min:num3;
    return min;
}

int GetUglyNumber1(int index)
{
    if(index <= 0)
        return 0;

    int *pUglyNumbers = new int[index];
    for(int i=0;i<index;i++)
    {
        pUglyNumbers[i] = 0;
    }
    pUglyNumbers[0] = 1;
    
    int nextUglyIndex = 1;

    int *pMultiply2 = pUglyNumbers;
    int *pMultiply3 = pUglyNumbers;
    int *pMultiply5 = pUglyNumbers;

    while(nextUglyIndex < index)
    {
       int min = Min(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5); 

        pUglyNumbers[nextUglyIndex] = min;
    
        //printf("*pMultiply2 = %d,*pMultiply3 = %d,*pMultiply5 = %d\n",*pMultiply2,*pMultiply3,*pMultiply5);
        //printf("min = %d,pUglyNumbers[nextUglyIndex] = %d\n",min,pUglyNumbers[nextUglyIndex]);
        while( *pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex] )
            ++pMultiply2;

        while( *pMultiply3*3 <= pUglyNumbers[nextUglyIndex] )
            ++pMultiply3;
        
        while( *pMultiply5*5 <= pUglyNumbers[nextUglyIndex] )
            ++pMultiply5;

        ++nextUglyIndex;
    }

    int ugly = pUglyNumbers[nextUglyIndex-1];
    delete  []pUglyNumbers;
    pUglyNumbers = NULL;
    return ugly;
}

// 测试用例

void test()
{
    int index;
    printf("请输入 index: \n");
    scanf("%d",&index);

    printf("解法一：\n");
    int ret  = GetUglyNumber(index);
    if( ret )
        printf("第 %d 个丑数是: %d\n",index,ret);
    else
        printf("程序出错!\n");

    printf("解法一：\n");
    
    ret  = GetUglyNumber1(index);
    if( ret )
        printf("第 %d 个丑数是: %d\n",index,ret);
    else
        printf("程序出错!\n");


}


int main(void)
{
    test();
    return 0;
}
