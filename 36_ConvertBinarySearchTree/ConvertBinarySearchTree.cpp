/*************************************************************************
	> File Name: ConvertBinarySearchTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月30日 星期五 21时33分26秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef struct BinaryTreeNode
{
    int m_nValue;
    struct BinaryTreeNode * m_pLeft;
    struct BinaryTreeNode * m_pRight;
}*BiTree,BiNode;

// 扩展先序遍历创建二叉树

void CreateBinaryTree(BiTree *bt)
{
   int data;
    // 按先序序列，依次输入二叉树结点中的值
    
    scanf("%d",&data);
    if(data == -1)
    {
       *bt = NULL; 
    }
    else
    {
       *bt = (BiTree)malloc(sizeof(BiNode));
        if(  NULL == bt)
        {
           printf("bt malloc failed!\n"); 
            return;
        }
        (*bt)->m_nValue= data;        // 生成根节点
        CreateBinaryTree(&((*bt)->m_pLeft));          // 构造左子树
        CreateBinaryTree(&((*bt)->m_pRight));         // 构造右子树
    }
}

void ConvertNode(BiTree pNode,BiTree* pLastNodeInList)
{
    // 如果当前结点为空
    if(pNode == NULL)
        return;

    BiTree pCurrent = pNode;
    if(pCurrent->m_pLeft != NULL)
        ConvertNode(pCurrent->m_pLeft,pLastNodeInList);

    // pLastNodeInList 用来记录上一个节点
    pCurrent->m_pLeft = *pLastNodeInList;
    if(*pLastNodeInList != NULL)
        (*pLastNodeInList)->m_pRight = pCurrent;

    *pLastNodeInList = pCurrent;
    if(pCurrent->m_pRight != NULL)
        ConvertNode(pCurrent->m_pRight,pLastNodeInList);

}

BiTree Convert(BiTree pRootOfTree)
{
   BiTree pLastNodeInList = NULL;

    ConvertNode(pRootOfTree,&pLastNodeInList);
    
    // pLastNodeInList 指向双向链表的尾结点
    // 我们需要返回双向链表的头结点

    BiTree pHeadOfList = pLastNodeInList;
    while(pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
        pHeadOfList = pHeadOfList->m_pLeft;

    // 返回双向链表的头结点
    return pHeadOfList;
}

// 二叉树的先序遍历

void PreOrder(BiTree bt)
{
   if(bt != NULL) 
    {
        printf("%d\t",bt->m_nValue);
        PreOrder(bt->m_pLeft);
        PreOrder(bt->m_pRight);

    }
}

// 打印双向链表

void PrintLinkList(BiTree pHead)
{
    while(pHead != NULL)
    {
        printf("%d\t",pHead->m_nValue);
        pHead = pHead->m_pRight;
    }
    printf("\n");
}

// 测试用例

void test()
{
    BiTree bt = NULL;
   // 创建二叉树
   CreateBinaryTree(&bt); 
  
    printf("二叉树为：\n");
   // 打印二叉树
    PreOrder(bt);
    // 将二叉树转换成双向链表
    BiTree list =  Convert(bt);

    printf("\n双向链表为:\n");
    // 打印双向链表
    PrintLinkList(list);
}

int main(void)
{
    test();

    return 0;
}
