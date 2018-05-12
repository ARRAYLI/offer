#include <iostream>  
#include<stdlib.h>
#include<stdio.h>
using namespace std;  
struct Node  
{  
    int data;  
    Node* next;  
  
    Node(int x)  
        :data(x)  
        ,next(NULL)  
    {}  
};  
  
void PushBack(Node** pHead,int x)  
{  
    if(*pHead==NULL)  
    {  
        *pHead=new Node(x);  
    }  
    else  
    {  
        Node* cur=*pHead;  
        while(cur->next)  
        {  
            cur=cur->next;  
        }  
        cur->next=new Node(x);  
    }  
}  
 // 删除重复的结点

void DeleteNode(Node**pHead)
{
    // 链表为空，或者链表只有一个结点则返回
    if(pHead == NULL || *pHead == NULL || (*pHead)->next == NULL)
        return;
    
    Node *pre = NULL;       // 用来标记当前结点的上一个节点
    Node *cur = *pHead;     // 当前结点

    while(cur)
    {
        Node *pNext = cur->next;        // 标记当前结点的下一个结点

        //若当前结点与下一个结点不重复
        if( pNext && cur->data!= pNext->data)
        {
            pre = cur;              // 标记当前结点的前一个结点
            cur = pNext;            // 当前结点的下一个结点
        }
        // 若当前结点与下一个结点重复
        else if( pNext && cur->data== pNext->data)
        {
            Node *del = cur;        // 从当前结点开始删除重复结点
            int val = cur->data;
            while(del && del->data == val)          // 删除结点直到结点中的值不为重复值
            {
                pNext = del->next;
                
                free(del);
                del = NULL;
                del = pNext;
            }
            
            // 删除完重复的结点以后，pre 指向不重复结点对的下一个结点
            if(pre)      // 若头结点重复，则修改头结点
                pre->next = pNext;  // 若头结点不重复，将以前标记的结点直接与 pNext 相连
            else
                *pHead = pNext;        
            cur = pNext;
        }
    }
}
 
void Print(Node* pHead)  
{  
    Node* cur=pHead;  
    while(cur)  
    {  
        cout<<cur->data<<" ";  
        cur=cur->next;  
    }  
    cout<<endl;  
}  
//删除有序链表重复的值  
void DeleteReValue(Node** pHead)  
{  
    if(pHead==NULL||*pHead==NULL||(*pHead)->next==NULL)  //链表为空或只有一个节点直接返回  
        return;  
    Node* prev=NULL;    //标记当前结点前一个  
    Node* cur=*pHead;   //标记当前结点  
    while(cur)  
    {  
        Node* pNext=cur->next;  //标记下一个结点  
          
        if(pNext && pNext->data!=cur->data)   //若当前结点与下一个结点不重复  
        {  
            prev=cur;                //标记当前结点前一个结点  
            cur=pNext;              //当前结点走下一个  
        }  
        else if(pNext && pNext->data==cur->data)   //若当前结点与下一个结点重复  
        {  
            Node* del=cur;          //从当前节点开始删除重复节点  
            int value=cur->data;  
            while(del && del->data==value)    //删除停止时间是直到删除的节点值不为重复结点的值  
            {  
                pNext=del->next;   //用pNext做中间转换值  
                delete del;  
                del=pNext;  
            }   //完成以后pNext指向不重复节点值的第一个  
  
            if(prev)  
                prev->next=pNext;    //若头结点不重复，将以前标记的前一个节点直接与pNext连接  
            else  
                *pHead=pNext;   //头结点重复则改正头节点  
  
            cur=pNext;    //当前结点从pNext再次开始  
        }   
  
        //cur=pNext;  
    }  
}  
int main()  
{  
    Node* pHead=NULL;  
    PushBack(&pHead,0);  
    PushBack(&pHead,0);  
    PushBack(&pHead,1);  
    PushBack(&pHead,2);  
    PushBack(&pHead,3);  
    PushBack(&pHead,3);  
    PushBack(&pHead,4);  
    PushBack(&pHead,4);  
    PushBack(&pHead,5);  
    PushBack(&pHead,6);  
    PushBack(&pHead,6);  
    PushBack(&pHead,6);  
    Print(pHead);  
    DeleteNode(&pHead);
   // DeleteReValue(&pHead);  
    Print(pHead);  
    return 0;  
}  
