// t1
#include <bits/stdc++.h>
using namespace std;
int n;
int num = 0;
bool temp = true;
int idx = 0;
char a1,a2;
bool isfirst = true;
int main()
{
    scanf("%d", &n);
    cin.sync();
    for (int ii = 0; ii < n / 2; ii++)
    {
        a1=cin.get();
        a2=cin.get();
        if ((a1 == 'G') && (a2 == 'H') && (temp))
        {
            idx = ii+1;
            num = num + 2;
            temp = true;
            if(isfirst){
                num = num-1;
                isfirst = false;
            }
        }
        else if ((a1  == 'H') && (a2 == 'G') && (!temp))
        {
            if(isfirst){
                isfirst = false;
            }
            temp = false;
        }
    }

    cout << num << endl;
}