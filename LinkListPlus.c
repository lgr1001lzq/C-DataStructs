#include <stdio.h>
#include <stdlib.h>
#define OK 100
#define NO 404
#define length 10
#define num 10

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
        h=newnode;  /*��ͷָ��ָ���½��Ľ�㡣*/
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

void Isempty(Node *head){
    Node *p=head->next;
    if(p!=NULL){
        printf("������Ϊ�գ�\n");
    }
    else{
        printf("������Ϊ�գ�");
    }
}

int Insertinedxof(Node *head,int index,int data){    /*�������ĳһ��������Ԫ�أ�����ɹ�����OK������NO*/

}

int main()
{
    Node *head =(Node*)malloc(sizeof(Node));
    head->next=NULL;
    CreateLinklist(head,length);
    Forwordindexof(head,num);
    Isempty(head);
    TraveLinklist(head);
    return 0;
}