/*
USER: iam_har1
TASK: ttwo
LANG: C++
*/
#include <cstdio>
#include <iostream>
char m[11][11];
int vis[101][101][5][5];
int dx[5] = {-1, 0, 1, 0}, dy[5] = {0, 1, 0, -1};
int ans;
bool ck(int x, int y)
{
    return x >= 0 && x < 10 && y >= 0 && y < 10 && m[x][y] != '*';
}
bool dfs(int fx, int fy, int df, int cx, int cy, int dc)
{
    // printf("f=(%d %d) %d c=(%d %d) %d\n",fx,fy,df,cx,cy,dc);
    int ff = fx * 10 + fy, cc = cx * 10 + cy;
    if (vis[ff][cc][df][dc])
        return 0;
    vis[ff][cc][df][dc] = 1;
    if (ff == cc)
        return 1;
    ans++;
    int nfx = fx + dx[df], nfy = fy + dy[df], ncx = cx + dx[dc], ncy = cy + dy[dc];
    if (!ck(nfx, nfy))
    {
        df = (df + 1) % 4;
        nfx = fx;
        nfy = fy;
    }
    if (!ck(ncx, ncy))
    {
        dc = (dc + 1) % 4;
        ncx = cx;
        ncy = cy;
    }
    if (dfs(nfx, nfy, df, ncx, ncy, dc))
        return 1;
    ans--;
    return 0;
}
int main()
{
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    int cx, cy, fx, fy;
    for (int i = 0; i < 10; i++)
    {
        scanf("%s", m[i]);
        for (int j = 0; m[i][j]; j++)
            if (m[i][j] == 'C')
            {
                cx = i;
                cy = j;
            }
            else if (m[i][j] == 'F')
            {
                fx = i;
                fy = j;
            }
    }
    if (dfs(fx, fy, 0, cx, cy, 0))
    {
        printf("%d\n", ans);
    }
    else
    {
        puts("0");
    }
    return 0;
}