/*************************************************************************
	> File Name: NumbersAppearOnce$.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 01时32分16秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 算法思想：任何一个数字异或它自己等于 0。也就是说，如果我们从头到尾异或数组中的每个数字，那么最终的结果刚好
// 是那个只出现一次的数字，因为那些成对出现的两次的数字全部在异或中抵消了

// 在整数 num 的二进制中国找到最右边是 1 的位
unsigned int FindFirstBits1(int num)
{
    int indexBit = 0;
    while((num & 1) == 0 && (indexBit< 8 *sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }
    
    return indexBit;
}

// 判断 num 的二进制表示中从右边数起的 indexBit 位是不是 1

bool IsBits1(int num,unsigned int indexBit)
{
    num = num>>indexBit;
    return (num & 1);
}

// 获取数组中只出现过一次的数字

void FindNumsAppearOnce(int *data,int len,int *num1,int *num2)
{
    if(data == NULL || len <= 0) 
        return ;

    // 异或结果
    int resultExclusiveOr = 0; 
    
    for(int i=0;i<len;i++)
        resultExclusiveOr ^= data[i];

    // 划分子数组
    unsigned int indexOf1 = FindFirstBits1(resultExclusiveOr);

    *num1 = *num2 = 0;
    for(int j=0;j<len;j++)
    {
       if(IsBits1(data[j],indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
    
}

// 测试用例：

void test()
{
    int data[] = {2,4,3,6,3,2,5,5};    
    int len = sizeof(data) / sizeof(data[0]);
    int num1,num2;

    FindNumsAppearOnce(data,len,&num1,&num2);
    
    printf("数组中两个只出现一次的数字是：%d\t%d\n",num1,num2);
}

int main(void)
{
    test(); 
    return 0;
}
