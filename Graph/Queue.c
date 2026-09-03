#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "Queue.h"

QNode * front = NULL;
QNode * rear = NULL;

void Qenqueue(int x)
{
    QNode * t = malloc(sizeof(QNode));
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

int Qdequeue()
{
    int x = -1;
    if(front == NULL)
    {
        printf("Queue is Empty.");
        return -1;
    }
    else
    {
        QNode * p = front;
        front = front->next;
        x = p->data;
        free(p);
        if(front == NULL)
            rear = NULL;
    }
    return x;
}

void Qdisplay()
{
    if(front == NULL)
    {
        printf("Queue Empty.");
        return;
    }
    QNode * p = front;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

bool QisEmpty()
{
    return front == NULL;
}
