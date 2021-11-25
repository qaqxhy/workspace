/*
ID:iam_har1
LANG:C++11
TASK:zerosum
*/
#include <bits/stdc++.h>
#define ze(now, c)  \
    \ str[now] = c; \
    \zero(now + 1);
#define MAX 200
using namespace std;
int n;
char str[9];

void out(void)
{
    int i;
    putchar('1');
    for (i = 1; i < n; i++)
    {
        printf("%c%d", str[i], i + 1);
    }
    putchar('\n');
}

void zero(int sum, int t, int now, char s)
{
    if (now == n)
    {
        if (s == '+')
        {
            sum += t;
        }
        else
        {
            sum -= t;
        }
        if (sum == 0 && str[0] == '+')
        {
            out();
        }
        return;
    }
    str[now] = ' ';
    zero(sum, t * 10 + now + 1, now + 1, s);
    if (s == '+')
    {
        sum += t;
    }
    else
    {
        sum -= t;
    }
    str[now] = '+';
    zero(sum, now + 1, now + 1, '+');
    str[now] = '-';
    zero(sum, now + 1, now + 1, '-');
}

int main()
{
#ifndef LOCALJUDGE
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
#endif
    cin>>n;
    zero(0, 0, 0, '+');
    return 0;
}