#include<bits/stdc++.h>
using namespace std;
int n,y,a[100050],b[100040],dp[100040][110];
int main()
{
    cin>>n>>y;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    dp[1][a[1]%y]=1;
    dp[1][(a[1]+b[1])%y]=1;
    dp[1][(a[1]-b[1]+y)%y]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=100;j++){
            if(dp[i-1][j]){
                dp[i][(j+a[i])%y]=1;
                dp[i][(j+a[i]+b[i])%y]=1;
                dp[i][(j+a[i]-b[i]+y)%y]=1;
            }
        }
    }
    for(int j=100;j>=0;j--){
        if(dp[n][j]){
            cout<<j;
            break;
        }
    }
    return 0;
}