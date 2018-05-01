#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

struct paket_st {
    char zemlja[MAX_NAZIV];
    char operater[MAX_NAZIV];
    unsigned mesecna_pretplata;
    unsigned broj_besplatnih_kwh;
    double cena_po_kwh;
};

struct cena_st {
    double ukupna_cena;
    char zemlja[MAX_NAZIV];
    char operater[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_pakete(FILE *in, struct paket_st paketi[], int *n);
double odredi_ukupnu_cenu(struct paket_st paket, int potroseno_kwh);
void transform(struct paket_st paketi[], struct cena_st cene[], int n,
int potroseno_kwh);
void snimi_cene(FILE *out, struct cena_st cene[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s POTROSENO_KWH IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    int potroseno_kwh = atoi(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct paket_st paketi[MAX_NIZ];
    struct cena_st cene[MAX_NIZ];
    int n;

    ucitaj_pakete(in, paketi, &n);
    transform(paketi, cene, n, potroseno_kwh);
    snimi_cene(out, cene, n);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code) {
    FILE *fp = fopen(filename, mode);
    if(fp == NULL) {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

void ucitaj_pakete(FILE *in, struct paket_st paketi[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %s %u %u %lf",
         paketi[*n].zemlja,
         paketi[*n].operater,
        &paketi[*n].mesecna_pretplata,
        &paketi[*n].broj_besplatnih_kwh,
        &paketi[*n].cena_po_kwh
    ) != EOF) {
        (*n)++;
    }
}

double odredi_ukupnu_cenu(struct paket_st paket, int potroseno_kwh) {
    double base = paket.mesecna_pretplata;

    int extra_kwh = potroseno_kwh - paket.broj_besplatnih_kwh;
    if (extra_kwh > 0) {
        base += extra_kwh * paket.cena_po_kwh;
    }

    return base;
}

void transform(struct paket_st paketi[], struct cena_st cene[], int n,
int potroseno_kwh) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(cene[i].zemlja, paketi[i].zemlja);
        strcpy(cene[i].operater, paketi[i].operater);

        cene[i].ukupna_cena = odredi_ukupnu_cenu(paketi[i], potroseno_kwh);
    }
}

void snimi_cene(FILE *out, struct cena_st cene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%7.2f %s %s\n",
            cene[i].ukupna_cena,
            cene[i].zemlja,
            cene[i].operater
        );
    }
}
