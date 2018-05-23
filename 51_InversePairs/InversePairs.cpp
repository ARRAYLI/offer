/*************************************************************************
	> File Name: InversePairs.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月26日 星期四 13时51分48秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

/* 统计两个子数组间的逆序对 */
long long MergePairsBetweenArray(int *arr,int *brr,int start,int mid,int end)
{
   int i = mid;
    int j = end;
    /* 辅助数组的最后一位 */
    int k = end;

    long long count = 0;
    /* 设置两个指针 i,j 依次从右往左依次比较
     * 将较大的一次放入数组的右边 */
    while(i>=start && j>=mid+1)
    {
        if( arr[i] > arr[j] )
        {
            count += j - mid;
            brr[k--] = arr[i--];
        }
        else
            brr[k--] = arr[j--];
    }

    /*将剩余一个数组中的元素拷贝到辅助数组中 */
    while(i>=start)     
        brr[k--] = arr[i--];
    while(j>=mid+1)
        brr[k--] = arr[j--];

    /* 从辅助数组中将元素拷贝到原数组中，使其有序排列 */
    for(i=end;i>k;i--)
        arr[i] = brr[i];

    return count;
}


// 统计数组中的所有逆序对
long long CountMergePairs(int *arr,int *brr,int start,int end)
{
    long long PairsNum = 0;
    if( start < end )
    {
        int mid = (start + end) / 2;

        // 统计左边数组的逆序对
        PairsNum += CountMergePairs(arr,brr,start,mid);
        /* 统计右边数组的逆序对 */
        PairsNum += CountMergePairs(arr,brr,mid+1,end);
        /* 统计左右数组间的逆序对*/
        PairsNum += MergePairsBetweenArray(arr,brr,start,mid,end);
    }
    return PairsNum;
}

long long CountTotalPairs(int *arr,int len)
{
    if(arr == NULL || len <2)
        return 0;

    // 动态申请辅助数组
    int *brr = new int(len);
    if( brr == NULL ) 
    {
        printf("动态申请辅助数组失败!\n"); 
        return 0;
    }

    long long sum = CountMergePairs(arr,brr,0,len-1);
    delete []brr;
    brr = NULL;
    return sum;
}

// 测试用例

void test()
{
   int arr[] = {7,6,5,4};     
   int len = sizeof(arr) / sizeof(arr[0]);
    
    long long sum = CountTotalPairs(arr,len);

    printf("总共有 %lld 个逆序对\n",sum);

}

int InversePairsCore(int *data,int *copy,int start,int end)
{
    if( start == end )
    {
        copy[start] = data[start];
        return 0;
    }

    int length = (end - start) / 2;
    int left = InversePairsCore(copy,data,start,start+length);
    int right = InversePairsCore(copy,data,start+length+1,end);

    /* i 初始化为前半段的最后一个数字的下标*/
    int i = start+length;    
    /* j 初始化为后半段最后一个数字的下标*/
    int j = end;
    int indexCopy = end;
    int count = 0; 

    while(i>=start && j>=start + length+1)
    {
       if(data[i]>data[j]) 
        {
            copy[indexCopy--] = data[i--];
            count += j-start-length;
        }
        else
        {
            copy[indexCopy--] = data[j--];
        }

    }
    
    for( ; i>=start; i--)
        copy[indexCopy--] = data[i];

    for( ;j>=start+length+1;--j )
        copy[indexCopy--] = data[i];

    return left+right+count;

}

int InversePairs(int *data,int length)
{
   if(data == NULL || length<0) 
        return 0;
    
    int *copy = new int[length];
    for(int i=0;i<length;i++)
        copy[i] = data[i];

    int count = InversePairsCore(data,copy,0,length-1);
    delete []copy;

    return count;
}

// 测试用例：
void test1()
{
   int arr[] = {7,6,5,4};     
   int len = sizeof(arr) / sizeof(arr[0]);
    
    long long sum = CountTotalPairs(arr,len);

    printf("总共有 %lld 个逆序对\n",sum);

}

int main(void)
{
    test();
    test1();
    return 0;
}
