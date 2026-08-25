#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top = NULL;
// ==
// struct Node
// {
//     int data;
//     struct Node *next;
// }*top = NULL;
void push(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        printf("Stack is Full!!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack is Empty, Nothing to pop\n");
        return -1;
    }
    else
    {
        struct Node *p;
        int x = -1;
        p = top;
        top = top->next;
        x = p->data;
        free(p);
        return x;
    }
}

int peek(int pos)
{
    struct Node *p = top;
    if(pos <= 0)
        return -1;

    for(int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if(p != NULL)
        return p->data;
        
    return -1;
}

// ==
// int peek(int pos)
// {
//     struct Node *p = top;
//     while(pos-- > 0 && p != NULL)
//         p = p->next;

//     if(p == NULL)
//     {
//         printf("Invalid Position\n");
//         return -1;
//     }
//     return p->data;
// }

int stackTop()
{
    if(top)
        return top->data;
    return -1;
}

int isEmpty()
{
    return(top == NULL);
}

int isFull()
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
        return 1;

    free(t);
    return 0;
}

void display()
{
    
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    
    struct Node *t = top;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}