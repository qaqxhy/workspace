// t2
#include <bits/stdc++.h>
using namespace std;
int n;
int G[1919];
int cg;
int L[1919];
int cl;
int cmp(int x, int y)
{
    return x > y;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'G')
        {
            int tp;
            scanf("%d", &tp);
            G[cg++] = tp;
        }
        else
        {
            int tp;
            scanf("%d", &tp);
            L[cl++] = tp;
        }
    }
    sort(G, G + cg);
    sort(L, L + cl);

/*    for (int i = 0; i <= n; i++)
    {
        cout << G[i] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << L[i] << " ";
    }
    cout << endl;*/
    int min = cg + cl;
    int temp = 0;
    int idxG = 0;
    for (int ii = 0; ii < cl; ii++)
    {
        temp = ii+cg-idxG;
        for (int jj = idxG; jj < cg; jj++)
        {
            if (G[jj] <= L[ii])
            {
                temp--;
            }
            else{
                idxG = jj;
                break;
            }
        }
        if(temp<min){
            min=temp;
        }
    }

    cout << min;
}