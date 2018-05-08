#include<iostream>  
#include<stack>  
using namespace std;  
  
// �������ṹ��  
  
typedef struct _BiTree  
{  
    char data;    // ������  
    struct _BiTree *Lchild;  // ���ӽ��ָ��  
    struct _BiTree *Rchlid;  // �Һ���ָ��  
}BiNode,*BiTree;  
  
// �ݹ��������������  
  
void PreOrder(BiTree root)  
{  
    if (NULL!=root)  
    {  
        cout << root->data<<" ";  
        PreOrder(root->Lchild);  
        PreOrder(root->Rchlid);  
    }  
}  
  
// �ݹ��������������  
  
void InOrder(BiTree root)  
{  
    if (NULL != root)  
    {  
        InOrder(root->Lchild);  
        cout << root->data << " ";  
        InOrder(root->Rchlid);  
    }  
}  
  
// �ݹ�������������  
  
void PostOrder(BiTree root)  
{  
    if (NULL!=root)  
    {  
        PostOrder(root->Lchild);  
        PostOrder(root->Rchlid);  
        cout << root->data<<" ";  
    }  
}  
  
// ����������  
  
void CreateBiTree(BiTree *root)  
{  
    char ch;  
    cin >> ch;  
    if (ch=='.')  
    {  
        *root = NULL;  
    }  
    else  
    {  
        *root = new BiNode;  
        if (NULL==*root)  
        {  
            cout << "��̬�����ڴ�ʧ��!" << endl;  
            return;  
        }  
        (*root)->data = ch;  
        CreateBiTree(&((*root)->Lchild));  
        CreateBiTree(&((*root)->Rchlid));  
    }  
}  
  
// ���������������߶ȵĵݹ��㷨  
  
int PostTreeDepth(BiTree root)  
{  
    int hl = 0; // ���������ĸ߶�  
    int hr = 0; // ���������ĸ߶�  
    int max = 0; // ��¼�����������������ĸ߶�  
    if (root == NULL)  
    {  
        return 0;  
    }  
    else   
    {  
  
        hl = PostTreeDepth(root->Lchild);  
        hr = PostTreeDepth(root->Rchlid);  
        max = hl > hr ? hl : hr;  
        return max + 1;  
    }  
}  
  
// �ǵݹ��������������  
  
void PreOrder1(BiTree root)  
{  
    stack<BiNode*>s;   // ����ջ  
    BiTree p = root;  
//  BiTree q = NULL;  
    while (p!=NULL||!s.empty())  
    {  
        if (p!=NULL)  
        {  
            cout << p ->data << "  ";  
            s.push(p);  
            p = p->Lchild;  
        }  
        else  
        {  
            p = s.top();  // ��¼��ǰջ��Ԫ��  
            s.pop();  // ջ��Ԫ�س�ջ  
            p = p->Rchlid;  
        }  
    }  
}  
  
// �ǵݹ��������������  
  
void InOrder1(BiTree root)  
{  
    stack<BiNode*>s;  
    BiNode *p = root;  
//  BiNode *q = NULL;  
  
    while (p != NULL | !s.empty())  
    {  
        if (NULL != p)  
        {  
            s.push(p);  
            p = p->Lchild;  
        }  
        else  
        {  
            p = s.top();  
            s.pop();  
            cout << p->data << "  ";  
            p = p->Rchlid;  
        }  
    }  
}  
  
// �ǵݹ�������������  
  
void PostOrder1(BiTree root)  
{  
    stack<BiNode*>s;  
    BiNode *p = root;  
    BiNode *q = NULL;  
  
    while (p!=NULL||!s.empty())  
    {  
        while (p!=NULL)  
        {  
            s.push(p);  
            p = p->Lchild;  
        }  
  
        if (!s.empty())  
        {  
            p = s.top();  
            if (p->Rchlid == NULL || p->Rchlid == q)  
            {  
                cout << p->data << "  ";  
                s.pop();  
                q = p;  
                p = NULL;  
  
            }  
            else  
            {  
                p = p->Rchlid;  
            }  
        }  
    }  
}  
  
int main(void)  
{  
    BiTree btree = NULL;  
    CreateBiTree(&btree);  
    PreOrder(btree);  
    cout << endl;  
    InOrder(btree);  
    cout << endl;  
    PostOrder(btree);  
    cout << endl;  
  
//  int n = PostTreeDepth(btree);  
//  cout << n << endl;  
  
  
    PreOrder1(btree);  
    cout << endl;  
  
    InOrder1(btree);  
    cout << endl;  
  
    PostOrder1(btree);  
    cout << endl;  
  
// AB.DF..G..C.E.H..  
    return 0;  
}  
