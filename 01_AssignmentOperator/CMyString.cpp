/*************************************************************************
> File Name: CMyString.cpp
> Author:    arrayli
> Mail:      1374367549@qq.com
> Created Time: 2018年03月07日 星期三 18时46分52秒
************************************************************************/

#if 0

#include<iostream>
#include<string.h>
using namespace std;

class CMyString
{

public:
    CMyString(char* pData = NULL);                      // 默认构造函数
    CMyString(const CMyString &str);                    // 拷贝构造函数
    CMyString & operator= (const CMyString & str);      // 复制运算符重载函数
    void print();                                       // 打印字符串
    ~CMyString(void);                                   // 析构函数
private:
    char *p_Data;
};


CMyString::CMyString(char* pData)
{
    // 如果 pData 为空，则为 pData 动态申请内存空间,并初始化
    if(NULL == pData)    
    {
        p_Data = new char[1];
        p_Data[0] = '\0';
    }
    // 如果 pData 不为空
    else
    {
       p_Data = new char[strlen(pData)+1];
        strcpy(p_Data,pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    p_Data = new char[strlen(str.p_Data)+1];
    strcpy(p_Data,str.p_Data);
}

CMyString & CMyString::operator= (const CMyString & str)      // 复制运算符重载函数 
{
    // 判断两个对象的指针是否一样,如果相等，则直接返回 *this
    if(this == &str)
        return *this;
    // 如果不相等，则先释放 p_Data 中的内存空间

    delete []p_Data;
    p_Data = NULL;
    
    // 重新给 p_Data 申请内存空间
    
    p_Data = new char[strlen(str.p_Data)+1];

    strcpy(p_Data,str.p_Data);
    
    return *this;
}

void CMyString::print()
{
    cout<<p_Data<<endl;
}


CMyString::~CMyString(void)
{
    if(NULL != p_Data) 
    {
        delete []p_Data;
        p_Data = NULL;
    }
}

// 测试用例:把一个 CMyString 的实例赋值给另外一个实例

void test1(void)
{
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print();
    
    // 使用拷贝构造函数

    CMyString str2(str1);
    cout<<"str2.print:"<<endl;
    str2.print();
}

// 测试用例： 使用赋值运算符,把一个 CMyString 的实例赋值给它自己

void test2(void)
{
    
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print();
    
    // 使用赋值运算符
    CMyString str2 = str1;
    cout<<"str2.print:"<<endl;
    str2.print();
}

// 测试用例：连续赋值以及赋值给自己

void test3(void)
{
        
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print(); 
    cout<<"赋值给自己："<<endl;
    str1 = str1;
    str1.print();

    cout<<"连续赋值："<<endl;

    CMyString str2,str3;
    
    str3 = str2 = str1;
    cout<<"str1.print:"<<endl;
    str1.print();
    cout<<"str2.print:"<<endl;
    str2.print();
    cout<<"str3.print:"<<endl;
    str3.print();

}

int main(void)
{
    cout<<"--------------------------test1--------------------"<<endl;
    test1();
    cout<<"--------------------------test2--------------------"<<endl;
    test2();
    cout<<"--------------------------test3--------------------"<<endl;
    test3();
    return 0;
}
#endif

#include<iostream>
#include<string.h>
using namespace std;

class CMyString
{

public:
    CMyString(char* pData = NULL);                      // 默认构造函数
    CMyString(const CMyString &str);                    // 拷贝构造函数
    CMyString & operator= (const CMyString & str);      // 复制运算符重载函数
    void print();                                       // 打印字符串
    ~CMyString(void);                                   // 析构函数
private:
    char *p_Data;
};


CMyString::CMyString(char* pData)
{
    // 如果 pData 为空，则为 pData 动态申请内存空间,并初始化
    if(NULL == pData)    
    {
        p_Data = new char[1];
        p_Data[0] = '\0';
    }
    // 如果 pData 不为空
    else
    {
       p_Data = new char[strlen(pData)+1];
        strcpy(p_Data,pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    p_Data = new char[strlen(str.p_Data)+1];
    strcpy(p_Data,str.p_Data);
}

CMyString & CMyString::operator= (const CMyString & str)      // 复制运算符重载函数 
{
    // 判断两个对象的指针是否一样,如果相等，则直接返回 *this
    if(this == &str)
        return *this;
    // 为了安全起见，我们不采用先释放 p_Data 的内存空间，通过创建临时实例，
    // 再交换临时实例和原来的实例即可，这样就会内存不足的 异常错误产生    
   
    // 使用赋值的对象参数来对临时变量进行初始化

    CMyString strTemp(str);
    char *p_strTemp = strTemp.p_Data;
    strTemp.p_Data = p_Data;
    p_Data = p_strTemp;

    return *this;
}

void CMyString::print()
{
    cout<<p_Data<<endl;
}


CMyString::~CMyString(void)
{
    if(NULL != p_Data) 
    {
        delete []p_Data;
        p_Data = NULL;
    }
}

// 测试用例:把一个 CMyString 的实例赋值给另外一个实例

void test1(void)
{
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print();
    
    // 使用拷贝构造函数

    CMyString str2(str1);
    cout<<"str2.print:"<<endl;
    str2.print();
}

// 测试用例： 使用赋值运算符,把一个 CMyString 的实例赋值给它自己

void test2(void)
{
    
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print();
    
    // 使用赋值运算符
    CMyString str2 = str1;
    cout<<"str2.print:"<<endl;
    str2.print();
}

// 测试用例：连续赋值以及赋值给自己

void test3(void)
{
        
   char *text = "nihao!";

    // 使用默认构造函数
    CMyString str1(text);
    cout<<"str1.print :"<<endl;
    str1.print(); 
    cout<<"赋值给自己："<<endl;
    str1 = str1;
    str1.print();

    cout<<"连续赋值："<<endl;

    CMyString str2,str3;
    
    str3 = str2 = str1;
    cout<<"str1.print:"<<endl;
    str1.print();
    cout<<"str2.print:"<<endl;
    str2.print();
    cout<<"str3.print:"<<endl;
    str3.print();

}

int main(void)
{
    cout<<"--------------------------test1--------------------"<<endl;
    test1();
    cout<<"--------------------------test2--------------------"<<endl;
    test2();
    cout<<"--------------------------test3--------------------"<<endl;
    test3();
    return 0;
}
