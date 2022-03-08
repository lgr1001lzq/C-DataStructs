#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define LEN 5

typedef struct Node{        /*����˫���������ݽṹ*/
    int data;
    struct Node *next;      /*����˫�������ָ����һ�����*/
    struct Node *before;    /*����˫�������ָ����һ�����*/
}Node;

void createBlinklist(Node *head,int len){       /*�����µ�˫������*/
    int i;                  /*ѭ������*/
    Node *h=head;           /*ͷָ��*/
    for(i=0;i<len;i++){
        Node *p=(Node *)malloc(sizeof(Node));     /*Ϊ�½������䶯̬�ռ�*/
        p->next=NULL;                             /*��ʼ���½�����ָ��ָ��*/
        p->before=NULL;                           /*��ʼ���½�����ָ��ָ��*/
        scanf("%d",&p->data);                     /*Ϊ�����������������*/
        h->next=p;                                /*��ͷָ��ָ��p*/
        p->before=h;                              /*��p����һ�����ָ��h*/
        p->next=h->next->next;                    /*��p����һ�����ָ��ͷ������һ�����*/
        h=p;                                      /*��ͷָ��ָ���½����*/
    }
}

int posordertreaveBlinklist(Node *head){        /*�����������*/
    Node *p=head->next;                         /*����ͷ���*/
    int len=1;                                  /*��������λ��*/
    while(p!=NULL){                             /*ͷ��㲻ΪNULL*/
        printf("%d\t",p->data);                 /*���������*/
        p=p->next;                              /*���ָ������ƶ�*/
        ++len;                                  /*����λ�ò�������*/
    }
    return len;                                 /*��������ĳ���*/
}

void insertBlinklistindexof(Node *head,int index,int data){      /*�������ĳ��λ�ò�����������*/
    int i=1;                                                     /*����λ�ò���*/
    Node *newnode=(Node *)malloc(sizeof(Node));                  /*Ϊ�²�������䶯̬�ռ�*/
    Node *h=head;                                                /*ͷָ��*/
    newnode->next=NULL;                                          /*��ʼ���½�����ָ��ָ��*/
    newnode->before=NULL;                                        /*��ʼ���½�����ָ��ָ��*/
    newnode->data=data;                                          /*�²�����������ָ����������*/
    while(h->next!=NULL){
        if(i==index){                                            /*������λ���������λ�����ʱ*/
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
            printf("�ý��λ������ĵ�%d��λ��",index);
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