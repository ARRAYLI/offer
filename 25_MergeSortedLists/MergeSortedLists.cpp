/*************************************************************************
	> File Name: MergeSortedLists.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月24日 星期六 07时43分19秒
 ************************************************************************/


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

ListNode* Merge(ListNode* pHead1,ListNode* pHead2)
{
    if(pHead1 == NULL)
        return pHead2;
    else if(pHead2 == NULL)
        return pHead1;

    ListNode* pMergedHead = NULL;

   if(pHead1->m_nVale < pHead2->m_nVale)
    {
        pMergedHead = pHead1;        
        pMergedHead->m_pNext = Merge(pHead1->m_pNext,pHead2);
    }
    else
    {
        pMergedHead = pHead2;        
        pMergedHead->m_pNext = Merge(pHead1,pHead2->m_pNext);
    }
    
    return pMergedHead;
}

// 测试用例
void test()
{
    // 创建链表的结点
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode7 = CreateListNode(7);

    // 连接链表结点
    ConnectListNode(pNode1,pNode3);
    ConnectListNode(pNode3,pNode5);
    ConnectListNode(pNode5,pNode7);

    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode8 = CreateListNode(8);

    // 连接链表结点
    ConnectListNode(pNode2,pNode4);
    ConnectListNode(pNode4,pNode6);
    ConnectListNode(pNode6,pNode8);

    ListNode* pHead1 = pNode1;
    ListNode* pHead2 = pNode2;
    
    // 打印链表结点
    printListNode(pHead1);
    printListNode(pHead2);

    ListNode* pMergedHead = Merge(pHead1,pHead2); 
    if( NULL == pMergedHead )
        return;
    printListNode(pMergedHead);

    // 销毁链表
    DestroyListNode(pMergedHead);

}

int main(void)
{
    test();

    return 0;
}
