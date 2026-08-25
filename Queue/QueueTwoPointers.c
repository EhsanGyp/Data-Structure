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
    printf("Enter the Queue size: ");
    scanf("%d",&qu->size);
    qu->rear = qu->front = -1;
    qu->q = (int *)malloc(qu->size * sizeof(int));
}

void insert(struct Queue *qu, int x)
{
    if(qu->rear == qu->size - 1)
        printf("Queue is Full, Can't insert %d \n", x);
    else
        qu->q[++qu->rear] = x;
}

int delete(struct Queue *qu)
{
    int x = -1;
    if(qu->rear == qu->front)
    {
        printf("Queue is Empty, Nothing to delete.\n");
        return x;
    }
    
    x = qu->q[++qu->front];
    return x;
}

void display(struct Queue qu)
{
    if(qu.rear == qu.front)
        printf("Queue is Empty, Nothing to delete.\n");
    else
    {
        for(int i = qu.front + 1; i <= qu.rear; i++)
            printf("%d ",qu.q[i]);
        printf("\n");
    }
}