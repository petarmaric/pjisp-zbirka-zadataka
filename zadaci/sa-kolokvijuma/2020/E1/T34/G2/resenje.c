#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

typedef struct suplement_st {
    char naziv[MAX_NAZIV];
    unsigned br_kapsula;
    unsigned br_po_danu;
    double cena;
}SUPLEMENT;

typedef struct cena_st {
    double cena;
    char naziv[MAX_NAZIV];
}CENA;


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj(FILE *in, SUPLEMENT suplementi[], int *n);
void transform(SUPLEMENT suplementi[], CENA cene[], int n);
void snimi(FILE *out, CENA cene[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("USAGE: IN_FILENAME OUT_FILENAME\n");
        exit(42);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    SUPLEMENT suplementi[MAX_NIZ];
    CENA cene[MAX_NIZ];
    int n;

    ucitaj(in, suplementi, &n);
    transform(suplementi, cene, n);
    snimi(out, cene, n);

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

void ucitaj(FILE *in, SUPLEMENT suplementi[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %u %u %lf",
        suplementi[*n].naziv,
        &suplementi[*n].br_kapsula,
        &suplementi[*n].br_po_danu,
        &suplementi[*n].cena
    ) != EOF) {
        (*n)++;
    }
}

void transform(SUPLEMENT suplementi[], CENA cene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(cene[i].naziv, suplementi[i].naziv);
        double br_dana = 1.0 * suplementi[i].br_kapsula
          / suplementi[i].br_po_danu;
        cene[i].cena = suplementi[i].cena / br_dana;
    }
}

void snimi(FILE *out, CENA cene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%.2f %s\n",
            cene[i].cena,
            cene[i].naziv
        );
    }
}
