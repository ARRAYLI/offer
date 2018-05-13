/*************************************************************************
	> File Name: RegularExpressionMatching.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 20时26分18秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

bool matchCore(char *str,char *pattren)
{
    // 表示匹配串和模式串相匹配
    if(*str == '\0' && *pattren == '\0')
        return true;
    
    // 匹配还没有匹配完，模式串完了 
    if(*str != '\0' && *pattren == '\0')
        return  false;
   
    // 如果模式串的第二个字符是 '*'
    if( *(pattren+1) == '*')
    {
       if(*pattren == *str || (*pattren == '.' && *str != '\0')) 
        {
            return matchCore(str+1,pattren+2) || matchCore(str+1,pattren) || matchCore(str,pattren+2);
        }
        else
        {
            return matchCore(str,pattren+2);
        }
    }

    if(*str == *pattren ||(*pattren == '.' && str != '\0'))
        return matchCore(str+1,pattren+1);

    return false;
}



bool match(char *str,char *pattren)
{
    if( str == NULL || pattren == NULL )
        return false;
    return matchCore(str,pattren);
}


// 测试用例

void test()
{
  char str[100] ={0};
  char pattren[100] = {0};
    
  while(scanf("%s%s",str,pattren))
    {
        bool res = match(str,pattren); 
        if(res)
        {
            printf("匹配\n");
        }
        else
        {
            printf("不匹配\n");
        }

    }
    
}

int main(void)
{
    test();
    return 0;
}
