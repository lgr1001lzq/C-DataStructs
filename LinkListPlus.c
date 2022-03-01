#include <stdio.h>
#include <stdlib.h>
#define OK 100
#define NO 404
#define length 10
#define num 10

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
        h=newnode;  /*将头指针指向新建的结点。*/
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

void Isempty(Node *head){
    Node *p=head->next;
    if(p!=NULL){
        printf("该链表不为空！\n");
    }
    else{
        printf("该链表为空！");
    }
}

int Insertinedxof(Node *head,int index,int data){    /*在链表的某一个结点插入元素，插入成功返回OK，否则NO*/

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