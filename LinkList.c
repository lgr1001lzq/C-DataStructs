#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
typedef int Elemtype;
typedef struct Node{
    Elemtype data;
    struct Node *next;
}Node;
typedef struct Node *Linklist;
void CrateListHead(Linklist *L,int n)
{
    Linklist p;
    int i;
    srand(time(0));
    *L=(Linklist)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(i=0;i<n;i++)
    {
        p=(Linklist)malloc(sizeof(Node));
        p->data = rand()%100+1;
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
Elemtype GetElem(Linklist L,int i,Elemtype *e)
{
    int j;
    Linklist p;
    p=L->next;
    j=1;
    while (p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    {
        return -1;
    }
    *e=p->data;
    return 1;
}