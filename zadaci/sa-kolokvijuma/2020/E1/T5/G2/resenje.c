#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAZIV 20+1
#define MAX_VRSTA 8+1
#define MAX_ZAUZETOST 8+1

typedef struct taxi_st {
    char naziv[MAX_NAZIV];
    char vrstaVozila[MAX_VRSTA];
    float cena_po_km;
    char zauzetost[MAX_ZAUZETOST];

    struct taxi_st* sledeci;
}TAXI;

void inicijalizacija(TAXI **glava) {
    *glava = NULL;
}

void dodajUListu(TAXI **glava, TAXI *novi) {
    if(*glava == NULL) {
        *glava = novi;
        return;
    }

    dodajUListu(&((*glava)->sledeci), novi);
}

TAXI *kreirajNoviElement(char naziv[], char vrsta[],
                        float cena_po_km, char zauzetost[]) {
    TAXI *novi = (TAXI *)malloc(sizeof(TAXI));
    if (novi == NULL) {
        printf("\tNema dovoljno memorije!\n");
        exit(4);
    }

    strcpy(novi->naziv, naziv);
    strcpy(novi->vrstaVozila, vrsta);
    novi->cena_po_km = cena_po_km;

    if(strcmp(zauzetost,"+") == 0) {
        strcpy(novi->zauzetost,"slobodan");
    } else {
        strcpy(novi->zauzetost,"zauzet");
    }

    novi->sledeci = NULL;

    return novi;
}

void ucitaj(FILE *in, TAXI **glava) {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    float cena_po_km;
    char zauzetost[MAX_ZAUZETOST];

    while(fscanf(in, "%s %s %f %s",naziv,vrsta,&cena_po_km,zauzetost) != EOF) {
        TAXI *novi = kreirajNoviElement(naziv, vrsta, cena_po_km, zauzetost);
        dodajUListu(glava, novi);
    }
}

void sacuvajElement(FILE *izlazna, TAXI *element) {
    fprintf(izlazna, "%s %s %.1f %s\n",
                element->vrstaVozila,
                element->naziv,
                element->cena_po_km,
                element->zauzetost);
}

void sacuvajListu(FILE *izlazna, TAXI *glava) {
    if(glava != NULL) {
        sacuvajElement(izlazna, glava);
        sacuvajListu(izlazna, glava->sledeci);
    }
}

void unistiListu(TAXI **glava) {
    if(*glava != NULL) {
        unistiListu(&((*glava)->sledeci));
        free(*glava);
        *glava = NULL;
    }
}

FILE *safe_open(char *imeDatoteke, char *rezim, int kodGreske) {
    FILE *fp = fopen(imeDatoteke, rezim);

    if (fp == NULL) {
        printf("\tNije moguce otvoriti datoteku %s!\n", imeDatoteke);
        exit(kodGreske);
    }

    return fp;
}

void algoritam(FILE *izlazna, TAXI *glava, char *vrstaVozila, float novac) {
    if (glava == NULL) {
        return;
    }

    TAXI *najduzi_taxi = NULL;
    float predjena_km = 0;
    int brojac = 0;
    float zaradaKompanije = 0;

    while(glava != NULL) {
        predjena_km = novac/glava->cena_po_km;
        if(najduzi_taxi == NULL) {
                najduzi_taxi = glava;
        } else if(novac/najduzi_taxi->cena_po_km < predjena_km) {
                najduzi_taxi = glava;
        }

        if(strcmp(glava->zauzetost,"zauzet") == 0) {
            zaradaKompanije += predjena_km*0.1*glava->cena_po_km;
        }

        if(strcmp(glava->zauzetost,"slobodan") == 0
                            && strcmp(glava->vrstaVozila, vrstaVozila) == 0) {
            brojac++;
        }

        glava = glava->sledeci;
    }

    fprintf(izlazna,"\nZa %.1f din mozemo se najduze voziti",novac);
    fprintf(izlazna," %.1f km",novac/najduzi_taxi->cena_po_km);
    fprintf(izlazna," %s taksijem.", najduzi_taxi->naziv);

    fprintf(izlazna,"\nKompanija ce ukupno ostvariti profit");
    fprintf(izlazna," od %.1f dinara.",zaradaKompanije);

    fprintf(izlazna,"\nBroj taksija koji su slobodni i tip vozila je");
    fprintf(izlazna," %s: %d.",vrstaVozila, brojac);
}

int main(int brArg, char **args) {
    if(brArg != 5) {
        printf("\tNiste dobro pozvali program!\n");
        exit(3);
    }

    float novac = atof(args[2]);
    char *vrstaVozila = args[3];

    FILE *ulazna = safe_open(args[1], "r", 1);
    FILE *izlazna = safe_open(args[4], "w", 2);

    TAXI *glava;

    inicijalizacija(&glava);
    ucitaj(ulazna, &glava);
    sacuvajListu(izlazna, glava);
    algoritam(izlazna,glava,vrstaVozila,novac);
    unistiListu(&glava);

    fclose(ulazna);
    fclose(izlazna);

    return 0;
}