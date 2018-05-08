/*************************************************************************
	> File Name: QueueWithTwoStacks.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月14日 星期三 23时19分03秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stack>
#include<exception>

using namespace std;

template <typename T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
   
    void appendTail(const T & node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;

};

template<typename T> CQueue<T>::CQueue(void)
{
    
}


template<typename T> CQueue<T>::~CQueue(void)
{
    
}

template<typename T> void  CQueue<T>::appendTail(const T &node)
{
    stack1.push(node); 
}
template<typename T> T CQueue<T>::deleteHead(void)
{

    if(stack2.size()<=0) 
    {
        while(stack1.size()>0)
        {
            T & data = stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }
    

    if(stack2.size() == 0)
    {
        printf("queue is empty!\n");
        T temp = (int) 1;
        return  temp;
    }
   
    T head = stack2.top();
    stack2.pop();
    return head;
}

void test()
{
    CQueue<int> q;
    
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);
    q.appendTail(4);
    
    int temp = q.deleteHead();
    
    printf("%d\t",temp);
    
    temp = q.deleteHead();
    printf("%d\t",temp);

    temp = q.deleteHead();
    printf("%d\t",temp);

    temp = q.deleteHead();
    printf("%d\t",temp);

    temp = q.deleteHead();
    printf("%d\t",temp);
}


int main(void)
{
    test();
    return 0;
}
