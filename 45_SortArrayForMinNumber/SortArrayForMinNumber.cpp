/*************************************************************************
	> File Name: SortArrayForMinNumber.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月08日 星期日 18时57分26秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

const int g_MaxNumberLength = 10;
char *g_StrCombine1 = new char[g_MaxNumberLength + 1];
char *g_StrCombine2 = new char[g_MaxNumberLength + 1];

int compare(const void *strNumber1,const void* strNumber2)
{

   strcpy(g_StrCombine1,*(const char**)strNumber1); 
   strcat(g_StrCombine1,*(const char**)strNumber2); 
    
    
   strcpy(g_StrCombine2,*(const char**)strNumber2); 
   strcat(g_StrCombine2,*(const char**)strNumber1); 

    return strcmp(g_StrCombine1,g_StrCombine2);
}


void PrintMinNumber(int *number,int len)
{
    if(number == NULL || len<=0)
        return;
    char** strNumber = new char*[g_MaxNumberLength+1];
    
    for(int i=0;i<g_MaxNumberLength;i++)
    {
        strNumber[i] = new char[g_MaxNumberLength+1];
        sprintf(strNumber[i],"%d",number[i]);
    }
    
    qsort(strNumber,len,sizeof(char*),compare);
    
    for(int i = 0;i<len;i++)
    {
        printf("%s\n",strNumber[i]);
    }
    
    printf("\n");

    for(int i=0;i<len;i++)
    {
        delete[] strNumber[i];
        strNumber[i] = NULL;
    } 
    
    delete[] strNumber;
    strNumber = NULL;
}

// 测试用例

void test()
{
   int number[] = {3,5,1,4,2}; 
    int len = sizeof(number) / sizeof(number[0]);
    
    PrintMinNumber(number,len);
}


int main(void)
{
    test();
    return 0;
}
