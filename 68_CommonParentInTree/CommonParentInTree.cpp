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
                
    return pBinaryTreeNode;
}        
  
// 连接二叉树的结点
void ConnectTreeNodes(BinaryTreeNode *pParent,BinaryTreeNode *pLeft,BinaryTreeNode *pRight)
{                   
    if( pParent != NULL )
    {               
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
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

// 要求：树为二叉排序树

BinaryTreeNode *GetLastCommonParent(BinaryTreeNode *pRoot,BinaryTreeNode *pNode1,BinaryTreeNode *pNode2)
{
   if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL) 
        return NULL;
   
    if(pRoot->m_nValue >pNode1->m_nValue && pRoot->m_nValue>pNode2->m_nValue)
        return GetLastCommonParent(pRoot->m_pLeft,pNode1,pNode2);
    else if(pRoot->m_nValue < pNode1->m_nValue && pRoot->m_nValue<pNode2->m_nValue)
        return GetLastCommonParent(pRoot->m_pRight,pNode1,pNode2);
    else if(pRoot->m_nValue > pNode1->m_nValue && pRoot->m_nValue < pNode2->m_nValue) 
        return  pRoot;
    return pRoot;
}

// 二叉排序树测试用例

void test1()
{
    // 创建结点
    BinaryTreeNode *pNode10 = CreateBinaryNode(10);
    BinaryTreeNode *pNode9 = CreateBinaryNode(9);
    BinaryTreeNode *pNode8 = CreateBinaryNode(8);
    BinaryTreeNode *pNode7= CreateBinaryNode(7);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryNode(1);

    // 连接排序二叉树的结点

    ConnectTreeNodes(pNode5,pNode3,pNode8);
    ConnectTreeNodes(pNode3,pNode2,pNode4);
    ConnectTreeNodes(pNode8,pNode6,pNode9);
    ConnectTreeNodes(pNode2,pNode1,NULL);
    ConnectTreeNodes(pNode6,pNode7,pNode10);

    // 获取二叉排序树的最低公共祖先
    BinaryTreeNode *LastCommonParent = GetLastCommonParent(pNode5,pNode1,pNode6);
    if( LastCommonParent == NULL )
        printf("不存在最低公共结点或出错!\n");
    else
        printf("%d 和 %d 在排序二叉树中的最低公共结点是：%d\n",pNode1->m_nValue,pNode6->m_nValue,LastCommonParent->m_nValue); 

    // 销毁二叉排序树
    DestroyTree(pNode5);
}


int main(void)
{
    test1();
    return 0;
}
