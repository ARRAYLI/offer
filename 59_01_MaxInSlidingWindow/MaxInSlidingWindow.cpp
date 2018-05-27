/*************************************************************************
	> File Name: MaxInSlidingWindow.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月16日 星期一 22时58分01秒
 ************************************************************************/

#include<iostream>
#include<deque>
#include<vector>
#include<stdio.h>
using namespace std;

vector<int> MaxInWindows(const vector<int> &num,unsigned int size)
{
    vector<int> maxInWindows;

    if(num.size() >= size && size>=1)
    {
        deque<int> index;
        for(unsigned int i = 0;i<size;i++)
        {
            while(!index.empty() && num[i] >= num[index.back()])
               index.pop_back(); 
            index.push_back(i);
        }

        for(unsigned int i = size;i<num.size();i++)
        {
            maxInWindows.push_back(num[index.front()]);

            while(!index.empty() && num[i]>= num[index.back()])
                index.pop_back();

            if(!index.empty() && index.front() <= (int)(i - size) )
                index.pop_front();

            index.push_back(i);
        }

        maxInWindows.push_back(num[index.front()]);
    }

    return maxInWindows;
}

// 测试用例：

void test()
{
    int num[] = {2,3,4,2,6,2,5,1};
   
    vector<int> v(num,num+sizeof(num)/sizeof(num[0]));
   
    unsigned int size = 3;
    vector<int> maxInWindows = MaxInWindows(v,size);
    
    vector<int>::const_iterator it = maxInWindows.begin();
    
    vector<int>::const_iterator itEnd = maxInWindows.end();
    
    for(; it != itEnd;++it)
    {
        printf("%d\t",*it);
    }
    printf("\n");
}

int main(void)
{
    test(); 
    return 0;
}
