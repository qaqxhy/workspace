#include <bits/stdc++.h>
using namespace std;
int head[10010],to[10010],nxt[10010],v[10010],cnt;
void add(int x,int y,int v)
{
    ::v[cnt]=v;
    to[cnt]=y;
    nxt[cnt]=head[x];
    head[x]++;
}
int main()
{
    
}