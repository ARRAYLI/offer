/*************************************************************************
	> File Name: KthNodeInBST.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月11日 星期三 20时24分38秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

// 算法思想：通过中序遍历即可从二叉搜索树中找到要查找的数值


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
    if( pBinaryTreeNode == NULL   )
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
    if( pParent != NULL   )
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


BinaryTreeNode *KthNodeCore(BinaryTreeNode *pRoot,int &k)
{
   if(pRoot == NULL || k <= 0) 
        return NULL;

    BinaryTreeNode *target = NULL;
  
    // 如果当前结点有左子树的话，继续递归遍历左子树
    if(pRoot->m_pLeft != NULL)
        target = KthNodeCore(pRoot->m_pLeft,k);
   
    // 如果当前结点的左子树为空
    if( target == NULL )
    {
        // 判断当前结点是否就是要找的那个结点,如果是的话，保留结点
        if(k == 1)        
            target = pRoot;
        // 如果不是继续遍历
        k--;
    }
    
    // 左子树遍历完后，如果目标结点还是没有找到的话，并且当前结点的右子树不为空，遍历当前结点的右子树
    if(target == NULL && pRoot->m_pRight != NULL)
        target = KthNodeCore(pRoot->m_pRight,k);

    // 返回目标结点
    return target;
}

BinaryTreeNode * KthNode(BinaryTreeNode *pRoot,int k)
{
    if(pRoot == NULL || k <= 0)
        return NULL;
    
    return KthNodeCore(pRoot,k);
}


// 中序遍历

void InOrder(BinaryTreeNode *pRoot)
{
    if(pRoot != NULL)
    {
        InOrder(pRoot->m_pLeft);
        printf("%d\t",pRoot->m_nValue);
        InOrder(pRoot->m_pRight);
    }

}

// 测试用例
   
void test()
{
    //创建二叉树结点
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode7 = CreateBinaryNode(7);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode8 = CreateBinaryNode(8);
    
    // 连接二叉树的各个节点
    ConnectTreeNodes(pNode5,pNode3,pNode7);
    ConnectTreeNodes(pNode3,pNode2,pNode4);
    ConnectTreeNodes(pNode7,pNode6,pNode8);
    
    // 二叉排序树的遍历

    InOrder(pNode5);
    printf("\n");

    int k = 0;
    printf("请输入要在二叉搜索树中要查找的第 K 大结点:\n");
    scanf("%d",&k);
    // 查找二叉搜搜树中的第 k 个结点

    BinaryTreeNode *node = KthNode(pNode5,k);
    if( node == NULL )
        printf("没有找到或者程序出错\n");
    else
        printf("二叉搜索树中第 %d 大结点是： %d\n",k,node->m_nValue);

    // 销毁二叉树
    DestroyTree(pNode5);
    
}   
   


int main(void)
{
    test(); 
    return 0;
}
