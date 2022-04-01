// t1
#include <bits/stdc++.h>
using namespace std;
int n;
int num = 0;
bool temp = true;
int idx = 0;
char a[1024];
int charnum = 0;
int main()
{
    scanf("%d", &n);
    bool tmp = false;
    while(cin.getline(a, sizeof(a))){
        charnum = charnum+1024;
        for (int ii = 0; ii < 512; ii++){
            if ((a[2 * ii] == 'G') && (a[2 * ii + 1] == 'H'))
            {
                idx = ii;
                num = 1;
                temp = true;
                tmp = true;
                break;
            }
            else if ((a[2 * ii] == 'H') && (a[2 * ii + 1] == 'G'))
            {
                idx = ii;
                temp=false;
                tmp = true;
                break;
            }
        }
        if(tmp){
            break;
        }
        if(charnum>n){
            break;
        }
    }
    cout<<num<<endl;
    for (int ii = idx; ii < 512; ii++){
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
    while(cin.getline(a, sizeof(a))){
        charnum = charnum+1024;
        for (int ii = 0; ii < 512; ii++){
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
        if(charnum>n){
            break;
        }
    }
    cout << num << endl;
}