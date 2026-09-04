#include <stdio.h>
#include <stdlib.h>

#include "AdList.h"

AdList * initAdList()
{
    AdList *p = malloc(sizeof(AdList));
    printf("Enter number of Vertices: \n");
    scanf("%d", &(p->Vertices));
	p->l = (Node **)malloc((p->Vertices) * sizeof(Node *));
	for(int i = 0; i < p->Vertices; i++)
		p->l[i] = NULL;	
    return p;
}

void addToAdList(AdList *p)
{
	for(int i = 0; i < p->Vertices; i++)
	{
		int value = 0;

		Node * head = malloc(sizeof(Node));
        head->Data = i;
        head->Next = NULL;
		Node * tail = head;

		do
		{
			printf("Enter Adjucent Node for vertice %d (enter -1 to stop): \n",i);
			scanf("%d", &value);
		
			if(value == -1)
				break;
			
			Node * newNode = malloc(sizeof(Node));
			newNode->Data = value;
			newNode->Next = NULL;

            tail->Next = newNode;
            tail = newNode;

        }while(value != -1);

        p->l[i] = head;
	}
}

void displayAdList(AdList *p)
{
    for(int i = 0; i < p->Vertices; i++)
    {
        Node * head = p->l[i];
        while(head)
        {
            printf("%d ", head->Data);
            if(head->Next)
                printf("-> ");
            head = head->Next;
        }
        printf("\n");
    } 
}

void freeAdList(AdList *p)
{
    for(int i = 0; i < p->Vertices; i++)
    {
        Node * current = p->l[i];
        while(current)
        {
            Node * temp = current;
            current = current->Next;
            free(temp);
        }
    }
    free(p->l);
    free(p);
}
