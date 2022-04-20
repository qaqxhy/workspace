/*
ID:iam_har1
LANG:C++11
TASK:fracdec
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int dec[114514];
int decnt=0;
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
    if(ceil(ans)==ans)
    {
        cout<<ans<<".0";
        return 0;
    }
    int in=ans;
    ans-=in;
    while(ans!=0)
    {
        ans*=10;
        ::dec[++decnt]=ans;
        int tmp=ans;
        ans-=tmp;
    }
    cout<<in<<endl<<decnt<<endl;
    for(int i=1;i<=decnt;i++)
    {
        cout<<::dec[i];
    }
    return 0;
}