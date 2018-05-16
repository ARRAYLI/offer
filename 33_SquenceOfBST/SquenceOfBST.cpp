/*************************************************************************
	> File Name: SquenceOfBST.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月29日 星期四 00时57分56秒
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


// 判断输入的整数数组是否是二叉搜索树树的后续遍历结果
bool VerifySquenceOfBST(int *sequence,int length)
{
    if(sequence == NULL || length<= 0)
        return false;

    int root = sequence[length - 1];
    
    // 在二叉搜素数中左子树的结点的值小于根节点的值
    int i  = 0;
    for(;i<length - 1;i++)
    {
       if(sequence[i] > root) 
            break;
    }
    
    // 在二叉搜树中右子树的结点的值大于根节点的值
    int j = i;
    for(;j<length-1;j++) 
    {
        // 如果右子树中有比根节点值小的数，则该序列不是二叉排序树的后序遍历结果 
       if(sequence[j] < root) 
            return false;
    }
    
    // 判断左子树是不是二叉搜索树
    bool left = true;
    if(i>0)
        left = VerifySquenceOfBST(sequence,i);

    // 判右子树是不是二叉搜索树
    bool right = true;
    if(j>0)
        right = VerifySquenceOfBST(sequence,j);

    return (left && right);
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
   
    int sequence[] = {5,7,6,9,11,10,8};
    int length = sizeof(sequence) / sizeof(sequence[0]);

    // 判断输入的整数数组是否是二叉搜索树树的后续遍历结果
    bool res = VerifySquenceOfBST(sequence,length);
    if(res)
    {
        printf("该序列是二叉搜索树的后续遍历结果!\n");     
    }
    else
    {
        printf("该序列不是二叉搜索树的后续遍历结果!\n");     
    }
    
    // 销毁二叉树
    DestroyTree(pNode8);
}


int main(void)
{
    test();
    return 0;
}

