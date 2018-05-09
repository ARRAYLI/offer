/*************************************************************************
	> File Name: RobotMove.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月17日 星期六 07时27分33秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

// 计算格子的行和列的值是 <= threshold

int getDigitSum(int num)
{
    int sum = 0;

    while(num>0)
    {
        sum += num%10;     // 先给 sum 加上 num 数字的个位
        num = num/10;      // 获取 num 的十位数字
    }
    
    return sum;
}


// 检测相邻格子是否符合要求
bool check(int threshold,int rows,int cols,int row,int col,bool *visited)
{
    if( row>=0 && row<rows && col>=0 && col<cols && getDigitSum(row)+getDigitSum(col)<= threshold && !visited[row*cols+col])
    {
        return true;
    }
    return false;
}

// 计算有多少个格子符合题目要求
int movingCountCore(int threshold,int rows,int cols,int row,int col,bool *visited)
{
    int count = 0;

    if(check(threshold,rows,cols,row,col,visited)) 
    {
       visited[row*cols + col] = true;

        count = 1 + movingCountCore(threshold,rows,cols,row,col-1,visited)        // 判断当前格子的左边是否符合条件
                  + movingCountCore(threshold,rows,cols,row,col+1,visited)        // 判断当前格子的右边是否符合条件
                  + movingCountCore(threshold,rows,cols,row-1,col,visited)        // 判断当前格子的上边是否符合条件
                  + movingCountCore(threshold,rows,cols,row+1,col,visited);       // 判断当前格子的下边是否符合条件

    }
   
    // 返回符合条件的格子数量
    return count;
}


int movingCount(int threshold,int rows,int cols)
{
    // 边界值检测
    if(threshold <0 || rows<= 0 || cols<= 0)
    {
        return 0;
    }
   
    // 动态申请辅助矩阵
    bool *visited = new bool[rows*cols];

    // 给刚刚申请的矩阵赋初值  false

    for(int i = 0; i<rows*cols; i++)
    {
        visited[i] = false;
    }

    int count = movingCountCore(threshold,rows,cols,0,0,visited);
    
    delete []visited;
    visited = NULL;
    
    return count;
}

// 测试用例：

void test()
{
    int m;
    int n;
    int k; 
    scanf("%d%d%d",&k,&m,&n);
    
    int res = movingCount(k,m,n);
    printf("res = %d\n",res);
}


int main(void)
{
   test(); 

    return 0;
}
