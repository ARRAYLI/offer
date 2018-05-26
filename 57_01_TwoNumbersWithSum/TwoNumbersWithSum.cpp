/*************************************************************************
	> File Name: TwoNumbersWithSum$.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 15时53分55秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

// 算法思想：
//          1.设置两个指针，第一个指针指向排序数组的首元素，第二个指针指向数组元素的最后一个元素的位置
//          2.求两个指针所指元素的和，如果两个元素的和大于输入的数字，则尾指针向前移动一位；如果和小于输入数字,
//              则指向首元素的指针向后移动一位；如果和刚好等于输入的数字，那么这两个指针所指元素就是要查找的 数字

bool FindNumbersWithSum(int data[],int len,int sum,int *num1,int *num2)
{
    bool found = false;
    
    if( data == NULL|| len<1 || num1 == NULL || num2 == NULL )
        return found;
    int ahead = len - 1;
    int behind = 0;
    
    while(behind < ahead)
    {
       long long CurSum = data[ahead]  + data[behind];
        
        if(CurSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }
        else if(CurSum > sum)
            ahead--;
        else
            behind++;

    }

    return found;
}

// 测试用例

void test()
{
    int data[100] = {0};
    int i = 0;
    int value;
    printf("输入排序数组，以 -1 结束:\n");
    scanf("%d",&value);

    while(value != -1)
    {
        data[i++] = value;
        scanf("%d",&value);
    }
    int len = i; 

    int sum = 0;
    printf("输入要查找的数字的和:\n");
    scanf("%d",&sum);

    int num1;
    int num2;
    bool ret = FindNumbersWithSum(data,len,sum,&num1,&num2);
    if(ret)
        printf("%d = %d + %d\n",sum,num1,num2);
    else
        printf("在排序数组中没有找到两个数的和为 %d\n",sum);
}

int main(void)
{
    test();
    return 0;
}
