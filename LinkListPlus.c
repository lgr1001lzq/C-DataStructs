#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define OK 100
#define NO 404
#define LENGTH 10
#define NUM 0

typedef struct Linklist{ /*定义链表的结点的数据结构体，链表的结点包含元素和指向。*/
    int element;
    struct Linklist *next;
}Node;

int CreateLinklist(Node *head,int len){   /*创建一个新的具体长度的链表，并返回是否成功创建。*/
    int i;
    Node *h=head;
    for(i=0;i<len;i++){
        Node *newnode=(Node*)malloc(sizeof(Node)); /*为新建的结点分配新的空间。*/
        newnode->next=NULL; /*初始化新建结点*/
        scanf("%d",&newnode->element);
        h->next=newnode; /*将头指针指向新建的结点，形成头节点。*/
        h=newnode; /*将头指针指向新建的结点。*/
    }
    if(h->next!=NULL){
        return OK;
    }
    else{
        return NO;
    }
    return len;
}

int TraveLinklist(Node *head){  /*遍历整个链表的所有结点，并返回相应的状态*/
    Node *p=head->next;   /*将头指针赋给结点p*/
    while(p!=NULL){  /*判断头结点是否为空*/
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

int Forwordindexof(Node *head,int data){    /*查找链表的某个结点，并返回该节点所在的位置，如果不存在该结点，则返回状态NO*/
    int index=1;    /*链表位置参数初始化*/
    Node *p=head->next;
    while(p!=NULL){
        if(p->element==data){
            printf("目标结点的位置为：%d\t",index);
        }
        index++; /*结点位置参数增加，直到找到目标结点*/
        p=p->next;    /*将指向不断右移*/
    }
    return index;
}

void Isempty(Node *head){    /*判断链表是否为空*/
    Node *p=head->next;    /*定义头结点*/
    if(p!=NULL){    /*头结点不为空则表明该链表不为空*/
        printf("该链表不为空！\n");
    }
    else{
        printf("该链表为空！");
    }
}

int Insertinedxof(Node *head,int index,int data){    /*在链表的某一个结点插入元素，插入成功返回OK，否则NO*/
    int i=1;
    Node *newnode=(Node*)malloc(sizeof(Node));   /*定义一个新的结点*/
    Node *p=head;    /*定义头结点*/
    newnode->next=NULL;    /*初始化新结点*/
    newnode->element=data;    /*将数据指向data*/
    while(p->next!=NULL){    /*头结点不为空*/
        if(i==index){     /*如果定位到指定的位置*/
            newnode->next=p->next;     /*将结点指向赋给新的结点*/
            p->next=newnode;     /*将新结点赋给原来结点的指向*/
            newnode=newnode->next;    /*新的结点不断向后移动*/
        }
        p=p->next;   /*结点向后遍历*/
        i++;   /*结点位置不断向后移动*/
    }
    return OK;
}

void deleteLinklist(Node *head){     /*删除整个链表*/
    Node *pre;          /*定义一个结点用以保存待删除结点*/
    while(head->next!=NULL){
        pre=head->next;   /*将头结点指向pre*/
        head->next=pre->next;    /*将pre指向头结点*/
        free(pre);     /*释放原头结点*/
    }
}

void deleteindexof(Node *head,int index){     /*删除链表某个位置的结点*/
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
    Node *head =(Node*)malloc(sizeof(Node));     /*为头指针分配空间*/
    head->next=NULL;                             /*初始化头结点*/
    CreateLinklist(head,LENGTH);    /*创建链表*/
    Insertinedxof(head,2,111);      /*在链表的第二个结点处插入一个新的结点*/
    ReverseLinklist(head);          /*倒置链表*/
    deleteindexof(head,5);          /*删除链表中第5个位置的结点*/
    Forwordindexof(head,NUM);       /*在链表中查找元素*/
    TraveLinklist(head);            /*遍历链表*/
    Sleep(1000);                    /*延时函数*/ 
    deleteLinklist(head);           /*删除结点*/
    Isempty(head);                  /*判断链表是否为空*/
    return 0;
}