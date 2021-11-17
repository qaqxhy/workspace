/*
ID:iam_har2
LANG:C++11
TASK:ride
*/
#include <bits/stdc++.h>
using namespace std;
char a[1010];
char b[1010];
int main()
{
    ios::sync_with_stdio(0);
    #ifndef LOCALJUDGE
        freopen(".in","r",stdin);
        freopen(".out","w",stdout);
    #endif
    cin >> (a + 1);
    cin >> (b + 1);
    int alen = strlen(a + 1);
    int blen = strlen(b + 1);
    long long atmp = 0, btmp = 0;
    for (int i = 1; i <= alen; i++)
    {
        atmp *= a[i] - 'A' + 1;
    }
    for (int i = 1; i <= blen; i++)
    {
        btmp *= b[i] - 'A' + 1;
    }
    if (atmp % 47 == btmp % 47)
        cout << "GO\n";
    else
        cout << "STAY\n";
    return 0;
}