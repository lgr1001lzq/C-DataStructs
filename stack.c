#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define len 5

typedef struct{     /*����һ��ջ�����ݽṹ�������������飬ջ�������ڽ���ѹջ�ͳ�ջʱ��ֻ��ջ��ָ�븡����ջ��ָ�벻�����������ﲻ��ջ��ָ����ж��塣*/
    int data[MAX];
    int top;
}SP;

SP* Initstack(){
    SP* s=(SP*)malloc(sizeof(SP));
    if(!s){
        printf("����ʧ�ܣ�����\n");
    }
    else{
        s->top=-1;
        return s;
    }
}

int  push(SP* s,int datas){
    if(s->top!=MAX-1){
        s->top++;
        s->data[s->top]=datas;
    }
    else if(s->top==MAX-1){
        printf("��ǰջ�����������ټ���Ԫ��");
    }
    return 0;
}

int pop(SP* s,int datas){
    if(s->top==MAX-1||s->top<MAX-1){
        datas=s->data[s->top];
        s->top--;
    }
    return 0;
}

int Empty_stack(SP* s){
    if(s->top==-1){
        printf("��ǰջΪ�գ�����\n");
        return 1;
    }
}

int print_stack(SP* s){
    int i;
    for(i=s->top;i>=0;i--){
        printf("ջ��Ԫ��Ϊ��%d\n",s->data[i]);
    }
    return 0;
}

int Top_stack(SP* s){
    return s->data[s->top];
}

int main(){
    int i;
    int num;
    SP* L;
    L=Initstack();
    for(i=0;i<len;i++){
        scanf("%d",&num);
        push(L,num);
    }
    print_stack(L);
    printf("��ǰջ��ջ��Ԫ��Ϊ��%d\n",Top_stack(L));
    for(i=0;i<len;i++){
        scanf("%d",&num);
        pop(L,num);
    }
    Empty_stack(L);
    print_stack(L);
    return 0;
}