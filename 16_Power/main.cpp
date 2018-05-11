/*************************************************************************
	> File Name: main.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 09时23分15秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
using namespace std;

int main(void)
{
    int num = -1;
    
    printf("%d\n",num);
   
    unsigned int absNum = (unsigned int)num;
    printf("%d\n",absNum);
   
    absNum = - absNum;
    printf("%d\n",absNum);
    return 0;
}
