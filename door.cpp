#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0,x;
    int i;
    for(i=1;i<=2020;i++){
        x=i;
        while(x){
            if(x%10==2){
                ans++;
            }
            x/=10;
        }
    }
    cout<<ans;
    return 0;
}