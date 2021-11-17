#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXR 1000

int max(int a, int b)
{
    return a > b ? a : b;
}

void main(void)
{
    int best[MAXR], oldbest[MAXR];
    int i, j, r, n, m;
    FILE *fin, *fout;

    fin = fopen("numtri.in", "r");
    assert(fin != NULL);
    fout = fopen("numtri.out", "w");
    assert(fout != NULL);

    fscanf(fin, "%d", &r);

    for (i = 0; i < MAXR; i++)
        best[i] = 0;

    for (i = 1; i <= r; i++)
    {
        memmove(oldbest, best, sizeof oldbest);
        for (j = 0; j < i; j++)
        {
            fscanf(fin, "%d", &n);
            if (j == 0)
                best[j] = oldbest[j] + n;
            else
                best[j] = max(oldbest[j], oldbest[j - 1]) + n;
        }
    }

    m = 0;
    for (i = 0; i < r; i++)
        if (best[i] > m)
            m = best[i];

    fprintf(fout, "%d\n", m);
    exit(0);
}