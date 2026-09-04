#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct QNode
{
    int data;
    struct QNode *next;
} QNode;

void Qenqueue(int x);
int Qdequeue(void);
void Qdisplay(void);
bool QisEmpty(void);

#endif
