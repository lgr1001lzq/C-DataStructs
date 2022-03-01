#include <iostream>
using namespace std;
int main()
{
    int x=10,y=90;
    for(int i=1;i<=120;i++){
        if(i%2==1){
            y-=x;
        }
        if(i%4==0){
            y*=2;
        }
        if(i%6==0){
            x*=2;
        }
    }
    cout<<y<<endl;
    return 0;
}