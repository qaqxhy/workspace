#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int m;
FILE *fout;

/* check if s is a runaround number;  mark where we've been by writing 'X' */
int isrunaround(char *s)
{
    int oi, i, j, len;
    char t[10];

    strcpy(t, s);
    len = strlen(t);

    i = 0;
    while (t[i] != 'X')
    {
        oi = i;
        i = (i + t[i] - '0') % len;
        t[oi] = 'X';
    }

    /* if the string is all X's and we ended at 0, it's a runaround */
    if (i != 0)
        return 0;

    for (j = 0; j < len; j++)
        if (t[j] != 'X')
            return 0;

    return 1;
}

/*
 * create an md-digit number in the string s.
 * the used array keeps track of which digits are already taken.
 * s already has nd digits.
 */
void permutation(char *s, int *used, int nd, int md)
{
    int i;

    if (nd == md)
    {
        s[nd] = '\0';
        if (atoi(s) > m && isrunaround(s))
        {
            fprintf(fout, "%s\n", s);
            exit(0);
        }
        return;
    }

    for (i = 1; i <= 9; i++)
    {
        if (!used[i])
        {
            s[nd] = i + '0';
            used[i] = 1;
            permutation(s, used, nd + 1, md);
            used[i] = 0;
        }
    }
}

void main(void)
{
    FILE *fin;
    char s[10];
    int i, used[10];

    fin = fopen("runround.in", "r");
    fout = fopen("runround.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &m);

    for (i = 0; i < 10; i++)
        used[i] = 0;

    for (i = 1; i <= 9; i++)
        permutation(s, used, 0, i);

    assert(0); /* not reached */
}