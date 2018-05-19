/*************************************************************************
	> File Name: NumberOf1.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月03日 星期二 17时08分01秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int NumberOf1(int n)
{
   int number = 0;

    while(n)
    {
        if(n % 10 == 1)
            number++;
        n = n/10;
    }
    
    return number;
}

// 不考虑时间复杂度的解法，时间复杂度为 O(nlogn)
int NumberOf1BetweenAndN(int n)
{
    int number = 0;

    for(int i = 1;i<=n;i++)
       number += NumberOf1(i); 
    
    return number;
}

// 测试用例

void test()
{
    int n;
    scanf("%d",&n);

    int res = NumberOf1BetweenAndN(n);
    
    printf(" res = %d\n",res);
}

int PowerBasse10(int n)
{
    int result = 1;
    for(int i=0;i<n;i++)
    {
        result *= 10; 
    }

    return result;
}



int NumberOf1(const char *strN)
{
    if(!strN || *strN <'0' || *strN > '9' || *strN == '\0')
        return 0;

    int first = *strN - '0';
    unsigned int len  = static_cast<unsigned int>(strlen(strN));

    if(len == 1 && first == 0)
        return 0; 
    
    if(len == 1 && first>0)
        return 1;

    // 假设 strN是 "21345"
    // numFirstDigit 是数字 100000-19999 的第一位数字

    int numFirstDigit = 0;
    if( first>1 )
        numFirstDigit = PowerBasse10(len-1);
    else if(first == 1)
        numFirstDigit = atoi(strN+1) +1;

    int numOtherDigits = first*(len-1)*PowerBasse10(len-2);

    int numRecursive = NumberOf1(strN+1);
    
    return numFirstDigit + numOtherDigits + numRecursive;
}


// 解法二：从数字规律着手明显提高时间效率的解法，能让面试官焕然一新

int  _NumberOf1BetweenAndN(int n)
{
   if(n<=0) 
        return 0;
    
    char strN[50];
    sprintf(strN,"%d",n);
    
    return NumberOf1(strN);

}

// 测试用例

void test1()
{
     int n;
    scanf("%d",&n);

    int res = _NumberOf1BetweenAndN(n);
    
    printf(" res = %d\n",res);
}


int main(void)
{
    test1();
    //test();
    return 0;
}
