#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *s;
};

void create(struct Stack *st)
{
    st->top = -1;
    printf("Enter the size of the Stack: ");
    scanf("%d",&st->size);
    st->s = (int*)malloc(st->size * sizeof(int));
}

void push(struct Stack *st, int x)
{
    if(st->top == st->size - 1)
        printf("Stack Overflow!!\n");
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if(st->top == -1)
        printf("Stack is Empty!!\n");
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int index = st.top - pos + 1;
    int x = -1;
    if(index < 0 || index > st.top)
    {
        printf("Invalid Position!!\n");
        return -1;
    }
    x = st.s[index];
    return x;
}

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack st)
{
    if(st.top == st.size - 1)
        return 1;
    return 0;
}

int Top(struct Stack st)
{
    if(!isEmpty(st))
        return st.s[st.top];
    return -1;
}

void Display(struct Stack st)
{
    if(isEmpty(st))
        printf("Stack is Empty, Nothing to Display!!\n");
    else
    {
        for(int i = st.top; i > -1; i--)
            printf("%d\t",st.s[i]);
        printf("\n");
    }
}
