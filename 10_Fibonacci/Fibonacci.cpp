/*************************************************************************
	> File Name: Fibonacci.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月15日 星期四 05时49分10秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 效率低
long long Fibonacci(int n)
{
    if( n == 0 )
        return 0;
    else if( n == 1 )
        return 1;
    else
        return Fibonacci(n-1)+Fibonacci(n-2);
}

// 解法二：

long long Fibonacci2(unsigned int n)
{
    long long FiN = 0;
    long long FibNOne = 0;
    long long FibNTwo = 1;
   
    if( n == 0 || n == 1 )
    {
       return n; 
    }


    for( unsigned int i = 2; i <= n; i++)
    {
        FiN = FibNOne + FibNTwo;
        FibNOne = FibNTwo;
        FibNTwo = FiN;
    }
    
    return FiN;
}


// 测试用例：

void test()
{
    unsigned int n;
    long long t;
    scanf("%ud",&n);
    
    t = Fibonacci2(n);

    printf("Fibonacci2(%d) = %lld\n",n,t);


    t = Fibonacci(n);

    printf("Fibonacci(%d) = %lld\n",n,t);

}


int main(void)
{
    test();
    return 0;
}
