/*************************************************************************
	> File Name: NumberAppearingOnce.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 01时54分13秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 查找数组中唯一出现一次的数字

int FindNumberAppearingOnce(int numbers[],int len)
{
    if(numbers == NULL || len<=0)
        return -1;

    int bitSum[32] = {0};

    for(int i = 0;i<len;i++)
    {
       int bitMask = 1;
        for(int j = 31;j>=0;j--)
        {
            int bit = numbers[i] & bitMask;
            if( bit != 0 )
                bitSum[j] += 1;

            bitMask = bitMask << 1;
        }

    }
    
    int result = 0;
    for(int i=0;i<32;i++)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }

    return result;
}

// 测试用例

void test()
{
    int data[] = {1,1,1,2,3,3,3,4,4,4};
    int len = sizeof(data) / sizeof(data[0]);
    int ret = FindNumberAppearingOnce(data,len);
    printf("数组中只出现一次的数字是: %d\n",ret);
}

int main(void)
{
    test();
    return 0;
}
