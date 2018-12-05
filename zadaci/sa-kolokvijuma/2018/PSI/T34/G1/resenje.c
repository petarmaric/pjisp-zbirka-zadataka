#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_NAZIV 30+1

struct serija_st {
    char naziv[MAX_NAZIV];
    double imdb_ocena;
    double max_gledanost;
    unsigned max_vreme_izmedju_sezona;
};

struct hype_st {
    double hype_faktor;
    char naziv[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_serije(FILE *in, struct serija_st serije[], int *n);
void transform(struct serija_st serije[], struct hype_st hypetrain[], int n);
void snimi_hypetrain(FILE *out, struct hype_st hypetrain[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct serija_st serije[MAX_NIZ];
    struct hype_st hypetrain[MAX_NIZ];
    int n;

    ucitaj_serije(in, serije, &n);
    transform(serije, hypetrain, n);
    snimi_hypetrain(out, hypetrain, n);

    fclose(in);
    fclose(out);

    return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code) {
    FILE *fp = fopen(filename, mode);
    if(fp == NULL) {
        printf("Can't open '%s'!", filename);
        exit(error_code);
    }
    return fp;
}

void ucitaj_serije(FILE *in, struct serija_st serije[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %lf %lf %u",
         serije[*n].naziv,
        &serije[*n].imdb_ocena,
        &serije[*n].max_gledanost,
        &serije[*n].max_vreme_izmedju_sezona
    ) != EOF) {
        (*n)++;
    }
}

double feel_the_hype(struct serija_st s) {
    return s.imdb_ocena * s.max_vreme_izmedju_sezona / s.max_gledanost;
}

void transform(struct serija_st serije[], struct hype_st hypetrain[], int n) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(hypetrain[i].naziv, serije[i].naziv);

        hypetrain[i].hype_faktor = feel_the_hype(serije[i]);
    }
}

void snimi_hypetrain(FILE *out, struct hype_st hypetrain[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%6.2lf %s\n",
            hypetrain[i].hype_faktor,
            hypetrain[i].naziv
        );
    }
}
