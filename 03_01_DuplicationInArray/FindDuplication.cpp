/*
*   面试题 3: 数组中重组的数字
*   题目：    找出数组中重复的数字
*             在一个长度为 n 的数组里所有数字都在 0 ~ n-1 的范围内。数组中某些数字的是重复的，但不知道有几个数字重复了，
*             也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果长度为 7 的数组 {2,3,1,0,2,5,3}，那么对应的
*             输出是重复的数字 2 或者 3
*
* */


#include<iostream>
using namespace std;


bool duplication(int numbers[],int length,int *duplicate)
{
    int i;

    // 检测数组是否为空或者数组大小为 0
    if(numbers == NULL || length <= 0)
    {
        duplicate = NULL;
        return false;
    }

    // 检测数组中是否有比 length 大的数据
    for( i = 0;i<length; i++ )
    {
        if(numbers[i]<0 || numbers[i] >length -1 )
        {
            return false;
        }
    }

    
    for( i=0;i<length;i++ )
    {
       while(numbers[i] != i) 
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplicate = numbers[i];
                return true;
            }
            
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }

    }
    return false;
}

int main(int argc,char *argv[])
{
   int numbers[] = {2,3,1,0,2,5,3};
    int duplicate;
    int length = sizeof(numbers)/sizeof(numbers[0]);

    if(duplication(numbers,length,&duplicate))    
    {
       cout<<duplicate<<endl; 
    }
    else
    {
        cout<<"没有重复的数据"<<endl;
    }


    return 0;
}
