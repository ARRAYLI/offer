/*************************************************************************
	> File Name: QueueWithMax.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月16日 星期一 23时26分27秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<stdio.h>
using namespace std;

template<typename T> class QueueWithMax
{
public:
    QueueWithMax():currentIndex(0) 
    {

    }
    
    void push_back(T number)
    {
       while(!maximums.empty() && number >= maximums.back().number) 
            maximums.pop_back();

        InterData internalData = {number,currentIndex};
        data.push_back(internalData);
        maximums.push_back(internalData);
    }

    void pop_front()
    {
        if(maximums.empty())
        {
            printf("队列是空的!\n");
            return;
        }
        
        if(maximums.front().index == data.front().index)
            maximums.pop_front();
        
        data.pop_front();
    }

    T max() const
    {
        if(maximums.empty())        
            return NULL;
        return maximums.front().number;
    }

private:
    struct InterData
    {
       T number; 
        int index;
    };
    deque<InterData> data;
    deque<InterData> maximums;
    int currentIndex;
};

// 测试用例

void test()
{
    QueueWithMax<int> q;

    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(2);

    int expected = q.max();
    
    printf("max = %d\n",expected);
}

int main(void)
{
    test();
    return 0;
}
