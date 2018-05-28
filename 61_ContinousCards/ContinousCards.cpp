/*************************************************************************
	> File Name: ContinousCards.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月19日 星期四 15时18分14秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<list>
using namespace std;

int compare(const void *arg1,const void *arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}

bool isContinuous(int *numbers,int length)
{
    if( numbers == NULL || length <1 )
        return false;

    // 先把数组排序
    qsort(numbers,length,sizeof(int),compare);
   
    int numberOfZero = 0;
    int numberOfGap = 0;

    // 统计数组中 0 的个数
    for(int i =0;i<length && numbers[i] == 0;i++)
        numberOfZero++;
   
    // 统计数组中空缺总数
    int small = numberOfZero;
    int big = small+1;

    // 统计排序后的相邻数字之间的空缺总数
    while(big<length)
    {
       // 两个数字不相等，有对子，不可能是顺序
        if(numbers[small] == numbers[big])
            return false;

        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        big++;
    }

    return (numberOfGap>numberOfZero) ? false : true;
}


// 测试用例：

void test()
{
    int num1[] = {1,3,2,5,4}; 
    if(isContinuous(num1,5))
        printf("num1 中的五张扑克牌是连续的!\n");
    else
        printf("num1 中的五张扑克牌是不连续的!\n");

    int num2[] = {1,3,2,6,4};
    if(isContinuous(num2,5))
         printf("num2 中的五张扑克牌是连续的!\n");
    else
       printf("numk 中的五张扑克牌是不连续的!\n");

    int num3[] = {0,3,2,6,4};
    if(isContinuous(num3,5))
        printf("num2 中的五张扑克牌是连续的!\n");
    else
        printf("num3 中的五张扑克牌是不连续的!\n");

    int num4[] = {0,3,1,6,4};
    if(isContinuous(num4,5))
        printf("num4 中的五张扑克牌是连续的!\n");
    else
        printf("num4 中的五张扑克牌是不连续的!\n");

    int num5[] = {1,3,0,5,0};
    if(isContinuous(num5,5))
        printf("num5 中的五张扑克牌是连续的!\n");
    else
        printf("num5 中的五张扑克牌是不连续的!\n");

    int num6[] = {1,3,0,7,0};
    if(isContinuous(num6,5))
         printf("num6 中的五张扑克牌是连续的!\n");
    else
        printf("num6 中的五张扑克牌是不连续的!\n");
}

int main(void)
{
    test();
    return 0;
}
