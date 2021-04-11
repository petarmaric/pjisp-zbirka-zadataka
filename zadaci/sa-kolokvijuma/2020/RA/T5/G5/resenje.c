#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CVECE 11
#define MAX_CVECARA 21

typedef struct cvece_st
{
  char cvecara[MAX_CVECARA];
  char vrsta_cveca[MAX_CVECE];
  double cena;
  struct cvece_st *sledeci;
} CVECE;

FILE *safe_fopen(char *filename, char *mode);
void ucitaj(FILE *in, CVECE **glava);
void inicijalizacija(CVECE **glava);
CVECE *napravi_cvor(char *cvecara, char *vrsta_cveca, double *cena);
void dodaj_cvor(CVECE **glava, CVECE *novi);
CVECE *najpovoljniji_cvet(CVECE *glava, char cvecara[], char vrsta_cveca[]);
void ispis(CVECE *glava);
void obrisi_listu(CVECE **glava);

int main(int BrArg, char **argv)
{
  if (BrArg != 3)
  {
    printf("Greska prilikom poziva programa\n");
    exit(EXIT_FAILURE);
  }

  char cvecara[21];
  char *vrsta_cveca = argv[1];
  FILE *in = safe_fopen(argv[2], "r");

  CVECE *glava;
  inicijalizacija(&glava);

  ucitaj(in, &glava);
  ispis(glava);

  CVECE *najpovoljniji = najpovoljniji_cvet(glava, cvecara, vrsta_cveca);
  if (najpovoljniji == NULL)
  {
    printf(
        "\nU trenutno raspolozivim cvecarama ne postoji cvet %s!\n",
        vrsta_cveca);
  }
  else
  {
    printf(
        "\nCvecara sa najpovoljnijim cvetom %s je %s, njena cena je %.2lf\n",
        vrsta_cveca,
        najpovoljniji->cvecara,
        najpovoljniji->cena);
  }
  obrisi_listu(&glava);

  fclose(in);

  return 0;
}
FILE *safe_fopen(char *filename, char *mode)
{
  FILE *fp = fopen(filename, mode);

  if (fp == NULL)
  {
    printf("Nije moguce otvoriti datoteku %s!\n", filename);
    exit(EXIT_FAILURE);
  }

  return fp;
}

void ucitaj(FILE *in, CVECE **glava)
{
  char cvecara[MAX_CVECARA];
  char vrsta_cveca[MAX_CVECE];
  double cena;

  while (fscanf(in, "%s %s %lf", cvecara, vrsta_cveca, &cena) != EOF)
  {
    dodaj_cvor(glava, napravi_cvor(cvecara, vrsta_cveca, &cena));
  }
}
void inicijalizacija(CVECE **glava)
{
  *glava = NULL;
}
CVECE *napravi_cvor(char *cvecara, char *vrsta_cveca, double *cena)
{
  CVECE *novi = (CVECE *)malloc(sizeof(CVECE));

  if (novi == NULL)
  {
    printf("Greska prilikom zauzimanja memorije!\n");
    exit(EXIT_FAILURE);
  }
  strcpy(novi->cvecara, cvecara);
  strcpy(novi->vrsta_cveca, vrsta_cveca);
  novi->cena = *cena;

  novi->sledeci = NULL;

  return novi;
}
void dodaj_cvor(CVECE **glava, CVECE *novi)
{
  if (*glava == NULL)
  {
    *glava = novi;
  }
  else
  {
    CVECE *tekuci = *glava;

    while (tekuci->sledeci != NULL)
    {
      tekuci = tekuci->sledeci;
    }

    tekuci->sledeci = novi;
  }
}
CVECE *najpovoljniji_cvet(CVECE *glava, char cvecara[], char vrsta_cveca[])
{
  if (glava == NULL)
  {
    return NULL;
  }
  CVECE *najpovoljniji = NULL;
  while (glava != NULL)
  {
    if (strcmp(glava->vrsta_cveca, vrsta_cveca) == 0)
    {
      if (najpovoljniji == NULL)
      {
        najpovoljniji = glava;
      }
      else if (glava->cena < najpovoljniji->cena)
      {
        najpovoljniji = glava;
      }
    }
    glava = glava->sledeci;
  }

  return najpovoljniji;
}
void ispis(CVECE *glava)
{
  CVECE *tekuci = glava;

  while (tekuci != NULL)
  {
    printf(
        "%6.2lf %s %s\n",
        tekuci->cena,
        tekuci->vrsta_cveca,
        tekuci->cvecara);
    tekuci = tekuci->sledeci;
  }
}
void obrisi_listu(CVECE **glava)
{
  CVECE *tekuci;

  while (*glava != NULL)
  {
    tekuci = *glava;
    *glava = (*glava)->sledeci;
    tekuci->sledeci = NULL;
    free(tekuci);
  }
}
