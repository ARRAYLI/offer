/*************************************************************************
	> File Name: PrintListInReversedOrder.c
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月13日 星期二 01时47分08秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;


// 链表存储结构

typedef struct _ListNode
{
    int m_nKey;
    struct _ListNode *next;
}ListNode;

// 链表尾插法

void InsertByTail(ListNode **pHead,int val)
{
   if(*pHead == NULL) 
    {
       *pHead =  (ListNode*)malloc(sizeof(ListNode));
        if( NULL == *pHead)
        {
            printf("malloc failed!\n");
            return;
        }
        (*pHead)->m_nKey = val;
        (*pHead)->next = NULL;
    }
    else
    {
        ListNode * pTemp = *pHead;         
        ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
        if( NULL == pNew)
        {
            printf("malloc failed!\n");
            return;
        }
        
        pNew->m_nKey = val;
        pNew->next = NULL;
    
        // 遍历到倒输第一个结点
        while( pTemp->next != NULL)
        {
           pTemp = pTemp->next; 
        }
        
        // 把新节点添加到链表尾部
        pTemp->next = pNew;
    }

}

// 销毁链表

void freeList(ListNode **pHead)
{
    ListNode * pTemp = *pHead;
    while( pTemp != NULL )
    {
        ListNode *temp = pTemp;
        pTemp = pTemp->next; 
        free(temp);
        temp = NULL;
    }
}

// 使用 栈 stack 来逆序打印数据

void Stack_Print(ListNode **pHead)
{
    if(*pHead == NULL)
    {
        printf("链表为空!\n"); 
        return;
    }
    stack<ListNode*>  s;

    ListNode *temp = *pHead;
    while( temp != NULL )
    {
        s.push(temp);
        temp = temp->next;
    }

    while(!s.empty())
    {
        ListNode * temp = s.top();
        s.pop();
        printf("%d\t",temp->m_nKey);
    }
}


// 利用递归的方法来逆序打印出数据

void Recursion_Print(ListNode **pHead)
{
    if(*pHead == NULL)
    {
        printf("链表为空!\n"); 
        return;
    }
    ListNode *temp = *pHead;

    if(temp != NULL)
    {
        if(temp->next != NULL)        
        {
            Recursion_Print(&(temp->next));
        }
        printf("%d\t",temp->m_nKey);
    }
}


// 遍历输出数据
void print(ListNode ** pHead)
{
    ListNode *temp = *pHead;
    if(*pHead == NULL)
    {
        printf("链表为空!\n"); 
        return;
    }
    while(temp != NULL) 
    {
        printf("%d\n",temp->m_nKey);
        temp = temp->next;
    }
}

// 测试用例1：输入的链表有多个结点

void test1()
{
    ListNode *list = NULL;

    InsertByTail(&list,1);
    InsertByTail(&list,2);
    InsertByTail(&list,3);
    InsertByTail(&list,4);

    print(&list);

    Recursion_Print(&list);
    printf("\n");
    Stack_Print(&list);
    printf("\n");
    freeList(&list);
}

// 测试用例2: 输入的链表有一个结点

void test2()
{

     ListNode *list = NULL;

    InsertByTail(&list,1);
    print(&list);

    Recursion_Print(&list);
    printf("\n");

    Stack_Print(&list);
    printf("\n");

    freeList(&list);

}

// 测绘用例3: 输入的链表指针结点为 NULL

void test3()
{
    ListNode *list = NULL;

    print(&list);

    Recursion_Print(&list);
    printf("\n");

    Stack_Print(&list);
    printf("\n");

    freeList(&list);
}

int main(void)
{
    test1();
    test2();
    test3();
    return 0;
}
