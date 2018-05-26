/*************************************************************************
	> File Name: ContinuousSqunenceWithSum.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 16时20分36秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 算法思想：
//          1.设置连个变量，small = 1,big = 2;
//          2.如果从 small 到 big 的序列数字之和大于 s ，则可以去掉序列中较小的值；如果序列之和小于 s,则增大 big,知道增到到
//              small  到 (1+s)/2 为止；如果序列之和等于 s ，则打印出各个和为 s 的序列

// 打印和为 s 的序列

void PrintContinuosSequence(int small,int big)
{
    for(int i=small;i<=big;i++)
    {
        printf("%d\t",i);
    }
    
    printf("\n");
}


void FindContinuousSequence(int sum)
{
    // 判断边界条件
   if(sum<3) 
        return;
   
    int small = 1;
    int big = 2;
    int end = (1+sum) / 2;
    int CurSum = small + big;
   
    // 要保证序列中的最小值小于 （1+s)/2 的值
    while(small < end)
    {
        if(CurSum == sum) 
            PrintContinuosSequence(small,big);

        // 如果序列之和不等于 s,并且当前序列之和大于 s
        while(CurSum > sum && small < end)
        {
            // 去掉最小的数值
            CurSum -= small;
            small++;

            if( CurSum == sum )
                PrintContinuosSequence(small,big);
        }
        
        // 如果序列之和小于 s
        // 序列继续向后移动
        big++;
        CurSum += big;
    }

}


// 测试用例：

void test()
{
    int s;
    printf("请输入序列的和：\n");
    scanf("%d",&s);
   
    // 获取和 s 的子序列
    FindContinuousSequence(s);
}

int main(void)
{
    test();
    return 0;
}
