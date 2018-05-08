/*************************************************************************
	> File Name: b.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月08日 星期四 11时26分35秒
 ************************************************************************/

#include<iostream>
using namespace std;


  bool duplicate(int numbers[],int length,int* duplication){
      if(numbers==NULL || length<=1){
          duplication=NULL;
          return false;

      }

      for(int i=0;i<length;i++){
          while(numbers[i]!=i){
              if(numbers[i]==numbers[numbers[i]]){
                  *duplication=numbers[i];
                  return true;

              }
              int tmp=numbers[i];
              numbers[i]=numbers[tmp];
              numbers[tmp]=tmp;

          }

      }

      return false;

  }

   int main()
   {
       int A[]={2,3,1,0,2,5,3};
       int len=sizeof(A)/sizeof(A[0]);

       int duplication;
       cout << duplicate(A,len,&duplication) << endl;
       cout << duplication << endl;
       return 0;

   }
