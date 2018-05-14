/*************************************************************************
	> File Name: SubstructureInTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月25日 星期日 10时40分46秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct BinaryTreeNode
{
    double m_dbValue;
    BinaryTreeNode * m_pLeft;
    BinaryTreeNode *m_pRight;
};

// 二叉树结点的创建

BinaryTreeNode* CreateBinaryNode(double val)
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
        printf("value of this node is : %lf\n",pNode->m_dbValue);
        
        if(pNode->m_pLeft != NULL)
            printf("value of its left child is : %lf\n",pNode->m_pLeft->m_dbValue);        
        else
            printf("left child is NULL\n");
        
        if(pNode->m_pRight != NULL) 
            printf("value of its right child is : %lf\n",pNode->m_pRight->m_dbValue);        
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

// 判断两个 double 数值是否相等。由于 double 和 float 在计算机中存储的数值有误差，所以只有当 |a-b| < 0.0000001 的时候才算
// 两个数字相等
bool Equal(double num1,double num2)
{
    if( (num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}

//  两个二叉树的根节点相同，递归判断两个二叉树的根节点下的左右子树
bool DoesTree1HaveTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2)
{
    if(pRoot2 == NULL)
        return true;        
    if(pRoot1 == NULL)
        return false;
    if( !Equal(pRoot1->m_dbValue,pRoot2->m_dbValue))
        return false;        
    
    return DoesTree1HaveTree2(pRoot1->m_pLeft,pRoot2->m_pLeft) && DoesTree1HaveTree2(pRoot1->m_pRight,pRoot2->m_pRight);
}

// 第一步
// 遍历二叉树 A ，在 A 中查找与子树 B 的根节点值一样的结点

bool HasSubTree(BinaryTreeNode* pRoot1,BinaryTreeNode *pRoot2)
{
   bool result = false;
    if(pRoot1 != NULL && pRoot2 != NULL)
    {
        // 判断两个根节点的值是否相同,如果相同，则调用 DoesTree1HaveTree2 来进行第二步判断
        if( Equal(pRoot1->m_dbValue,pRoot2->m_dbValue) )
            result = DoesTree1HaveTree2(pRoot1,pRoot2);

        // 递归遍历根节点的左右子树，判断二叉树 A 是否存在子树 B
        if(!result)
            result = HasSubTree(pRoot1->m_pLeft,pRoot2);
        if(!result)
            result = HasSubTree(pRoot1->m_pRight,pRoot2);
    }
    
    return result;
}

// 测试代码

void test()
{
    // 创建 二叉树 A 的各个节点
    BinaryTreeNode *pNodeA1 = CreateBinaryNode(8);    
    BinaryTreeNode *pNodeA2 = CreateBinaryNode(8);    
    BinaryTreeNode *pNodeA3 = CreateBinaryNode(7);    
    BinaryTreeNode *pNodeA4 = CreateBinaryNode(9);    
    BinaryTreeNode *pNodeA5 = CreateBinaryNode(2);    
    BinaryTreeNode *pNodeA6 = CreateBinaryNode(4);    
    BinaryTreeNode *pNodeA7 = CreateBinaryNode(7);    
   
    // 连接二叉树 A 的各个节点，建立二叉树
    ConnectTreeNodes(pNodeA1,pNodeA2,pNodeA3);
    ConnectTreeNodes(pNodeA2,pNodeA4,pNodeA5);
    ConnectTreeNodes(pNodeA5,pNodeA6,pNodeA7);

    // 创建二叉树 B 的各个节点
    BinaryTreeNode *pNodeB1 = CreateBinaryNode(8); 
    BinaryTreeNode *pNodeB2 = CreateBinaryNode(9); 
    BinaryTreeNode *pNodeB3 = CreateBinaryNode(2); 
    
    // 连接二叉树 B 的各个节点，建立二叉树
    ConnectTreeNodes(pNodeB1,pNodeB2,pNodeB3);

    // 打印二叉树 A 和 二叉树 B

    printTree(pNodeA1);
    printTree(pNodeB1);

    bool res = HasSubTree(pNodeA1,pNodeB1);
    if( res )
    {
        printf("二叉树 B 是 二叉树 A 的子树\n");        
    }
    else
    {
        printf("二叉树 B 不是 二叉树 A 的子树\n");        
    }

    // 销毁二叉树
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);

}

int main(void)
{
    test();
    return 0;
}
