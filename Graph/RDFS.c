#include "AdList.h"
#include "Stack.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void DFSrecurse(AdList * p, bool * Visited)
{
   if(SisEmpty())
       return;

   int CurrentRow = Spop();
   printf("%d, ", CurrentRow);

   Node * Head = p->l[CurrentRow];
   while(Head)
   {
       int Neighbor = Head->Data;
       while(!Visited[Neighbor])
       {
           Visited[Neighbor] = 1;
           Spush(Neighbor);
       }

       Head = Head->Next;
   }

   DFSrecurse(p, Visited);

}

void RDFS(AdList * p,  int start)
{
    bool * Visited = calloc(p->Vertices, sizeof(bool));
    if(Visited == NULL)
    {
        fprintf(stderr, "Visited Array allocation failed\n");
        return;
    }

    Visited[start] =  1;
    Spush(start);

    DFSrecurse(p, Visited);

    free(Visited);
}

int main()
{
    AdList * List;
    List = initAdList();
    addToAdList(List);

    int start;
    printf("Which vertice would you like to start with?(0 to %d): \n", (List->Vertices - 1));
    scanf("%d", & start);
    
    RDFS(List, start);

    return 0;
}


