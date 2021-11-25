/*
ID:iam_har1
LANG:C++11
TASK:money
*/
#include <fstream>
#include <cstring>
using namespace std;
const int mm = 11000;
ifstream cin("money.in");
ofstream cout("money.out");
long long f[mm];
int cost[33];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = cost[i]; j <= m; j++)
            f[j] += f[j - cost[i]];
    }
    cout << f[m] << endl;
}