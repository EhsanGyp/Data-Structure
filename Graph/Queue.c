#include <stdlib.h>
#include <stdio.h>

struct Node 
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if(t == NULL)
    {
        printf("Queue is full");
        return;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    if(front == NULL)
    {
        printf("Queue is Empty.");
        return -1;
    }
    else
    {
        struct Node *p = front;
        front = front->next;
        x = p->data;
        free(p);
        if(front == NULL)
            rear = NULL;
    }
    return x;
}

void display()
{
    if(front == NULL)
    {
        printf("Queue Empty.");
        return;
    }
    struct Node *p = front;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}