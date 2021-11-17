#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define MAX (1 << 8 + 1)
#define NMAX 65
#define BMAX 10
#define DMAX 10

int nums[NMAX], dist[MAX][MAX];
int N, B, D, maxval;
FILE *in, *out;

void findgroups(int cur, int start)
{
    int a, b, canuse;
    char ch;
    if (cur == N)
    {
        for (a = 0; a < cur; a++)
        {
            if (a % 10)
                fprintf(out, " ");
            fprintf(out, "%d", nums[a]);
            if (a % 10 == 9 || a == cur - 1)
                fprintf(out, "\n");
        }
        exit(0);
    }
    for (a = start; a < maxval; a++)
    {
        canuse = 1;
        for (b = 0; b < cur; b++)
            if (dist[nums[b]][a] < D)
            {
                canuse = 0;
                break;
            }
        if (canuse)
        {
            nums[cur] = a;
            findgroups(cur + 1, a + 1);
        }
    }
}

int main()
{
    in = fopen("hamming.in", "r");
    out = fopen("hamming.out", "w");
    int a, b, c;
    fscanf(in, "%d%d%d", &N, &B, &D);
    maxval = (1 << B);
    for (a = 0; a < maxval; a++)
        for (b = 0; b < maxval; b++)
        {
            dist[a][b] = 0;
            for (c = 0; c < B; c++)
                if (((1 << c) & a) != ((1 << c) & b))
                    dist[a][b]++;
        }
    nums[0] = 0;
    findgroups(1, 1);
    return 0;
}
