/*************************************************************************
	> File Name: GreatestSumOfSubarrays.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月03日 星期二 16时51分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

bool g_InvalidInput = false;

int FindGreatsSumOfSubArray(int  *pData,int nlen)
{
   if(pData == NULL || nlen<=0) 
    {
        g_InvalidInput = true; 
        return 0;
    }
    
    g_InvalidInput = false;

    int CurSum = 0;
    
    int nGreatestSum = 0x80000000;
   
    printf("%d\n",nGreatestSum);
    for(int i =0;i<nlen;i++)
    {
        if(CurSum<=0)
            CurSum = pData[i];
        else
           CurSum += pData[i];

        if(CurSum>nGreatestSum)
            nGreatestSum = CurSum;
    }

    return nGreatestSum;
}

// 测试用例

void test()
{
    int n;
   
    int data[] = {1,-2,3,10,-4,7,2,-5};
    int len = sizeof(data) / sizeof(data[0]);

    int res = FindGreatsSumOfSubArray(data,len);
    
    printf("res = %d\n",res);
}

int main(void)
{
    test();
    return 0;
}
