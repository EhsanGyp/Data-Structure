#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Tree
{
private:
    Node *root;
public:
    Tree(){root = nullptr;}
    ~Tree();
    void CreateTree();
    void Preorder(Node *p);
    void Preorder(){Preorder(root);}
    void Postorder(Node *p);
    void Postorder(){Postorder(root);}
    void Levelorder(Node *p);
    void Levelorder(){Levelorder(root);}
    void Inorder(Node *p);
    void Inorder(){Inorder(root);}
    int Height(Node *p);
    int Height(){return Height(root);}
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    queue <Node *> q;
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.emplace(root);
    while(! q.empty())
    {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p->data << " :" << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }
        cout << "Enter right child of " << p->data << " :" << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Levelorder(Node *p)
{
    if(root == nullptr)
        return;
    queue <Node *> q;
    cout << root->data << ", " << flush;
    q.emplace(root);
    while(! q.empty())
    {
        p = q.front();
        q.pop();
        if(p->lchild)
        {
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}