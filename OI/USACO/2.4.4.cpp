/*
ID: iam_har1
LANG: C
PROG: cowtour
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 200000

struct node
{
    int x, y;
};

struct node nodes[150];
int table[150][150];
int N;
double distance_table[150][150];
double max_distance[150];

void GetInput(FILE *fin)
{
    int i, j;
    char c;

    fscanf(fin, "%d", &N);

    for (i = 0; i < N; i++)
    {
        fscanf(fin, "%d %d", &(nodes[i].x), &(nodes[i].y));
    }

    fscanf(fin, "%c", &c);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            fscanf(fin, "%c", &c);
            if (c == '0')
            {
                table[i][j] = 0;
            }
            else
            {
                table[i][j] = 1;
            }
        }
        fscanf(fin, "%c", &c);
    }
}

double GetDistance(int i, int j)
{
    double diff_x = (double)(nodes[i].x - nodes[j].x);
    double diff_y = (double)(nodes[i].y - nodes[j].y);

    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

void Floyd(void)
{
    int i, j, k;
    double temp;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (table[i][j] == 1)
            {
                distance_table[i][j] = GetDistance(i, j);
            }
            else
            {
                distance_table[i][j] = MAX;
            }
        }
    }

    for (k = 0; k < N; k++)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                temp = distance_table[i][k] + distance_table[k][j];
                if ((i != j) && (temp < distance_table[i][j]))
                {
                    distance_table[i][j] = temp;
                }
            }
        }
    }
}

void GetMaxDistance(void)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        max_distance[i] = 0.0;
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if ((max_distance[i] < distance_table[i][j]) && distance_table[i][j] != MAX)
            {
                max_distance[i] = distance_table[i][j];
            }
        }
    }
}

double GetMinDiameter(void)
{
    double ret = MAX, temp;
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if ((i != j) && (distance_table[i][j] == MAX))
            {
                temp = GetDistance(i, j) + max_distance[i] + max_distance[j];
                if (temp < ret)
                {
                    ret = temp;
                }
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        if (max_distance[i] > ret)
        {
            ret = max_distance[i];
        }
    }
    return ret;
}

int main(void)
{
    FILE *fin, *fout;
    double result;

    fin = fopen("cowtour.in", "r");
    fout = fopen("cowtour.out", "w");

    /*get input*/
    GetInput(fin);
    /*Floyd*/
    Floyd();
    /*get the max distance of each point*/
    GetMaxDistance();
    /*get the minimum diameter*/
    result = GetMinDiameter();
    fprintf(fout, "%lf\n", result);
    return 0;
}