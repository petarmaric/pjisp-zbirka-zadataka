#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1
#define MAX_NIZ 30

struct kafa_st {
    char naziv_kafe[MAX_NAZIV];
    double cena_kafe;
    int kolicina_kofeina;
};

struct kafa_pred_ispit_st {
    char naziv_kafe[MAX_NAZIV];
    int broj_kafa;
    double cena;
    int kolicina_kofeina;
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj(FILE *in, struct kafa_st kafe[], int *n);
double prosek(struct kafa_st kafe[], int n);
void transform(struct kafa_st kafe[], struct kafa_pred_ispit_st kafe_pred_ispit[], int n, double kolicina_kofeina);
void snimi(FILE *out, struct kafa_st kafe[], struct kafa_pred_ispit_st kafe_pred_ispit[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME KOLICINA_KOFEINA\n", args[0]);
        exit(3);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];
    int kolicina_kofeina = atoi(args[3]);

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct kafa_st kafe[MAX_NIZ];
    struct kafa_pred_ispit_st kafe_pred_ispit[MAX_NIZ];
    int n;

    ucitaj(in, kafe, &n);
    transform(kafe, kafe_pred_ispit, n, kolicina_kofeina);
    snimi(out, kafe, kafe_pred_ispit, n);

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

void ucitaj(FILE *in, struct kafa_st kafe[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %lf %d",
         kafe[*n].naziv_kafe,
        &kafe[*n].cena_kafe,
        &kafe[*n].kolicina_kofeina
    ) != EOF) {
        (*n)++;
    }
}

double prosek(struct kafa_st kafe[], int n){
    int i;
    double prosek;
    for(i=0; i<n; i++) {
        prosek += kafe[i].kolicina_kofeina;
    }
    return prosek / n;
}

void transform(struct kafa_st kafe[], struct kafa_pred_ispit_st kafe_pred_ispit[], int n, double kolicina_kofeina) {
    int i, broj_kafa;
    for(i=0; i<n; i++) {
        strcpy(kafe_pred_ispit[i].naziv_kafe, kafe[i].naziv_kafe);

        broj_kafa = kolicina_kofeina / kafe[i].kolicina_kofeina;
        kafe_pred_ispit[i].broj_kafa = broj_kafa;
        kafe_pred_ispit[i].cena = broj_kafa * kafe[i].cena_kafe;
        kafe_pred_ispit[i].kolicina_kofeina = broj_kafa * kafe[i].kolicina_kofeina;
    }
}

void snimi(FILE *out, struct kafa_st kafe[], struct kafa_pred_ispit_st kafe_pred_ispit[], int n) {
    int i;
    double p = prosek(kafe, n);
    for(i=0; i<n; i++) {
        fprintf(
            out, "%s %d %.2lf %d",
            kafe_pred_ispit[i].naziv_kafe,
            kafe_pred_ispit[i].broj_kafa,
            kafe_pred_ispit[i].cena,
            kafe_pred_ispit[i].kolicina_kofeina
        );
        if(kafe[i].kolicina_kofeina > p){
            fprintf(out, " UPOZORENJE, jaka kafa");
        }
        fprintf(out, "\n");
    }
}
