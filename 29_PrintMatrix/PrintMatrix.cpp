/*************************************************************************
	> File Name: PrintMatrix.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月27日 星期二 01时56分46秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#define LEN 100

using namespace std;

void PrintMatrixInCircle(int **number,int cols,int rows,int start)
{
    int endX = rows - start - 1;
    int endY = cols - start - 1;
    
    // 从左到右打印一行

    for(int i = start;i<=endX;++i)
    {
        printf("%d\t",number[start][i]);
    }
    // 从上到下打印一列
    if(start<endY)
    {
        for(int i = start+1;i<=endY;++i)
        {
            printf("%d\t",number[i][endY]);
        }
    }
    // 从右至左打印一行
    if(start<endX && start<endY)
    {
        for(int i = endY-1;i>=start; --i)
        {
            printf("%d\t",number[endX][i]);
        }
    }
    // 从下到上答应一列
    if(start<endX && start<endY-1)
    {
        for(int i = endX-1;i>=start; i--)
        {
            printf("%d\t",number[i][start]);
        }
    }
}

void PrintMatrixClockwisely(int **number,int cols,int rows)
{
    if( number == NULL || cols<=0 || rows<=0  )
        return;
    int start = 0;
    
    while(cols>start*2 && rows>start*2)
    {
        PrintMatrixInCircle(number,cols,rows,start);  
        ++start;
    }
}

// 打印原始矩阵
void PrintMatrix(int **number,int rows,int cols)
{
   for(int i =0;i<rows;++i)
    {
        for(int j = 0;j<cols;j++)
        {
            printf("%d\t",number[i][j]); 
        }
        printf("\n");
    }

}

// 测试用例

void test()
{
    int rows = 0;
    int cols = 0;
    int **number = NULL;
    printf("请输入矩阵的行和列 : \n");
    scanf("%d%d",&rows,&cols);
    number = new int*[rows];

    for(int i = 0;i<rows;i++)
    {
        number[i] = new int[cols];

        for(int j = 0;j<cols;j++)
            scanf("%d",&number[i][j]); 
    }

    printf("打印原始矩阵:\n"); 
    
    PrintMatrix(number,rows,cols);

    printf("顺序时针打印矩阵:\n");
   PrintMatrixClockwisely(number,cols,rows); 

   for(int i = 0;i<rows;i++)
    {
        delete []number[i];
        number[i] = NULL;
    }    

}


int main(void)
{
    test();
    return 0;
}
