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
    void insert(int x);
    int deleteFromQueue();
    void display();
};

Queue :: Queue(int size)
{
    this->size = size;
    rear = front = -1;
    q = new int[size];
}

Queue :: ~Queue()
{
    delete []q;
}

void Queue :: insert(int x)
{
    if(rear == size - 1)
    {
        cout << "Queue is Full, Can not put " << x << " in Queue." << endl;
        return;
    }
    
    q[++rear] = x;
}

int Queue :: deleteFromQueue()
{
    int x = -1;
    if(rear == front)
    {
        cout << "Queue is Empty, Nothing to Delete" << endl;
        return -1;
    }
    x = q[++front];
    return x;
}

void Queue :: display()
{
    if(rear == front)
    {
        cout << "Queue is Empty, Nothing to Display" << endl;
        return;
    }

    for(int i = front + 1; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}