#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int rear;
    int front;
    int *q;
};

void create(struct Queue *qu)
{
    printf("Enter Queue Size: ");
    scanf("%d",&qu->size);
    qu->rear = qu->front = 0;
    qu->q = (int *)malloc(qu->size * sizeof(int));
}

void enqueue(struct Queue *qu, int x)
{
    if((qu->rear + 1) % qu->size == qu->front)
    {
        printf("Queue is Full, Can not insert anything\n");
        return;
    }
    qu->rear = (qu->rear + 1) % qu->size;
    qu->q[qu->rear] = x;
}

int dequeue(struct Queue *qu)
{
    int x = -1;
    if(qu->front == qu->rear)
    {
        printf("Queue is Empty, Can not delete anything\n");
        return -1;
    }

    qu->front = (qu->front + 1) % qu->size;
    x = qu->q[qu->front];
    return x;
}

void display(struct Queue qu)
{
    if(qu.front == qu.rear)
    {
        printf("Queu is Empty, Nothing to Display\n");
        return;
    }
    
    int i = qu.front + 1;
    while( i != (qu.rear + 1) % qu.size)
    {
        printf("%d ", qu.q[i]);
        i = (i + 1) % qu.size;
    }
    printf("\n");
}