/*************************************************************************
	> File Name: DeleteNodeInList.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 16时36分17秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

typedef struct _ListNode
{
    int m_nValue;
    _ListNode* m_pNext;
}ListNode;

// 打印链表

void printListNode(ListNode *pHead)
{
    while(pHead)
    {
        printf("%d\t",pHead->m_nValue);
        pHead = pHead->m_pNext;
    }
    printf("\n");
}

// 销毁链表

void DestroyListNode(ListNode **pHead)
{
   ListNode* pNode = *pHead; 
    while(pNode)
    {
        ListNode *temp = pNode;
        pNode = pNode->m_pNext;

        free(temp);
        temp = NULL;
    }
}

// 创建链表结点

ListNode *CreatedLinkNode(int num)
{
   ListNode *pNew = (ListNode*) malloc(sizeof(ListNode));
    if(NULL == pNew)
    {
        printf("pNew malloc failed!\n");
        return NULL;
    }
    pNew->m_nValue = num;
    pNew->m_pNext = NULL;

    return pNew;
}

// 连接两个结点

void ConnectNode(ListNode *pNode1,ListNode* pNode2)
{
   if( pNode1 == NULL || pNode2 == NULL ) 
        return;
    pNode1->m_pNext = pNode2;
    pNode2->m_pNext = NULL;
}

void DeleteNode(ListNode **pHead, ListNode *pToBeDeleted)
{
    // 检测边界条件
    if(!pHead || !pToBeDeleted)
        return; 
    
    // 要删除的结点不是尾结点

    if(pToBeDeleted->m_pNext != NULL)
    {
        ListNode *pNext = pToBeDeleted->m_pNext; 
        pToBeDeleted->m_nValue = pNext->m_nValue; 
        pToBeDeleted->m_pNext = pNext->m_pNext;

        free(pNext);
        pNext = NULL;
    }
    // 链表只有一个结点，删除尾结点
    
    else if(*pHead == pToBeDeleted)
    {
        free(pToBeDeleted);
        pToBeDeleted = NULL;
        *pHead = NULL;
    }
    // 链表中多个结点，删除尾结点
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = NULL;
        free(pToBeDeleted);
        pToBeDeleted = NULL;
    }

}


// 测试用例

void test()
{
   ListNode* pNode1 = CreatedLinkNode(1); 
   ListNode* pNode2 = CreatedLinkNode(2); 
   ListNode* pNode3 = CreatedLinkNode(3); 
   ListNode* pNode4 = CreatedLinkNode(4); 
   ListNode* pNode5 = CreatedLinkNode(5); 

    ConnectNode(pNode1,pNode2);
    ConnectNode(pNode2,pNode3);
    ConnectNode(pNode3,pNode4);
    ConnectNode(pNode4,pNode5);

    printListNode(pNode1);

    // 删除中间结点 3
    DeleteNode(&pNode1,pNode3);
    printListNode(pNode1);
    
    // 删除尾部结点 5
    DeleteNode(&pNode1,pNode5);
    printListNode(pNode1);
    
    // 删除头部结点 1
    DeleteNode(&pNode1,pNode1);
    printListNode(pNode1);

    DestroyListNode(&pNode1);

}

int main(void)
{
    test();
    return 0;
}
