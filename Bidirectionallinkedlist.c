#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEN 5

typedef struct Node{        /*创建双向链表数据结构*/
    int data;
    struct Node *next;      /*定义双向链表的指向下一个结点*/
    struct Node *before;    /*定义双向链表的指向上一个结点*/
}Node;

void createBlinklist(Node *head,int len){       /*创建新的双向链表*/
    int i;                  /*循环次数*/
    Node *h=head;           /*头指针*/
    for(i=0;i<len;i++){
        Node *p=(Node *)malloc(sizeof(Node));     /*为新建结点分配动态空间*/
        p->next=NULL;                             /*初始化新建结点的指针指向*/
        p->before=NULL;                           /*初始化新建结点的指针指向*/
        scanf("%d",&p->data);                     /*为结点数据域输入数据*/
        h->next=p;                                /*将头指针指向p*/
        p->before=h;                              /*将p的上一个结点指向h*/
        p->next=h->next->next;                    /*将p的下一个结点指向头结点的下一个结点*/
        h=p;                                      /*将头指针指向新建结点*/
    }
}

int posordertreaveBlinklist(Node *head){        /*正序遍历链表*/
    Node *p=head->next;                         /*定义头结点*/
    int len=1;                                  /*定义链表位置*/
    while(p!=NULL){                             /*头结点不为NULL*/
        printf("%d\t",p->data);                 /*输出数据域*/
        p=p->next;                              /*结点指向向后移动*/
        ++len;                                  /*链表位置不断增加*/
    }
    return len;                                 /*返回链表的长度*/
}

void insertBlinklistindexof(Node *head,int index,int data){      /*在链表的某个位置插入具体的数据*/
    int i=1;                                                     /*链表位置参数*/
    Node *newnode=(Node *)malloc(sizeof(Node));                  /*为新插入结点分配动态空间*/
    Node *h=head;                                                /*头指针*/
    newnode->next=NULL;                                          /*初始化新建结点的指针指向*/
    newnode->before=NULL;                                        /*初始化新建结点的指针指向*/
    newnode->data=data;                                          /*新插入结点数据域指向输入数据*/
    while(h->next!=NULL){
        if(i==index){                                            /*当链表位置与待插入位置相等时*/
            newnode->next=h->next;                               /**/
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
    posordertreaveBlinklist(head);
}