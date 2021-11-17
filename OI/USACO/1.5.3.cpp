#include <stdio.h>

int m[21][21][21];
int poss[21];
int A, B, C;

int main(void)
{
    int i, j, k;
    int flag;
    FILE *in = fopen("milk3.in", "r");
    fscanf(in, "%d %d %d", &A, &B, &C);
    fclose(in);
    for (i = 0; i < 21; i++)
        for (j = 0; j < 21; j++)
            for (k = 0; k < 21; k++)
                m[i][j][k] = 0;
    for (i = 0; i < 21; i++)
        poss[i] = 0;
    m[0][0][C] = 1;

    for (flag = 1; flag;)
    {
        flag = 0;
        for (i = 0; i <= A; i++)
            for (j = 0; j <= B; j++)
                for (k = 0; k <= C; k++)
                {
                    if (m[i][j][k])
                    {
                        if (i == 0)
                            poss[k] = 1;
                        if (i)
                        {
                            if (j < B)
                            {
                                if (B - j >= i)
                                {
                                    if (m[0][j + i][k] == 0)
                                    {
                                        m[0][j + i][k] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[i - (B - j)][B][k] == 0)
                                    {
                                        m[i - (B - j)][B][k] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                            if (k < C)
                            {
                                if (C - k >= i)
                                {
                                    if (m[0][j][k + i] == 0)
                                    {
                                        m[0][j][k + i] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[i - (C - k)][j][C] == 0)
                                    {
                                        m[i - (C - k)][j][C] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                        }
                        if (j)
                        {
                            if (i < A)
                            {
                                if (A - i >= j)
                                {
                                    if (m[i + j][0][k] == 0)
                                    {
                                        m[i + j][0][k] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[A][j - (A - i)][k] == 0)
                                    {
                                        m[A][j - (A - i)][k] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                            if (k < C)
                            {
                                if (C - k >= j)
                                {
                                    if (m[i][0][k + j] == 0)
                                    {
                                        m[i][0][k + j] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[i][j - (C - k)][C] == 0)
                                    {
                                        m[i][j - (C - k)][C] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                        }
                        if (k)
                        {
                            if (i < A)
                            {
                                if (A - i >= k)
                                {
                                    if (m[i + k][j][0] == 0)
                                    {
                                        m[i + k][j][0] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[A][j][k - (A - i)] == 0)
                                    {
                                        m[A][j][k - (A - i)] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                            if (j < B)
                            {
                                if (B - j >= k)
                                {
                                    if (m[i][j + k][0] == 0)
                                    {
                                        m[i][j + k][0] = 1;
                                        flag = 1;
                                    }
                                }
                                else
                                {
                                    if (m[i][B][k - (B - j)] == 0)
                                    {
                                        m[i][B][k - (B - j)] = 1;
                                        flag = 1;
                                    }
                                }
                            }
                        }
                    }
                }
    }
    {
        FILE *out = fopen("milk3.out", "w");
        for (i = 0; i < 21; i++)
        {
            if (poss[i])
            {
                fprintf(out, "%d", i);
                i++;
                break;
            }
        }
        for (; i < 21; i++)
        {
            if (poss[i])
            {
                fprintf(out, " %d", i);
            }
        }
        fprintf(out, "\n");
    }
    return 0;
}
