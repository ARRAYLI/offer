/*************************************************************************
	> File Name: CommonParentInTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月24日 星期二 19时13分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

// 二叉树的存储结构

struct BinaryTreeNode
{ 
    int m_nValue;
    struct BinaryTreeNode *m_pLeft;                                                                             
    struct BinaryTreeNode *m_pRight;
    struct BinaryTreeNode *m_pParent;
};
  
// 二叉树结点的创建
BinaryTreeNode* CreateBinaryNode(int val)
{                   
    BinaryTreeNode *pBinaryTreeNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if( pBinaryTreeNode == NULL )
    {               
             printf("pBinaryTreeNode malloc failed!\n"); 
             return NULL;
    }               
    pBinaryTreeNode->m_nValue = val;
    pBinaryTreeNode->m_pLeft = NULL;
    pBinaryTreeNode->m_pRight = NULL;
    pBinaryTreeNode->m_pParent = NULL;
                
    return pBinaryTreeNode;
}        
  
// 连接二叉树的结点
void ConnectTreeNodes(BinaryTreeNode *pParent,BinaryTreeNode *pLeft,BinaryTreeNode *pRight)
{                   
    if( pParent != NULL )
    {               
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
        pLeft->m_pParent = pParent;
        pRight->m_pParent = pParent;
    }               
}   
  
// 销毁二叉树 
 
 void DestroyTree(BinaryTreeNode *pRoot)
 {                  
     if(pRoot != NULL)
     {              
             BinaryTreeNode *pLeft = pRoot->m_pLeft;
             BinaryTreeNode *pRight = pRoot->m_pRight;
                      
              free(pRoot);
              pRoot = NULL;
                     
              DestroyTree(pLeft);
              DestroyTree(pRight);
                     
            }              
 }         


//题目：树中两个结点的最低公共祖先

// 要求：树中包含指向父节点的指针

BinaryTreeNode *GetLastCommonParent(BinaryTreeNode *pNode1,BinaryTreeNode *pNode2)
{
    if( pNode1 != NULL && pNode2 != NULL )
    {
        BinaryTreeNode *p1 = pNode1;
        BinaryTreeNode *p2 = pNode2;

        while(p1 != NULL && p2 != NULL )
        {
            if( p1->m_nValue != p2->m_nValue )
            {
                p1 = p1->m_pParent;
                p2 = p2->m_pParent;
            }
            else
                return p1;
        }

    }
    return NULL;
}
// 二叉树测试用例

void test1()
{
    // 创建结点
    BinaryTreeNode *pNode7= CreateBinaryNode(7);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryNode(1);

    // 连接二叉树的结点

    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,pNode5);
    ConnectTreeNodes(pNode3,pNode6,pNode7);

    // 获取二叉树的最低公共祖先
    BinaryTreeNode *LastCommonParent = GetLastCommonParent(pNode4,pNode7);
    if( LastCommonParent == NULL )
        printf("不存在最低公共结点或出错!\n");
    else
        printf("%d 和 %d 在排序二叉树中的最低公共结点是：%d\n",pNode4->m_nValue,pNode7->m_nValue,LastCommonParent->m_nValue); 

    LastCommonParent = GetLastCommonParent(pNode6,pNode7);
    if( LastCommonParent == NULL )
        printf("不存在最低公共结点或出错!\n");
    else
        printf("%d 和 %d 在排序二叉树中的最低公共结点是：%d\n",pNode6->m_nValue,pNode7->m_nValue,LastCommonParent->m_nValue); 
    // 销毁二叉树
    DestroyTree(pNode1);
}


int main(void)
{
    test1();
    return 0;
}
