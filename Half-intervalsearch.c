#include<stdio.h>
#include<stdlib.h>

#define max 10
int halfsearch(int arr[],int s,int m);
int main()
{
    int n,e;
    int ement;
    int arr[max];
    printf("������һ����������飺\n");
    for(n=0;n<max;n++)
    {
        scanf("%d",&arr[n]);
    }
    printf("����������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%d",&e);

    ement = halfsearch(arr,max,e);

    if(ement)
    {
        printf("��Ҫ���ҵ�Ԫ��λ������ĵ�%d��λ��",ement);
    }
    else
    {
        printf("�Բ���δ�������в��ҵ��������Ԫ��!!!");
    }
    return 0;
}
int halfsearch(int arr[],int s,int m)
{
    int index,low=0,end=s-1;
    while(low<=end)
    {
        index=(low+end)/2;
        if(arr[index]==m)
        {
            return index+1;
        }
        else if(arr[index]>m)
        {
            end=index-1;
        }
        else
        {
            low=index+1;
        }
    }
    return -1;
}
