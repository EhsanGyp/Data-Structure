#include <iostream>
using namespace std;

class Node
{
public:
    int data;
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
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue :: Queue()
{
    front = nullptr;
    rear = nullptr;
}

Queue :: ~Queue()
{
    while(front)
    {
        Node *p = front;
        front = front->next;
        delete p;
    }
}

void Queue :: enqueue(int x)
{
    Node *t = new Node;
    if(t == nullptr)
        cout << "Queue overflow" << endl;     
    else
    {
        t->data = x;
        t->next = nullptr;
        if(front == nullptr)
        {
            front = t;
            rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue :: dequeue()
{
    int x = -1;
    if(front == nullptr)
    {
        cout << "Empty Queue!";
        return x;
    }
    Node *p = front;
    x = p->data;
    front = front->next;
    delete p;
    return x;
}

void Queue :: display()
{
    if(front == nullptr)
        cout << "Empty Queue" << endl;
    else
    {
        Node *p = front;
        while(p)
        {
        cout << p->data << " ";
        p = p->next;
        }
    }
    cout << endl;
}