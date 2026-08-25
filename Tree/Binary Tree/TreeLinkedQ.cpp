#include <iostream>
using namespace std;


class TreeNode
{
public:
    TreeNode *lchild;
    int data;
    TreeNode *rchild;
};

class Node
{
public:
    TreeNode *data;
    Node *next; 
};

class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(TreeNode *p);
    TreeNode * dequeue();
};

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue()
{

    Node *t = front;
    while(front)
    {
        t = front;
        front = front->next;
        delete t;
    }
    rear = nullptr;
}

void Queue::enqueue(TreeNode *p)
{
    Node *t = new Node;
    t->data = p;
    t->next = nullptr;
    if(isEmpty())
        front = rear = t;
    else
    {
        rear->next = t;
        rear = t;
    }
}

TreeNode * Queue::dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return nullptr;
    }
    Node *t = front;
    TreeNode *x = t->data;
    front = front->next;
    if(front == nullptr)
        rear = nullptr;
    delete t;
    return x;
}

bool Queue::isEmpty()
{
    return front == nullptr;
}

class Stack
{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    void push(TreeNode *p);
    TreeNode * pop();
    TreeNode * peek(int index);
    bool isEmpty();
    TreeNode * stackTop();
};

Stack::Stack()
{
    top = nullptr;
}

Stack::~Stack()
{
    Node *p = top;
    while(top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack::push(TreeNode *p)
{
    Node *t = new Node;
    t->data = p;
    t->next = top;
    top = t;
}

TreeNode * Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack is Empty!!" << flush;
        return nullptr;
    }
    Node *temp = top;
    TreeNode *p = top->data;
    top = top->next;
    delete temp;
    return p;
}

TreeNode * Stack::peek(int index)
{
    if(isEmpty())
    {
        cout << "Stack is Empty!!" << flush;
        return nullptr;
    }
    if(index < 0)
    {
        cout << "Invalid index!!" << flush;
        return nullptr;
    }
    Node *p = top;
    for(int i = 0; p != nullptr && i < index; i++)
        p = p->next;
    if(p != nullptr)
        return p->data;
    return nullptr;
}

TreeNode * Stack::stackTop()
{
    if(top)
        return top->data;
    return nullptr;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

class Tree
{
private:
    TreeNode *root;
public:
    Tree(){root = nullptr;}
    ~Tree();
    void CreateTree();
    void Rpreorder(TreeNode *p);
    void Rpreorder(){Rpreorder(root);}
    void Rpostorder(TreeNode *p);
    void Rpostorder(){Rpostorder(root);}
    void Rinorder(TreeNode *p);
    void Rinorder(){Rinorder(root);}
    void Ipreorder(TreeNode *p);
    void Ipreorder(){Ipreorder(root);}
    void Ipostorder(TreeNode *p);
    void Ipostorder(){Ipostorder(root);}
    void Iinorder(TreeNode *p);
    void Iinorder(){Iinorder(root);}
    void Levelorder(TreeNode *p);
    void Levelorder(){Levelorder(root);}
    int Height(TreeNode *p);
    int Height(){return Height(root);}
    TreeNode * getRoot(){return root;}
    void DeleteTree(TreeNode *p);
};

void Tree::CreateTree()
{
    TreeNode *p, *t;
    int x;
    cout << "Enter root value : " << flush;
    cin >> x;
    Queue q;
    root = new TreeNode;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);
    while(! q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": " <<flush;
        cin >> x;
        if(x != -1)
        {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": " <<flush;
        cin >> x;
        if(x != -1)
        {
            t = new TreeNode;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Rpreorder(TreeNode *p)
{
    if(p)
    {
        cout << p->data << ", " << flush;
        Rpreorder(p->lchild);
        Rpreorder(p->rchild);
    }
}

void Tree::Rpostorder(TreeNode *p)
{
    if(p)
    {
        Rpostorder(p->lchild);
        Rpostorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Rinorder(TreeNode *p)
{
    if(p)
    {
        Rinorder(p->lchild);
        cout << p->data << ", " << flush;
        Rinorder(p->rchild);
    }
}

void Tree::Levelorder(TreeNode *p)
{
    if(root == nullptr)
        return;
    Queue q;
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

int Tree::Height(TreeNode *p)
{
    int l = 0;
    int r = 0;
    if(p == nullptr)
        return 0;
    l = Height(p->lchild);
    r = Height(p->rchild);
    if(l > r) return l + 1;
    else return r + 1;   
}

void Tree::DeleteTree(TreeNode *p)
{
    if(p)
    {
        DeleteTree(p->lchild);
        DeleteTree(p->rchild);
        delete p;
    }
}

void Tree::Ipreorder(TreeNode *p)
{
    Stack s;
    while(p != nullptr || !s.isEmpty())
    {
        if(p != nullptr)
        {
        cout << p->data << " ," << flush;
        s.push(p);
        p = p->lchild;
        }
        else
        {
            p = s.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::Ipostorder(TreeNode *p)
{
    Stack s;
    TreeNode *lastVisited = nullptr;
    while(p != nullptr || !s.isEmpty())
    {
        if(p != nullptr)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            TreeNode *top = s.stackTop();
            if(top->rchild != nullptr && lastVisited != top->rchild)
            {
                p = top->rchild;
            }
            else
            {
                cout << top->data << ", " << flush;
                lastVisited = s.pop();
            }
        }
    }
    cout << endl;
}

void Tree::Iinorder(TreeNode *p)
{
    Stack s;
    while(p != nullptr || !s.isEmpty())
    {
        if(p != nullptr)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.pop();
            cout << p->data << ", " << flush;
            p = p->rchild;
        }
    }
    cout << endl;
}

Tree::~Tree()
{
    DeleteTree(root);
    root = nullptr;
}

int main()
{
    Tree t;
    t.CreateTree();
    t.Rinorder();
    
    return 0;
}