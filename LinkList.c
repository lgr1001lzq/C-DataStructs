#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
void createLinkList(Node *head,int size)
{
    Node *rear=head;
    int i;
    for(i=0;i<size;i++)
    {
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->next=NULL;
        scanf("%d",&newnode->data);
        rear->next=newnode;
        rear=newnode;
    }
}
void TreaveLinkList(Node *head)
{
    Node *p=head->next;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
    putchar('\n');
}
