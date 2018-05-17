/*************************************************************************
	> File Name: CopyComplexList.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月30日 星期五 13时48分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct ListNode
{
    int m_nVale;
    ListNode* m_pNext;
    ListNode* m_pSibling;
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
    pNew->m_pSibling = NULL;

    return pNew;
}

// 连接链表

void ConnectListNode(ListNode* pNode,ListNode* pNext,ListNode* pSibling)
{
   if(pNode != NULL) 
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

// 打印链表

void printListNode(ListNode *pNode)
{
   while(pNode)
    {
        printf("The value of this node is :%d\n",pNode->m_nVale);
        if(pNode->m_pSibling)
            printf("The value of its sibling is : %d\n",pNode->m_pSibling->m_nVale);    
        else
            printf("This node does not have a sibling\n");
        
        printf("\n");
        pNode = pNode->m_pNext;
    }
    printf("\n");
}

void print(ListNode *pHead)
{
    while( NULL != pHead )
    {
        printf("%d\t",pHead->m_nVale);
        pHead = pHead->m_pNext;
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

// 复杂链表复制：第一步
// 复制原始链表结点，并把复制的结点连接在当前结点的后面

void CloneNodes(ListNode* pHead)
{
   ListNode* pNode = pHead; 
    
    while(pNode != NULL)
    {
       ListNode *pCloned = (ListNode*) malloc(sizeof(ListNode));
        if( pCloned == NULL )
        {
           printf("pCloned malloc failed!\n"); 
            return;
        }
        pCloned->m_nVale = pNode->m_nVale;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = NULL;
        pNode->m_pNext = pCloned;
        
        pNode = pCloned->m_pNext;
    }

}

// 复杂链表复制：第二步
// 设置复制出来的结点的 m_pSibling 
// 假设原始链表上的 N 的 m_pSibling 指向结点 S ，那么对其复制出来的 N' 是 N 的 m_pNext 指向的结点
// 同样，S' 也是 S 的 m_pNext 指向的 结点。

void ConnectSiblingNodes(ListNode *pHead)
{
   ListNode *pNode = pHead; 
    
    while(pNode != NULL)
    {
       ListNode* pCloned = pNode->m_pNext; 
        if(pNode->m_pSibling != NULL)
        {
           pCloned->m_pSibling = pNode->m_pSibling->m_pNext; 
        }
        pNode = pCloned->m_pNext;
    }
}

// 复杂链表复制：第三步
// 把第二部得到的链表拆分成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表

ListNode* RecoonectNodes(ListNode *pHead)
{
   ListNode* pNode = pHead; 
    ListNode* pClonedHead = NULL;
    ListNode * pClonedNode = NULL;
    
    if(pNode != NULL)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    while(pNode != NULL)
    {
       pClonedNode->m_pNext = pNode->m_pNext; 
        pClonedNode = pClonedNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    
    return pClonedHead;
}

// 合并上面三步过程，就是复杂链表的复制过程

ListNode *Clone(ListNode* pHead)
{
    CloneNodes(pHead);
    ConnectSiblingNodes(pHead);
    return RecoonectNodes(pHead);
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

    // 连接链表的结点
    ConnectListNode(pNode1,pNode2,pNode3);
    ConnectListNode(pNode2,pNode3,pNode5);
    ConnectListNode(pNode3,pNode4,NULL);
    ConnectListNode(pNode4,pNode5,pNode2);

    // 打印链表结点
//    printListNode(pNode1);
 
    print(pNode1);
    ListNode* temp = Clone(pNode1);
    if(NULL == temp)
    {
        printf("copy falied!\n");
    }
    else
    {
        print(temp);
    }

    // 销毁链表
    DestroyListNode(pNode1);
    DestroyListNode(temp);

}
int main(void)
{
   test(); 
    return 0;
}
