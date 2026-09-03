#ifndef ADLIST_H
#define ADLIST_H

typedef struct Node
{
    int Data;
    struct Node * Next;
} Node;

typedef struct
{
    int Vertices;
    Node ** l;
} AdList;

AdList * initAdList();
void addToAdList(AdList *p);
void displayAdList(AdList *p);
void freeAdList(AdList *p);

#endif
