/*************************************************************************
	> File Name: ConstructBinaryTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月13日 星期二 11时00分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<iostream>

using namespace std;

typedef struct _BinaryTreeNode
{
    int m_nValue;
    struct _BinaryTreeNode *m_pLeft;
    struct _BinaryTreeNode *m_pRight;
}BinaryTreeNode;

// 根据先序遍历，中序遍历重建二叉树

BinaryTreeNode *ConstructByPreIn(int *preorder,int *inorder,int length)
{
    if( preorder == NULL || inorder == NULL || length<=0) 
        return NULL;
    
    // 新建一个结点，当前先序序列的第一个元素为根节点
    
    //printf("preOrder[0] = %d\n",preorder[0]);
    int root_val = preorder[0];
    BinaryTreeNode *root = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode)) ;
    if( root == NULL )
    {
       printf("new BinaryTreeNode failed!\n"); 
    }
    root->m_nValue = root_val; 
    root->m_pLeft = root->m_pRight = NULL; 
    
    // 初始化左右子树的参数
    
    int leftLength = 0;
    int rightLength = 0;

    //在中序序列中找到根节点的位置（必存在 )

    int i;
    for( i=0;i<length;i++ )
    {
        if( inorder[i] == root_val )        
        {
            leftLength = i;
            rightLength = length - i -1;
            break;
        }

    }

    // 中序序列中，根节点左边的为左子树，右边的 又子树

    int *leftPre = preorder+1;
    int *leftIn = inorder;
    int *rightPre = preorder+leftLength+1;
    int *rightIn = inorder+leftLength+1;

    // 递归构建左子树

    root->m_pLeft = ConstructByPreIn(leftPre,leftIn,leftLength);
    root->m_pRight = ConstructByPreIn(rightPre,rightIn,rightLength);

    return root;
}

// 递归法先序遍历

void PreOrder(BinaryTreeNode *root)
{
    if(root == NULL)    
        return;
    printf("%d\t",root->m_nValue);
    PreOrder(root->m_pLeft);
    PreOrder(root->m_pRight);
}

// 递归法中序遍历

void InOrder(BinaryTreeNode *root)
{
    if(root == NULL)    
        return;
    InOrder(root->m_pLeft);
    printf("%d\t",root->m_nValue);
    InOrder(root->m_pRight);
}

// 递归法后序遍历

void PostOrder(BinaryTreeNode *root)
{
    if(root == NULL)    
        return;
    PostOrder(root->m_pLeft);
    PostOrder(root->m_pRight);
    printf("%d\t",root->m_nValue);
}

// 非递归法先序遍历

void _PreOrder(BinaryTreeNode* root)
{
    BinaryTreeNode *p = root;          
    stack<BinaryTreeNode*> s;
    
    while( p!=NULL || !s.empty() )
    {
        if( p!= NULL )
        {
            printf("%d\t",p->m_nValue);
            s.push(p);
            p = p->m_pLeft;
        }
        else
        {
            p = s.top();
            s.pop();
            p = p->m_pRight;
        }
    }

}


// 非递归法中序遍历

void _InOrder(BinaryTreeNode* root)
{
    BinaryTreeNode *p = root;   
    stack<BinaryTreeNode*> s;

    while( p!=NULL || !s.empty() )
    {
        if(p != NULL)
        {
            s.push(p);
            p=p->m_pLeft;
        }
        else
        {
            p = s.top();            
            s.pop();
            printf("%d\t",p->m_nValue);
            p = p->m_pRight;
        }
    }

}


// 非递归法先序遍历

void _PostOrder(BinaryTreeNode* root)
{

    BinaryTreeNode* p = root; 

   BinaryTreeNode* q = NULL; 

   stack<BinaryTreeNode*> s;

    while( p!=NULL || !s.empty() )
    {
        while( p != NULL )
        {
            s.push(p);
            p = p->m_pLeft;
        }
        if(!s.empty())
        {
           p = s.top(); 
            if(p->m_pRight == NULL || p->m_pRight == q)
            {
                printf("%d\t",p->m_nValue);
                s.pop();
                q = p;
                p = NULL;
            }
            else
            {
                p = p->m_pRight;
            }
        }
    }
}

// 打印

void print_tree(int *arr1,int *arr2,int length)
{
    int i;
    for(i=0;i<length;i++)
    {
        printf("%d\t",arr1[i]);
    }
    printf("\n");

    for(i=0;i<length;i++)
    {
        printf("%d\t",arr2[i]);
    }
    printf("\n");

}

// 后序递归销毁二叉树

void PostDestoryBinaryTree(BinaryTreeNode* root)
{
    if( root == NULL )
        return;
    
    PostDestoryBinaryTree(root->m_pLeft); 
    PostDestoryBinaryTree(root->m_pRight); 
    
    free(root);
    root = NULL;
}


// 测试用例

void test()
{
    int preOrder[] = {1,2,4,7,3,5,6,8};
    int inOrder[] = {4,7,2,1,5,3,8,6};
    int length = sizeof(preOrder) /sizeof(preOrder[0]);
  
    printf("%d\n",length);
    //print_tree(preOrder,inOrder,length);
    BinaryTreeNode *root = ConstructByPreIn(preOrder,inOrder,length);    
   
    printf("Binary tree preOrder!\n");
    PreOrder(root);
    printf("\n");
    printf("Binary tree inOrder!\n");
    InOrder(root); 
    printf("\n");
    printf("Binary tree postOrder!\n");
    PostOrder(root);

    printf("\n");
    printf("Recursion Binary tree preOrder!\n");
    _PreOrder(root);
    printf("\n");
    printf("Recursion Binary tree inOrder!\n");
    _InOrder(root); 
    printf("\n");
    printf("Recursion Binary tree postOrder!\n");
    _PostOrder(root);

    printf("\n");

    PostDestoryBinaryTree(root);
}

int main(void)
{
   test(); 

    return 0;
}

