/*************************************************************************
	> File Name: NumberOf1InBinary.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月18日 星期日 03时34分17秒
 ************************************************************************/

#include<stdio.h>

// 可能引起死循环的解法
// 如果输入负数的话，就会产生死循环
int NumberOf1_1(int n)
{
    int count = 0;
    while(n)
    {
        if( n & 1 )
        count++;
        n = n >> 1;
    }
    return count;
}

// 常规解法

int NumberOf1_2(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if( n & flag )
            count++;
        flag = flag << 1;
    }    
    return count;
}

// 能给面试管带来惊喜的解法

int NumberOf1_3(int n)
{
    int count = 0;
    while(n)
    {
        ++count;

        n = (n-1) & n;
    }    
    return count;
}

int main(void)
{
    int n;
    printf("请输入一个数字：\n");
   
    scanf("%d",&n);
    
   int  res = NumberOf1_2(n);
    printf("res = %d\n",res);
   
    res = NumberOf1_3(n);
    printf("res = %d\n",res);
    
   res = NumberOf1_1(n);
    printf("res = %d\n",res);
   return 0; 
}
