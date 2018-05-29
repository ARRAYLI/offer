/*************************************************************************
	> File Name: ConstructArray.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月24日 星期二 14时12分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void multiply(const vector<int> &array1,vector<int>& array2)
{
    int len1 = array1.size();
    int len2 =array2.size();

    if( len1 == len2 && len2>1 )
    {
        array2[0] = 1;
        for(int i =1 ;i<len1;i++)
        {
            array2[i] = array2[i-1] * array1[i-1];
        }
        
        double temp = 1;
        for(int i=len1-2;i>=0;i--)
        {
           temp *= array1[i+1];
            array2[i] *= temp;
        }

    }

}

// 测试用例

void test()
{
    int input[] = {1,2,3,4,5,6,7};
    int output[] = {0,0,0,0,0,0,0};
    vector<int> v1(input,input+sizeof(input)/sizeof(int));
    vector<int> v2(output,output+sizeof(output)/sizeof(int));
    
    multiply(v1,v2);

    for(vector<int>::iterator it = v2.begin();it != v2.end();++it)
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
