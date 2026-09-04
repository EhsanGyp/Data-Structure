#ifndef STACK_H
#define STACK_H

typedef struct SNode
{ 
    int data;
    struct SNode * next;
} SNode;

void Spush(int x);
int Spop();
int Speek(int pos);
int SstackTop();
int SisEmpty();
int SisFull();
void Sdisplay();

#endif
