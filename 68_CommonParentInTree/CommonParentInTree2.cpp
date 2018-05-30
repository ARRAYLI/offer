/*************************************************************************
	> File Name: CommonParentInTree.cpp
	> Author:    arrayli
	> Mail:      1374367549@qq.com
	> Created Time: 2018年04月24日 星期二 19时13分02秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<list>

using namespace std;


// 二叉树的存储结构

struct BinaryTreeNode
{ 
    int m_nValue;
    struct BinaryTreeNode *m_pLeft;                                                                             
    struct BinaryTreeNode *m_pRight;
};
  
list<BinaryTreeNode*> path1;
list<BinaryTreeNode*> path2;

bool isExistsData1 =true;
bool isExistsData2 =true;


// 二叉树结点的创建
BinaryTreeNode* CreateBinaryNode(int val)
{                   
    BinaryTreeNode *pBinaryTreeNode = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    if( pBinaryTreeNode == NULL )
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
    if( pParent != NULL )
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


//题目：树中两个结点的最低公共祖先

// 要求：一颗普通的二叉树

bool GetNodePath(BinaryTreeNode *pRoot,BinaryTreeNode* pNode,list<BinaryTreeNode*> &path)
{
    if(pRoot == NULL)
        return false;

    path.push_back(pRoot);
    if( pRoot == pNode )
         return true;
    else
    {
        bool found = false;
        found = GetNodePath(pRoot->m_pLeft,pNode,path); 
        
        if(!found)
            found = GetNodePath(pRoot->m_pRight,pNode,path);

        if(!found)
            path.pop_back();
       
        return found;
    }
}

BinaryTreeNode *GetLastCommonNode(list<BinaryTreeNode*> &path1,list<BinaryTreeNode*> &path2)
{
    list<BinaryTreeNode*>::iterator it1 = path1.begin();
    list<BinaryTreeNode*>::iterator it2 = path2.begin();

    BinaryTreeNode *pLast = NULL;
    
    while(it1 != path1.end() && it2 != path2.end())
    {
        if( *it1 == *it2 )
            pLast = *it1;
        it1++;
        it2++;
    }
    
    return pLast;
}


// 获取二叉排序树的最低公共祖先

BinaryTreeNode *GetLastCommonParent(BinaryTreeNode *pRoot,BinaryTreeNode *pNode1,BinaryTreeNode *pNode2)
{
   if(pRoot == NULL || pNode1 == NULL || pNode2 == NULL) 
        return NULL;
    
    if( !GetNodePath(pRoot,pNode1,path1) )
    {
        isExistsData1 = false;
        return NULL;
    }

    if( !GetNodePath(pRoot,pNode2,path2) )
    {
       isExistsData2 = false;
        return NULL;
    }
    
    return GetLastCommonNode(path1,path2);
}



// 普通二叉树测试用例

void test1()
{
    // 创建结点
    BinaryTreeNode *pNode15 = CreateBinaryNode(15);
    BinaryTreeNode *pNode14 = CreateBinaryNode(14);
    BinaryTreeNode *pNode13 = CreateBinaryNode(13);
    BinaryTreeNode *pNode12 = CreateBinaryNode(12);
    BinaryTreeNode *pNode11 = CreateBinaryNode(11);
    BinaryTreeNode *pNode10 = CreateBinaryNode(10);
    BinaryTreeNode *pNode9 = CreateBinaryNode(9);
    BinaryTreeNode *pNode8 = CreateBinaryNode(8);
    BinaryTreeNode *pNode7= CreateBinaryNode(7);
    BinaryTreeNode *pNode6 = CreateBinaryNode(6);
    BinaryTreeNode *pNode5 = CreateBinaryNode(5);
    BinaryTreeNode *pNode4 = CreateBinaryNode(4);
    BinaryTreeNode *pNode3 = CreateBinaryNode(3);
    BinaryTreeNode *pNode2 = CreateBinaryNode(2);
    BinaryTreeNode *pNode1 = CreateBinaryNode(1);

    // 连接二叉树的结点

    ConnectTreeNodes(pNode1,pNode2,pNode3);
    ConnectTreeNodes(pNode2,pNode4,pNode5);
    ConnectTreeNodes(pNode4,pNode8,pNode9);
    ConnectTreeNodes(pNode5,pNode10,pNode11);
    ConnectTreeNodes(pNode6,pNode12,pNode13);
    ConnectTreeNodes(pNode7,pNode14,pNode15);

    // 获取二叉树的最低公共祖先
    BinaryTreeNode *LastCommonParent = GetLastCommonParent(pNode1,pNode10,pNode11);
    if( LastCommonParent == NULL )
        printf("不存在最低公共结点或出错!\n");
    else
        printf("%d 和 %d 在排序二叉树中的最低公共结点是：%d\n",pNode10->m_nValue,pNode11->m_nValue,LastCommonParent->m_nValue); 

    // 销毁二叉树
    DestroyTree(pNode5);
}


int main(void)
{
    test1();
    return 0;
}
