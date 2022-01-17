/*
TASK:comehome
LANG:C++
ID:iam_har1
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 99999999
using namespace std;
 
int w[60][60];
bool cow[30];
 
void init() {
    for(int i = 0; i < 60; ++i)
            for(int j = 0; j < 60; ++j)
                    w[i][j] = INF;
 
    for(int i = 0; i <= 26; ++i)  cow[i] = false;
}
 
void floyd() {
    for(int k = 0; k < 60; ++k)
            for(int i = 0; i < 60; ++i)
                    for(int j = 0; j < 60; ++j)
                            if(w[i][k] < INF &&
                               w[k][j] < INF &&
                               w[i][j] > w[i][k] + w[k][j])
                               w[i][j] = w[i][k] + w[k][j];
}
 
int main() {
    freopen("comehome.in","r",stdin);
    freopen("comehome.out","w",stdout);
    int n;
    init();
 
    scanf("%d",&n);
    getchar();
    while(n--) {
        char a,b;
        int dis;
        scanf("%c %c%d",&a,&b,&dis);
        getchar();
 
        if(a >= 'A' && a <= 'Z') cow[a - 'A'] = true;
        if(b >= 'A' && b <= 'Z') cow[b - 'A'] = true;
 
        w[a - 'A'][b - 'A'] = min(w[a - 'A'][b - 'A'],dis);
        w[b - 'A'][a - 'A'] = min(w[b - 'A'][a - 'A'],dis);
    }
 
    floyd();
 
    int min_step = INF;
    char min_cow;
 
    for(int i = 0; i < 25; ++i)
            if(cow[i] && w[i][25] < min_step) {
                    min_step = w[i][25];
                    min_cow = 'A' + i;
            }
 
    printf("%c %d\n",min_cow,min_step);
    return 0;
}