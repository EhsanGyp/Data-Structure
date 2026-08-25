#include <stdlib.h>
#include <stdio.h>
struct Queue
{
    int size;
    int rear;
    int *q;
};

void create(struct Queue *qu)
{
    printf("Enter size for the Queue: ");
    scanf("%d",&qu->size);
    qu->rear = -1;
    qu->q = (int *)malloc(qu->size * sizeof(int));
}

void insert(struct Queue *qu, int x)
{
    if(qu->rear == qu->size - 1)
        printf("Queue is Full!! can not add %d\n",x);
    else
        qu->q[++qu->rear] = x;
}

int delete(struct Queue *qu)
{
    int x = -1;
    if(qu->rear == -1)
    {
        printf("Queue is Empty, Nothing to Delete.\n");
        return x;
    }
    else
    {
        x = qu->q[0];

        for(int i = 0; i < qu->rear; i++)
            qu->q[i] = qu->q[i + 1];
        
        qu->rear--;
            
    }
    return x;
}

void display(struct Queue qu)
{
    if(qu.rear == -1)
        printf("Queue is Empty, Nothing to Display.\n");
    
    for(int i = 0; i <= qu.rear; i++)
        printf("%d ",qu.q[i]);
    printf("\n");
}

int main()
{
    struct Queue qu;
    create(&qu);
    insert(&qu,2);
    insert(&qu,1);
    insert(&qu,8);
    insert(&qu,5);
    insert(&qu,3);

    display(qu);

    delete(&qu);

    display(qu);
    return 0;
}