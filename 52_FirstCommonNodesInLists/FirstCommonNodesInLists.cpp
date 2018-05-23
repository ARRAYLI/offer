/*************************************************************************
	> File Name: FirstCommonNodesInLists.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月26日 星期四 15时02分40秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
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
    if( pNode1 == NULL || pNode2 == NULL  ) 
        return;
    pNode1->m_pNext = pNode2;
    pNode2->m_pNext = NULL;
}                                                                                                                                    
// 获取链表的长度

int getLinkListLength(ListNode *pHead)
{
    int count = 0;
   while(pHead != NULL)
    {
        count++;
        pHead = pHead->m_pNext;
    }

    return count;
}

// 获取两个链表的第一个公共结点
ListNode* FindFirstCommonNode(ListNode* pHead1,ListNode* pHead2)
{
   // 获取两个链表的长度 
    int len1 = getLinkListLength(pHead1);
    int len2 = getLinkListLength(pHead2);
   
    int nLenDif = len1-len2;

    ListNode *pLong = pHead1;
    ListNode* pShort = pHead2;
    if(len2 > len1)
    {
       pLong = pHead2;
        pShort = pHead1;
        nLenDif = len2-len1;     
    }
    
    // 先在长链表上走几步，再同时 在两个链表上遍历

    for(int i=0;i<nLenDif;i++)
        pLong = pLong->m_pNext;

    while(pLong != NULL && pShort != NULL && pLong != pShort)
    {
        pLong = pLong->m_pNext;
        pShort = pShort->m_pNext;
    }
    ListNode *pFirstCommonNode = pLong;
    return pFirstCommonNode;
}

// 销毁链表
void DestroyListNode(ListNode **pHead1,ListNode **pHead2)
{
    ListNode *pFirstCommonNode = FindFirstCommonNode(*pHead1,*pHead2);
   
    ListNode *temp1 = *pHead1;
    ListNode *temp2 = *pHead2;
    /* 销毁链表1 到 pFirstCommonNode 结点之前 */
    while(temp1 != pFirstCommonNode)
    {
        ListNode *temp  = temp1;
        temp1 = temp->m_pNext;
        
        free(temp);
        temp = NULL;
    }

    /* 销毁链表2 到 pFirstCommonNode 结点之前 */
    while(temp2 != pFirstCommonNode)
    {
        ListNode *temp  = temp2;
        temp2 = temp->m_pNext;
        
        free(temp);
        temp = NULL;
    }
    /* 销毁链表1 和 链表公共部分结点  */
    while(temp1 != NULL)
    {
        ListNode *temp  = temp1;
        temp1 = temp->m_pNext;
        
        free(temp);
        temp = NULL;
    }

}

// 测试用例

void test()
{
    // 创建链表结点
    ListNode *pNode1 = CreatedLinkNode(1);
    ListNode *pNode2 = CreatedLinkNode(2);
    ListNode *pNode3 = CreatedLinkNode(3);
    ListNode *pNode4 = CreatedLinkNode(4);
    ListNode *pNode5 = CreatedLinkNode(5);
    ListNode *pNode6 = CreatedLinkNode(6);
    ListNode *pNode7 = CreatedLinkNode(7);

    // 连接链表
    // 较长链表
    ConnectNode(pNode1,pNode2);
    ConnectNode(pNode2,pNode3);
    ConnectNode(pNode3,pNode6);
    ConnectNode(pNode6,pNode7);


    // 较短链表
    ConnectNode(pNode4,pNode5);
    ConnectNode(pNode5,pNode6);
    ConnectNode(pNode6,pNode7);
    
    // 打印两个链表
    printListNode(pNode1);
    printListNode(pNode4);

    // 获取两个链表的第一个公共结点
    ListNode *pListFirstCommonNonde = FindFirstCommonNode(pNode1,pNode4);
    
    printf("两个链表的第一个公共结点是 ： %d\n",pListFirstCommonNonde->m_nValue);
    // 销毁链表
    DestroyListNode(&pNode1,&pNode4);
}



int main(void)
{
   test(); 
    return 0;
}
