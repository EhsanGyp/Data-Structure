#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int rear;
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
    rear = -1;
    q = new int[size];
}

Queue :: ~Queue()
{
    delete []q;
}

void Queue :: insert(int x)
{
    if(rear == size -1)
    {   cout << "Queue is Full Can not add " << x << endl;
        return;
    }

    q[++rear] = x;
}

int Queue :: deleteFromQueue()
{
    int x = -1;
    if(rear == -1)
    {    
        cout << "Queue is Empty, Nothing to delete." << endl;
        return x;
    }
    else
    {
        x = q[0];
        for(int i = 0; i < rear; i++)
            q[i] = q[i + 1];
        rear--;
    }
    return x;
}

void Queue :: display()
{
    if(rear == -1)
        cout << "Queue is Empty, Nothing to Display" << endl;
    else
    {
        cout << "Queue: ";
        for(int i = 0; i <= rear; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}