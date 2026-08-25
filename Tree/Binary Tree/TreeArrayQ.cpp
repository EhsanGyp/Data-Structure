#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **q;
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node * dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = 0;
    rear = 0;
    q = new Node * [size];
}

Queue::~Queue()
{
    delete []q;
}

bool Queue::isEmpty()
{
    return front == rear;
}

bool Queue::isFull()
{
    return (rear + 1) % size == front;
}

void Queue::enqueue(Node * x)
{
    if(isFull())
    {
        cout << "Queue is full!!" << endl;
        return;
    }
    rear = (rear + 1) % size;
    q[rear] = x;        
}

Node * Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty!!" << endl;
        return nullptr;
    }
    front = (front + 1) % size;
    return q[front];
}

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
    void Inorder(Node *p);
    void Inorder(){Inorder(root);}
    void Levelorder(Node *p);
    void Levelorder(){Levelorder(root);}
    int Height(Node *p);
    int Height(){return Height(root);}
    Node * getRoot(){return root;}
    void DeleteTree(Node *p);
};

void Tree::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(25);
    root = new Node;
    cout << "Enter root value: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": " << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": " << flush;
        cin >> x;
        if(x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p)
{
    if(p)
    {
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Postorder(Node *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Levelorder(Node *p)
{
    if(root == nullptr)
        return;
    Queue q(100);
    cout << root->data << ", " << flush;
    q.enqueue(root);
    while(! q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}

int Tree::Height(Node *p)
{
    int l = 0;
    int r = 0;
    if(p == nullptr)
        return 0;
    l = Height(p->lchild);
    r = Height(p->rchild);
    if (l > r) return l + 1;
    else return r + 1;
}

void Tree::DeleteTree(Node *p)
{
    if(p)
    {
        DeleteTree(p->lchild);
        DeleteTree(p->rchild);
        delete p;
    }
}

Tree::~Tree()
{
    DeleteTree(root);
    root = nullptr;
}