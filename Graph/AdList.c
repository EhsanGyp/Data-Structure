#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int Data;
	struct Node * Next;
}Node;

typedef struct
{
	int Vertices;
	Node ** l;
}AdList;

void initAdList(AdList *p)
{
	p->l = (Node **)malloc((p->Vertices) * sizeof(Node *));
	for(int i = 0; i < p->Vertices; i++)
		p->l[i] = NULL;	
}

void addToList(AdList *p)
{
	for(int i = 0; i < p->Vertices; i++)
	{
		int value = 0;
		Node * head = NULL;
		Node * tail = NULL;
		do
		{
			printf("Enter Adjucent Node (enter -1 to stop): \n");
			scanf("%d", &value);
		
			if(value == -1)
				break;
			
			Node * newNode = malloc(sizeof(Node));
			newNode->Data = value;
			newNode->Next = NULL;
		if(head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->Next = newNode;
			tail = newNode;
		}

		}while(value != -1);

		p->l[i] = head;
	}
}

