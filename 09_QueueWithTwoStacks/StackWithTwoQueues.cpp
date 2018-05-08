/*************************************************************************
> File Name: StackWithTwoQueues.cpp
> Author:    arrayli
> Mail:      1374367549@qq.com
> Created Time: 2018年03月15日 星期四 04时42分43秒
************************************************************************/

/* 用两个队列实现一个栈  */


#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;

template <typename T> class CStack
{
public:
    CStack();
    ~CStack();
    void appendTail(const T &node);
    T deleteHead();
private:
    queue<T> queue1; 
    queue<T> queue2; 
};

template <typename T> CStack<T>::CStack()
{

}

template <typename T> CStack<T>::~CStack()
{

}

// 插入元素
template <typename T> void CStack<T>::appendTail(const T& node)
{
    if( queue1.size()>0 && queue2.size()>0 )
    {
        // 异常情况
        return; 
    }

    if(queue1.size() == 0)
    {
        // 把队列中的第一个元素放入到 queue2 中
        queue2.push(node);
    }
    else
    {
        // 把剩下的元素放入到 queue1中
        queue1.push(node);
    }

}

// 队列元素出对
template <typename T> T CStack<T>::deleteHead()
{
    if(queue1.size() == 0 && queue2.size()==0)
    {
        // 异常情况
    }

    T temp;
    if(queue1.size() > 0)
    {

        // 把 queue1 中的 n-1 个元素出对，然后入队到 queue2 中，剩下最后一个元素出对
        while(queue1.size()>1)
        {
            temp = queue1.front(); 
            queue1.pop();
            queue2.push(temp);
        }

        temp = queue1.front();
        queue1.pop();
    }
    else   
    {
        // 把 queue2 中的 n-1 个元素出对，然后入队到 queue1 中，剩下最后一个元素出对
        while(queue2.size()>1)
        {
            temp = queue2.front(); 
            queue2.pop();
            queue1.push(temp);
        }

        temp = queue2.front();
        queue2.pop();


    }
    return temp;       
}

// 测试用例：

void test()
{
   CStack<char> s; 
    
    s.appendTail('a');
    s.appendTail('b');
    s.appendTail('c');

    char t;
    
    t = s.deleteHead();
    printf("%c\t",t);


    t = s.deleteHead();
    printf("%c\t",t);

    t = s.deleteHead();
    printf("%c\t",t);
    t = s.deleteHead();
    printf("\n");
}



int main(void)
{
    test();

    return 0;
}
