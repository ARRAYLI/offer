/*************************************************************************
	> File Name: PathInTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年03月30日 星期五 13时26分04秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>

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

void FindPath(BinaryTreeNode *pRoot,int exceptedSum,vector<int> &path,int currentSum)
{
    // 给当前路径长度加上结点值
    currentSum += pRoot->m_nValue;     
   
    // 把结点的值放入容器中
    path.push_back(pRoot->m_nValue);
    
    bool isLeaf;
    // 判断当前结点是否为叶节点
    isLeaf = (pRoot->m_pLeft == NULL) && (pRoot->m_pRight == NULL);

    // 如果是叶节点，并且路径上结点的值的和等于输入的值
    // 打印这条路径
    if(currentSum == exceptedSum && isLeaf)
    {
        printf("A path is found:\n");    
        vector<int>::iterator it = path.begin();
        
        for(;it != path.end();++it)
        {
            printf("%d\t",*it);
        }
        printf("\n");
    }
    
    // 如果不是叶节点，则遍历它的子节点
    if(pRoot->m_pLeft != NULL)
        FindPath(pRoot->m_pLeft,exceptedSum,path,currentSum);        
    if(pRoot->m_pRight != NULL)
        FindPath(pRoot->m_pRight,exceptedSum,path,currentSum);


    // 在返回父节点前，在路径上删除当前结点
    path.pop_back();
}

//  二叉树中和尾某一值的路径

void FindPath(BinaryTreeNode *pRoot,int expectedSum)
{
    if(pRoot == NULL)
        return;

    // 使用 vector 来保存路径
    vector<int> path;

    // 当前的路径长度
    int currentSum = 0;
    FindPath(pRoot,expectedSum,path,currentSum);    
}




// 测试用例

void test()
{
     //创建二叉树结点
    BinaryTreeNode *pNode10 = CreateBinaryNode(10);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode12 = CreateBinaryNode(12);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode7 = CreateBinaryNode(7);

    // 连接二叉树的各个节点
    ConnectTreeNodes(pNode10,pNode5,pNode12);
    ConnectTreeNodes(pNode5,pNode4,pNode7);

    int exceptedSum = 0;
    scanf("%d",&exceptedSum);
    // 打印二叉树中值为某一和的路径
    FindPath(pNode10,exceptedSum);

    // 销毁二叉树
    DestroyTree(pNode10);
}


int main(void)
{
    test();
    return 0;
}

