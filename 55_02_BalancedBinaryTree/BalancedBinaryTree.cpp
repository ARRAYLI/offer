/*************************************************************************
	> File Name: TreeDepth.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月15日 星期日 00时45分12秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
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
    if( pBinaryTreeNode == NULL)
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
    if( pParent != NULL    )
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

// 获取二叉树的深度

int TreeDepth(BinaryTreeNode *pRoot)
{
    if( pRoot == NULL)
    return 0;

    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight); 

    int res = left > right ? left+1:right+1;

    return res;
}

// 需要重复遍历结点多次的解法，简单但不足以打动面试官

// 判断一颗二叉树是否是平衡二叉树

bool isBalanced(BinaryTreeNode *pRoot)
{
   if( pRoot == NULL ) 
        return true;
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);

    int ret = left - right;
    if( ret >1 || ret < -1)
        return false;
    return isBalanced(pRoot->m_pLeft) && isBalanced(pRoot->m_pRight);
}



// 解法二：每个结点只遍历一次，正是面试官喜欢的

bool isBalanced(BinaryTreeNode *pRoot,int *pDepth)
{
    if( pRoot == NULL )    
    {
        *pDepth = 0;
        return true;
    }
    
    int left,right;
    if(isBalanced(pRoot->m_pLeft,&left) && isBalanced(pRoot->m_pRight,&right))
    {
        int dif = left - right;
        if( dif<= 1 || dif >= -1 )
        {
            *pDepth =1+(left > right? left:right); 
            return true;
        }
    }
    
    return false;
}

bool isBalanced2(BinaryTreeNode *pRoot)
{
    int depth = 0;
    return isBalanced(pRoot,&depth);
}


// 测试用例

void test()
{
    // 创建结点
    BinaryTreeNode *pNode1 = CreateBinaryNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode7 = CreateBinaryNode(7);

    // 连接结点
    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,pNode5);
    ConnectTreeNodes(pNode5,pNode7,NULL);
    ConnectTreeNodes(pNode3,NULL,pNode6);
   
    
    bool ret = isBalanced(pNode1);
    if(ret)
        printf("二叉树是一颗平衡二叉树\n");
    else
        printf("二叉树不是一颗平衡二叉树\n");
    
    ret = isBalanced2(pNode1);
    if(ret)
        printf("二叉树是一颗平衡二叉树\n");
    else
        printf("二叉树不是一颗平衡二叉树\n");
   
    // 销毁二叉树
    DestroyTree(pNode1);
}

int main(void)
{
    test();

    return 0;
}
