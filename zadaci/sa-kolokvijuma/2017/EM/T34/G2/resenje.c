#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

struct prevoznik_st {
    char operater[MAX_NAZIV];
    double cena_karte;
    double max_masa_besplatnog_prtljaga;
    double cena_po_kg;
};

struct cena_st {
    double ukupna_cena;
    char operater[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_prevoznike(FILE *in, struct prevoznik_st prevoznici[], int *n);
double odredi_ukupnu_cenu(struct prevoznik_st prevoznik, double masa);
void transform(struct prevoznik_st prevoznici[], struct cena_st cene[], int n,
double masa);
void snimi_cene(FILE *out, struct cena_st cene[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s MASA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    double masa = atof(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct prevoznik_st prevoznici[MAX_NIZ];
    struct cena_st cene[MAX_NIZ];
    int n;

    ucitaj_prevoznike(in, prevoznici, &n);
    transform(prevoznici, cene, n, masa);
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

void ucitaj_prevoznike(FILE *in, struct prevoznik_st prevoznici[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %lf %lf %lf",
         prevoznici[*n].operater,
        &prevoznici[*n].cena_karte,
        &prevoznici[*n].max_masa_besplatnog_prtljaga,
        &prevoznici[*n].cena_po_kg
    ) != EOF) {
        (*n)++;
    }
}

double odredi_ukupnu_cenu(struct prevoznik_st prevoznik, double masa) {
    double base = prevoznik.cena_karte;

    double extra_masa = masa - prevoznik.max_masa_besplatnog_prtljaga;
    if (extra_masa > 0) {
        base += extra_masa * prevoznik.cena_po_kg;
    }

    return base;
}

void transform(struct prevoznik_st prevoznici[], struct cena_st cene[], int n,
double masa) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(cene[i].operater, prevoznici[i].operater);

        cene[i].ukupna_cena = odredi_ukupnu_cenu(prevoznici[i], masa);
    }
}

void snimi_cene(FILE *out, struct cena_st cene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%7.2f %s\n",
            cene[i].ukupna_cena,
            cene[i].operater
        );
    }
}
