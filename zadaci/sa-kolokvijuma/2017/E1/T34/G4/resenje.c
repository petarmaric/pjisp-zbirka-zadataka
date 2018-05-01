#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BROJ_PARCADI_PO_PIZZI 8
#define MAX_NAZIV 20+1
#define MAX_NIZ 30

struct zelja_st {
    unsigned broj_gostiju;
    char pizza[MAX_NAZIV];
};

struct porudzbina_st {
    double broj_parcadi;
    unsigned broj_celih_pizza;
    char pizza[MAX_NAZIV];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_zelje(FILE *in, struct zelja_st zelje[], int *n);
double odredi_broj_parcadi(struct zelja_st zelja, double apetit);
unsigned odredi_broj_celih_pizza(double broj_parcadi);
void transform(struct zelja_st zelje[], struct porudzbina_st porudzbine[],
int n, double apetit);
void snimi_porudzbine(FILE *out, struct porudzbina_st porudzbine[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s APETIT IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    double apetit = atof(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct zelja_st zelje[MAX_NIZ];
    struct porudzbina_st porudzbine[MAX_NIZ];
    int n;

    ucitaj_zelje(in, zelje, &n);
    transform(zelje, porudzbine, n, apetit);
    snimi_porudzbine(out, porudzbine, n);

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

void ucitaj_zelje(FILE *in, struct zelja_st zelje[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%u %s",
        &zelje[*n].broj_gostiju,
         zelje[*n].pizza
    ) != EOF) {
        (*n)++;
    }
}

double odredi_broj_parcadi(struct zelja_st zelja, double apetit) {
    return zelja.broj_gostiju * apetit;
}

unsigned odredi_broj_celih_pizza(double broj_parcadi) {
    return (unsigned) ceil(broj_parcadi / BROJ_PARCADI_PO_PIZZI);
}

void transform(struct zelja_st zelje[], struct porudzbina_st porudzbine[],
int n, double apetit) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(porudzbine[i].pizza, zelje[i].pizza);

        porudzbine[i].broj_parcadi = odredi_broj_parcadi(zelje[i], apetit);
        porudzbine[i].broj_celih_pizza = odredi_broj_celih_pizza(
            porudzbine[i].broj_parcadi
        );
    }
}

void snimi_porudzbine(FILE *out, struct porudzbina_st porudzbine[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%5.1f %2u %s\n",
            porudzbine[i].broj_parcadi,
            porudzbine[i].broj_celih_pizza,
            porudzbine[i].pizza
        );
    }
}
