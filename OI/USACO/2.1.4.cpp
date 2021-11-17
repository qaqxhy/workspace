#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int n;
FILE *fout;

/* print the fractions of denominator <= n between n1/d1 and n2/d2 */
void genfrac(int n1, int d1, int n2, int d2)
{
    if (d1 + d2 > n) /* cut off recursion */
        return;

    genfrac(n1, d1, n1 + n2, d1 + d2);
    fprintf(fout, "%d/%d\n", n1 + n2, d1 + d2);
    genfrac(n1 + n2, d1 + d2, n2, d2);
}

void main(void)
{
    FILE *fin;

    fin = fopen("frac1.in", "r");
    fout = fopen("frac1.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    fprintf(fout, "0/1\n");
    genfrac(0, 1, 1, 1);
    fprintf(fout, "1/1\n");
}