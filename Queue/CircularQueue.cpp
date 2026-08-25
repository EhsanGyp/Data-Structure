#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int rear;
    int front;
    int *q;

public:
    Queue(int size);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue :: Queue(int size)
{   
    this->size = size;
    rear = front = 0;
    q = new int[size];
}

Queue :: ~Queue()
{
    delete []q;
}

void Queue :: enqueue(int x)
{
    if((rear + 1) % size == front)
    {
        cout << "Queue is Full" << endl;
        return;
    }
    rear = (rear + 1) % size;
    q[rear] = x;
}

int Queue :: dequeue()
{
    int x = -1;
    if(rear == front)
    {
        cout << "Queue is Empty" << endl;
        return x;
    }
    front = (front + 1) % size;
    x = q[front];
    return x;
}

void Queue :: display()
{
    if(rear == front)
    {
        cout << "Queue is Empty" << endl;
        return;
    }

    int i = (front + 1) % size;
    cout << "Queue Elements: ";
    while(i != (rear + 1) % size)
    {
        cout << q[i] << " ";
        i = (i + 1) % size;
    }
    cout << endl;
}