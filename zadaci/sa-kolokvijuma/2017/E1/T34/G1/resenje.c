#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

struct artikal_st {
    double cena;
    unsigned broj_prodatih;
    double trgovacka_marza;
    char naziv[MAX_NAZIV];
};

struct zarada_st {
    double zarada;
    char naziv[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_artikle(FILE *in, struct artikal_st artikli[], int *n);
double odredi_zaradu(struct artikal_st artikal);
void transform(struct artikal_st artikli[], struct zarada_st zarade[], int n);
void snimi_zarade(FILE *out, struct zarada_st zarade[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct artikal_st artikli[MAX_NIZ];
    struct zarada_st zarade[MAX_NIZ];
    int n;

    ucitaj_artikle(in, artikli, &n);
    transform(artikli, zarade, n);
    snimi_zarade(out, zarade, n);

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

void ucitaj_artikle(FILE *in, struct artikal_st artikli[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%lf %u %lf %s",
        &artikli[*n].cena,
        &artikli[*n].broj_prodatih,
        &artikli[*n].trgovacka_marza,
         artikli[*n].naziv
    ) != EOF) {
        (*n)++;
    }
}

double odredi_zaradu(struct artikal_st artikal) {
    return artikal.cena * artikal.broj_prodatih * artikal.trgovacka_marza / 100;
}

void transform(struct artikal_st artikli[], struct zarada_st zarade[], int n) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(zarade[i].naziv, artikli[i].naziv);

        zarade[i].zarada = odredi_zaradu(artikli[i]);
    }
}

void snimi_zarade(FILE *out, struct zarada_st zarade[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%7.2f %s\n",
            zarade[i].zarada,
            zarade[i].naziv
        );
    }
}
