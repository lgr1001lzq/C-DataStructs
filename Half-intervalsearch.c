#include<stdio.h>
#include<stdlib.h>

#define max 10
int halfsearch(int arr[],int s,int m);
int main()
{
    int n,e;
    int ement;
    int arr[max];
    printf("请输入一组有序的数组：\n");
    for(n=0;n<max;n++)
    {
        scanf("%d",&arr[n]);
    }
    printf("请输入你想要查找的元素：\n");
    scanf("%d",&e);

    ement = halfsearch(arr,max,e);

    if(ement)
    {
        printf("你要查找的元素位于数组的第%d个位置",ement);
    }
    else
    {
        printf("对不起，未在数组中查找到你输入的元素!!!");
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
