/*************************************************************************
> File Name: FindInPartiallySortedMatrix.cpp
> Author:    arrayli
> Mail:      1374367549@qq.com
> Created Time: 2018年03月11日 星期日 13时54分20秒
************************************************************************/

#include<stdio.h>

void print(int *arr)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d\t",(*(arr+i)+j));
        }

        printf("\n");
    }

}

int Find(int *arr,int rows,int cols,int number)
{
    int res = -1;
    print(arr);
    // 检测二维数组是否存在
    if(arr != NULL && rows > 0 && cols >0)
    {
        // 获取到第一行
        int row = 0;
        // 获取到数组最后的一列
        int col = cols -1;
        while( row<rows && col>=0 )
        {
            // 如果找到数据
            if(arr[row*col+col] == number) 
            {
                res = 0;
                break;
            }
            else if(arr[row*col+col] > number)
            {
                col--;
            }
            else
            {
                row++;
            }
        }

    }

    return res;
}

// 测试用例

void test()
{
    int arr[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
    
    int row = 4;
    int col = 4;

    int number = 0;

    scanf("%d",&number);

    int res = Find((int*)arr,row,col,number);    
    // 如果找到数据
    if(!res)
    {
        printf("在二维数组中找到数据 : %d\n",number);    
    }
    else
    {
        printf("在二维数组中找到数据没有找到数据 : %d\n",number);    
    } 

}


int main(void)
{
    test();   
    return 0;
}
