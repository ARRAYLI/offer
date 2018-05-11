/*************************************************************************
	> File Name: Power.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 09时08分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

bool g_InvalidInput = false;

// 自以为题目简单的解法
double Power_1(double base,int exponent)
{
    double result = 1.0;
    for(int i=0;i<exponent;i++)
    {
        result *= base;
    }
    return result;
}

double PowerWithUnsignedExponent_1(double base,unsigned int exponent)
{
    double result = 1.0;
    for(int i=1;i<=exponent;i++)
    {
        result *= base;
    }
    return result;
}

double PowerWithUnsignedExponent_2(double base,unsigned int exponent)
{
    if(exponent == 0) 
        return 1;
    if(exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent_2(base,exponent>>1);
    result *= result;   
    if( (exponent & 0x1) == 1 )
        result *= base;
    return result;
}

bool equal(double num1,double num2)
{
    if((num1 - num2 > -0.0000001) && (num1-num2<0.0000001))
        return true;
    else
    return false;
}

// 全面但不够高效的解法，我们离 offer 已经很近了
double Power_2(double base,int exponent)
{
   g_InvalidInput = false; 
    if(equal(base,0.0) && exponent <0 )
    {
       g_InvalidInput = true; 
        return 0.0;
    }
    
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent <0)
        absExponent = (unsigned int)(-exponent);
  
    //double result = PowerWithUnsignedExponent_1(base,absExponent);  
    double result = PowerWithUnsignedExponent_2(base,absExponent);  
    if(exponent < 0)
        result = 1.0/result;
    return result;
}


// 测试用例 1 

void test1()
{
    double num;
    int exponent;
    while(scanf("%lf%d",&num,&exponent))
    {
       double result = Power_1(num,exponent); 
        printf("Pow_1(%lf,%d) = %lf\n",num,exponent,result);
    }

}

// 测试用例 2 

void test2()
{
    double num;
    int exponent;
    while(scanf("%lf%d",&num,&exponent))
    {
       double result = Power_2(num,exponent); 
        printf("Pow_2(%lf,%d) = %lf\n",num,exponent,result);
    }

}

// 测试用例 3 

void test3()
{
    double num;
    int exponent;
    while(scanf("%lf%d",&num,&exponent))
    {
       double result = Power_2(num,exponent); 
        printf("Pow_3(%lf,%d) = %lf\n",num,exponent,result);
    }

}
int main(void)
{
    //test1();
    //test2();
    test3();
    return 0;
}
