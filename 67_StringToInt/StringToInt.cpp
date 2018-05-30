/*************************************************************************
	> File Name: AtoI.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月24日 星期二 18时26分25秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// 使用枚举类型，来区分是空字符串是否有效
enum status {kValid=0,KInValid};

// 使用全局变量来区分字符串数组是否有效
int g_Status = kValid;

int StringToIntCore(const char *str,bool minus)
{
    long long num = 0;

    while(*str != '\0')
    {
       if(*str >= '0' && *str <= '9') 
        {
            int flag = minus ? -1:1; 

            num = num*10+flag*(*str - '0');
            
            // 考虑是否会溢出
            if( (!minus && num > 0x7FFFFFFF) || (minus && (signed int)num < 0x80000000))
            {
                num = 0;
                break;
            }
            str++;
        }
        else
        {
           num = 0;
            break;
        }

    }
    
    if(*str == '\0')
    {
        g_Status = kValid;
    }
   
    return num;
}


int StringToInt(const char* str)
{
    g_Status = KInValid;
    // 用来保存字符串转换成数字的结果
   long long num = 0; 
    
    if( str != NULL && *str != '\0' )
    {
        // 使用 Bool 变量来确认是否有负号或者正号
        bool minus = false;        
        if( *str == '+' )
            str++;
        else if( *str == '-' )
        {
            str++;
            minus = true;
        }
        if(*str != '\0')
        {
           num = StringToIntCore(str,minus); 
        }
    
    }
    return (int)num;
}

// 测试用例

void test()
{
    int ret = StringToInt("");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    ret = StringToInt(NULL);    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    ret = StringToInt("123");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    ret = StringToInt("123");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    ret = StringToInt("-123456");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    ret = StringToInt("123456");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);

    g_Status =  kValid;
    ret = StringToInt("dasda1234");    
    if( g_Status == KInValid && ret == 0)
        printf("无效的输入\n");
    else
        printf("%d\n",ret);
}

int main()
{
   // int ret = StringToInt("-123");
    //printf("%d\n",ret);
    test();
    return 0; 
}
