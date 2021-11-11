#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x;
    int y;
} e[100100];
int cmp(node a, node b)
{
    return a.y<b.y;
}
int main()
{
    ios::sync_with_stdio(0);
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> e[i].x >> e[i].y;
    sort(e + 1, e + 1 + q, cmp);
    int ans = 0;
    int l = 1, r = q;
    while (l <= r)
    {
        ans = max(ans, e[l].y + e[r].y);
        if (e[l].x > e[r].x)
        {
            e[l].x -= e[r].x;
            r--;
        }
        else if (e[l].x == e[r].x)
        {
            l++;
            r--;
        }
        else
        {
            e[r].x -= e[l].x;
            l++;
        }
    }
    cout<<ans;
    return 0;

}