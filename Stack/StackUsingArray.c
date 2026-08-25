#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void stackCreate(struct Stack *st)
{
    printf("Enter Size: ");
    scanf("%d",&st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {   
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int x = -1;
    if(st.top - pos + 1 < 0)
        printf("Invalid index\n");
    else
    {
        x = st.S[st.top - pos + 1];
    }
    return x;
}

int stackIsEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int stackIsFull(struct Stack st)
{
    return st.top == st.size - 1;
}

int stackTop(struct Stack st)
{
    if(!stackIsEmpty(st))
        return st.S[st.top];
    return -1;
}

void stackDisplay(struct Stack st)
{
    if(stackIsEmpty(st))
        printf("Stack is Empty");
    int i;
    for(i = st.top; i >= 0; i--)
        printf("%d\n",st.S[i]);
}

int main()
{
    struct Stack st;
    stackCreate(&st);

    push(&st,10);
    push(&st,11);
    push(&st,12);
    printf("Top Element: %d\n",stackTop(st));
    stackDisplay(st);
    pop(&st);
    printf("Top Element: %d\n",stackTop(st));
    stackDisplay(st);
    return 0;
}