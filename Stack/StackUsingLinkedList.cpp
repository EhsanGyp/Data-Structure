#include <iostream>
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
    int peek(int index);
    int stackIsEmpty();
    int stackIsFull();
    int stackTop();
    void Display();
};

Stack :: Stack()
{
    top = nullptr;
}

Stack :: ~Stack()
{
    Node *p = top;
    while(top)
    {
        top = top->next;
        delete p;
        p = top;
    }
}

void Stack :: push(int x)
{
    Node *t = new Node;
    if(t == nullptr)
        cout << "Stack Overflow" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack :: pop()
{
    int x = -1;
    Node *p;
    if(top == nullptr)
        cout << "Stack Underflow" << endl;
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack :: stackIsFull()
{
    Node *t = new Node;
    int r = -1;
    if(t)
        r = 1;
    else
        r = 0;
    delete t;
    return r;
}

int Stack :: stackIsEmpty()
{
    if(top)
        return 0;
    return 1;
}

int Stack :: stackTop()
{
    if(top)
        return top->data;
    return 0;
}

int Stack :: peek(int index)
{
    if(index < 1)
        return -1;
    if(stackIsEmpty())
        return -1;
    else
    {
        Node *p = top;
        for(int i = 0; p != nullptr && i < index - 1; i++)
            p = p->next;
        
        if(p)
            return p->data;
        else
            return -1;
    }
}

void Stack :: Display()
{
    Node *p = top;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}   

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    Stack st;
    int size = sizeof(A)/sizeof(A[0]);
    
    for(int i = 0; i < size; i++)
        st.push(A[i]);

    cout << "Stack: " << endl; 
    st.Display();
    cout << st.peek(3) << endl;
    cout << st.peek(-1) << endl;
    cout << st.peek(10) << endl;
    cout << st.stackIsEmpty() << endl;
    cout << st.stackIsFull() << endl;

    return 0;
}