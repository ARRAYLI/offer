/*************************************************************************
	> File Name: 12_StringPathInMatrix.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月17日 星期六 05时37分29秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

//此函数，用来判断当前路径满足的条件下，相邻格子是存在一个格子满足条件
bool hasPathCore(const char *matrix,int rows,int cols,int row,int col,char *str,int &pathLength,bool *visited)
{
    // 如果目标路径中的所有格子都已经被遍历完，则返回 true
    if(str[pathLength] == '\0')
        return true;
    bool hasPath = false;

    // 如果找到一个满足条件的路径的格子
    if(row>=0 && row<rows && col>=0 && col<cols && matrix[row*cols+col] == str[pathLength] && !visited[row*cols+col])
    {
        // 目标路径的格子向后移动一格
        ++pathLength; 
        // 通过辅助矩阵标记，此格子已经被访问过，下次不能再次被访问。
        visited[row*cols+col] = true;
       
        // 如果矩阵格子(row,col) 与路径字符串下标为 pathLength 的字符一样时，从它的4个相邻格子中寻找与路径字符串
        // 下标为 pathLength+1 的字符串相等的格子
        
        hasPath = hasPathCore(matrix,rows,cols,row,col-1,str,pathLength,visited) ||             // 判断左边格子
                  hasPathCore(matrix,rows,cols,row-1,col,str,pathLength,visited) ||             // 判断右边格子
                  hasPathCore(matrix,rows,cols,row,col+1,str,pathLength,visited) ||             // 判断上方格子
                  hasPathCore(matrix,rows,cols,row+1,col,str,pathLength,visited);               // 判断下方格子

        // 如果没有找到，则说明当前第 pathLength 个字符定位不确定，返回上一个位置，重新定位
        if(!hasPath)
        {
           --pathLength;
            visited[row*cols+col] = false;
        }
    }
    return hasPath;
}


// 判断任意一个坐标中的值是否是路径中的一个数值

bool hasPath(const char*matrix,int rows,int cols,char *str)
{
    // 边界检查，检测下标是否越界
    if( matrix == NULL || rows<1 || cols<1 || str == NULL )
    {
        return false;
    }
    
    // 动态申请一个辅助矩阵，来标记路径是否已经进入了格子
    bool *visited = new bool[rows*cols];
    
    // 给辅助矩阵初始化，清空
    memset(visited,0,rows*cols);
    
    int pathLength = 0;

    // 循环的目的是为了实现从矩阵中随机出发，寻找路径
    for(int row = 0;row<rows;row++)
    {
        for(int col = 0;col<cols;col++)
        {
            printf("row = %d,col = %d\n",row,col);
           if(hasPathCore(matrix,rows,cols,row,col,str,pathLength,visited))
                return true;
        }

    }

    // 释放动态分配的内存空间
    delete []visited;
    visited = NULL;

    return false;
}



int main(void)
{
   char matrix[3][4] = {{'a','b','t','g'},
                         {'c','f','c','s'},
                         {'j','d','e','h'} 
                    };
    
    //const char *matrix1 = "abtgcfcsjdeh";
    char str[] = "bfce";
    
    bool res = hasPath((const char*)matrix,3,4,str);
    
    cout<<res<<endl;

    return 0;
}
