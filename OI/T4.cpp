#include <bits/stdc++.h>
using namespace std;
int l[10010];
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,k;
    cin>>n>>k;
    long long ans;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
    }
    sort(l+1,l+n+1,cmp);
    for(int i=1;i<=k;i++)
    {
        ans+=l[i];
    }
    cout<<ans<<endl;
    return 0;
}