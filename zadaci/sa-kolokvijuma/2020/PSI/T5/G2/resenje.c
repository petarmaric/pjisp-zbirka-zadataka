#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAFFE 20 + 1
#define MAX_VRSTA_KAFE 20 + 1

typedef struct kafa_st
{
  char caffe[MAX_CAFFE];
  char vrsta_kafe[MAX_VRSTA_KAFE];
  double cena;

  struct kafa_st *sledeci;
} KAFA;

FILE *safe_fopen(char *filename, char *mode);
void ucitaj(FILE *in, KAFA **glava);
void inicijalizacija(KAFA **glava);
KAFA *napravi_cvor(char *caffe, char *vrsta_kafe, double *cena);
void dodaj_cvor(KAFA **glava, KAFA *novi);
double prosek(KAFA *glava, char vrsta_kafe[]);
void ispis(KAFA *glava);
void obrisi_listu(KAFA **glava);

int main(int BrArg, char **argv)
{
  if (BrArg != 3)
  {
    printf("Greska prilikom poziva programa\n");
    exit(EXIT_FAILURE);
  }

  char *vrsta_kafe = argv[1];
  FILE *in = safe_fopen(argv[2], "r");
  KAFA *glava;

  inicijalizacija(&glava);

  ucitaj(in, &glava);
  ispis(glava);

  double prosecna_cena = prosek(glava, vrsta_kafe);
  if (prosecna_cena == 0)
  {
    printf("\n%s kafa nije u ponudi!\n", vrsta_kafe);
  }
  else
  {
    printf(
        "\nProsecna cena %s kafe je = %6.2lf\n",
        vrsta_kafe, prosecna_cena);
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

void ucitaj(FILE *in, KAFA **glava)
{
  char caffe[MAX_CAFFE];
  char vrsta_kafe[MAX_VRSTA_KAFE];
  double cena;

  while (fscanf(in, "%s %s %lf", caffe, vrsta_kafe, &cena) != EOF)
  {
    dodaj_cvor(glava, napravi_cvor(caffe, vrsta_kafe, &cena));
  }
}
void inicijalizacija(KAFA **glava)
{
  *glava = NULL;
}
KAFA *napravi_cvor(char *caffe, char *vrsta_kafe, double *cena)
{
  KAFA *novi = (KAFA *)malloc(sizeof(KAFA));

  if (novi == NULL)
  {
    printf("Greska prilikom zauzimanja memorije!\n");
    exit(EXIT_FAILURE);
  }
  strcpy(novi->caffe, caffe);
  strcpy(novi->vrsta_kafe, vrsta_kafe);
  novi->cena = *cena;

  novi->sledeci = NULL;

  return novi;
}
void dodaj_cvor(KAFA **glava, KAFA *novi)
{
  if (*glava == NULL)
  {
    *glava = novi;
  }
  else
  {
    KAFA *tekuci = *glava;

    while (tekuci->sledeci != NULL)
    {
      tekuci = tekuci->sledeci;
    }

    tekuci->sledeci = novi;
  }
}
int broj_kafe(KAFA *glava, char vrsta_kafe[])
{
  int brojac = 0;

  while (glava != NULL)
  {
    if (strcmp(glava->vrsta_kafe, vrsta_kafe) == 0)
    {
      brojac++;
    }
    glava = glava->sledeci;
  }
  return brojac;
}

double suma_kafa(KAFA *glava, char vrsta_kafe[])
{
  double suma = 0;

  while (glava != NULL)
  {
    if (strcmp(glava->vrsta_kafe, vrsta_kafe) == 0)
    {
      suma += glava->cena;
    }
    glava = glava->sledeci;
  }
  return suma;
}
double prosek(KAFA *glava, char vrsta_kafe[])
{
  int brojac = broj_kafe(glava, vrsta_kafe);
  if (brojac == 0)
  {
    return 0;
  }
  else
  {
    return suma_kafa(glava, vrsta_kafe) / brojac;
  }
}
void ispis(KAFA *glava)
{
  KAFA *tekuci = glava;

  while (tekuci != NULL)
  {
    printf(
        "%6.2lf %s %s\n",
        tekuci->cena,
        tekuci->vrsta_kafe,
        tekuci->caffe);
    tekuci = tekuci->sledeci;
  }
}
void obrisi_listu(KAFA **glava)
{
  KAFA *tekuci;

  while (*glava != NULL)
  {
    tekuci = *glava;
    *glava = (*glava)->sledeci;
    tekuci->sledeci = NULL;
    free(tekuci);
  }
}
