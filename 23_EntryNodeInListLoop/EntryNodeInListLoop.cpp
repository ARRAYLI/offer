/*************************************************************************
	> File Name: KthNodeFromEnd.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月23日 星期五 20时28分11秒
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

// 找到快慢指针相遇的结点

ListNode* MeetingNode(ListNode* pHead)
{
   if(pHead == NULL) 
        return NULL;

    ListNode *pSlow = pHead->m_pNext;       // 快指针

    // 检查链表是否只有一个节点
    if(pSlow == NULL)
        return NULL;

    ListNode *pFast = pSlow->m_pNext;       // 慢指针

    // 循环遍找到快慢指着相遇的结点
    while(pFast != NULL && pSlow != NULL )
    {
        // pFast == pSlow 表示两个指针相遇，找到相遇结点
        if(pFast == pSlow)
            return pFast;

        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;

        // 防止 pFast 到了链表尾部，造成程序出错
        // 快指针每次走两步，慢指针每次走一步
        if(pFast != NULL)
        {
            pFast = pFast->m_pNext; 
        }
        
    }
    // 没有找到相遇结点，即链表不存在环
    return NULL;
}


// 寻找环中的结点个数，然后找到换的入口点

ListNode *EntryNodeOfLoop(ListNode *pHead)
{
    // 找到两个指针相遇的结点
   ListNode *meetingNode = MeetingNode(pHead); 
    
    if(NULL == meetingNode)
        return NULL; 
    
    // 获取环中的结点个数
    int nodesInLoop = 1;
    ListNode *pNode1 = meetingNode;
    
    // 循环遍历，当遍历到下一个结点和相遇结点相同的话，即可求出环中结点的个数
    while(pNode1->m_pNext != meetingNode)
    {
        nodesInLoop++;
        pNode1 = pNode1->m_pNext;
    }

    // 从链表的头部开始遍历
    pNode1 = pHead;
    // 从链表的头部向后遍历 nodesInLoop 各节点
    for(int i = 0;i<nodesInLoop; i++)
    {
       pNode1 = pNode1->m_pNext; 
    }
    
    ListNode* pNode2 = pHead;
    // 开始循环遍历两个指针，知道两指针所指向的结点相同时，则找到链表的环的入口结点
    while(pNode1 != pNode2)
    {
       pNode1 = pNode1->m_pNext; 
        pNode2 = pNode2->m_pNext;
    }

    return pNode1;
}

// 销毁链表

void DestroyListNode(ListNode* pHead)
{
    // 获取链表的环的肉蔻结点
    ListNode* pNodeOfLoop = EntryNodeOfLoop(pHead);

    // 如果是环，而已知环的入口结点,环形链表的销毁方法如下
    if( NULL != pNodeOfLoop)
    {
        ListNode *FindNodeOfTail = pHead;
        while(FindNodeOfTail->m_pNext != pNodeOfLoop)
        {
            FindNodeOfTail = FindNodeOfTail->m_pNext;
        }
        // 把最后一个结点的指针，指向 NULL,不在指向环
        FindNodeOfTail->m_pNext = NULL;
    }
    while(pHead)
    {
        ListNode *temp = pHead;
        pHead = pHead->m_pNext;

        free(temp);
        temp = NULL;
    }
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
   
    // 使链表存在环
    ConnectListNode(pNode6,pNode3);

    // 获取环的入口结点
    ListNode *temp = EntryNodeOfLoop(pNode1);
    if( NULL == temp )
    {
        printf("链表不存在环!\n");
    }
    else
    {
        printf("环的入口结点是：%d\n",temp->m_nVale);
    }
    // 销毁链表
    DestroyListNode(pNode1);

}
int main(void)
{
   test(); 
    return 0;
}
