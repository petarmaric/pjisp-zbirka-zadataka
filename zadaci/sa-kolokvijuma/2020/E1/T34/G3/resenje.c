#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OBJEKAT 30

#define MAX_ULICA 21
#define MAX_TIP_OBJEKTA 11
#define MAX_PRIJAVLJEN_KVAR 3

#define MIN_KVAROVA 2

typedef struct objekat_st {
    char ulica[MAX_ULICA];
    unsigned broj;
    unsigned broj_domacinstava;
    char tip_objekta[MAX_TIP_OBJEKTA];
    char prijavljen_kvar[MAX_PRIJAVLJEN_KVAR];
} OBJEKAT;

FILE *safe_fopen(char *, char *, int);
void ucitaj(FILE *, OBJEKAT *, int *);
int prijavljen_kvar(OBJEKAT);
void ispisi_bez_struje(FILE *, OBJEKAT *, int);
unsigned domacinstva_bez_struje(OBJEKAT *, int);
int kvar_trafo_stanice(OBJEKAT *, int, int);

int main(int argc, char **argv) {
    OBJEKAT objekti[MAX_OBJEKAT];    
    int n;

    if(argc != 4) {
        printf("Primer poziva: %s 5 trafo_stanica.txt bez_energije.txt\n",
            argv[0]);
        exit(EXIT_FAILURE);
    }

    int limit_prijavljenih_kvarova = atoi(argv[1]);

    if(limit_prijavljenih_kvarova < MIN_KVAROVA) {
        printf("Minimalni broj kvarova mora biti %d!\n", MIN_KVAROVA);
        exit(2);
    }

    FILE *pin = safe_fopen(argv[2], "r", 3);
    ucitaj(pin, objekti, &n);
    fclose(pin);

    FILE *pout = safe_fopen(argv[3], "w", 4);
    ispisi_bez_struje(pout, objekti, n);
    fprintf(pout, "\nBroj domacinstava bez struje: %u\n",
        domacinstva_bez_struje(objekti, n));
    if(kvar_trafo_stanice(objekti, n, limit_prijavljenih_kvarova)) {
        fprintf(pout, "\nMoguc kvar trafo stanice!\n");
    }
    fclose(pout);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *name, char *mode, int error_code) {
    FILE *fp = fopen(name, mode);

    if(fp == NULL) {
        printf("Nije moguce otvoriti datoteku %s!\n", name);
        exit(error_code);
    }

    return fp;
}

void ucitaj(FILE *pin, OBJEKAT *objekti, int *pn) {
    int i;

    while(fscanf(pin, "%s %u %u %s %s",
                 objekti[i].ulica,
                 &objekti[i].broj,
                 &objekti[i].broj_domacinstava,
                 objekti[i].tip_objekta,
                 objekti[i].prijavljen_kvar
          ) != EOF) {
        i++;
    }

    *pn = i;
}

int prijavljen_kvar(OBJEKAT objekat) {
    return strcmp(objekat.prijavljen_kvar, "DA") == 0;
}

void ispisi_bez_struje(FILE *pout, OBJEKAT *objekti, int n) {
    int i;

    for(i = 0;i < n;i++) {
        if(prijavljen_kvar(objekti[i])) {
            fprintf(pout, "%s %2u %s\n",
                objekti[i].ulica, objekti[i].broj, objekti[i].tip_objekta);
        }
    }
}

unsigned domacinstva_bez_struje(OBJEKAT *objekti, int n) {
    int i;
    unsigned ukupno_domacinstava = 0;

    for(i = 0;i < n;i++) {
        if(prijavljen_kvar(objekti[i])) {
            ukupno_domacinstava += objekti[i].broj_domacinstava;
        }
    }

    return ukupno_domacinstava;
}

int kvar_trafo_stanice(
    OBJEKAT *objekti,
    int n,
    int limit_prijavljenih_kvarova
) {
    int i, objekti_bez_struje = 0;

    for(i = 0;i < n;i++) {
        if(prijavljen_kvar(objekti[i])) {
            objekti_bez_struje++;
        }
    }

    return objekti_bez_struje >= limit_prijavljenih_kvarova;
}
