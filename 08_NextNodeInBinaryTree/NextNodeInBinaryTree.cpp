/*************************************************************************
	> File Name: NextNodeInBinaryTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月14日 星期三 20时56分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stack>
using namespace std;

typedef struct _BinaryTreeNode
{
    int m_cValue;
    struct _BinaryTreeNode *m_pLeft;
    struct _BinaryTreeNode *m_pRight;
    struct _BinaryTreeNode *m_pParent;
}BinaryTreeNode;

BinaryTreeNode * GetNext(BinaryTreeNode *pNode)
{
    if(pNode == NULL)  
        return NULL;
   
    BinaryTreeNode *pNext = NULL;

    if( pNode->m_pRight != NULL)
    {
        BinaryTreeNode *pRight = pNode->m_pRight;
        while( pRight->m_pLeft != NULL )  
            pRight = pRight->m_pLeft;

        pNext = pRight;
    }
    else if( pNode->m_pParent != NULL )
    {
        BinaryTreeNode *pCurrent = pNode; 
        BinaryTreeNode *pParent = pNode->m_pParent;
        
        while( pParent != NULL && pCurrent == pParent->m_pRight )
        {
           pCurrent = pParent; 
           pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }

   return pNext; 
}

// 销毁二叉树

void DestoryBinaryTree(BinaryTreeNode *root)
{
   if( root != NULL ) 
    {
        BinaryTreeNode * pLeft = root->m_pLeft;
        BinaryTreeNode * pRight = root->m_pRight;
        
        free(root);
        root = NULL;
        
        DestoryBinaryTree(pLeft);
        DestoryBinaryTree(pRight);
    }
}

// 递归中序遍历二叉树

void Recursion_InOrder( BinaryTreeNode *root )
{
    if( root == NULL )
      return;
    
    Recursion_InOrder(root->m_pLeft);
    printf("%d\t",root->m_cValue);
    Recursion_InOrder(root->m_pRight);

}

// 非递归中序遍历二叉树

void InOrder( BinaryTreeNode *root )
{
    stack<BinaryTreeNode*> s;
    
    BinaryTreeNode *pNode = root;
    
    while( pNode != NULL || !s.empty() )
    {
       if( pNode != NULL )
        {
            s.push(pNode);
            pNode = pNode->m_pLeft;
        }
        
        if( !s.empty() )
        {
            pNode = s.top(); 
            s.pop();
            printf("%d\t",pNode->m_cValue); 
            pNode = pNode->m_pRight;
        }

    }
}

// 二叉树插入节点

void  InsertBinaryNode(BinaryTreeNode *root,int ch)
{
   if(root->m_cValue > ch)
    {
        if(root->m_pLeft == NULL)
        {
            BinaryTreeNode *pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            if( NULL == pNode )
            {
                printf("malloc root failed!\n");
                return ;
            }
            pNode->m_pLeft = pNode->m_pRight = NULL;
            pNode->m_cValue = ch;
            root->m_pLeft = pNode;
        }
        else
        {
            InsertBinaryNode(root->m_pLeft,ch);
        }

    }
    else
    {
        if(root->m_pRight == NULL)
        {
            BinaryTreeNode *pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            if( NULL == pNode )
            {
                printf("malloc root failed!\n");
                return ;
            }
            pNode->m_pLeft = pNode->m_pRight = NULL;
            pNode->m_cValue = ch;
            root->m_pRight = pNode;
        }
        else
        {
            InsertBinaryNode(root->m_pRight,ch);
        }
    }
} 

// 创建二叉树

BinaryTreeNode *CreatBinaryTree( void )
{

   int ch;
    BinaryTreeNode *root = NULL;
    BinaryTreeNode *pNode = NULL;

    scanf("%d",&ch);
    while( ch != -1 ) 
    {
        if( root == NULL )
        {
            pNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
            if( pNode == NULL )
            {
                printf("malloc root failed!\n");
                return NULL;
            }
            pNode->m_pLeft = pNode->m_pRight = NULL;
            pNode->m_cValue = ch;
            root = pNode;
        }    
        else
        {
            InsertBinaryNode(pNode,ch);
        }
        scanf("%d",&ch);

    }
    
    return root;
}

int main(void)
{
    BinaryTreeNode *root = NULL;    

    root = CreatBinaryTree();
    
    Recursion_InOrder(root);
    printf("\n");
    
    BinaryTreeNode *pNew = NULL;
    pNew = GetNext(root);
    printf("%d\n",pNew->m_cValue);

    DestoryBinaryTree(root);
    return 0;
}
