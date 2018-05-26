/*************************************************************************
	> File Name: ReverseWordsInSentence.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 16时17分07秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

// 算法思想：
//          1、先给 整个字符串逆序
//          2、然后给每个单词包括标点符号逆序,即可得到结果


void  Reverse(char *pBegin,char* pEnd)
{
   if(pBegin == NULL || pEnd == NULL) 
        return;
   
    // 字符串逆序
    while(pBegin < pEnd)
    {
       char temp = *pBegin; 
        *pBegin = *pEnd;
        *pEnd = temp;
    
        pBegin++;
        pEnd--;
    }
}

char *ReverseSentence(char *pData)
{
    printf("pData = %s\n",pData);
   if(pData == NULL) 
        return NULL;

    // 指向字符串的首元素
    char *pBegin = pData;
    // 指向字符串的尾部元素
    char *pEnd = pData;
    
    while(*pEnd != '\0')
        pEnd++;

    pEnd--;


    // 先翻转整个句子，即逆序整个句子
    Reverse(pBegin,pEnd);

    // 翻转句子中的每个单词以及标点符号

    pBegin = pEnd = pData;

    // 循环遍历字符串中的单词，并翻转
    while(*pBegin != '\0')
    {
        // 如果是空格的话，指向单词首元素的 指针和尾指针都向后移动一个字符，跳过空格
       if(*pBegin == ' ') 
        {
           pBegin++;
            pEnd++;
        }
        // 如果尾指针指向空格或者指向 '\0',则逆序单词
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
           Reverse(pBegin,--pEnd); 

            // 尾指针向后移动一个字符，继续遍历
            pEnd++;
            // 头指针指向下一个单词的第一个字符
            pBegin = pEnd;
        }
        else
            pEnd++;

    }
    printf("pData = %s\n",pData);
    return pData;
}

// 测试用例

void test()
{
    char str[] = "I am a student.";
    char *pStr = NULL; 
    pStr = ReverseSentence(str);
    if( pStr != NULL )
        printf("逆序后的结果为：%s\n",pStr);
    else
       printf("程序出错!\n"); 

    char *str1 = NULL;
    pStr = ReverseSentence(str1);
    if( pStr != NULL )
        printf("逆序后的结果为：%s\n",pStr);
    else
        printf("程序出错!\n"); 
    
    char str2[] = "beautiful";
    pStr = ReverseSentence(str2);
    if( pStr != NULL )
        printf("逆序后的结果为：%s\n",pStr);
    else
       printf("程序出错!\n");     
}

int main(void)
{
    test();
    return 0;
}
