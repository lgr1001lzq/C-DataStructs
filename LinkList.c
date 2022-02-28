#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
void CreateLinkList(Node *head,int size)
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
void InsertForword(Node *head,int data){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->next=NULL;
    newnode->data=data;
    newnode->next=head->next;
    head->next=newnode;
}
void DeleteSame(Node *head){
    Node *curr=head->next;
    while(curr!=NULL){
        Node *pre=curr;
        Node *p=curr->next;
        while(p!=NULL){
            if(curr->data==p->data){
                pre->next=p->next;
                free(p);
                p=pre->next;
            }
            else{
                pre=pre->next;
                p=p->next;
            }
        }
        curr=curr->next;
    }
}
void ReverseLinklist(Node *head){
    Node *curr;
    Node *pre=NULL;
    while(head->next!=NULL){
        curr=head->next;
        head->next=curr->next;
        curr->next=pre;
        pre=curr;        
    }
    head->next=pre;
}
void DeleteLinklist(Node *head){
    Node *curr;
    while(head->next!=NULL){
        curr=head->next;
        head->next=curr->next;
        free(curr);
    }
}
void Isempty(Node *head){
    if(head->next!=NULL){
        printf("该链表不为空！\n");
    }
    else{
        printf("该链表为空！\n");
    }
}
void main()
{
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    CreateLinkList(head,15);
    Isempty(head);
    TreaveLinkList(head);
    InsertForword(head,20);
    TreaveLinkList(head);
    DeleteSame(head);
    TreaveLinkList(head);
    DeleteLinklist(head);
    Isempty(head);
}