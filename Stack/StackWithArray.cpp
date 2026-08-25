#include <iostream>
#include <stdexcept>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *s;
public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int pos);
    bool isEmpty();
    bool isFull();
    void display();
};

Stack :: Stack(int size)
{
    this->size = size;
    top = -1;
    s = new int[size];
}

Stack :: ~Stack()
{
    delete []s;
}

void Stack :: push(int x)
{
    if(isFull())
        throw runtime_error("Stack is Full!! Can not Push more DATA!!");
    else
    {
        top++;
        s[top]= x;
    }
}

int Stack :: pop()
{
    int x = -1;
    if(isEmpty())
        throw runtime_error("Stack is Empty!! Nothing to pop :D"); 
        // cout << "Stack is Empty!! Nothing to pop :D" << endl;
        // return -1;
    x = s[top];
    top--;
    return x;
}

int Stack :: peek(int posFromTop)
{
    int x = -1;
    int index = top - posFromTop + 1;
    if(isEmpty())
    {
        throw runtime_error("Stack is Empty!! Nothing to pop :D");
        // cout << "Stack is Empty!! Nothing to pop :D" << endl;
        // return -1;
    }
    if(index < 0 || index > top)
    {
        throw runtime_error("Invalid Position.");
        // cout << "Invalid Position!!" << endl;
        // return -1;
    }
    x = s[index];
    return x;
}

bool Stack :: isEmpty()
{
    return top == -1;
}

bool Stack :: isFull()
{
    return top == size - 1;
}

void Stack :: display()
{
    int i = -1;
    if(isEmpty())
        throw runtime_error("Stack is Empty!! Nothing to pop :D");
        // cout << "Stack is Empty!! Nothing to Display" << endl;
    else
    {
        cout << "Stack: " << endl;
        for(i = top; i >= 0; i--)
            cout << s[i] << " | ";
        cout << endl;
    }
}

int main()
{
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    st.push(35);
    st.display();

    return 0;
}