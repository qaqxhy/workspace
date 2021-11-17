#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAXFARMER 5000

typedef struct Farmer Farmer;
struct Farmer
{
    int p; /* price per gallon */
    int a; /* amount to sell */
};

int farmcmp(const void *va, const void *vb)
{
    return ((Farmer *)va)->p - ((Farmer *)vb)->p;
}

int nfarmer;
Farmer farmer[MAXFARMER];

void main(void)
{
    FILE *fin, *fout;
    int i, n, a, p;

    fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");

    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d %d", &n, &nfarmer);
    for (i = 0; i < nfarmer; i++)
        fscanf(fin, "%d %d", &farmer[i].p, &farmer[i].a);

    qsort(farmer, nfarmer, sizeof(farmer[0]), farmcmp);

    p = 0;
    for (i = 0; i < nfarmer && n > 0; i++)
    {
        /* take as much as possible from farmer[i], up to amount n */
        a = farmer[i].a;
        if (a > n)
            a = n;
        p += a * farmer[i].p;
        n -= a;
    }

    fprintf(fout, "%d\n", p);
    exit(0);
}