/*************************************************************************
	> File Name: DicesProbability.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月16日 星期一 23时42分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int g_maxValue = 6;

void Probability(int original,int current,int sum,int *pProbabilities)
{
    if( current == 1 )
        pProbabilities[sum-original]++;
    else
        for(int i= 1;i<g_maxValue;i++)
    {
        Probability(original,current-1,i+sum,pProbabilities);
    }
}

void Probability(int number,int *pProbabilities)
{
    for(int i=1;i<g_maxValue;i++)
    {
        Probability(number,number,i,pProbabilities);
    }

}

// 解法一：基于递归求骰子的点数，时间效率不够高


void PrintProbabbility(int number)
{
    if(number < 1)
        return;
    
    int maxSum = number * g_maxValue;
    int *pProbabilities = new int[maxSum - number + 1];

    for(int i=number;i<=maxSum;i++)
        pProbabilities[i-number] = 0;

    Probability(number,pProbabilities);

    int total = pow((double)g_maxValue,number);
    
    for(int i = number;i<=maxSum;i++)
    {
        double ratio = (double) pProbabilities[i-number] / total;
        printf("%d: %e\n",i,ratio);
    }
    
    delete [] pProbabilities;
    pProbabilities = NULL;
}

// 解法二：基于循环求骰子点数，时间性能好

void PrintProbabbility1(int number)
{
   if(number<1) 
        return;
    
    int *pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number +1];
    pProbabilities[1] = new int[g_maxValue * number +1];

    for(int i = 0;i<g_maxValue;i++)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
    
    int flag = 0;
    for(int i = 1;i<g_maxValue;i++)
        pProbabilities[flag][i] = 1;
    for(int k =2;k<= number;k++)
    {
        for(int i = 0;i<k;i++)
            pProbabilities[1-flag][i] = 0;

        for(int i = k;i<= g_maxValue;i++)
        {
           pProbabilities[1-flag][i] = 0;

            for(int j = 1;j<=i && j<= g_maxValue;j++)
                pProbabilities[1-flag][i] += pProbabilities[flag][i-j];
        }

        flag = 1- flag;
    }

    double total = pow((double)g_maxValue,number);
    for(int i=0;i<=g_maxValue;i++)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d:%e\n",i,ratio);
    }

    delete []pProbabilities[0];
    pProbabilities[0] = NULL;
    
    delete []pProbabilities[1];
    pProbabilities[1] = NULL;
}


// 测试用例

void test()
{
   int n,s;

    //printf("请输入骰子的个数 n 以及骰子的总和数 s :\n");
    scanf("%d",&n);
    
    printf("方法一：\n");
    PrintProbabbility(n);

    printf("方法二：\n");
    PrintProbabbility1(n);

}

int main(void)
{
    test();
    return 0;
}
