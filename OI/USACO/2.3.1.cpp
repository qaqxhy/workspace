/*
ID:iam_har1
LANG:C++11
TASK:prefix
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

set<string> a[11];
string l, k, p;
bool f[200003];
int ans = -1, m;

inline int max(int s, int d)
{
    if (s >= d)
        return s;
    return d;
}

int main()
{
    #ifndef LOCALJUDGE
        freopen("prefix.in","r",stdin);
        freopen("prefix.out","w",stdout);
    #endif
    while (true)
    {
        cin >> l;
        if (l == ".")
            break;
        a[l.length()].insert(l);
        m = max(m, l.length());
    }
    while (cin >> p)
    {
        k = k + p;
    }
    f[-1] = 1;
    for (int i = 0; i < k.length(); i++)
    {
        for (int j = min(i, m - 1); j >= 0; j--)
        {
            string o = k.substr(i - j, j + 1); //提取从i-j开始,长度为5的k的子串
            if (a[o.length()].count(o) && f[i - j - 1])
            { //如果o可以被构成,并且除了o其它的也能被构成
                ans = i;
                f[i] = 1;
                break;
            }
        }
    }
    printf("%d\n", ans + 1);
    return 0;
}