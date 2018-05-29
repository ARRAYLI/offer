/*************************************************************************
	> File Name: AddTwoNumbers.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月24日 星期二 13时44分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 加法运算

int Add(int num1,int num2)
{
    int sum,carry;

    while(num2 != 0)
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) <<1;
        num1 = sum;
        num2 = carry;
    }
    return num1;
}

// 不使用新变量，交换两个变量的值

// 方法一：加减法交换数值

void Swap1(int *num1,int *num2)
{
   *num1 = *num1 + *num2;
    *num2 = *num1 - *num2;
    *num1 = *num1 - *num2;
}

// 方法二： 位运算

void Swap2(int *num1,int *num2)
{
    int a = *num1;
    int b = *num2;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    *num1 = a;
    *num2 = b;
}

// 测试用例：

void test()
{
    int num1,num2;
    printf("请输入两个整数：\n");
    scanf("%d%d",&num1,&num2);
    
    int ret = Add(num1,num2);
    
    printf("%d + %d = %d\n",num1,num2,ret);

    Swap1(&num1,&num2);
    printf("交换后的结果是：num1 = %d,num2 = %d\n",num1,num2);
    Swap2(&num1,&num2);
    printf("交换后的结果是：num1 = %d,num2 = %d\n",num1,num2);
}


int main(void)
{
   test();

    return 0;
}
