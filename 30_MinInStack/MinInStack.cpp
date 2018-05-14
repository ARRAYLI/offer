/*************************************************************************
	> File Name: MinInStack.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月27日 星期二 10时21分02秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<assert.h>
#include<stdio.h>
using namespace std;

template<typename T> 
class StackWithMin
{

public:
    // 构造函数
    StackWithMin();
    // 析构函数
    ~StackWithMin();
    
    // 获取栈顶元素
    T & top() const;
    
    // 栈顶元素出栈
    void pop() ;

    // 元素入栈
    void push(const T &value);

    // 获取最小元素
    const T& min();

    // 判断是否为空
    bool empty() const;
    
    // 获取栈的大小
    size_t size() const;

private:
    // 辅助栈，存放所有最小的元素
    stack<T> m_min;
    // 数据栈，存放栈的所有数据
    stack<T> m_data;
};

template<typename T> 
StackWithMin<T>::StackWithMin()
{
    
}

template<typename T> 
StackWithMin<T>::~StackWithMin()
{
    
}

// 获取栈顶元素
template<typename T>
T & StackWithMin<T>::top() const
{
    return m_data.top();    
}
    
// 栈顶元素出栈
template<typename T>
void StackWithMin<T>::pop() 
{
    // 检测数据栈和辅助栈是否为空
   assert(m_data.size() > 0 && m_min.size()>0); 
    
    // 如果当前数据栈和辅助栈不为空
    // 元素栈和辅助栈弹出元素
    m_data.pop();
    m_min.pop();
}

// 元素入栈
template<typename T>
void StackWithMin<T>::push(const T &value)
{
    // 元素入栈
    m_data.push(value);
    // 如果辅助最小元素栈为空栈或者 当前入栈的 元素的值小于辅助栈中的最小元素的话，元素压入辅助栈中
    if(m_min.size() == 0 || value<m_min.top())
        m_min.push(value);
    // 如果当前辅助栈不为空，或者刚刚入栈的数据大于辅助栈中的最小元素，则再把辅助栈中的栈顶元素再次压入辅助栈
    else
        m_min.push(m_min.top());
}

// 获取最小元素
template<typename T>
const T& StackWithMin<T>::min()
{
    assert(m_data.size()>0 && m_min.size()>0);

    // 返回辅助栈中的最小元素
    return m_min.top();
}

// 判断是否为空
template<typename T>
bool StackWithMin<T>::empty() const
{
    return m_data.empty();    
}
   
// 获取栈的大小
template<typename T>
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

// 测试用例

void test()
{
    StackWithMin<int> stack;
    
    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(3);
    stack.push(0);

    int temp = stack.min();
    printf("栈中最小的元素是:%d\n",temp);
    stack.pop();
    stack.pop();
    stack.pop();
    stack.push(1);
    stack.push(6);
    stack.push(3);
    stack.push(2);
    temp = stack.min();
    printf("栈中最小的元素是:%d\n",temp);
}

int main(void)
{
    test();
    return 0;
}


