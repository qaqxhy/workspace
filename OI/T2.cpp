#include<bits/stdc++.h>
using namespace std;
int g,y;
char ans[6][6];
char ges[6][6];
int gbu[30];
int abu[30];
int main()
{
    for(int i=1;i<=3;i++)
    {
        scanf("%s",ans[i]+1);
    }
    for(int i=1;i<=3;i++)
    {
        scanf("%s",ges[i]+1);
    }
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=3;j++)
        {
            abu[ans[i][j]-'A'+1]++;
            gbu[ges[i][j]-'A'+1]++;
            if(ans[i][j]==ges[i][j])
            {
                g++;
                abu[ans[i][j]-'A'+1]--;
                gbu[ges[i][j]-'A'+1]--;
            }
        }
    }
    for(int i=1;i<26;i++)
    {
        if(abu[i]&&gbu[i])
        {
            y+=min(gbu[i],abu[i]);
        }
    }
    printf("%d\n%d",g,y);
}