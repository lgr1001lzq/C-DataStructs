#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEN 5

typedef struct Node{        /*创建双向链表数据结构*/
    int data;
    struct Node *next;
    struct Node *before;
}Node;

void createBlinklist(Node *head,int len){       /*创建新的双向链表*/
    int i;
    Node *h=head;
    for(i=0;i<len;i++){
        Node *p=(Node *)malloc(sizeof(Node));
        p->next=NULL;
        p->before=NULL;
        scanf("%d",&p->data);
        h->next=p;
        p->before=h;
        p->next=h->next->next;
        h=p;
    }
}

int posordertreaveBlinklist(Node *head){        /*正序遍历链表*/
    Node *p=head->next;
    int len=1;
    while(p!=NULL){
        printf("%d\t",p->data);
        p=p->next;
        ++len;
    }
    return len;
}

void insertBlinklistindexof(Node *head,int index,int data){
    int i=1;
    Node *newnode=(Node *)malloc(sizeof(Node));
    Node *h=head;
    newnode->next=NULL;
    newnode->before=NULL;
    newnode->data=data;
    while(h->next!=NULL){
        if(i==index){
            newnode->next=h->next;
            newnode->before=h->before;
            h->next=newnode;
            newnode=newnode->next;
        }
        h=h->next;
        i++;
    }
}

void  deleteBlinklistindexof(Node *head,int index){
    int i=1;
    Node *hre;
    Node *pre=head;
    while(pre->next!=NULL){
        if(i==index){
            hre=pre->next;
            pre->next=hre->next;
            pre->before=hre->before;
            free(hre);
        }
        i++;
        pre=pre->next;
    }
}

void reverseBlinklist(Node *head){
    Node *h=head;
    Node *end;
    while(1){
        if(h->next!=NULL){
            h=h->next;
        }
        if(h->next==NULL){
            end->before=h;
        }
        if(end->before!=NULL){
            printf("%d\t",end->data);
            end=end->before;
        }
        if(end->before==h->before){
            break;
        }
    }
}

void forwardBlinklist(Node *head,int data){
    Node *h=head->next;
    int index=1;
    while(h!=NULL){
        if(h->data==data){
            printf("该结点位于链表的第%d个位置",index);
        }
        h=h->next;
        index++;
    }
}

void deleteBlinklist(Node *head){
    Node *h=head;
    Node *hre;
    while(h->next!=NULL){
        hre=h->next;
        h->next=hre->next;
        h->before=hre->before;
        free(hre);
    }
}

int main(){
    Node *head=(Node *)malloc(sizeof(Node));
    head->next=NULL;
    head->before=NULL;
    createBlinklist(head,LEN);
    deleteBlinklist(head);
    posordertreaveBlinklist(head);
}