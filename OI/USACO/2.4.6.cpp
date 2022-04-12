/*
ID:iam_har1
LANG:C++11
TASK:fracdec
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    #ifndef LOCALJUDGE
        freopen("fracdec.in","r",stdin);
        freopen("fracdec.out","w",stdout);
    #endif
    cin>>n>>m;
    int t=sqrt(min(n,m));
    for(int i=2;i<=t;i++)
    {
        while(n%i==0&&m%i==0)
        {
            n/=i;
            m/=i;
        }
    }
    double ans=(double)n/(double)m;
    cout<<ans;
    return 0;
}