/*************************************************************************
	> File Name: SortArray.c
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月12日 星期一 14时31分41秒
 ************************************************************************/

#include<stdio.h>

#define LEN  100

void sortArray(int *arr1,int len1,int *arr2,int len2)
{
    if(arr1 == NULL || len1<= 0 || arr2 == NULL || len2 <=0) 
        return;

    int indexOflen1 = len1-1;
    int indexOflen2 = len2-1;
    int indexOfarr1 = len1 + len2-1;

    while( indexOflen1>= 0 && indexOflen2>= 0  )
    {
       if(arr1[indexOflen1] >= arr2[indexOflen2]) 
        {
            arr1[indexOfarr1] = arr1[indexOflen1];
            indexOfarr1--; 
            indexOflen1--;
        }
        else
        {
            arr1[indexOfarr1] = arr2[indexOflen2];
            indexOfarr1--;
            indexOflen2--;
        }
    }
    if(indexOflen1>=0)
    {
        arr1[indexOfarr1] = arr1[indexOflen1];
        indexOfarr1--; 
        indexOflen1--;
    }
    if(indexOflen2>=0)
    {
        arr1[indexOfarr1] = arr2[indexOflen2];
        indexOfarr1--;
        indexOflen2--;
    }

}

void print(int *arr1,int len1,int *arr2,int len2)
{
    int i;

    printf("arr1:\t");
    for(i=0;i<len1;i++)
    {
        printf("%d\t",arr1[i]);
    }
    printf("\n");

    printf("arr2:\t");
    for(i=0;i<len2;i++)
    {
        printf("%d\t",arr2[i]);
    }    
    printf("\n");
}

int main(void)
{

    int arr1[LEN] = {1,2,4,5,7,8,9};
    int arr2[]  = {2,4,6,8,10};
    
    print(arr1,7,arr2,5);

    sortArray(arr1,7,arr2,5);
    
    print(arr1,12,arr2,5);
    return 0;
}
