/*************************************************************************
	> File Name: StringPermutation.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月01日 星期日 14时45分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;


void Permutation(char *pStr,char *pBegin)
{
    if(*pBegin == '\0')
    {
        printf("%s\n",pStr);
    }
    else
    {
        for(char *pCh = pBegin;*pCh != '\0';pCh++)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;

            Permutation(pStr,pBegin+1);
            temp = *pCh;
            *pCh= *pBegin;
            *pBegin = temp;
        }

    }
}


void Permutation(char *pStr)
{
    if(pStr == NULL) 
        return;

    Permutation(pStr,pStr);
}

// 测试用例

void test()
{
    char str[128] = "";
    
    scanf("%s",str);
    
    Permutation(str);

}

int main(void)
{
    test();

    return 0;
}
