/*
ID:iam_har1
LANG:C++
TASK:maze1
*/
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int w,h,ans=0,s[205][100],cx1=-1,cy1=-1,cx2=-1,cy2=-1;
char m[205][100];
string temp;
void dfs(int x,int y)
{
    if(x-1>0 && m[x-1][y]==' ' && (s[x][y]+1<s[x-1][y] || s[x-1][y]==-1))
    {
        //cout<<s[x][y]+1<<' '<<x-1<<' '<<y<<endl;
        s[x-1][y]=s[x][y]+1;
        dfs(x-1,y);
    }
    if(x+1<2*h && m[x+1][y]==' ' && (s[x][y]+1<s[x+1][y] || s[x+1][y]==-1))
    {

        //cout<<s[x][y]+1<<' '<<x+1<<' '<<y<<endl;
        s[x+1][y]=s[x][y]+1;
        dfs(x+1,y);
    }
    if(y-1>0 && m[x][y-1]==' ' && (s[x][y]+1<s[x][y-1] || s[x][y-1]==-1))
    {

        //cout<<s[x][y]+1<<' '<<x<<' '<<y-1<<endl;
        s[x][y-1]=s[x][y]+1;
        dfs(x,y-1);
    }
    if(y+1<2*w && m[x][y+1]==' ' && (s[x][y]+1<s[x][y+1] || s[x][y+1]==-1))
    {
        //cout<<s[x][y]+1<<' '<<x<<' '<<y+1<<endl;
        s[x][y+1]=s[x][y]+1;
        dfs(x,y+1);
    }
}
int main(void)
{
    freopen("maze1.in","r",stdin);
    freopen("maze1.out","w",stdout);
    scanf("%d%d",&w,&h);
    getchar();
    memset(s,-1,sizeof(s));
    for(int i=0;i<=2*h;i++)
    {
        getline(cin,temp);
        for(int j=0;j<=2*w;j++)
        {
            m[i][j]=temp[j];
            if(m[i][j]==' ')
            {
                if(i==0 || i==h*2 || j==0 || j==w*2)
                {
                    s[i][j]=0;
                    if(cx1==-1)
                    {
                        cx1=i;
                        cy1=j;
                    }
                    else
                    {
                        cx2=i;
                        cy2=j;
                    }
                }
            }
        }
    }
    //cout<<cx1<<' '<<cy1<<' '<<s[cx1][cy1]<<' '<<cx2<<' '<<cy2<<' '<<s[cx2][cy2]<<endl;
    dfs(cx1,cy1);
    dfs(cx2,cy2);
    for(int i=0;i<=2*h;i++)
        for(int j=0;j<=2*w;j++)
            if(s[i][j]>ans)
                ans=s[i][j];
    printf("%d\n",(ans+1)/2);
    return 0;
}