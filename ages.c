#include <stdio.h>
int main()
{
    int ages=10;
    int y1,y2;
    for(;ages<30;ages++)
    {
        y1=ages*ages*ages;
        printf("y1=%d\n",y1);
        y2=ages*ages*ages*ages;
        printf("y2=%d\n",y2);
        printf("ages:%d\n",ages);
    }
    return 0;
}