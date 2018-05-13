/*************************************************************************
	> File Name: KthNodeFromEnd.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月21日 星期三 07时20分49秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct ListNode
{
    int m_nVale;
    ListNode* m_pNext;
};

// 给链表创建结点
ListNode *CreateListNode(int val)
{
   ListNode * pNew = (ListNode*)malloc(sizeof(ListNode));
    if(pNew == NULL)
    {
       printf("pNew malloc failed!\n"); 
        return NULL;
    }
    pNew->m_pNext = NULL;
    pNew->m_nVale = val;
    return pNew;
}

// 连接链表

void ConnectListNode(ListNode* pNode1,ListNode* pNode2)
{
   if(pNode1 == NULL) 
    {
        printf("pNode1 is NULL\n");
        return;
    }
    
    pNode1->m_pNext = pNode2;
}

// 销毁链表

void DestroyListNode(ListNode* pHead)
{
   while(pHead)
    {
        ListNode *temp = pHead;
        pHead = pHead->m_pNext;
        
        free(temp);
        temp = NULL;
    }

}

// 打印链表

void printListNode(ListNode *pNode)
{
   while(pNode)
    {
        printf("%d\t",pNode->m_nVale);
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

// 寻找链表中数第 K 个结点

ListNode *FindKthToTail(ListNode *pHead,int k)
{
    if(pHead == NULL || k<=0) 
        return NULL;
    
    ListNode* pAHead = pHead;    // 第一个遍历的指针
    ListNode* pBehind = NULL;    // 第二个遍历的指针

    // 先给 pAHead 走 K-1 步
    for(int i =0;i<k-1;i++)
    {
        // 循环遍历，应该判断下一个结点是否为空
       if(pAHead->m_pNext != NULL) 
        {
            pAHead = pAHead->m_pNext;
        }
        // 如果下一个结点为空的话，并且还没有遍历走 k - 1 步的话，就出错，返回 NULL
        else
        {
            return NULL;    
        } 
    }
    // 给 pBehind 指针指向链表的头，从头开始遍历
    pBehind = pHead;
    // 然后 pAHead,pBehind 一起走，直到 pBehind 指针走到链表尾部

    while(pAHead->m_pNext)
    {
       pBehind = pBehind->m_pNext; 
        pAHead = pAHead->m_pNext;
    }

    return pBehind;
}



// 测试用例

void test()
{
   ListNode *pNode1 = CreateListNode(1); 
   ListNode *pNode2 = CreateListNode(2); 
   ListNode *pNode3 = CreateListNode(3); 
   ListNode *pNode4 = CreateListNode(4); 
   ListNode *pNode5 = CreateListNode(5); 
   ListNode *pNode6 = CreateListNode(6); 

    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    ConnectListNode(pNode3,pNode4);
    ConnectListNode(pNode4,pNode5);
    ConnectListNode(pNode5,pNode6);

    printListNode(pNode1);

    int num = 0;
    printf("请输入要查找的链表的第倒输 K 个结点:\n");
    
    scanf("%d",&num);
        
    while(num<=0)
    {
        printf("您的输入有错，请重新入：\n"); 
        scanf("%d",&num);
    }

    ListNode *temp = FindKthToTail(pNode1,num);
    if( temp != NULL )
    {
        printf("倒输第 K 个结点的值 : %d\n",temp->m_nVale);
    }
    else
    {
        printf("链表第 %d 结点不存在\n",num);
    }

    DestroyListNode(pNode1);
}

int main(void)
{
    test();
    return 0;
}
