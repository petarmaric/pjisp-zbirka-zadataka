#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 21
#define MAX_VRSTA 16

typedef struct proizvod_st {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    double cena;
    struct proizvod_st *sledeci;
} PROIZVOD;

FILE *safe_fopen(char *filename, char *mode);
void ucitaj(FILE *ulazna, PROIZVOD **pglava);
void ispisi_vrstu(PROIZVOD *glava, char *vrsta);

void inicijalizacija(PROIZVOD **pglava);
PROIZVOD *napravi_cvor(char *naziv, char *vrsta, double cena);
void dodaj_po_ceni(PROIZVOD **pglava, PROIZVOD *novi);
void obrisi_listu(PROIZVOD **pglava);

int main(int argc, char *argv[]) {
    PROIZVOD *glava;

    if(argc != 3) {
        printf("Primer poziva: %s proizvodi.txt hemija\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r");

    ucitaj(ulazna, &glava);
    ispisi_vrstu(glava, argv[2]);
    obrisi_listu(&glava);

    fclose(ulazna);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        printf("Greska prilikom otvaranja datoteke %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    return fp;
}

void ucitaj(FILE *ulazna, PROIZVOD **pglava) {
    char tmp_naziv[MAX_NAZIV];
    char tmp_vrsta[MAX_VRSTA];
    double tmp_cena;

    while(fscanf(ulazna, "%s %lf %s", tmp_naziv, &tmp_cena, tmp_vrsta) != EOF) {
        dodaj_po_ceni(pglava, napravi_cvor(tmp_naziv, tmp_vrsta, tmp_cena));
    }
}

void ispisi_vrstu(PROIZVOD *glava, char *vrsta) {
    PROIZVOD *tekuci = glava;
    int postoji_proizvod = 0;

    while(tekuci != NULL) {
        if(strcmp(tekuci->vrsta, vrsta) == 0) {
            printf("%6.2lf %-12s %s\n",
                tekuci->cena, tekuci->naziv, tekuci->vrsta);
            postoji_proizvod = 1;
        }
        tekuci = tekuci->sledeci;
    }

    if(!postoji_proizvod) {
        printf("Ne postoji nijedan proizvod vrste %s!\n", vrsta);
    }
}

void inicijalizacija(PROIZVOD **pglava) {
    *pglava = NULL;
}

PROIZVOD *napravi_cvor(char *naziv, char *vrsta, double cena) {
    PROIZVOD *novi = (PROIZVOD *)malloc(sizeof(PROIZVOD));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novi->naziv, naziv);
    strcpy(novi->vrsta, vrsta);
    novi->cena = cena;
    novi->sledeci = NULL;

    return novi;
}

void dodaj_po_ceni(PROIZVOD **pglava, PROIZVOD *novi) {
    if(*pglava == NULL) {
        *pglava = novi;
    } else {
        if((*pglava)->cena > novi->cena) {
            novi->sledeci = *pglava;
            *pglava = novi;
        } else {
            PROIZVOD *tekuci = *pglava;

            while(tekuci->sledeci != NULL && 
                  tekuci->sledeci->cena < novi->cena) {
                tekuci = tekuci->sledeci;
            }

            novi->sledeci = tekuci->sledeci;
            tekuci->sledeci = novi;
        }
    }
}

void obrisi_listu(PROIZVOD **pglava) {
    PROIZVOD *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}
