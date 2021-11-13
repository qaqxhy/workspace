#include<bits/stdc++.h>
using namespace std;
double ans,n,m;
int x;
double dfs(double n,double m,int x){
    double ans=100000.00;
    if (x==1){
        return max(n,m)/min(n,m);    
    }
    for (int i=1;i<=x-1;i++){
        double tmp=i*n/x;
        ans=min(ans,max(dfs(tmp,m,i),dfs(n-tmp,m,x-i)));
    }
    for (int i=1;i<=x-1;i++){
        double tmp=i*m/x;
        ans=min(ans,max(dfs(n,tmp,i),dfs(n,m-tmp,x-i)));
    }
    return ans;
}
int main(){
    cin>>n>>m>>x;

    printf("%.6lf\n",dfs(n,m,x));
}