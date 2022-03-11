#include <bits/stdc++.h>
using namespace std;
int n;
long long dfs(long long a, long long b, long long c)
{
    if (a == b)
    {
        return c;
    }
    else if (a > b)
    {
        if (a % 2 == 1)
        {
            c = dfs(a + 1, b, c + 1);
        }
        else
            c = dfs(a / 2, b, c + 1);
    }
    else if (a < b)
    {
        if (a>b/2&&a < b/4*3)
        {
            a/=2;
            c++;
            a=b/2;
            c+=b/2-a;
            a*=2;
            c++;
        }
        else if(a<b/2)
        {
            a=b/2;
            c+=b/2-a;
            a*=2;
            c++;
        }
        else
            return c + b - a;
    }
    return c;
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        printf("%lld\n", dfs(a, b, 0));
    }
}