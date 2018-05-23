/*************************************************************************
	> File Name: FirstCharacterInStream.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年05月06日 星期日 14时21分36秒
 ************************************************************************/

#include<iostream>
#include<limits>
#include<stdio.h>
using namespace std;

class CharStatistics
{
public:
    CharStatistics():index(0)
    {
        for(int i=0;i<256;i++)
        {
            occurrence[i] = -1;
        }
    }
    
    void Insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;
        index++;
    }
    char FirstAppearOnce()
    {
       char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        
        for(int i=0;i<256;i++)
        {
            if(occurrence[i] >=0 && occurrence[i] <minIndex)
            {
                ch = char(i);
                minIndex = occurrence[i];
            }
        }
        return ch;
    }

private:
    int index;
    int occurrence[256];

};

// 测试用例

void test()
{
    CharStatistics chars;
    chars.Insert('g');
    chars.Insert('o');
    chars.Insert('o');
    chars.Insert('g');
    chars.Insert('l');
    chars.Insert('e');

    char c = chars.FirstAppearOnce();
    if(c != '\0')
    {
       printf("字符流中只出现一次的字符是 :%c\n",c); 
    }
    else
    {
        printf("程序出错\n");
    }
}


int main(void)
{
    test();
    return 0;
}
