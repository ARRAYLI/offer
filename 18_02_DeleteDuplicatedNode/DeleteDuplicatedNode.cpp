/*************************************************************************
	> File Name: DeleteNodeInList.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月20日 星期二 13时16分11秒
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

// 尾插法建表

void InsertByTail(ListNode** pHead,int val)
{
    if(*pHead == NULL) 
    {
        *pHead = (ListNode*)malloc(sizeof(ListNode));
        if( *pHead == NULL ) 
        {
            printf("*pHead malloc failed!\n");
            return;
        }
        (*pHead)->m_nValue = val;
        (*pHead)->m_pNext = NULL;
    }
    else
    {
        ListNode* pNode = *pHead;
        ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
        if( NULL == pNew )
        {
            printf("pNew malloc failed!\n");
            return;
        }
        pNew->m_nValue = val;
        pNew->m_pNext = NULL;
        // 找到最后一个结点，然后把新建的结点连接到最后一个结点上
       while(pNode->m_pNext != NULL)
        {
            pNode = pNode->m_pNext;
        }
        
        pNode->m_pNext = pNew;
    }
}

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

// 删除重复的结点

void DeleteDuplication(ListNode **pHead)
{
    // 链表为空，或者链表只有一个结点则返回
    if(pHead == NULL || *pHead == NULL || (*pHead)->m_pNext == NULL)
        return;
    
    ListNode *pre = NULL;       // 用来标记当前结点的上一个节点
    ListNode *cur = *pHead;     // 当前结点

    while(cur)
    {
        ListNode *pNext = cur->m_pNext;        // 标记当前结点的下一个结点

        //若当前结点与下一个结点不重复
        if( pNext && cur->m_nValue != pNext->m_nValue)
        {
            pre = cur;              // 标记当前结点的前一个结点
            cur = pNext;            // 当前结点的下一个结点
        }
        // 若当前结点与下一个结点重复
        else if( pNext && cur->m_nValue == pNext->m_nValue )
        {
            ListNode *del = cur;        // 从当前结点开始删除重复结点
            int val = cur->m_nValue;
            while(del && del->m_nValue == val)          // 删除结点直到结点中的值不为重复值
            {
                pNext = del->m_pNext;
                
                free(del);
                del = NULL;
                del = pNext;
            }
            
            // 删除完重复的结点以后，pre 指向不重复结点对的下一个结点
            if(pre)      // 若头结点重复，则修改头结点
                pre->m_pNext = pNext;  // 若头结点不重复，将以前标记的结点直接与 pNext 相连
            else
                *pHead = pNext;        
        }
        cur = pNext;
    }
}

//删除有序链表重复的值  
void DeleteReV(ListNode** pHead)  
{  
    if(pHead==NULL||*pHead==NULL||(*pHead)->m_pNext==NULL)  //链表为空或只有一个节点直接返回  
        return;  
    ListNode* prev=NULL;    //标记当前结点前一个  
    ListNode* cur=*pHead;   //标记当前结点  
    while(cur)  
    {  
        ListNode* pNext=cur->m_pNext;  //标记下一个结点  
          
        if(pNext && pNext->m_nValue!=cur->m_nValue)   //若当前结点与下一个结点不重复  
        {  
            prev=cur;                //标记当前结点前一个结点  
            cur=pNext;              //当前结点走下一个  
        }  
        else if(pNext && pNext->m_nValue==cur->m_nValue)   //若当前结点与下一个结点重复  
        {  
            ListNode* del=cur;          //从当前节点开始删除重复节点  
            int value=cur->m_nValue;  
            while(del && del->m_nValue==value)    //删除停止时间是直到删除的节点值不为重复结点的值  
            {  
                pNext=del->m_pNext;   //用pNext做中间转换值  
                delete del;  
                del=pNext;  
            }   //完成以后pNext指向不重复节点值的第一个  
  
            if(prev)  
                prev->m_pNext=pNext;    //若头结点不重复，将以前标记的前一个节点直接与pNext连接  
            else  
                *pHead=pNext;   //头结点重复则改正头节点  
  
            cur=pNext;    //当前结点从pNext再次开始  
        }   
  
        //cur=pNext;  
    }  
}
// 测试用例

void test()
{
    ListNode *pHead = NULL;    
    InsertByTail(&pHead,1);
    InsertByTail(&pHead,2);
    InsertByTail(&pHead,3);
    InsertByTail(&pHead,3);
    InsertByTail(&pHead,4);
    InsertByTail(&pHead,4);
    InsertByTail(&pHead,5);
    
    //printListNode(pHead);
    printListNode(pHead);

    //InsertByTail(&pHead,6);
//    printListNode(pHead);
   
    
    //DeleteReValue(&pHead);
    DeleteDuplication(&pHead); 

    printListNode(pHead);
    //printListNode(&pHead);
    
    DestroyListNode(&pHead);
}


int main(void)
{

    test();
    return 0;
}
