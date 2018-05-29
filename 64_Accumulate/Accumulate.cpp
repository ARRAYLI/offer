/*************************************************************************
	> File Name: Accumulate.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月22日 星期日 12时04分51秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 解法一：利用构造函数求解
// 解题思想：通过创建对象来实现对数字的累加，缺点数字不能太大，否则会消耗大量的资源

class Temp 
{
public:
    Temp()
    {
        ++N;
        sum += N;
    }

    static void Rest()
    {
       N = 0;
        sum =0;
    }

    static int GetSum()
    {
       return sum; 
    }
private:
    static int N;
    static int sum;
};

int Temp::N = 0;
int Temp::sum = 0;

int Sum_Solution1(int n)
{
    Temp::Rest();
    Temp *a = new Temp[n];
    delete []a;
    a = NULL;

    return Temp::GetSum();
}

// 测试用例1

void test1()
{
     int n;
    printf("请输入数字 n：\n");
    scanf("%d",&n);
    
    int ret = Sum_Solution1(n);
    printf("1+2+.......+n = %d\n",ret);   

}

// 解法二：利用虚函数求解
// 解题思想：通过虚函数来实现基类是递归函数的出口，派生类实现函数的递归
class A;
A* array[2];

class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B:public A
{
public:    
    virtual unsigned int Sum(unsigned int n)
    {
        return array[!!n]->Sum(n-1)+n;
    }
};

int Sum_Solution2(int n)
{
    A a;
    B b;
    array[0] = &a;
    array[1] = &b;

    int value = array[1]->Sum(n);
    printf("%d\n",value);
    return value;
}

// 测试用例二：

void test2()
{
     int n;
    printf("请输入数字 n：\n");
    scanf("%d",&n);
    
    int ret = Sum_Solution2(n);
    printf("1+2+.......+n = %d\n",ret);   
}

// 解法三： 利用函数指针来求解

typedef unsigned int(*fun)(unsigned int);

// 递归出口
unsigned int Solution3_Teminator(unsigned int n)
{
    return 0;
}

// 递归处理程序
unsigned int Sum_Solution3(unsigned int n)
{
    static fun f[2] = {Solution3_Teminator,Sum_Solution3};

   return n+f[!!n](n-1);
}

// 测试用3：

void test3()
{
    int n;
    printf("请输入数字 n：\n");
    scanf("%d",&n);

    int ret = Sum_Solution3(n);
    printf("1+2+.......+n = %d\n",ret);   

}

// 解法四：利用模板类型求解

template<unsigned int n>struct Sum_Solution4
{
    enum Value{ N = Sum_Solution4<n-1>::N+n }; 
};

template<>struct Sum_Solution4<1>
{
   enum Value { N = 1}; 
};

// 测试用例四：
void test4()
{
    int ret = Sum_Solution4<10>::N;
    printf("1+2+.......+n = %d\n",ret);   
}

int main(void)
{
    test1();
    test2();
    test3();
    test4();
    return 0;
}
