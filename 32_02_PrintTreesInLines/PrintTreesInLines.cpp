/*************************************************************************
	> File Name: PrintTreesInLines.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月28日 星期三 23时56分24秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<queue>

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

// 分行从上到下打印二叉树

void Print(BinaryTreeNode *pRoot)
{
   if(pRoot == NULL) 
        return;
    
    queue<BinaryTreeNode*> nodes;
    nodes.push(pRoot);
    
    int nextLevel = 0;
    int toBePrint = 1;
    
    while( !nodes.empty())
    {
        BinaryTreeNode *pNode = nodes.front();
        printf("%d\t",pNode->m_nValue);
       
        // 如果当前结点的左子树不为空的 话，把该结点加入队列 中，并且 nextLevel 的 值 加 1
        if(pNode->m_pLeft != NULL)
        {
            nodes.push(pNode->m_pLeft); 
            nextLevel++;
        }
        
        // 如果当前结点的右子树不为空的 话，把该结点加入队列 中，并且 nextLevel 的 值 加 1
        if(pNode->m_pRight != NULL)
        {
            nodes.push(pNode->m_pRight);
            nextLevel++;
        }
       
        // 从队列中弹出根节点
        nodes.pop();
        // 打印完根节点后，要打印的结点数 --
        toBePrint--;

        // 判断将要打印的数是否打完，打完则换行
        if(toBePrint == 0) 
        {
           printf("\n"); 
            // 把下一行要打印的数据的个数赋值给将要打印的数字个数
            toBePrint = nextLevel;
            nextLevel = 0;
        }

    }
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
    Print(pNode8);
    
    // 销毁二叉树
    DestroyTree(pNode8);
}

void test1()
{
    queue<int> d;
    d.push(1);
    d.push(2);
    d.push(3);
    d.push(4);
    d.push(5);
    
    while(!d.empty())
    {
        int temp = d.front();
        printf("%d\t",temp);
        d.pop();
    } 
    printf("\n");
}

int main(void)
{
    test();
    test1();
    return 0;
}
