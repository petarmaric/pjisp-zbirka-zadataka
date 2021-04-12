#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20 + 1
#define MAX_NIZ 30

typedef struct skijaliste_st
{
    char naziv[MAX_NAZIV];
    double cena_dnevne_karte;
} skijaliste;

FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_skijalista(FILE *in, skijaliste skijalista[], int *n);
int nadji_najbolju_ponudu(skijaliste skijalista[], int n);

int main(int arg_num, char **args)
{
    if (arg_num != 2)
    {
        printf("USAGE: %s MASA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    char *in_filename = args[1];

    FILE *in = safe_fopen(in_filename, "r", 1);

    int br_dana;
    printf("Unesi broj dana: ");
    scanf("%d", &br_dana);

    int n;
    skijaliste skijalista[MAX_NIZ];

    ucitaj_skijalista(in, skijalista, &n);

    int najbolji = nadji_najbolju_ponudu(skijalista, n);
    printf(
        "%s %.2lf",
        skijalista[najbolji].naziv,
        skijalista[najbolji].cena_dnevne_karte * br_dana);
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

void ucitaj_skijalista(FILE *in, skijaliste skijalista[], int *n)
{
    *n = 0;
    while (fscanf(
               in, "%s %lf",
               skijalista[*n].naziv,
               &skijalista[*n].cena_dnevne_karte) != EOF)
    {
        (*n)++;
    }
}

int nadji_najbolju_ponudu(skijaliste skijalista[], int n)
{
    int najbolji = 0;
    int i;
    for (i = 1; i < n; i++)
    {
        if (skijalista[najbolji].cena_dnevne_karte >
            skijalista[i].cena_dnevne_karte)
        {
            najbolji = i;
        }
    }
    return najbolji;
}
