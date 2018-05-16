/*************************************************************************
	> File Name: StackPushPopOrder.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月27日 星期二 11时17分23秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

bool isPopOrder(const int* push,const int *pop,int  length)
{
    bool isPossible = false;
    if( push != NULL && pop != NULL && length>0)
    {

        int i = 0;      // i 用来记录栈的压入序列
        int j = 0;      // j 用来记录栈的弹出序列

        stack<int> s;

        // 从入栈的元素序列诸逐个检查弹出栈的序列
        while( j<length )
        {
            // 当辅助栈的元素不是要弹出的元素
            // 先压入一些数字入栈

            // 如果辅助栈为空或者辅助栈的栈顶元素和弹出序列元素不相等
            while(s.empty() || s.top() != pop[j])
            {
                // 如果所有数字都压入辅助栈了，退出循环
                if(i >length -1)
                     break;

                s.push(push[i]);
                i++;
            }

            // 如果辅助栈中的栈顶元素和弹出序列中的栈顶元素不同，则直接返回 退出循环 
            if(s.top() != pop[j])
                break;

            // 如果辅助栈中的栈顶元素和弹出序列元素相同，则弹出序列下标后移动
            s.pop();
            j++;
        }

        if(s.empty()  &&  j == length)
        {
            isPossible = true;    
        }
    }
    return isPossible;
}

// 测试用例

void test()
{
    int length = 5;
    int push[] = { 1, 2, 3, 4, 5  };
    int pop[] = { 4, 3, 5, 1, 2  };
    int pop1[] = { 4, 5, 3,2, 1  };
    
    bool res = isPopOrder(push,pop,length);
    if(res)
    {
        printf("栈的压入、弹出序列相同!\n");
    }
    else
    {
        printf("栈的压入、弹出序列不相同!\n");
    }
}


int main(void)
{
    test();
    return 0;
}
