#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30
#define MAX_NAME 11
#define MAX_FLIGHT 4
#define OUT_NAME_MAX 51

typedef struct let_st {
    char ID[MAX_NAME];
    char aerodrom_polazak[MAX_FLIGHT];
    char aerodrom_dolazak[MAX_FLIGHT];
    int duzina;
    int broj_presedanja;
} LET;

FILE *safe_fopen(char *, char *);
void ucitaj_letove(FILE *, LET[], int *);
void ispisi_letove(FILE *, LET [], char *, int);
float izracunaj_cenu(LET);

int main(int argc, char **args) {
    LET letovi[MAX_SIZE];
    int n;
    char out_name[OUT_NAME_MAX];

    if(argc != 3) {
        printf("Primer poziva programa: ./let letovi.txt VIE\n");
        exit(EXIT_FAILURE);
    }

    FILE *in = safe_fopen(args[1], "r");

    strcpy(out_name, "letovi_ka_");
    strcat(out_name, args[2]);
    strcat(out_name, ".txt");
    FILE *out = safe_fopen(out_name, "w");

    ucitaj_letove(in, letovi, &n);
    fclose(in);

    ispisi_letove(out, letovi, args[2], n);
    fclose(out);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *filename, char *mode) {
    FILE *f = fopen(filename, mode);

    if(f == NULL) {
        printf("Greska prilikom otvaranja datoteke %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    return f;
}

void ucitaj_letove(FILE *in, LET letovi[], int *pn) {
    int i = 0;

    while(fscanf(in, "%s %s %s %d %d",
                 letovi[i].ID,
                 letovi[i].aerodrom_polazak,
                 letovi[i].aerodrom_dolazak,
                 &letovi[i].duzina,
                 &letovi[i].broj_presedanja
    ) != EOF) {
        i++;
    }

    *pn = i;
}


void ispisi_letove(FILE *out, LET letovi[], char *x, int n) {
    int i;
    int br = 0;

    for(i = 0;i < n;i++) {
        if(strcmp(letovi[i].aerodrom_dolazak, x) == 0) {
            fprintf(out, "%s %s %0.2f\n",
                letovi[i].ID,
                letovi[i].aerodrom_polazak,
                izracunaj_cenu(letovi[i])
            );
            br++;
        }
    }

    if(br == 0) {
        fprintf(out, "Nema letova ka zadatom aerodromu!\n");
    }
}

float izracunaj_cenu(LET let) {
    float cena = 0;

    if(let.duzina < 5000) {
        cena += let.duzina * 0.5;
    } else if(let.duzina >= 5000 && let.duzina < 10000) {
        cena += let.duzina * 0.75;
    } else if(let.duzina > 10000){
        cena += let.duzina;
    }

    cena += -5 * let.broj_presedanja;
    return cena;
}
