/*************************************************************************
	> File Name: Singleton.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月08日 星期四 01时04分55秒
 ************************************************************************/

#if 0

#include<iostream>
using namespace std;

// 懒汉式单例模式

class Singleton
{

private:
    Singleton();
public:
    static Singleton* getInstance();
    //static void freeSingleton();
    ~Singleton();
private:
    static Singleton *m_ps;
};

Singleton::Singleton()
{
    // 给静态成员变量指针初始化为 NULL
   m_ps = NULL;     
}


// 全局静态访问点
Singleton* Singleton::getInstance()
{
    if(NULL == m_ps)    
    {
        m_ps = new Singleton;
    }
    return m_ps;
}


Singleton::~Singleton()
{

   if(NULL != m_ps) 
    {
        delete m_ps;        
        m_ps = NULL;
    }
}

// 懒汉式单例模式
Singleton* Singleton::m_ps = NULL;

void test()
{
    Singleton *p1 = Singleton::getInstance(); 
    Singleton *p2 = Singleton::getInstance(); 
    
    if( p1 == p2 )
    {
       cout<<"p1 与 p2 是同一个对象" <<endl;
    }
    else
    {
       cout<<"p1 与 p2 不是同一个对象" <<endl;
    }

}

int main(void)
{
    test();    

    return 0;
}
#endif

// 饿汉式单例模式

#if 0

#include<iostream>
using namespace std;

// 饿汉式单例模式

class Singleton
{

private:
    Singleton();
public:
    static Singleton* getInstance();
    //static void freeSingleton();
    ~Singleton();
private:
    static Singleton *m_ps;
};

Singleton::Singleton()
{
    // 给静态成员变量指针初始化为 NULL
   m_ps = NULL;     
}


// 全局静态访问点
Singleton* Singleton::getInstance()
{
    return m_ps;
}


Singleton::~Singleton()
{

   if(NULL != m_ps) 
    {
        delete m_ps;        
        m_ps = NULL;
    }
}

// 饿汉式单例模式
Singleton* Singleton::m_ps = new Singleton;

void test()
{
    Singleton *p1 = Singleton::getInstance(); 
    Singleton *p2 = Singleton::getInstance(); 
    
    if( p1 == p2 )
    {
       cout<<"p1 与 p2 是同一个对象" <<endl;
    }
    else
    {
       cout<<"p1 与 p2 不是同一个对象" <<endl;
    }

}

int main(void)
{
    test();    

    return 0;
}

#endif


// 懒汉式多线程单例模式

#include<iostream>
#include<pthread.h>
#include<unistd.h>
using namespace std;


// 懒汉式多线程单例模式
class Singleton
{

private:
    Singleton();
public:
    static Singleton* getInstance();
    void print();
    //static void freeSingleton();
    ~Singleton();
private:
    static Singleton *m_ps;
    static pthread_mutex_t mutex;
    static int count;
};

void Singleton::print()
{
    cout<<"staic int count : "<<count<<endl;
}

Singleton::Singleton()
{
    // 给静态成员变量指针初始化为 NULL
   m_ps = NULL;     
    // 给互斥锁初始化
    
    pthread_mutex_init(&mutex,NULL);
    sleep(3);
}


// 全局静态访问点
Singleton* Singleton::getInstance()
{
    // 加锁
    pthread_mutex_lock(&mutex);
    if(NULL == m_ps)
    {
        m_ps = new Singleton;
        count++;
    }
    // 解锁
    pthread_mutex_unlock(&mutex);
    return m_ps;
}


Singleton::~Singleton()
{

   if(NULL != m_ps) 
    {
        delete m_ps;        
        m_ps = NULL;
    }
}

// 饿汉式多线程单例模式
Singleton* Singleton::m_ps = NULL;
pthread_mutex_t Singleton::mutex;
int Singleton::count = 0;

void *thread_handler(void* arg)
{
    cout<<"我是线程 ："<<pthread_self()<<endl;
    pthread_detach(pthread_self());
    Singleton::getInstance()->print();
    return NULL;
}

void test()
{
    int i;
    pthread_t tid[3];
    for( i=0;i<3;i++ )
    {
        pthread_create(&tid[i],NULL,thread_handler,NULL);
    }

    for(i=0;i<3;i++)
    {
        pthread_join(tid[i],NULL);
    }

}

int main(void)
{
    test();    

    return 0;
}

