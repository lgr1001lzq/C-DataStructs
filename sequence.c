#include <stdio.h>
int main()
{
    int i;
    for(i=1;i<100;i++){
        if(i%2==0){
            printf("%d\n",i*i/2);
        }
        else{
            printf("%d\n",(i*i-1)/2);
        }
    }
    printf("\n");
}