#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

typedef struct knjiga_st {
    char naziv[MAX_NAZIV];
    char izdavac[MAX_NAZIV];
    unsigned br_str;
}KNJIGA;

typedef struct duzina_citanja_st {
    double br_dana;
    char naziv[MAX_NAZIV];
}CITANJE;


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj(FILE *in, KNJIGA knjige[], int *n);
void transform(KNJIGA knjige[], CITANJE duzine_citanja[], int n,
double br_strana);
void snimi(FILE *out, CITANJE duzine_citanja[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s BR_STR IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    double br_strana = atof(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    KNJIGA knjige[MAX_NIZ];
    CITANJE duzine_citanja[MAX_NIZ];
    int n;

    ucitaj(in, knjige, &n);
    transform(knjige, duzine_citanja, n, br_strana);
    snimi(out, duzine_citanja, n);

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

void ucitaj(FILE *in, KNJIGA knjige[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %s %u",
        knjige[*n].naziv,
        knjige[*n].izdavac,
        &knjige[*n].br_str
    ) != EOF) {
        (*n)++;
    }
}

void transform(KNJIGA knjige[], CITANJE duzine_citanja[], int n,
double br_strana) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(duzine_citanja[i].naziv, knjige[i].naziv);

        duzine_citanja[i].br_dana = knjige[i].br_str / br_strana / 24;
    }
}

void snimi(FILE *out, CITANJE duzine_citanja[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%.2f %s\n",
            duzine_citanja[i].br_dana,
            duzine_citanja[i].naziv
        );
    }
}
