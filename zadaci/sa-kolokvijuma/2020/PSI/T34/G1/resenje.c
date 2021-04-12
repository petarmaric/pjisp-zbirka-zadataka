#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20 + 1
#define MAX_NIZ 30

typedef struct caj_st
{
    char naziv[MAX_NAZIV];
    unsigned min;
    unsigned max;
} caj;

FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_cajeve(FILE *in, caj cajevi[], int *n);
int nadji_najjaci(caj cajevi[], int n);

int main(int arg_num, char **args)
{
    if (arg_num != 2)
    {
        printf("USAGE: %s MASA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    char *in_filename = args[1];

    FILE *in = safe_fopen(in_filename, "r", 1);

    int n;
    caj cajevi[MAX_NIZ];

    ucitaj_cajeve(in, cajevi, &n);

    int najjaci = nadji_najjaci(cajevi, n);
    printf(
        "%s %.2lf",
        cajevi[najjaci].naziv,
        (cajevi[najjaci].min + cajevi[najjaci].max) / 2.0);
    fclose(in);

    return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code)
{
    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

void ucitaj_cajeve(FILE *in, caj cajevi[], int *n)
{
    *n = 0;
    while (fscanf(
               in, "%s %u %u",
               cajevi[*n].naziv,
               &cajevi[*n].min,
               &cajevi[*n].max) != EOF)
    {
        (*n)++;
    }
}

int nadji_najjaci(caj cajevi[], int n)
{
    int najjaci = 0;
    int i;
    double prosek_i, prosek_najjaci;
    for (i = 1; i < n; i++)
    {
        prosek_i = (cajevi[i].min + cajevi[i].max) / 2;
        prosek_najjaci = (cajevi[najjaci].min + cajevi[najjaci].max) / 2;
        if (prosek_najjaci < prosek_i)
        {
            najjaci = i;
        }
    }
    return najjaci;
}
