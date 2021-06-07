#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 9

typedef struct racun {
    unsigned int sifra;
    char naziv[MAX_NAZIV];
    double cena;
    struct racun *sledeci;
} RACUN;

void inicijalizacija(RACUN **);
RACUN *napraviCvor(unsigned int, char *, double);
FILE *safeFopen(char *, char *, int);
void ucitajStavke(FILE *, RACUN **);
void dodajSortirano(RACUN **, RACUN *); 
void izracunajCenu(FILE *, RACUN *);
void obrisiListu(RACUN **);
void izbrisiStavku(RACUN **, unsigned int);

int main(int argc, char **argv) {
    RACUN *glava;

    if(argc != 3) {
        printf("Primer poziva: %s racun.txt"
        " zavrsniRacun.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);
    
    FILE *in = safeFopen(argv[1], "r", 1);
    ucitajStavke(in, &glava);
    fclose(in);
    
    int sifra;
    
    do {
        printf("\nUnesite sifru proizvoda: ");
        scanf("%d", &sifra);
        
        izbrisiStavku(&glava, sifra);
    } while(sifra != -1);
    
    FILE *out = safeFopen(argv[2], "w", 2);
    izracunajCenu(out, glava);
    fclose(out);
    obrisiListu(&glava);
    
    return EXIT_SUCCESS;
   
}

FILE *safeFopen(char *name, char *mode, int errorCode) {
    FILE *fp = fopen(name, mode);

    if(fp == NULL) {
        printf("Greska prilikom otvaranja fajla %s!\n", name);
        exit(errorCode);
    }

    return fp;
}

void ucitajStavke(FILE *in, RACUN **glava) {
    unsigned int sifra;
    char naziv[MAX_NAZIV];
    double cena;
    RACUN *novi;

    while(fscanf(in, "%u %s %lf",
                 &sifra, naziv, &cena)
    != EOF) {
        novi = napraviCvor(
                   sifra, naziv, cena
               );
        dodajSortirano(glava, novi);
    }
}

void izracunajCenu(FILE *out, RACUN *glava) {
    RACUN *tekuci = glava;
    double cena = 0;
    while(tekuci != NULL) {
        cena += tekuci->cena;
        fprintf(out, "%u %s %.2lf\n",
            tekuci->sifra, tekuci->naziv, tekuci->cena);
         
        tekuci = tekuci->sledeci;
    }
    
    if(cena == 0) {
        fprintf(out, "\nRacun je bez stavki!\n");
    }
    else {
         fprintf(out, "\nUkupna cena proizvoda"
         " je %.2lf din. \n", cena);
    }   
}

void inicijalizacija(RACUN **glava) {
    *glava = NULL;
}

RACUN *napraviCvor(unsigned int sifra, char *naziv, double cena) {
    RACUN *novi = (RACUN *) malloc(sizeof(RACUN));

    if(novi == NULL) {
        printf("Nije moguce zauzeti memoriju!\n");
        exit(EXIT_FAILURE);
    }
    novi->sifra = sifra;
    strcpy(novi->naziv, naziv);
    novi-> cena = cena;
    novi->sledeci = NULL;

    return novi;
}

void dodajSortirano(RACUN **glava, RACUN *novi) {
    if(*glava == NULL || (*glava)->cena < novi->cena) {
        novi->sledeci = *glava;
        *glava = novi;
    } else {
        RACUN *tekuci = *glava;
        
        while(tekuci->sledeci != NULL && tekuci->sledeci->cena > novi->cena) {
            tekuci = tekuci->sledeci;
        }

        novi->sledeci = tekuci->sledeci;
        tekuci->sledeci = novi;
    }
}

void izbrisiStavku(RACUN **glava, unsigned int sifra){
    int postoji = 0;
    
    RACUN *tekuci = *glava, *prethodni = *glava;
 
     if(sifra != -1) { 
         while(tekuci != NULL && tekuci->sifra != sifra) {
             prethodni = tekuci;
             tekuci = tekuci->sledeci;
         }
     
         if(tekuci != NULL) {
             postoji = 1;
             if(tekuci == *glava) {
                 *glava = (*glava)->sledeci;
             } else {
                 prethodni->sledeci = tekuci->sledeci;
             }

         tekuci->sledeci = NULL;
         free(tekuci);
         }
    }
    else{
      return;
    }
     
     if(postoji == 1) {
         printf("Uspesno ste uklonili stavku!\n");
     }
     else {
         printf("Stavka sa unetom sifrom ne postoji!\n");
     }
    
}
void obrisiListu(RACUN **glava) {
    RACUN *tmp;

    while(*glava != NULL) {
        tmp = *glava;
        *glava = (*glava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}
