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
    deq->front = deq->rear = 0;
    deq->q = (int *)malloc(deq->size * sizeof(int));
}

void insertWithRear(struct DEQueue *deq, int x)
{
    if((deq->rear + 1) % deq->size == deq->front)
    {
        printf("Queue is Full(Rear)!!\n");
        return;
    }
    deq->rear = (deq->rear + 1) % deq->size;
    deq->q[deq->rear] = x;
}

int removeWithFront(struct DEQueue *deq)
{
    if(deq->rear == deq->front)
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    deq->front = (deq->front + 1) % deq->size;
    return deq->q[deq->front];
}

void insertWithFront(struct DEQueue *deq, int x)
{
    if((deq->size + deq->front - 1) % deq->size == deq->rear)
    {
        printf("Queue is Full(Front)!!\n");
        return;
    }
    deq->front = (deq->size + deq->front - 1) % deq->size;
    deq->q[deq->front] = x;
}

int removeWithRear(struct DEQueue *deq)
{
    if(deq->rear == deq->front)
    {
        printf("Queue is Empty!!\n");
        return -1;
    }
    int x = deq->q[deq->rear];
    deq->rear = (deq->size + deq->rear - 1) % deq->size;
    return x;
    
}
