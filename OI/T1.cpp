// t1
#include <bits/stdc++.h>
using namespace std;
int n;
char a[114514];
int num = 0;
bool temp=true;
int main()
{
    scanf("%d", &n);
    scanf("%s", a);
    for (int ii = 0; ii < n / 2; ii++){
        
        if ((a[2 * ii] == 'G') && (a[2 * ii + 1] == 'H'))
        {
            num = num+1;
            temp = true;
            break;
        }
        else if ((a[2 * ii] == 'H') && (a[2 * ii + 1] == 'G'))
        {
            temp=false;
            break;
        }
    }
    for (int ii = 0; ii < n / 2; ii++){
        if ((a[2 * ii] == 'G') && (a[2 * ii + 1] == 'H') && (!temp))
        {
            num = num+2;
            temp = true;
        }
        else if ((a[2 * ii] == 'H') && (a[2 * ii + 1] == 'G') && (temp))
        {
            temp=false;
        }
    }
    cout << num << endl;
}