/*************************************************************************
	> File Name: MaxValueOfGifts.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月10日 星期二 18时11分22秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int getMaxValue(const int(* values)[100],int rows,int cols)
{
    
    if(values == NULL || rows <= 0 || cols <= 0)
        return 0;

    int **maxValues = new int*[rows];

    for(int i=0;i<rows;i++)
        maxValues[i] = new int[cols];
    
    for(int i=0;i<rows;i++)
    {
       for(int j=0;j<cols;j++)
        {
            int left = 0;
            int up = 0;

            if(i>0)
                up = maxValues[i-1][j];
            if(j>0)
                left = maxValues[i][j-1];

            maxValues[i][j] = std::max(left,up) + values[i][j];
        }
    }

    int maxValue = maxValues[rows-1][cols-1];
    
    for(int i =0;i<rows;i++)
    {
        delete []maxValues[i];
        maxValues[i] = NULL;
    } 
    delete []maxValues;
    maxValues = NULL;

    return maxValue;
}

int getMaxValue_solution2(int(* values)[100], int rows, int cols)
{
    if(values == NULL || rows <= 0 || cols <= 0)
    return 0;

    int* maxValues = new int[cols];

    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
        {
            int left = 0;
            int up = 0;

            if(i > 0)
            up = maxValues[j];

            if(j > 0)
            left = maxValues[j - 1];

            maxValues[j] = std::max(left, up) + values[i][j];
        }

    }

    int maxValue = maxValues[cols - 1];

    delete maxValues;
    maxValues = NULL;
    return maxValue;
}

// 测试用例

void test()
{
    int rows;
    int cols;
    int arr[100][100] = {0};
    printf("请输入 行和列:\n");
    scanf("%d%d",&rows,&cols);

    printf("开始输入棋盘中的数字：\n");
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            scanf("%d",&arr[i][j]);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

    int maxValue = getMaxValue(arr,rows,cols);

    printf("礼物的最大值是: %d\n",maxValue);
    
    printf("优化后的程序的最大值是:\n");
    int maxValue1 = getMaxValue_solution2(arr,rows,cols);

    printf("礼物的最大值是: %d\n",maxValue1);

}

int main(void)
{
    test();
    return 0;
}
