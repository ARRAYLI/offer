/*************************************************************************
	> File Name: DigitsInSequence.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月08日 星期日 18时37分50秒
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<stdio.h>

using namespace std;

// 获取 m 位数字共有多少个
int countAtOfInterges(int digits)
{
    if(digits == 1)
        return 10;
    int count = (int)pow(10,digits - 1);
    
    return 9*count;
}

// 获取第一个 m 位数字
int beginNumber(int digits)
{
    if(digits == 1)
        return 0;
    
    return pow(10,digits-1);
}

// 当我们知道要找的那一位数字位于某 m 位数之中后，就可以用如下函数找出那一位数字
int digitAtIndex(int index,int digits)
{
    int number = beginNumber(digits) + index/digits;
    
    int indexFromRight = digits - index % digits;

    for(int i =1;i<indexFromRight;i++)
       number /= 10;
    
    return number % 10;
}

//  获取第 m 位数字是什么
int digitAtIndex(int index)
{
    if(index<0)
        return -1;

    int digits = 1;
    while(true)
    {
       int numbers = countAtOfInterges(digits); 
        if( index < numbers*digits )
            return digitAtIndex(index,digits);

        index -= digits * numbers;
        digits++;
    }
}

/// 测试用例

void test()
{
    int n;
    scanf("%d",&n);
    
    int res = digitAtIndex(n);
    
    printf("第 %d 位数字是 %d\n",n,res);
}

int main(void)
{
    test();
    return 0;
}
