/*************************************************************************
	> File Name: KLeastNumbers.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月02日 星期一 16时42分01秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

int RanddomInRange(int min,int max)
{
    int random = rand()%(max - min +1) + min;
    return random;
}

// 交换值

void Swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int *data,int len,int begin,int end)
{
    // 检测边界条件
    if(data == NULL || len<=0 || begin<0 || end<0 || end>= len)
        return -1;
    int index = RanddomInRange(begin,end);
    
    Swap(&data[index],&data[end]);
    
    int small = begin - 1;    

    for(index = begin;index<end;index++)
    {
        if(data[index] <data[end])
        {
           ++small;
            if(small != index)
                Swap(&data[index],&data[small]);
        }
    }

    ++small;
    Swap(&data[small],&data[end]);
    
    return small;
}


// 解法一:时间复杂度为 O(n)的算法，只有当我们可以修改数组时可用

void GetLeastNumbers(int *input,int *output,int n,int k)
{
    // 检测边界条件
    if( input == NULL || output == NULL || k>n || n<=0 || k<=0 )
        return;
    
    int start = 0;
    int end = n -1;
    int index = Partition(input,n,start,end);
    
    while(index != k -1)
    {
       if(index>k-1) 
        {
            end = index - 1;
            index = Partition(input,n,start,end);
        }
        else
        {
            start = index+1;        
            index = Partition(input,n,start,end);
        }
    }

    for(int i=0;i<k;i++)
    {
       output[i] = input[i];
    }
}

// 测试用例：

void test()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
   
    int *data = new int[n];
    int *output = new int[k];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&data[i]);
    }
    
    GetLeastNumbers(data,output,n,k); 

    for(int i=0;i<k;i++)
    {
        printf("%d\t",output[i]);
    }
    printf("\n");

    delete []data;
    data = NULL;
    delete []output;
    output = NULL;
}

// 解法二：基于堆排序，适合处理海量数据
void GetLeastNumbersHeap(vector<int> &data, vector<int>& result,int k)
{
   if(k<1 || data.size()<k) 
        return;
    
    for(int i = 0;i<data.size();i++)
    {
        if(i<k)
        {
            result.push_back(data[i]);
        }
        else
        {
            // 建堆，使得堆顶最大（默认大根堆，找 k 个最小用最大堆，找 k 个最大用最小堆
            make_heap(result.begin(),result.end());    

            // 和堆顶比较，如果比堆顶小，则替换掉堆顶
            if(data[i] < result[0])
            {
                result[0] = data[i];
            }
        }

    }


}

// 测试用例：

void test1()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
   
    vector<int> data;
    vector<int> result;

    for(int i = 0;i<n;i++)
    {
        int num = 0;
        scanf("%d",&num);
        data.push_back(num);    
    }

    GetLeastNumbersHeap(data,result,k);
    for(int i = 0;i<result.size();i++)
    {
        printf("%d\t",result[i]);
    }
    
    printf("\n");
}

//解法三：基于红黑树排序
//时间复杂度为 O(nlogk)的算法，特别适合处理海量数据
// 使用 multiset，从大到小排序

typedef multiset<int,greater<int> > inSet;
typedef multiset<int,greater<int> >::iterator setIterator;

void GetLeastNumbers(const vector<int> &data,inSet &leastNumbrs,int k)
{
   leastNumbrs.clear(); 
    if(k<1 || data.size() <k)
        return;

    vector<int>::const_iterator iter = data.begin();
    
    for(;iter != data.end();++iter)
    {
       if(leastNumbrs.size() < k) 
            leastNumbrs.insert(*iter);
       else
        {
            setIterator iterGreatest = leastNumbrs.begin();
            if(*iter < *leastNumbrs.begin())
            {
                leastNumbrs.erase(iterGreatest);                
                leastNumbrs.insert(*iter);
            }
        }
    }

}

// 测试用例

void test2()
{
     int n;
    int k;
    inSet result;
    scanf("%d%d",&n,&k);
   
    vector<int> data;

    for(int i = 0;i<n;i++)
    {
        int num = 0;
        scanf("%d",&num);
        data.push_back(num);    
    }

    GetLeastNumbers(data,result,k);
    setIterator iter = result.begin();

    for(;iter != result.end();++iter)
    {
        printf("%d\t",*iter);
    }
    
    printf("\n");
}

int main(void)
{
    //test();
    //test1();
    test2();
    return 0;
}
