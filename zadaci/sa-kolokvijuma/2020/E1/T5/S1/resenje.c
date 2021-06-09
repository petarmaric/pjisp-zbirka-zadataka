#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PREZIME 20+1
#define MAX_VRSTA 4+1

typedef struct potrosnjaGasa_st {
    char prezime[MAX_PREZIME];
    char vrstaStambeneJedinice[MAX_VRSTA];
    float brojPotrosenihKubika;
    float osnovnaCenaPoKubiku;
    float cenaPoKubikuPrekoGranice;
    float ukupnaCena;

    struct potrosnjaGasa_st* sledeci;
}GAS;

void inicijalizacija(GAS **glava) {
    *glava = NULL;
}

void dodajUListu(GAS **glava, GAS *novi) {
    if(*glava == NULL) {
        *glava = novi;
        return;
    }

    dodajUListu(&((*glava)->sledeci), novi);
}

GAS *kreirajNoviElement(char prezime[], char vrstaStambeneJedinice[],
                float brojPotrosenihKubika, float osnovnaCenaPoKubiku,
                float cenaPoKubikuPrekoGranice, float granica) {
    GAS *novi = (GAS *)malloc(sizeof(GAS));

    if (novi == NULL) {
        printf("\tNema dovoljno memorije!\n");
        exit(4);
    }

    strcpy(novi->prezime, prezime);
    strcpy(novi->vrstaStambeneJedinice, vrstaStambeneJedinice);
    novi->brojPotrosenihKubika = brojPotrosenihKubika;
    novi->osnovnaCenaPoKubiku = osnovnaCenaPoKubiku;
    novi->cenaPoKubikuPrekoGranice = cenaPoKubikuPrekoGranice;

    //ukupna cena
    if(novi->brojPotrosenihKubika <= granica) {
        novi->ukupnaCena = novi->brojPotrosenihKubika 
                                                * novi->osnovnaCenaPoKubiku;
    }else{
        novi->ukupnaCena = granica * novi->osnovnaCenaPoKubiku +
        (novi->brojPotrosenihKubika - granica)*novi->cenaPoKubikuPrekoGranice;
    }
    novi->sledeci = NULL;

    return novi;
}

void ucitaj(FILE *ulazna, GAS **glava, float granica) {
    char prezime[MAX_PREZIME];
    char vrstaStambeneJedinice[MAX_VRSTA];
    float brojPotrosenihKubika;
    float osnovnaCenaPoKubiku;
    float cenaPoKubikuPrekoGranice;

    while(fscanf(ulazna, "%s %s %f %f %f", prezime,
                                        vrstaStambeneJedinice,
                                        &brojPotrosenihKubika,
                                        &osnovnaCenaPoKubiku,
                                        &cenaPoKubikuPrekoGranice) != EOF) {
        GAS *novi = kreirajNoviElement(prezime, 
                                        vrstaStambeneJedinice, 
                                        brojPotrosenihKubika,
                                        osnovnaCenaPoKubiku,
                                        cenaPoKubikuPrekoGranice,
                                        granica);
        dodajUListu(glava, novi);
    }
}

void sacuvajElement(FILE *izlazna, GAS *element) {
    fprintf(izlazna, "%.1f %.2f %s %s\n", element->brojPotrosenihKubika,
                                          element->ukupnaCena,
                                          element->vrstaStambeneJedinice,
                                          element->prezime);
}

void sacuvajListu(FILE *izlazna, GAS *glava) {
    if(glava != NULL) {
        sacuvajElement(izlazna, glava);
        sacuvajListu(izlazna, glava->sledeci);
    }
}

void unistiListu(GAS **glava) {
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

void najvisaCena(FILE *izlazna, GAS *glava, 
                    char *vrstaStambeneJedinice, float granica) {
    if (glava == NULL) {
        return;
    }

    GAS *najveci = NULL;
    float prihodProsVrste = 0, prihodOstatka = 0;
    int brojac = 0;

    while(glava != NULL) {
        if(strcmp(glava->vrstaStambeneJedinice, vrstaStambeneJedinice) == 0){
            if(najveci == NULL) {
                najveci = glava;
            } else if(najveci->ukupnaCena < glava->ukupnaCena) {
                najveci = glava;
            }
            prihodProsVrste += glava->ukupnaCena;

            brojac++;
        }else
        {
            prihodOstatka += glava->ukupnaCena;
        }

        glava = glava->sledeci;
    }

    fprintf(izlazna, "\n\nPorodica %s zivi u", najveci->prezime);
    fprintf(izlazna, " stambenoj jedinici tipa %s", vrstaStambeneJedinice);
    fprintf(izlazna, " i ima najveci mesecni racun.\n");
    fprintf(izlazna, "Srbijagas na mesecnom nivou zaradice");
    fprintf(izlazna, " %.2lf din nakon sto porodice koje ne\n",prihodOstatka);
    fprintf(izlazna, "zive u %s plate svoje racune.\n",vrstaStambeneJedinice);
    fprintf(izlazna, "Prosecan iznos mesecnog racuna koji svaka porodica\n");
    fprintf(izlazna, "treba da plati iznosi %.2f din.",prihodProsVrste/brojac);

}

int main(int brArg, char **args) {

    if(brArg != 5) {
        printf("\tNiste dobro pozvali program!\n");
        exit(3);
    }

    float granica = atof(args[1]);
    char *vrstaStambeneJedinice = args[3];

    FILE *ulazna = safe_open(args[2], "r", 1);
    FILE *izlazna = safe_open(args[4], "w", 2);

    GAS *glava;

    inicijalizacija(&glava);
    ucitaj(ulazna, &glava, granica);
    sacuvajListu(izlazna, glava);
    najvisaCena(izlazna, glava, vrstaStambeneJedinice, granica);
    unistiListu(&glava);

    fclose(ulazna);
    fclose(izlazna);

    return 0;
}