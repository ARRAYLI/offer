/*************************************************************************
	> File Name: SymmetricalBinaryTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月27日 星期二 01时27分51秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
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

bool isSymmetrical(BinaryTreeNode *pRoot1,BinaryTreeNode* pRoot2)
{
    // 如果二叉树的左右，子节点都为 NULL，则返回 true
    if(pRoot1 == NULL && pRoot2 == NULL)
        return true;

    // 如果二叉树的左、有子节点中有一个为 NULL ，则二叉树是不对称的
    if(pRoot1 == NULL || pRoot2 == NULL)
        return false;
    
    // 如果二叉树的左右子节点的值不相等的话，则返回 false
    if(pRoot1->m_dbValue != pRoot2->m_dbValue)
        return false;

    // 递归遍历二叉树的左子树左子节点的值，判断是否和右子树右子节点值是否相同
    // 递归遍历二叉树右子树的右子节点的值是否和左子树的左子节点相同
    return isSymmetrical(pRoot1->m_pLeft,pRoot2->m_pRight) && isSymmetrical(pRoot1->m_pRight,pRoot2->m_pLeft);
}

// 判断一颗二叉树是否是对称的二叉树，只需要传一个根节点
// 然后进行递归判断二叉树是否是对称二叉树
bool isSymmetrical(BinaryTreeNode *pRoot)
{
    return isSymmetrical(pRoot,pRoot);
}

void test()
{
   // 创建二叉树的各个节点

    BinaryTreeNode *pNode1 = CreateBinaryNode(8);
    BinaryTreeNode *pNode2 = CreateBinaryNode(6);
    BinaryTreeNode *pNode3 = CreateBinaryNode(6);
    BinaryTreeNode *pNode4 = CreateBinaryNode(5);
    BinaryTreeNode *pNode5 = CreateBinaryNode(7);
    BinaryTreeNode *pNode6 = CreateBinaryNode(7);
    BinaryTreeNode *pNode7 = CreateBinaryNode(5);
    
    // 连接二叉树的结点
    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,pNode5);
    ConnectTreeNodes(pNode3,pNode6,pNode7);
        
    // 打印二叉树
    printTree(pNode1);

    bool res = isSymmetrical(pNode1);
    if(res)
    {
        printf("此二叉树是一颗对称二叉树\n");
    }
    else
    {
        printf("此二叉树不是一颗对称二叉树\n");
    }
    // 销毁二叉树
    DestroyTree(pNode1);
}


int main(void)
{
    test();

    return 0;
}
