/*************************************************************************
	> File Name: SerializeBinaryTrees.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月30日 星期五 22时49分55秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

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

//  中序遍历二叉树

void Inorder(BinaryTreeNode *pRoot)
{
    if(pRoot != NULL)
    {
        Inorder(pRoot->m_pLeft); 
        printf("%d\t",pRoot->m_nValue);
        Inorder(pRoot->m_pRight); 

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

// 序列化二叉树

void Serialize(BinaryTreeNode *pRoot)
{
   if(pRoot == NULL) 
    {
        printf("$,");
        //stream<<"$,";
        return;
    }

    //stream<<pRoot->m_nValue<<",";
    printf("%d,",pRoot->m_nValue);
    Serialize(pRoot->m_pLeft);
    Serialize(pRoot->m_pRight);
}

// 反序列化二叉树

void Deserialize(BinaryTreeNode **pRoot,)
{
    int number;
    if(ReadStream())
}


// 测试用例

void test()
{
     //创建二叉树结点
    BinaryTreeNode *pNode1 = CreateBinaryNode(1);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);

    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,NULL);
    ConnectTreeNodes(pNode3,pNode5,pNode6);

    // 打印二叉树
    Inorder(pNode1);
   

    // 序列化二叉树

    Serialize(pNode1);

    printf("\n");
    // 销毁二叉树
    DestroyTree(pNode1);
}


int main(void)
{
    test();
    return 0;
}

