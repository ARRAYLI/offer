/*************************************************************************
	> File Name: TraslateNumbersToStrings.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月11日 星期三 16时52分35秒
 ************************************************************************/

#include<string.h>
#include<iostream>
#include<stdio.h>

using namespace std;

// 数字转换成字符串

char *COnvert(int number,char *str,int len)
{
    if(number <=0 || len<=0 || str == NULL)
        return NULL;

    char *address = str;
    int i = len-1;
    while(number && i>=0)
    {
       str[i] = number / 10 + '0';
        number /= 10;
        i--;
    }
   return address; 
}

int GetTranslationCount(char *str)
{
   int len = strlen(str) + 1; 
    int *counts = new int[len];
    
    int count = 0;
    for(int i = len-1;i>=0;i--)
    {
        count = 0;
        if(i<len-1)
            count = counts[i+1];
        else
            count = 1;
        
        if(i<len-1)
        {
            int digit1 = str[i] - '0';
            int digit2 = str[i+1] - '0';
            int converted = digit1*10 + digit2;

            if(converted >= 10 && converted <= 25)
            {
                if(i<len-2) 
                    count += counts[i+2];
                else
                    count += 1;
            }

        }

        counts[i] = count;
    }

    count = counts[0];
    delete [] counts;

    return count;
}


int GetTranslation(int number)
{
    if(number <0)
        return 0;
   
    char str[128] = "";

    COnvert(number,str,128);
    printf("%s\n",str);
    return GetTranslationCount(str);
}

// 测试用例

void test()
{
    int num;
    printf("请输入一个整数:\n");
    
    scanf("%d",&num);

   int count = GetTranslation(num);

    printf("总共有 %d 中翻译方法 \n",count);
}


int main()
{
    test();
    return 0;
}
