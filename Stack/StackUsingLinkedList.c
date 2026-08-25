#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top = NULL;

void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack is Full");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    struct Node *t;
    int x = -1;

    if(top == NULL)
        printf("Stack is Empty");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int peek(int pos)
{
    int i;
    struct Node *p = top;
    for(i = 0; p != NULL && i < pos - 1; i++)
        p = p->next;
    if(p)
        return p->data;
    else
        return -1;
}

int stackTop()
{
    if(top)
        return top->data;
    return -1;   
}

int isEmpty()
{
    if(top)
        return 0;
    return 1;
}

int isFull()
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    int r = -1;
    if(t)
        r = 1;
    r = 0;
    free(t);
    return r;
}

void Display()
{
    struct Node *p;
    p = top;
    while(p)
    {
        printf("%d\n",p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();
    printf("%d\n",peek(1));
    printf("%d\n",isFull());

    return 0;
}