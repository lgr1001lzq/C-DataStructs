#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    int a[20][20];
    int i,j;
    cin>>m>>n;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin>>a[j][i];
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}