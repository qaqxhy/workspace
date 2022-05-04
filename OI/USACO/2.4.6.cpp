/*
ID:iam_har1
LANG:C++11
TASK:fracdec
*/


#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 100010;
int mod, d, x, y, cnt, t, pos, tot;
char a[maxn], ans[maxn], c[maxn];
int b[maxn];
bool f[maxn], flag;

void close()
{
    fclose(stdin);
    fclose(stdout);
    exit(0);
}

void work()
{
    while (1)
    {
        t = x;
        x *= 10;
        mod = x % y;
        x = x / y;
        if (f[t] == true || mod == 0)
        {
            if (mod == 0)
            {
                cnt++;
                a[cnt] = x + 48;
                flag = true;
            }
            break;
        }
        cnt++;
        a[cnt] = x + 48;
        b[cnt] = t;
        f[t] = true;
        x = mod;
    }
    /*
    printf("t:%d\n",t);
    for (int i=1;i<=cnt;i++)
    cout<<b[i]<<" ";
    cout<<endl;
    */
    for (int i = 1; i <= cnt; i++)
        if (t == b[i])
        {
            pos = i;
            break;
        }
    if (flag)
    {
        for (int i = 1; i <= cnt; i++)
            printf("%c", a[i]);
        cout << endl;
        close();
    }
    tot = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (pos == i)
        {
            tot++;
            ans[tot] = '(';
        }
        tot++;
        ans[tot] = a[i];
    }
    tot++;
    ans[tot] = ')';
    for (int i = 1; i <= tot; i++)
    {
        printf("%c", ans[i]);
        if (i % 76 == 0)
            printf("\n");
    }
    cout << endl;
}

void init()
{
    freopen("fracdec.in", "r", stdin);
    freopen("fracdec.out", "w", stdout);
    scanf("%d%d", &x, &y);
    int d = x / y;
    x = x - d * y;
    cnt = 0;
    while (1)
    {
        mod = d % 10;
        d = d / 10;
        cnt++;
        c[cnt] = mod + 48;
        if (d == 0)
            break;
    }
    for (int i = 1; i <= cnt; i++)
        a[i] = c[cnt - i + 1];
    cnt++;
    a[cnt] = '.';
}

int main()
{
    init();
    work();
    close();
    return 0;
}