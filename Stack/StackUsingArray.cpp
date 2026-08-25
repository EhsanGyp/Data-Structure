#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *S;

public:
    Stack(int size);
    ~Stack();
    void push(int x);
    int pop();
    int peek(int index);
    int stackIsFull();
    int stackIsEmpty();
    void stackDisplay();
    int stackTop();
};

Stack :: Stack(int size)
{
    this->size = size;
    top = -1;
    S = new int[size];
}

Stack :: ~Stack()
{
    delete []S;
}

void Stack :: push(int x)
{
    if(stackIsFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        S[top] = x;
    }
}

int Stack :: pop()
{
    int x = -1;
    if(stackIsEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        x = S[top];
        top--;
    }
    return x;
}

int Stack :: peek(int index)
{
    int x = -1;
    if(top - index + 1 < 0)
        cout << "Invalid Position" << endl;
    else
        x = S[top - index + 1];
    return x;
}

int Stack :: stackIsFull()
{
    if(top == size - 1)
        return 1;
    return 0;
}

int Stack :: stackIsEmpty()
{
    if(top == -1)
        return 1;
    return 0;
}

void Stack :: stackDisplay()
{
    for(int i = top; i >= 0; i--)
        cout << S[i] << " | " << flush;
    cout << endl;
}

int Stack :: stackTop()
{
    if(stackIsEmpty())
        return 0;
    return S[top];
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int size = sizeof(A) / sizeof(A[0]);
    Stack st(size);
    
    for(int i = 0; i < size; i++)
        st.push(A[i]);
    

    cout << "Stack: " << flush;
    st.stackDisplay();

    cout << st.stackTop() << endl;

    for(int i = 0; i < size; i++)
        cout << st.pop() << " " << flush;
    cout << endl;

    st.pop();

    return 0;
}