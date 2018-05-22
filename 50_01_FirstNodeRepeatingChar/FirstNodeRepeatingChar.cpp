/*************************************************************************
	> File Name: FirstNodeRepeatingChar.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年05月06日 星期日 14时11分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

char FirstNotRepeartingChar(char *str)
{
    if( str == NULL )
        return '\0';
    
    const int tableSize = 256;
    unsigned int hashTable[tableSize];

    for(int i=0;i<tableSize;i++)
    {
       hashTable[i]  = 0;
    }
    
    char *pHashKey = str;
    
    while( *pHashKey != '\0' )
    {
        printf("*pHashKey = %d\n",*pHashKey);
        hashTable[*pHashKey++]++;
    }

    pHashKey = str;

    while(*pHashKey != '\0')
    {
       if(hashTable[*pHashKey] == 1) 
            return *pHashKey;            
        pHashKey++;
    }
    
    return '\0';
}

// 测试用例

void test()
{
    char str[100] = "";
    printf("请输入字符串:\n");
    scanf("%s",str);
    
    char c = FirstNotRepeartingChar(str);
    
    if(c != '\0')
        printf("第一个只出现一次的字符: %c\n",c);
    else
        printf("程序出错\n");

}

int main(void)
{
    test();
    return 0;
}
