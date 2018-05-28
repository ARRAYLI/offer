/*************************************************************************
	> File Name: ContinousCards.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月19日 星期四 15时18分14秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<list>
using namespace std;

// 经典解法，用环形链表模拟

int LastRemaining(unsigned int n,unsigned int m)
{
    if(n<1||m<1) 
        return -1;
    unsigned int i = 0;

    list<int> numbers;

    for(i=0;i<n;i++)
        numbers.push_back(i);

    list<int>::iterator current = numbers.begin();
    while(numbers.size()>1)
    {
       for( i =1;i<m;i++ )
        {
            current++;
            if( current == numbers.end() )
                current = numbers.begin();
        }
        
        list<int>::iterator next = ++current;
        if(next == numbers.end())
            next = numbers.begin();

        --current;
        numbers.erase(current);
        current = next;
    }
    return *current;
}

// 创新的解法

int LastRemaining1(int n,int m)
{
    if(n<1||m<1)
        return -1;
    int last = 0;
    for(int i =2;i<=n;i++)
        last = (last+m) % i;
    return last;
}


// 测试用例：

void test()
{
    int n,m;
    printf("请输入数字 n 和 m :\n");
    scanf("%d%d",&n,&m);

    printf("解法一：\n");
    int ret = LastRemaining(n,m);
    if( ret == -1 )
        printf("输入有误!\n");
    else
        printf("最后一个数字是：%d\n",ret);

    printf("解法二：\n");
    ret = LastRemaining1(n,m);
    if( ret == -1 )
        printf("输入有误!\n");
    else
        printf("最后一个数字是：%d\n",ret);


}

int main(void)
{
    test();
    return 0;
}
