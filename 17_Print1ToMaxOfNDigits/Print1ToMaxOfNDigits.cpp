/*************************************************************************
	> File Name: Print1ToMaxOfNDigits.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 10时40分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

// 打印字符表示的数字

void PrintNum(char *num)
{
    int i = 0;
    while(num[i] == '0')
        i++;

    puts(num+i);
}

// 递归设置从 index 位往右的个位数字，并打出来
void RecusionPrint1ToN(char *num,int len,int index)
{
    if(index == len)
    {
        PrintNum(num);
        return;
    }
    int i;
    for(i=0;i<10;i++)
    {
        num[index] = i+'0';
        RecusionPrint1ToN(num,len,index+1);
    }
}


void Print1ToMaxN(int n)
{
    if(n<=0)
        return;
    
    char *num = new char[n];
    if( num == NULL ) 
    {
        printf("new char failed!\n");
        return;
    }
    
    // 给每个字节初始化为 0

    memset(num,'0',sizeof(char)*n);
    num[n] = '\0';

    // 全部打出来

   RecusionPrint1ToN(num,n,0); 

    delete []num;
    num = NULL;
}


int main(void)
{
    int n;
    scanf("%d",&n);
    Print1ToMaxN(n);
    return 0;
}
