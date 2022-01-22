#include <stdio.h>
#include <stdlib.h>
#define max 10
int main()
{
    int arr[max]={1,2,5,6,0,9,8,53,22,40};
    int node,index,i;
    scanf("%d",&index);
    for(i=0;i<max;i++)
    {
        if(arr[i] == arr[index])
        {
            node=arr[index];
            printf("%d在数组的第%d个位置上",node,index);
        }
    }
	system("pause");
    return 0;
}

