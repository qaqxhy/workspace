// t1
#include <bits/stdc++.h>
using namespace std;
int n;
int num = 0;
bool temp = true;
int idx = 0;
int main()
{
    scanf("%d", &n);
    cin.sync();
    num = 0;
    for (int ii = 0; ii < n / 2; ii++)
    {
        char a1, a2;
        a1=cin.get();
        a2=cin.get();
        if ((a1 == 'G') && (a2 == 'H'))
        {
            idx = ii+1;
            num = num + 1;
            temp = true;
            break;
        }
        else if ((a1  == 'H') && (a2 == 'G'))
        {
            temp = false;
            idx = ii+1;
            break;
        }
    }
    cin.sync();
    for (int ii = idx; ii < n / 2; ii++)
    {
        char a1,a2;
        a1=cin.get();
        a2=cin.get();
        if ((a1 == 'G') && (a2 == 'H') && (!temp))
        {
            num = num + 2;
            temp = true;
        }
        else if ((a1 == 'H') && (a2 == 'G') && (temp))
        {
            temp = false;
        }
    }

    cout << num << endl;
}