#include<iostream>
using namespace std;
long long T,a,b,ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cin>>a>>b;
        int t=a^b;
        ans+=t;
    }
    cout<<ans;
    return 0;
}
