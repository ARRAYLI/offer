/*************************************************************************
	> File Name: erfen.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月08日 星期四 13时43分58秒
 ************************************************************************/

#include<iostream>
using namespace std;

int erfenFind(int *arr,int len,int val)
{
    int start = 0;
    int end = len -1;
    int middle = 0; 

    while(end >= start)
    {
       middle = (end+start)/2;
        if( arr[middle] > val )
        {
            start = middle -1 ;
        }
        else if( arr[middle] < val )
        {
            end = middle + 1;
        }
        else
        {
            return middle; 
        }

    }
    
    return 0;
}


int main(void)
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr) /sizeof(arr[0]);

    int res = erfenFind(arr,len,5);
    cout<<res<<endl;

    return 0;
}
