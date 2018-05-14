/*************************************************************************
	> File Name: ReverseList.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月24日 星期六 07时26分52秒
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

ListNode* ReverseList(ListNode* pHead)
{
   ListNode* pReversedHead = NULL; 
    ListNode* pNode = pHead;
    ListNode* pPrev = NULL;
    
    while(pNode)
    {
       ListNode* pNext = pNode->m_pNext; 
        if(NULL == pNext)
            pReversedHead = pNode;

        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    
    return pReversedHead;
}

// 测试用例

void test()
{
    // 创建链表的结点  
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);

    // 连接链表结点
    ConnectListNode(pNode1,pNode2);
    ConnectListNode(pNode2,pNode3);
    ConnectListNode(pNode3,pNode4);
    ConnectListNode(pNode4,pNode5);
    ConnectListNode(pNode5,pNode6);

    // 打印链表结点
    printListNode(pNode1);

    // 反转链表
    ListNode* pReversepHead = ReverseList(pNode1);
    
    // 打印链表结点
    printListNode(pReversepHead);

    // 销毁链表
    DestroyListNode(pReversepHead);

}


int main(void)
{
    test();
    return 0;
}
