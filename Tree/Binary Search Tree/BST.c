#include <stdlib.h>
#include <stdio.h>

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root = NULL;

void Insert(struct Node *p, int key)
{
    struct Node *r = NULL, *t;
    while(p != NULL)
    {
        r = t;
        if(key == p->data)
            return;
        else if(key < p->data)
            p = p->lchild;
        else 
            p = p->rchild;
    }
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = key;
    t->lchild = t->rchild = NULL;
    if(key < r->data)
        r->lchild = t;
    else
        r->rchild = t;
}

struct Node * RInsert(struct Node *p, int key)
{
    struct Node *t;
    if(p == NULL)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
        p->lchild = (p->lchild, key);
    else if(key > p->data)
        p->rchild = (p->rchild, key);
    return p;
}

struct Node * Search(struct Node *p, int key)
{
    while(p != NULL)
    {
        if(key == p->data)
            return p;
        else if(key < p->data)
            p = p->lchild;
        else 
            p = p->rchild;
    }
    return NULL;
}

struct Node * RSearch(struct Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    else if(key < p->data)
        return RSearch(p->lchild, key);
    else
        return RSearch(p->rchild, key);
}

int Height(struct Node *p)
{
    int x, y;
    if(p == NULL)
        return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node * InPre(struct Node *p)
{
    while(p && p->rchild != NULL)
        p = p->rchild;
    return p;
}

struct Node * InSucc(struct Node *p)
{
    while(p && p->lchild != NULL)
        p = p->lchild;
    return p;
}

struct Node * Delete(struct Node *p, int key)
{
    struct Node *q;
    if(p == NULL)
        return NULL;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        if(p == root)
            root = NULL;
        free(p);
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key); 
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
    }
    return p;
}