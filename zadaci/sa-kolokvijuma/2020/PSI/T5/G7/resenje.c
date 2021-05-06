#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SADRZAJ 31
#define MAX_LOMLJIVO 3

typedef struct paket_st {
  char sadrzaj[MAX_SADRZAJ];
  double masa;
  char lomljivo[MAX_LOMLJIVO];
  struct paket_st *sledeci;
} PAKET;

FILE *safe_fopen(char *filename, char *mode);
void ucitaj(FILE *ulazna, PAKET **pglava);
void ispisi_cene_dostave(PAKET *glava, double dodatno_po_kg);

void inicijalizacija(PAKET **pglava);
PAKET *napravi_cvor(char *sadrzaj, double masa, char *lomljivo);
void dodaj_cvor(PAKET **pglava, PAKET *novi);
void obrisi_listu(PAKET **pglava);

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("Primer poziva: %s paketi.txt 5.5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *ulazna = safe_fopen(argv[1], "r");
    PAKET *glava;
    double dodatno_po_kg = atof(argv[2]);

    inicijalizacija(&glava);

    ucitaj(ulazna, &glava);
    ispisi_cene_dostave(glava, dodatno_po_kg);

    obrisi_listu(&glava);

    fclose(ulazna);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        printf("Nije moguce otvoriti datoteku %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    return fp;
}

void ucitaj(FILE *ulazna, PAKET **pglava) {
    char sadrzaj[MAX_SADRZAJ];
    double masa;
    char lomljivo[MAX_LOMLJIVO];

    while(fscanf(ulazna, "%s %lf %s", sadrzaj, &masa, lomljivo) != EOF) {
        dodaj_cvor(pglava, napravi_cvor(sadrzaj, masa, lomljivo));
    }
}

void ispisi_cene_dostave(PAKET *glava, double dodatno_po_kg) {
    PAKET *tekuci = glava;

    while(tekuci != NULL) {
        double cena;

        if(tekuci->masa > 0 && tekuci->masa <= 5) {
            cena = 200;
        } else if(tekuci->masa > 5 && tekuci->masa <= 10) {
            cena = 400;
        } else if(tekuci->masa > 10) {
            cena = 400 + (tekuci->masa - 10) * dodatno_po_kg;
        }

        printf("%-10s %2s %5.2lf\n", tekuci->sadrzaj, tekuci->lomljivo, cena);
        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(PAKET **pglava) {
    *pglava = NULL;
}

PAKET *napravi_cvor(char *sadrzaj, double masa, char *lomljivo) {
    PAKET *novi = (PAKET *)malloc(sizeof(PAKET));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novi->sadrzaj, sadrzaj);
    novi->masa = masa;
    strcpy(novi->lomljivo, lomljivo);
    novi->sledeci = NULL;

    return novi;
}

void dodaj_cvor(PAKET **pglava, PAKET *novi) {
    if(*pglava == NULL) {
        *pglava = novi;
    } else {
        PAKET *tekuci = *pglava;

        while(tekuci->sledeci != NULL) {
            tekuci = tekuci->sledeci;
        }

        tekuci->sledeci = novi;
    }
}

void obrisi_listu(PAKET **pglava) {
    PAKET *tmp; 

    while(*pglava != NULL) {
       tmp = *pglava;
       *pglava = (*pglava)->sledeci; 
       tmp->sledeci = NULL;
       free(tmp);
    }
}

