#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_IME 16+1

struct takmicar_st {
    char ime[MAX_IME];
    char prezime[MAX_IME];
    unsigned ocena_1;
    unsigned ocena_2;
    unsigned ocena_3;
};

struct ocena_st {
    double prosecna_ocena;
    char ime[MAX_IME];
    char prezime[MAX_IME];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_takmicare(FILE *in, struct takmicar_st takmicari[], int *n);
void transform(struct takmicar_st takmicari[], struct ocena_st ocene[], int n);
void snimi_ocene(FILE *out, struct ocena_st ocene[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct takmicar_st takmicari[MAX_NIZ];
    struct ocena_st ocene[MAX_NIZ];
    int n;

    ucitaj_takmicare(in, takmicari, &n);
    transform(takmicari, ocene, n);
    snimi_ocene(out, ocene, n);

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

void ucitaj_takmicare(FILE *in, struct takmicar_st takmicari[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %s %u %u %u",
         takmicari[*n].ime,
         takmicari[*n].prezime,
        &takmicari[*n].ocena_1,
        &takmicari[*n].ocena_2,
        &takmicari[*n].ocena_3
    ) != EOF) {
        (*n)++;
    }
}

double odredi_prosecnu_ocenu(struct takmicar_st takmicar) {
    return (takmicar.ocena_1 + takmicar.ocena_2 + takmicar.ocena_3) / 3.;
}

void transform(struct takmicar_st takmicari[], struct ocena_st ocene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(ocene[i].ime, takmicari[i].ime);
        strcpy(ocene[i].prezime, takmicari[i].prezime);

        ocene[i].prosecna_ocena = odredi_prosecnu_ocenu(takmicari[i]);
    }
}

void snimi_ocene(FILE *out, struct ocena_st ocene[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%4.2lf %s %s\n",
            ocene[i].prosecna_ocena,
            ocene[i].ime,
            ocene[i].prezime
        );
    }
}
