/*************************************************************************
	> File Name: PrintTreeFromTopToBottom.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月28日 星期三 23时41分30秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;
 
 struct BinaryTreeNode
 {
         int m_nValue;
         BinaryTreeNode * m_pLeft;
     BinaryTreeNode *m_pRight;

 };

  // 二叉树结点的创建

 BinaryTreeNode* CreateBinaryNode(int val)
 {
     BinaryTreeNode *pBinaryTreeNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
     if( pBinaryTreeNode == NULL  )
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
     if( pParent != NULL  )
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
 
void PrintFromTopToBottom(BinaryTreeNode *pTreeRoot)
{
    if(pTreeRoot == NULL) 
       return;
    
    deque<BinaryTreeNode*> dequeTreeNode;

    // 把二叉树的根节点加入到到队列中
    dequeTreeNode.push_back(pTreeRoot);

    while(dequeTreeNode.size())
    {
       BinaryTreeNode *pNode = dequeTreeNode.front(); 
        dequeTreeNode.pop_front();
        
        printf("%d\t",pNode->m_nValue);
        
        if(pNode->m_pLeft)
            dequeTreeNode.push_back(pNode->m_pLeft);
        if(pNode->m_pRight)
            dequeTreeNode.push_back(pNode->m_pRight);
    }
    printf("\n");
}

// 测试用例

void test()
{
    //创建二叉树结点
    BinaryTreeNode *pNode8 = CreateBinaryNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryNode(11);

    // 连接二叉树的各个节点
    ConnectTreeNodes(pNode8,pNode6,pNode10);
    ConnectTreeNodes(pNode6,pNode5,pNode7);
    ConnectTreeNodes(pNode10,pNode9,pNode11);
    
    // 从上到下打印二叉树
    PrintFromTopToBottom(pNode8);
    
    // 销毁二叉树
    DestroyTree(pNode8);
}

int main(void)
{
    test();
    return 0;
}
