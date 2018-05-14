/*************************************************************************
	> File Name: MirrorOfBinaryTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月25日 星期日 11时39分31秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;

struct BinaryTreeNode
{
    int m_dbValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode *m_pRight;
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
    pBinaryTreeNode->m_dbValue = val;
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

// 打印二叉树的单个节点

void printBinaryTreeNode( const BinaryTreeNode *pNode)
{
    if(NULL != pNode) 
    {
        printf("value of this node is : %d\n",pNode->m_dbValue);
        
        if(pNode->m_pLeft != NULL)
            printf("value of its left child is : %d\n",pNode->m_pLeft->m_dbValue);        
        else
            printf("left child is NULL\n");
        
        if(pNode->m_pRight != NULL) 
            printf("value of its right child is : %d\n",pNode->m_pRight->m_dbValue);        
        else
            printf("left child is NULL\n");
    }
    else
    {
       printf("this node is NULL\n"); 
    }
}

// 打印二叉树

void printTree(const BinaryTreeNode *pRoot)
{
    printBinaryTreeNode(pRoot);
   if(pRoot != NULL) 
    {
        if(pRoot->m_pLeft != NULL)
            printTree(pRoot->m_pLeft);
        if(pRoot->m_pRight != NULL)
            printTree(pRoot->m_pRight);
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

// 递归求出二叉树的镜像
void MirrorRecursively(BinaryTreeNode *pNode)
{
    // 判断如果根节点是空的话，直接返回
   if(pNode == NULL) 
        return;
    
    // 判断根节点的左右子树是否为空，为空的话直接返回
    if(pNode->m_pLeft == NULL && pNode->m_pRight == NULL)
        return;

    // 交换根节点下的左右非叶节点的所有子节点
    BinaryTreeNode *temp = pNode->m_pLeft;    
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = temp;

    // 递归遍历当前结点结点下左子树的所有子节点 
    if(pNode->m_pLeft)
        MirrorRecursively(pNode->m_pLeft);

    // 递归遍历当前结点结点下右子树的所有子节点 
    if(pNode->m_pRight)
        MirrorRecursively(pNode->m_pRight);
}

// 非递归法求出二叉树的镜像

void  MirrorRecursivelyOfStack(BinaryTreeNode *pRoot)
{
    if(pRoot == NULL)
        return;

    stack<BinaryTreeNode*> stackTree;
    stackTree.push(pRoot);
    
    while(stackTree.size()>0)
    {
        BinaryTreeNode* pNode = stackTree.top();
        stackTree.pop();

        BinaryTreeNode *temp = pNode->m_pLeft;
        pNode->m_pRight = pNode->m_pRight;
        pNode->m_pRight = temp;
        
        if(pNode->m_pLeft)
            stackTree.push(pNode->m_pLeft);
        if(pNode->m_pRight)
            stackTree.push(pNode->m_pRight);

    }    
}


void test()
{
   // 创建二叉树的各个节点

    BinaryTreeNode *pNode8 = CreateBinaryNode(8);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode10 = CreateBinaryNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode7 = CreateBinaryNode(7);
    BinaryTreeNode *pNode9 = CreateBinaryNode(9);
    BinaryTreeNode *pNode11 = CreateBinaryNode(11);
    
    // 连接二叉树的结点
    ConnectTreeNodes(pNode8,pNode6,pNode10);
    ConnectTreeNodes(pNode6,pNode5,pNode7);
    ConnectTreeNodes(pNode10,pNode9,pNode11);
        
    // 打印二叉树
    printTree(pNode8);

    // 获取二叉树的镜像
    MirrorRecursively(pNode8); 

    printTree(pNode8);
    // 销毁二叉树
    DestroyTree(pNode8);
}


int main(void)
{
    test();

    return 0;
}
