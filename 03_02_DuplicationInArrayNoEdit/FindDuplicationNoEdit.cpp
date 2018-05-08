/*************************************************************************
	> File Name: 02FindDuplicationNoEdit.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月08日 星期四 12时37分19秒
 ************************************************************************/

#include<iostream>
using namespace std;

// 计算数字的范围
int countRange(const int *arr,int len,int start,int end)
{
    if( arr == NULL )
        return 0;

    int counter = 0;
    int i;

    for(i=0;i<len;i++)
    {
        if(arr[i] >= start && arr[i] <= end)
            counter++;
    }

    return counter;
}

// 获取重复数字
int getDuplication(const int *arr,int len)
{
    if( arr == NULL || len <=0 )
        return -1;
    
    int i;

    for(i=0;i<len;i++)
    {
        // 检测数组中是否有不合法数据出现
        if(arr[i]<=0 || arr[i]>len -1)
            return -1;
    }
    
    int start = 1;
    int end = len-1;
    
    while(end >= start)
    {
       int middle = ((end-start) >> 2) + start;
       int count = countRange(arr,len,start,middle); 
        
        if(end == start)
        {
            if(count>1)
                return start;
            else
                break;
        }
        if( count > (middle - start+1))
            end = middle;
        else
            start = middle + 1;

    }
    
    return -1;
}

int main(void)
{
    int arr[] = {2,3,5,4,3,2,6,7};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    int res = getDuplication(arr,len);
    
    if(res == -1)
    {
        cout<<"没有重复的数字或者返回错误"<<endl;
    }
    else
    {
        cout<<"找到一个重复的数字是:"<<res<<endl;
    }

    return 0;
}
