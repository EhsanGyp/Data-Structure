#include <iostream>
#include <excpt.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack();
    ~Stack();
    void push(int x);
    int pop();
    int peek(int pos);
    bool isEmpty();
    bool isFull();
    int stackTop();
    void display();
};

Stack :: Stack()
{
    top = nullptr;
}

Stack :: ~Stack()
{
    Node *t = top;
    while(top)
    {
        top = top->next;
        free(t);
        t = top;
    }
}

void Stack :: push(int x)
{
    Node *t = new Node;
    if(t == nullptr)
        throw runtime_error("Stack Overflow!!");

    t->data = x;
    t->next = top;
    top = t;
}

int Stack :: pop()
{
    int x = -1;
    if(top == nullptr)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    Node *t = top;
    x = t->data;
    top = top->next;
    delete t;
    return x;
}

bool Stack :: isEmpty()
{
    return top == nullptr;
}

bool Stack :: isFull()
{
    return false;
}

// ==
// {
//     Node *t = new Node;
//     int r = t ? 0 : 1;
//     delete t;
//     return r;
// }

int Stack :: stackTop()
{
    if(top);
        return top->data;
    return 0;
}

int Stack :: peek(int pos)
{
    if(pos < 0)
        return -1;
    
    if(isEmpty())
        return -1;

    else
    {
        Node *p = top;
        for(int i = 0; i < pos - 1 && p != nullptr; i++)
            p = p->next;

        if(p)
            return p->data;
        
        else
            return -1;
    }
}

void Stack :: display()
{
    Node *p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}