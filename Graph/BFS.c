#include "AdList.h"
#include "Queue.h"

#include <stdlib.h>
#include <stdio.h>

void BreadFirstSearch(AdList *p, int start)
{
    bool * Visited = calloc(p->Vertices, sizeof(bool));
    if(Visited == NULL)
    {
        fprintf(stderr, "Visited Array allocation failed.\n");
        return;
    }
    
    Visited[start] = 1;
    Qenqueue(start);
    
    while(!QisEmpty())
    {
        int CurrentRow = Qdequeue();
        printf("%d ,", CurrentRow);

        Node * Head = p->l[CurrentRow];
        while(Head)
        {
            int Neighbor = Head->Data;
            if(!Visited[Neighbor])
            {
                Visited[Neighbor] = 1;
                Qenqueue(Neighbor);
            }

            Head = Head->Next;
        }
    }
}

int main()
{
    AdList * List;
    List = initAdList();
    addToAdList(List);

    int start;
    printf("Which vertice would you like to start with?(0 to %d): \n", (List->Vertices - 1));
    scanf("%d", & start);
    
    BreadFirstSearch(List, start);

    return 0;
}
