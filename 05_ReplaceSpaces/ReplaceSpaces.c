/*************************************************************************
	> File Name: ReplaceSpaces.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月12日 星期一 13时52分33秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
using namespace std;

#define MAX_LEN 256

void ReplaceSpaces(char str[],int length)
{
    if( str == NULL || length <=0 )
        return;

   int numSpaces = 0; 
    int oldLen = 0;
   int i = 0;
    
    // 查找空格数
    while(str[i] != '\0')
    {
        oldLen++;
       if(str[i] == ' ') 
            numSpaces++;
        i++;
    }
    
    // 求出把空格转换成 %20 后的字符串数组所占的总长度
    int newLen = oldLen + numSpaces*2;

    // 如果转换后的数组总长度大于数组的总长度，退出程序
    
    if(newLen > length)
        return;

    int indexOfOld = oldLen;    // 定义指向旧数组的尾部元素下标
    int indexOfNew = newLen;    // 定义指向新数组的尾部元素下标

    while(indexOfNew >=0 && indexOfNew > indexOfOld)
    {
        if(str[indexOfOld] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOld];
        }
        --indexOfOld;
    }
}

int main(void)
{
   char str[MAX_LEN] = {0};
    char str1[MAX_LEN] = {0};
    char *ptr = NULL;
    strcpy(str1,"ABCDE");

    strcpy(str,"  We are    happy .");
    
    printf("str = %s\n",str);
    
    ReplaceSpaces(str,MAX_LEN);
    
    printf("str = %s\n",str);

printf("str1 = %s\n",str1);
    
    ReplaceSpaces(str,MAX_LEN);
    
    printf("str1 = %s\n",str1);

    printf("ptr = %s\n",ptr);
    
    ReplaceSpaces(ptr,MAX_LEN);
    
    printf("ptr = %s\n",ptr);



    return 0;
}
