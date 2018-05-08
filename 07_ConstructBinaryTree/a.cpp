#include <stdio.h>  
#include <vector>  
#include <iostream>  

using namespace std;  
/** 
* Definition for binary tree 
**/  
struct TreeNode {  
    int val;  
    TreeNode *left;  
    TreeNode *right;  
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};  
  
//剑指offer原书版，根据先序遍历序列、中序遍历序列重建二叉树  
TreeNode* ConstructByPreIn(int *preOrder, int *inOrder, int length)  
{  
    if (preOrder == NULL || inOrder == NULL || length <= 0) return NULL;  
    //新建结点,当前先序序列第一个元素为根结点  
    int root_val = preOrder[0];   
    TreeNode *root = new TreeNode(root_val);  
    //初始化左右子树参数  
    int leftLength = 0;  
    int rightLength = 0;  
    //在中序序列中找到根节点的位置（必存在）  
    for (int i = 0; i < length; i++)  
    {  
        if (inOrder[i] == root_val)  
        {  
            leftLength = i;  
            rightLength = length - i - 1;  
            break;  
        }  
    }  
    //中序序列中，根节点左边的为左子树，右边的为右子树  
    int *leftPre = preOrder + 1;  
    int *leftIn = inOrder;  
    int *rightPre = preOrder + leftLength + 1;  
    int *rightIn = inOrder + leftLength + 1;  
    //递归构建左右子树  
    root->left = ConstructByPreIn(leftPre, leftIn, leftLength);  
    root->right = ConstructByPreIn(rightPre, rightIn, rightLength);  
    return root;  
  
}  
  
//牛客网版本，根据先序中序序列重建二叉树  
TreeNode* reConstructBinaryTree(vector<int> preOrder, vector<int> inOrder) {  
    if (preOrder.empty() || inOrder.empty()) return NULL;  
    //新建结点,当前先序序列第一个元素为根结点  
    int root_val = preOrder[0];  
    TreeNode *root = new TreeNode(root_val);  
    //初始化左右子树参数  
    int leftLength = 0;  
    int rightLength = 0;  
    //在中序序列中找到根节点的位置（必存在）  
    for (int i = 0; i < inOrder.size(); i++)  
    {  
        if (inOrder[i] == root_val)  
        {  
            leftLength = i;  
            rightLength = inOrder.size() - i - 1;  
            break;  
        }  
    }  
    //中序序列中，根节点左边的为左子树，右边的为右子树  
    vector<int> leftPre (preOrder.begin() + 1, preOrder.begin() + 1 + leftLength);  
    vector<int> leftIn (inOrder.begin(), inOrder.begin() + leftLength);  
    vector<int> rightPre (preOrder.begin() + leftLength + 1, preOrder.begin() + leftLength + 1 + rightLength);  
    vector<int> rightIn (inOrder.begin() + leftLength + 1, inOrder.begin() + leftLength + 1 + rightLength);  
    //递归构建左右子树  
    root->left = reConstructBinaryTree(leftPre, leftIn);  
    root->right = reConstructBinaryTree(rightPre, rightIn);  
    return root;  
}  
  
//先序遍历  
void PreOrder(TreeNode *root)  
{  
    if (root == NULL)  
        return;  
    std::cout << root->val << ' ';  
    PreOrder(root->left);  
    PreOrder(root->right);  
}  
  
//中序遍历  
void InOrder(TreeNode *root)  
{  
    if (root == NULL)  
        return;  
    InOrder(root->left);  
    std::cout << root->val << " ";  
    InOrder(root->right);  
}  
  
//后序遍历  
void PostOrder(TreeNode *root)  
{  
    if (root == NULL) return;  
    PostOrder(root->left);  
    PostOrder(root->right);  
    std::cout << root->val << ' ';  
}  
  
int main()  
{  
    //原书版本函数测试  
    int preOrder[] = { 1,2,4,7,3,5,6,8 };  
    int inOrder[] = { 4,7,2,1,5,3,8,6 };  
    TreeNode *tree = ConstructByPreIn(preOrder, inOrder, 8);  
    PreOrder(tree);    //先序输出  
    std::cout << std::endl;  
    InOrder(tree);     //中序输出  
    std::cout << std::endl;  

    PostOrder(tree);     //中序输出  
    std::cout << std::endl;  
    /*
    //牛客网版本函数测试  
    vector<int> pre = { 1,2,4,7,3,5,6,8 };  
    vector<int> in = { 4,7,2,1,5,3,8,6 };  
    TreeNode *tree2 = reConstructBinaryTree(pre, in);  
    PreOrder(tree2);    //先序输出  
    std::cout << std::endl;  
    InOrder(tree2);     //中序输出  
    std::cout << std::endl;  
  
    system("pause");  
    */

    return 0;  
}
