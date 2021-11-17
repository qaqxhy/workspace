#include <stdio.h>
#include <assert.h>
#include <string>

using namespace std;

// open files
FILE *fin = fopen("ariprog.in", "r");
FILE *fout = fopen("ariprog.out", "w");

// global variables
unsigned int N, M, maxMM;
unsigned int numbers[65000];
unsigned int number_size = 0;
unsigned char num_available[125001];
unsigned char dist_available[125001];
int have_res = 0;
int skipstep = 1;

// read the input

int read_input()
{
    fscanf(fin, "%d %d", &N, &M);
    return 0;
}

int cmp_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void asm_num(int a, int b)
{
    for (unsigned int n = 1; n < N; n++)
        if (num_available[a + n * b] == 0)
            return;

    fprintf(fout, "%d %d\n", a, b);
    have_res++;
    if (have_res == 1)
        skipstep = b;
}

void asm_num()
{
    for (unsigned int b = 1; b < maxMM; b += skipstep)
    {
        if (dist_available[b])
        {
            for (unsigned int p = 0; p < number_size && numbers[p] + (N -
                                                                      1) *
                                                                         b <=
                                                            maxMM;
                 p++)
                asm_num(numbers[p], b);
        }
    }
}

int process()
{
    memset(num_available, 0, sizeof(unsigned char) * 125001);
    memset(dist_available, 0, sizeof(unsigned char) * 125001);

    for (unsigned int m1 = 0; m1 <= M; m1++)
    {
        for (unsigned int m2 = m1; m2 <= M; m2++)
        {
            int n = m1 * m1 + m2 * m2;

            if (!num_available[n])
            {
                num_available[n] = 1;
                numbers[number_size++] = n;
            }
        }
    }

    qsort(numbers, number_size, sizeof(unsigned int), cmp_int);

    maxMM = M * M + M * M;
    for (unsigned int n1 = 0; n1 < number_size; n1++)
    {
        unsigned int _n1 = numbers[n1];
        for (unsigned int n2 = n1 + 1; n2 < number_size && _n1 + (numbers
                                                                      [n2] -
                                                                  _n1) *
                                                                       (N - 1) <=
                                                               maxMM;
             n2++)
        {
            assert(numbers[n2] - _n1 >= 0 && numbers[n2] - _n1 < 125001);
            if (num_available[_n1 + (numbers[n2] - _n1) * (N - 1)] &&
                num_available[_n1 + (numbers[n2] - _n1) * (N - 2)])
                dist_available[numbers[n2] - _n1] = true;
        }
    }

    asm_num();

    if (!have_res)
        fprintf(fout, "NONE\n");

    return 0;
}

int main()
{
    read_input();
    process();
    fclose(fin);
    fclose(fout);
    return 0;
}
Here is an even faster solution of "UaE ProGrammeR" :

#include <fstream>
#include <iostream>

    using namespace std;
void quicksort(int[], int, int);
int pivotlist(int[], int, int);

ofstream out("ariprog.out");

int n;
int main()
{
    ifstream in("ariprog.in");

    bool array[125001] = {false}, noneF;
    int m, upper, upperdef, def, p;
    int places[300000], pl = 0;
    noneF = true;

    in >> n >> m;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
        {
            if (!array[i * i + j * j])
            {
                places[pl] = i * i + j * j; //Saving generated numbers
                pl++;
            }
            array[i * i + j * j] = true;
        }

    upper = 2 * m * m;
    upperdef = upper / (n - 1);

    quicksort(places, 0, pl - 1);

    for (def = 1; def <= upperdef; def++) // Loop to check for solutions
                                          // It looks for solutions in
                                          // correct order so you
                                          // print the solution directly
                                          // without sorting first, thnx to who said:
                                          // Trade Memory for Speed !!
    {
        for (p = 0; places[p] <= (upper - ((n - 2) * def)); p++)
        {
            bool is;
            is = true;
            int where;

            for (int c = (n - 1); c >= 0; c--)
                if (!array[places[p] + c * def])
                {
                    is = false;
                    where = (p + c * def);
                    break;
                }

            if (is)
            {
                noneF = false;
                out << places[p] << " " << def << endl;
            }
        }
    }

    if (noneF)
        out << "NONE" << endl;

    return 0;
}

void quicksort(int array[], int start, int last)
{
    int pivot;
    if (start < last)
    {
        pivot = pivotlist(array, start, last);
        quicksort(array, start, pivot - 1);
        quicksort(array, pivot + 1, last);
    }
}

int pivotlist(int array[], int f, int l)
{
    int pivotpoint;
    int pivotvalue, temp;

    pivotvalue = array[f];
    pivotpoint = f;

    for (int i = f + 1; i <= l; i++)
    {
        if (array[i] < pivotvalue)
        {
            pivotpoint++;
            temp = array[i];
            array[i] = array[pivotpoint];
            array[pivotpoint] = temp;
        }
    }
    temp = array[f];
    array[f] = array[pivotpoint];
    array[pivotpoint] = temp;

    return pivotpoint;
}