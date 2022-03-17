#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define len 5

typedef struct{     /*创建一个栈的数据结构，包括线性数组，栈顶，由于进行压栈和出栈时，只有栈顶指针浮动，栈底指针不浮动，故这里不对栈底指针进行定义。*/
    int data[MAX];
    int top;
}SP;

SP* Initstack(){
    SP* s=(SP*)malloc(sizeof(SP));
    if(!s){
        printf("创建失败！！！\n");
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
        printf("当前栈已满，不能再加入元素");
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
        printf("当前栈为空！！！\n");
        return 1;
    }
}

int print_stack(SP* s){
    int i;
    for(i=s->top;i>=0;i--){
        printf("栈内元素为：%d\n",s->data[i]);
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
    printf("当前栈的栈顶元素为：%d\n",Top_stack(L));
    for(i=0;i<len;i++){
        scanf("%d",&num);
        pop(L,num);
    }
    Empty_stack(L);
    print_stack(L);
    return 0;
}