/*************************************************************************
	> File Name: LeftRotateString.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 18时13分56秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

// 算法思想：
//          1.先把字符串的前 n 个字符翻转
//          2、然后把剩下的字符翻转
//          3、最后把整个字符串翻转

void Reverse(char *pBegin,char *pEnd)
{
    if(pBegin == NULL || pEnd == NULL)
        return;
    
    while(pBegin < pEnd)
    {
        char temp = *pBegin;        
        *pBegin = *pEnd;
        *pEnd = temp;

        pBegin++;
        pEnd--;
    }
}

char *LeftRotateString(char *pStr,int n)
{
   if(pStr != NULL) 
    {
        int nLength = strlen(pStr);
        if(nLength >0 && n>0 && n<nLength)
        {
            char *pFirstStart = pStr;
            char *pFirstEnd = pStr + n - 1;
            char *pSecondStart = pStr + n;
            char *pSecondEnd = pStr + nLength - 1;
            
            // 翻转字符串的前面 n 个字符
            Reverse(pFirstStart,pFirstEnd);
            
            // 翻转字符串的后面部分
            Reverse(pSecondStart,pSecondEnd);

            // 翻转整个字符串
            Reverse(pFirstStart,pSecondEnd);

        }
    }
    
    return pStr;
}

// 测试用例

void test()
{
    char str1[] = "abcdefg";
    int len = strlen(str1);
    char *pstr = NULL;

    pstr = LeftRotateString(str1,0);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str1,0,pstr);

    // 左旋 1 个字符
    
    char str2[] = "abcdefg";
    pstr = LeftRotateString(str2,1);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str2,1,pstr);

    // 左旋 2 个字符
    char str3[] = "abcdefg";
    pstr = LeftRotateString(str3,2);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str3,2,pstr);

    // 左旋 len-1 个字符
    char str4[] = "abcdefg";
    pstr = LeftRotateString(str4,len-1);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str4,len-1,pstr);
   
    // 左旋 len 个字符
    char str5[] = "abcdefg";
    pstr = LeftRotateString(str5,len);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str5,len,pstr);
    
    // 左旋 len+1 个字符
    char str6[] = "abcdefg";
    pstr = LeftRotateString(str6,len+1);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str6,len+1,pstr);

    // 字符串为 NULL
    pstr = LeftRotateString(NULL,0);
    if( pstr == NULL )
        printf("error\n");
    else
        printf("字符串%s 从第 %d 个字符翻转后的结果为： %s\n",str1,0,pstr);

}

int main(void)
{
    test();
    return 0;
}
