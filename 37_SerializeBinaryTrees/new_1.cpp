#include <cstdio>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <fstream>

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

void Serialize(const BinaryTreeNode* pRoot, ostream& stream)
{
    if(pRoot == NULL)
    {
        stream << "$,";
        return;
    }

    stream << pRoot->m_nValue << ',';
    Serialize(pRoot->m_pLeft, stream);
    Serialize(pRoot->m_pRight, stream);
}

bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;

    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }

    bool isNumeric = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumeric = true;
    }

    return isNumeric;
}

void Deserialize(BinaryTreeNode** pRoot, istream& stream)
{
    int number;
    if(ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_nValue = number;
        (*pRoot)->m_pLeft = NULL;
        (*pRoot)->m_pRight = NULL;

        Deserialize(&((*pRoot)->m_pLeft), stream);
        Deserialize(&((*pRoot)->m_pRight), stream);
    }
}

// ==================== Test Code ====================
bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    if(pRoot1 == NULL && pRoot2 == NULL)
        return true;

    if(pRoot1 == NULL || pRoot2 == NULL)
        return false;

    if(pRoot1->m_nValue != pRoot2->m_nValue)
        return false;

    return isSameTree(pRoot1->m_pLeft, pRoot2->m_pLeft) &&
        isSameTree(pRoot1->m_pRight, pRoot2->m_pRight);
}

void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != NULL)
        printf("%s begins: \n", testName);

    Inorder(pRoot);

    char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    Serialize(pRoot, fileOut);
    fileOut.close();

    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pNewRoot = NULL;
    Deserialize(&pNewRoot, fileIn2);
    fileIn2.close();

    Inorder(pNewRoot);

    if(isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    DestroyTree(pNewRoot);
}

//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryNode(2);

    ConnectTreeNodes(pNode5, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode3, NULL);
    ConnectTreeNodes(pNode3, pNode2, NULL);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryNode(2);

    ConnectTreeNodes(pNode5, NULL, pNode4);
    ConnectTreeNodes(pNode4, NULL, pNode3);
    ConnectTreeNodes(pNode3, NULL, pNode2);

    Test("Test3", pNode5);

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryNode(5);

    Test("Test4", pNode5);

    DestroyTree(pNode5);
}

void Test5()
{
    Test("Test5", NULL);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryNode(5);
    BinaryTreeNode* pNode2 = CreateBinaryNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryNode(5);
    BinaryTreeNode* pNode5 = CreateBinaryNode(5);
    BinaryTreeNode* pNode61 = CreateBinaryNode(5);
    BinaryTreeNode* pNode62 = CreateBinaryNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryNode(5);
    BinaryTreeNode* pNode72 = CreateBinaryNode(5);

    ConnectTreeNodes(pNode1, NULL, pNode2);
    ConnectTreeNodes(pNode2, NULL, pNode3);
    ConnectTreeNodes(pNode3, pNode4, NULL);
    ConnectTreeNodes(pNode4, pNode5, NULL);
    ConnectTreeNodes(pNode5, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode71, NULL);
    ConnectTreeNodes(pNode62, NULL, pNode72);

    Test("Test6", pNode1);

    DestroyTree(pNode1);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}
