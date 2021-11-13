#include<bits/stdc++.h>
using namespace std;
int N,I,H,R,b[10030];
bitset<100004000>v;
int main()
{

    cin>>N>>I>>H>>R;
    while(R--){
        int A,B;
        cin>>A>>B;
        if(A>B)swap(A,B);
        if(v[A*10000+B])continue;
        v[A*10000+B]=1;
        b[A+1]--;b[B]++;
    }
    for(int i=0;i<=N;i++)b[i]+=b[i-1];
    for(int i=1;i<=N;i++)b[i]+=H,cout<<b[i]<<endl;
    return 0;
}