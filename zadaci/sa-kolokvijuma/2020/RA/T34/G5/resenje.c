#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 15

typedef struct rodjendan_st
{
  char ime[MAX_SIZE];
  unsigned dan;
  unsigned mesec;
  unsigned br_parcadi;
} RODJUS;

FILE *safe_open(char *, char *);
void ucitaj(FILE *, RODJUS *, int *);
void ispisi_slavljenika(RODJUS *niz, int n);
float suma_parcadi(RODJUS *niz, int n);
void broj_torti(RODJUS *niz, int p);

int main()
{

  RODJUS niz[MAX_SIZE];

  FILE *in;
  int t, n;
  in = safe_open("rodjendan.txt", "r");

  ucitaj(in, niz, &n);
  ispisi_slavljenika(niz, n);
  broj_torti(niz, t);

  fclose(in);
}
FILE *safe_open(char *name, char *mode)
{

  FILE *fp = fopen(name, mode);

  if (fp == NULL)
  {
    printf("Doslo je do greske prilikom otvaranja fajla %s.\n", name);
    exit(EXIT_FAILURE);
  }

  return fp;
}
void ucitaj(FILE *in, RODJUS *niz, int *n)
{
  *n = 0;
  while (
      fscanf(
          in,
          "%s %u %u %u",
          niz[*n].ime,
          &niz[*n].dan,
          &niz[*n].mesec,
          &niz[*n].br_parcadi) != EOF)
  {
    (*n)++;
  }
}
void ispisi_slavljenika(RODJUS *niz, int n)
{
  int i;

  for (i = 0; i < n; i++)
  {
    if ((niz[i].mesec == 12 && niz[i].dan == 5))
      printf("Srecan rodjendan %s!\n", niz[i].ime);
  }
}
float suma_parcadi(RODJUS *niz, int n)
{
  int i;
  unsigned suma = niz[0].br_parcadi;
  for (i = 1; i < n; i++)
  {
    suma += niz[i].br_parcadi;
  }
  return suma;
}
void broj_torti(RODJUS *niz, int t)
{

  do
  {
    printf("Unesite broj torti (maksimalno 10):\n ");
    scanf("%d", &t);
  } while (t <= 0 || t > 10);
  int n;
  int max_parcadi = t * 10;

  if ((suma_parcadi(niz, n)) <= max_parcadi)
  {
    printf("Ima dovoljno torte!\n");
  }
  else
  {
    printf("Nema dovoljno torte!\n");
  }
}
