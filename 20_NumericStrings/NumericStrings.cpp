/*************************************************************************
	> File Name: NumericStrings.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 23时19分09秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 该函数用来扫描字符串中 0 - 9 的数位
bool scanUsignedInterger(const char ** str)
{
    const char *before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    // 当 str 存在若干个 0 - 9 的数字时，返回 true
    return *str > before;
}


// 扫描 “+” 或者 “-”
bool scanInter(const char** str)
{
   if(**str == '+' || **str == '-') 
        ++(*str);

    return scanUsignedInterger(str);
}


// 数字的格式可以用 A[.[B]][e|EC] 或者 .B[e|EC] 表示，其中 A 和 C 都是整数（可以有正负号，
// 也可以没有），而 B 是一个无符号的整数

bool isNumeric(const char *str)
{
    if( str == NULL )
        return false;

    bool numeric = scanInter(&str);

    //如果出现 '.',则接下来出现小数部分
    if( *str == '.' )
    {
        // 跳过小数点字符,向后移动一个字符
       ++str; 
        
        // 下面一行代码使用 || 的原因
        // 1.小数可以没有整数部分，如: .123 等于 0.123
        // 2.小数点后面可以没有数字，如: 233. 等于 233.0
        // 3.当然，小数点前面和后面都可以有数字，如 233.666
    
        numeric =  scanUsignedInterger(&str) || numeric;

    }

    // 如果出现 'e' 或者 'E'，则接下来的数字是指数部分
    
    if( *str == 'e' || *str == 'E' )
    {
        // 跳过字符 'e' 或者 'E',向后移动一个字符
        ++str;

        // 下面一行代码使用 && 的原因
        // 1.当 e 或 E 前面没有数字时，整个字符串不能表示数字，如: .e1、.e2;
        // 2.当 e 或 E 后面没有数字时，整个字符串不能表示数字，如: 12e、12e+5.4

        numeric = numeric && scanUsignedInterger(&str);
    }

    // 最后判断是否遍历到了字符串数组的尾部
    return numeric && (*str == '\0');
}



int main(void)
{
    char str[100] = {0};
   
    while(scanf("%s",str) != 0)
    {
        bool res =  isNumeric(str);
        if(res)
        {
            printf("%s 是一个数值\n",str);
        }
        else
        {

            printf("%s 不是一个数值\n",str);
        }
    }
    return 0;
}
