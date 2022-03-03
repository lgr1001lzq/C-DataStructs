#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define OK 100
#define NO 404
#define LENGTH 10
#define NUM 0

typedef struct Linklist{ /*��������Ľ������ݽṹ�壬����Ľ�����Ԫ�غ�ָ��*/
    int element;
    struct Linklist *next;
}Node;

int CreateLinklist(Node *head,int len){   /*����һ���µľ��峤�ȵ������������Ƿ�ɹ�������*/
    int i;
    Node *h=head;
    for(i=0;i<len;i++){
        Node *newnode=(Node*)malloc(sizeof(Node)); /*Ϊ�½��Ľ������µĿռ䡣*/
        newnode->next=NULL; /*��ʼ���½����*/
        scanf("%d",&newnode->element);
        h->next=newnode; /*��ͷָ��ָ���½��Ľ�㣬�γ�ͷ�ڵ㡣*/
        h=newnode; /*��ͷָ��ָ���½��Ľ�㡣*/
    }
    if(h->next!=NULL){
        return OK;
    }
    else{
        return NO;
    }
    return len;
}

int TraveLinklist(Node *head){  /*����������������н�㣬��������Ӧ��״̬*/
    Node *p=head->next;   /*��ͷָ�븳�����p*/
    while(p!=NULL){  /*�ж�ͷ����Ƿ�Ϊ��*/
        printf("%d\t",p->element);
        p=p->next;
    }
    if(p->next==NULL){
        return OK;
    }
    else{
        return NO;
    }
}

int Forwordindexof(Node *head,int data){    /*���������ĳ����㣬�����ظýڵ����ڵ�λ�ã���������ڸý�㣬�򷵻�״̬NO*/
    int index=1;    /*����λ�ò�����ʼ��*/
    Node *p=head->next;
    while(p!=NULL){
        if(p->element==data){
            printf("Ŀ�����λ��Ϊ��%d\t",index);
        }
        index++; /*���λ�ò������ӣ�ֱ���ҵ�Ŀ����*/
        p=p->next;    /*��ָ�򲻶�����*/
    }
    return index;
}

void Isempty(Node *head){    /*�ж������Ƿ�Ϊ��*/
    Node *p=head->next;    /*����ͷ���*/
    if(p!=NULL){    /*ͷ��㲻Ϊ�������������Ϊ��*/
        printf("������Ϊ�գ�\n");
    }
    else{
        printf("������Ϊ�գ�");
    }
}

int Insertinedxof(Node *head,int index,int data){    /*�������ĳһ��������Ԫ�أ�����ɹ�����OK������NO*/
    int i=1;
    Node *newnode=(Node*)malloc(sizeof(Node));   /*����һ���µĽ��*/
    Node *p=head;    /*����ͷ���*/
    newnode->next=NULL;    /*��ʼ���½��*/
    newnode->element=data;    /*������ָ��data*/
    while(p->next!=NULL){    /*ͷ��㲻Ϊ��*/
        if(i==index){     /*�����λ��ָ����λ��*/
            newnode->next=p->next;     /*�����ָ�򸳸��µĽ��*/
            p->next=newnode;     /*���½�㸳��ԭ������ָ��*/
            newnode=newnode->next;    /*�µĽ�㲻������ƶ�*/
        }
        p=p->next;   /*���������*/
        i++;   /*���λ�ò�������ƶ�*/
    }
    return OK;
}

void deleteLinklist(Node *head){     /*ɾ����������*/
    Node *pre;          /*����һ��������Ա����ɾ�����*/
    while(head->next!=NULL){
        pre=head->next;   /*��ͷ���ָ��pre*/
        head->next=pre->next;    /*��preָ��ͷ���*/
        free(pre);     /*�ͷ�ԭͷ���*/
    }
}

void deleteindexof(Node *head,int index){     /*ɾ������ĳ��λ�õĽ��*/
    Node *now;
    Node *p=head;
    int i=1;
    while(p->next!=NULL){
        if(i==index){
            now=p->next;
            p->next=now->next;
            free(now);
        }
        p=p->next;
        i++;
    }   
}

void ReverseLinklist(Node *head){
    Node *pre=NULL;
    Node *curr;
    while(head->next!=NULL){
        curr=head->next;
        head->next=curr->next;
        curr->next=pre;
        pre=curr;
    }
    head->next=pre;
}

int main()
{
    Node *head =(Node*)malloc(sizeof(Node));     /*Ϊͷָ�����ռ�*/
    head->next=NULL;                             /*��ʼ��ͷ���*/
    CreateLinklist(head,LENGTH);    /*��������*/
    Insertinedxof(head,2,111);      /*������ĵڶ�����㴦����һ���µĽ��*/
    ReverseLinklist(head);          /*��������*/
    deleteindexof(head,5);          /*ɾ�������е�5��λ�õĽ��*/
    Forwordindexof(head,NUM);       /*�������в���Ԫ��*/
    TraveLinklist(head);            /*��������*/
    Sleep(1000);                    /*��ʱ����*/ 
    deleteLinklist(head);           /*ɾ�����*/
    Isempty(head);                  /*�ж������Ƿ�Ϊ��*/
    return 0;
}