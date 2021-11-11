#include <bits/stdc++.h>
using namespace std;
int dp[250][250][250];
int num[100];
const int mod = 97654321;
vector<int> vec[1010];
int main()
{
    int n, m, cnt;
    cin >> n >> m >> cnt;
    for (int i = 1; i <= cnt; i++)
    {
        char a[10];
        cin >> a;
        num[i] = a[1] - 'A';
    }
    for (int i = 1; i <= cnt; i++)
    {
        if (num[i] <= 25)
            dp[1][0][num[i]] = 1;
        else
            dp[1][1][num[i]] = 1;
    }
    int ans = 0;
    for (int i = 2; i <= n + m; i++)
        for (int j = 0; j <= n && j <= i; j++)
            for (int k = 1; k <= cnt; k++)
            {
                int len = vec[num[k]].size();
                if (num[k] <= 25)
                {
                    if (j == i)
                        continue;
                    for (int t = 0; t < len; t++)
                    {
                        dp[i][j][num[k]] += dp[i - 1][j][vec[num[k]][t]];
                        dp[i][j][num[k]] %= mod;
                    }
                }
                else
                {
                    if (j == 0)
                        continue;
                    for (int t = 0; t < len; t++)
                    {
                        dp[i][j][num[k]] += dp[i - 1][j - 1][vec[num[k]][t]];
                        dp[i][j][num[k]] %= mod;
                    }
                }
                if (i == n + m && j == n)
                {
                    // cout<<"ans cH";
                    ans += dp[i][j][num[k]];
                    ans %= mod;
                }
            }
    cout << ans;
    return 0;
}
