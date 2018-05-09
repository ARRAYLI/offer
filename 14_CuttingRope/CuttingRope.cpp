/*************************************************************************
	> File Name: CuttingRope.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月18日 星期日 02时41分05秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void print(int *arr,int length)
{
    for(int i=0;i<=length; ++i)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}


// 动态规划 时间复杂度 O(n2) 空间复杂度 O(n)
int maxProductAfterCutting_solution1(int length)
{
    if(length<2)
        return 0;
    if(length == 2)
        return 1;
    if( length == 3 )
        return 2;

    int *products = new int[length+1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;
    
    for(int i = 4; i<=length; ++i )
    {
        max = 0;
       for(int j=1;j<=i/2;++j)
        {
           int product = products[j] * products[i-j];
            if(max < product)
                max = product;

            products[i] = max;
        }
    }

    print(products,length);
    max = products[length];

    delete []products;
    products = NULL;

    return max;
}

// 贪婪法 时间复杂度 O(1)   空间复杂度 : O(1)
int maxProductAfterCutting_solution2(int length)
{
    if(length<2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    // 尽可能多的剪去长度为 3 的绳子段
    int timesOf3 = length / 3; 
    
    // 当绳子最后剩下的长度为 4 的时候，不能再去剪长度为 3 的绳子段
    // 此时更好的方法是把绳子剪成长度为 2 的声字段，应为 2*2>1*3
    
    if(length - timesOf3*3 == 1)
        timesOf3 -= 1;

    int timesOf2 = (length -timesOf3*3) / 2;
    int maxValue = pow(3,timesOf3) * pow(2,timesOf2);
   
    return maxValue;
}


int main(void)
{
   int length;
    printf("请输入绳子的长度：\n");
    scanf("%d",&length);

    printf("动态规划法，所求结果：\n");
    int res = maxProductAfterCutting_solution1(length);
    
    printf("res = %d\n",res);
    
    printf("贪婪法，所求结果：\n");
   res = maxProductAfterCutting_solution2(length);
    
    printf("res = %d\n",res);
    return 0;
}
