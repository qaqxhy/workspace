#include <algorithm>
#include <iostream>
#define N 100110
using namespace std;
int n, m;
int d[N];
int cmp(int n, int m)
{
    return n > m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    sort(d + 1, d + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (i >= d[i])
        {
            int t = 0;
            for (int j = 1; j <= n; j++)
            {
                if (t == m)
                {
                    break;
                }
                if (d[j] == d[i])
                {
                    t++;
                    d[j]++;
                }
            }
        }
        else
        {
            continue;
        }
        for (int j = 1; j <= n; j++)
        {
            if (j >= d[j])
            {
                cout << d[j] << endl;
                return 0;
            }
        }
    }
    return 0;
}