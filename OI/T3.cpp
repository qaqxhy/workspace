#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int a[6]={0};
        int b[6]={0};
        for(int i=1;i<=4;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=4;i++)
        {
            scanf("%d",&b[i]);
        }
        int win=0;
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                if(a[i]>b[j])
                {
                    win++;
                }
            }
        }
        if(win==16||win==0)
        {
            printf("no\n");
        }
        else
            printf("yes\n");
    }
}