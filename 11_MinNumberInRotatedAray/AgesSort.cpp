/*************************************************************************
	> File Name: MinNumberInRotatedAray.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月15日 星期四 06时55分46秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int arr[] = {50,30,40,50,25,35,35,25,45,65,45};

void SortAges(int ages[],int length)
{
    if( NULL == ages || length <= 0 )
    {
        return;
    }
    
    const int oldAge = 99;
    int timesOfAge[oldAge +1];

    int i;

    for(i = 0;i<oldAge;i++)
        timesOfAge[i] = 0;
    
    for( i=0;i<length;i++ )
    {
        int age = ages[i];
        if(age<0 || age> oldAge)
        {
            printf("%d 不在年龄范围\n",age);
           return; 
        }
        ++timesOfAge[age];
    }

    int index = 0;
    for( i=0;i<= oldAge;i++ )
    {
        for(int j = 0; j<timesOfAge[i];j++)
        {
            ages[index]  = i;
            ++index; 
        }
    }

}

void print(int *arr,int len)
{
    for(int i=0; i<len;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
// 测试用例：

void test()
{
    int len = sizeof(arr)/sizeof(arr[0]);
    print(arr,len);
    SortAges(arr,len);    
    print(arr,len);
}

int main(void)
{
    test();
    return 0;
}


