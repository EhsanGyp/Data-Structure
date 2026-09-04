#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

SNode * top = NULL;

void Spush(int x)
{
    struct SNode * t;
    t = malloc(sizeof(SNode));
    if(t == NULL)
        printf("Stack is Full!!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Spop()
{
    if(top == NULL)
    {
        printf("Stack is Empty, Nothing to pop\n");
        return -1;
    }
    else
    {
        SNode *p;
        int x = -1;
        p = top;
        top = top->next;
        x = p->data;
        free(p);
        return x;
    }
}

int Speek(int pos)
{
    SNode * p = top;
    if(pos <= 0)
        return -1;

    for(int i = 0; i < pos - 1 && p != NULL; i++)
        p = p->next;

    if(p != NULL)
        return p->data;
        
    return -1;
}

int SstackTop()
{
    if(top)
        return top->data;
    return -1;
}

int SisEmpty()
{
    return(top == NULL);
}

int SisFull()
{
    SNode * t = malloc(sizeof(SNode));
    if(t == NULL)
        return 1;

    free(t);
    return 0;
}

void Sdisplay()
{
    
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }
    
    SNode * t = top;
    while(t != NULL)
    {
        printf("%d\n",t->data);
        t = t->next;
    }
}
