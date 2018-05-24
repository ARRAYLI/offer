/*************************************************************************
	> File Name: MissingNumber.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月11日 星期三 19时03分29秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// 算法思想：1.首先在数组中使用 二分法来找到数组下标和它对应的数值不相同的下标
//           2.然后判断它是不是第一个下标和对应的值不相同的数字，如果是，则找到缺失的数字。如果不是，则继续查找

int GetMissingNumber(int *numbers,int length)
{
    // 检测数组是否合法
    if( numbers == NULL || length <= 0 )
        return -1;
    
    int left = 0;
    int right = length - 1;

    // 使永二分法来查找数字
    while(left < right)
    {
        int mid = (left + right) /2;

        // 如果数组中下标和对应的数值不相等的话
        if( numbers[mid] != mid  )
        {
            // 判断是否是第一个数值和对应下标不相同的数
            if(mid == 0 || numbers[mid-1] == mid-1 )
                return mid;
            right = mid-1;
        }
        else
            left = mid+1;

    }
   
    // 最后一个数字确实 n
    if( left == right )
        return length;

    return -1;
}

// 测试用例1:

void test()
{
    int ret = -1;
    // 缺第一个数字 0
    int numbers[] = {1,2,3,4,5};
    ret = GetMissingNumber(numbers,sizeof(numbers)/sizeof(numbers[0]));
    printf("缺少数字 : %d\n",ret);
  
    // 缺失最后一个数字
    int numbers1[] = {0,1,2,3,4};
    ret = GetMissingNumber(numbers1,sizeof(numbers1)/sizeof(numbers1[0]));
    printf("缺少数字 : %d\n",ret);
    
    // 缺失中间某个数字
    int numbers2[] = {0,1,2,4,5};
    ret = GetMissingNumber(numbers2,sizeof(numbers2)/sizeof(numbers2[0]));
    printf("缺少数字 : %d\n",ret);
  
    // 数组中只有一个数字
    int numbers3[] = {0};
    ret = GetMissingNumber(numbers3,sizeof(numbers3)/sizeof(numbers3[0]));
    printf("缺少数字 : %d\n",ret);

    // 空数组

    ret = GetMissingNumber(NULL,-1);
    printf("缺少数字 : %d\n",ret);
}

int main(void)
{
    test();

    return 0;
}
