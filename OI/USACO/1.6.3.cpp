#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

FILE *fout;
long a, b;

int isprime(long n)
{
    long i;

    if (n == 2)
        return 1;

    if (n % 2 == 0)
        return 0;

    for (i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return 0;

    return 1;
}

void gen(int i, int isodd)
{
    char buf[30];
    char *p, *q;
    long n;

    sprintf(buf, "%d", i);

    p = buf + strlen(buf);
    q = p - isodd;

    while (q > buf)
        *p++ = *--q;
    *p = '\0';

    n = atol(buf);
    if (a <= n && n <= b && isprime(n))
        fprintf(fout, "%ld\n", n);
}

void genoddeven(int lo, int hi)
{
    int i;

    for (i = lo; i <= hi; i++)
        gen(i, 1);

    for (i = lo; i <= hi; i++)
        gen(i, 0);
}

void generate(void)
{
    genoddeven(1, 9);
    genoddeven(10, 99);
    genoddeven(100, 999);
    genoddeven(1000, 9999);
}

void main(void)
{
    FILE *fin;

    fin = fopen("pprime.in", "r");
    fout = fopen("pprime.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%ld %ld", &a, &b);

    generate();
    exit(0);
}
