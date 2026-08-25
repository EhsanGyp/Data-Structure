#include <stdio.h>
#include <stdlib.h>

struct DEQueue
{
    int size;
    int front;
    int rear;
    int *q;
};

void createDEQueue(struct DEQueue *deq, int size)
{
    deq->size = size;
    deq->front = deq->rear = -1;
    deq->q = (int *)malloc(deq->size * sizeof(int));
}

void insertWithRear(struct DEQueue *deq, int x)
{
    if(deq->rear == deq->size - 1)
    {
        printf("Queue is Full(Rear)!!\n");
        return;
    }
    deq->q[++deq->rear] = x;
}

int removeWithFront(struct DEQueue *deq)
{
    if(deq->rear == deq->front)
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return deq->q[++deq->front];
}

void insertWithFront(struct DEQueue *deq, int x)
{
    if(deq->front == -1)
    {
        printf("Queue is Full(Front)!!\n");
        return;
    }
    deq->q[deq->front--] = x;
}

int removeWithRear(struct DEQueue *deq)
{
    if(deq->rear == deq->front)
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    return deq->q[deq->rear--];
    
}
