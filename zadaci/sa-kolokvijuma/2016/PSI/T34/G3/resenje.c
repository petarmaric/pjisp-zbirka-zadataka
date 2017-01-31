#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_IME 20+1
#define MAX_DIJAGNOZA 20+1

struct pacijent_st {
    char ime[MAX_IME];
    char prezime[MAX_IME];
    unsigned masa;
    double visina;
};

struct analiza_st {
    char ime[MAX_IME];
    char prezime[MAX_IME];
    double bmi;
    char dijagnoza[MAX_DIJAGNOZA];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_pacijente(FILE *in, struct pacijent_st pacijenti[], int *n);
double odredi_bmi(struct pacijent_st pacijent);
void transform(struct pacijent_st pacijenti[], struct analiza_st analize[], int n);
void snimi_analize(FILE *out, struct analiza_st analize[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(1);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct pacijent_st pacijenti[MAX_NIZ];
    struct analiza_st analize[MAX_NIZ];
    int n;

    ucitaj_pacijente(in, pacijenti, &n);
    transform(pacijenti, analize, n);
    snimi_analize(out, analize, n);

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

void ucitaj_pacijente(FILE *in, struct pacijent_st pacijenti[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %s %u %lf",
         pacijenti[*n].ime,
         pacijenti[*n].prezime,
        &pacijenti[*n].masa,
        &pacijenti[*n].visina
    ) != EOF) {
        (*n)++;
    }
}

double odredi_bmi(struct pacijent_st pacijent) {
    return pacijent.masa / (pacijent.visina * pacijent.visina);
}

void transform(struct pacijent_st pacijenti[], struct analiza_st analize[], int n) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(analize[i].ime, pacijenti[i].ime);
        strcpy(analize[i].prezime, pacijenti[i].prezime);

        double bmi = odredi_bmi(pacijenti[i]);
        analize[i].bmi = bmi;
        
        if (bmi < 18.5) {
            strcpy(analize[i].dijagnoza, "Pothranjenost");
        } else if (bmi < 25.0) {
            strcpy(analize[i].dijagnoza, "Idealna tezina");
        } else if (bmi < 30.0) {
            strcpy(analize[i].dijagnoza, "Prekomerna tezina");
        } else {
            strcpy(analize[i].dijagnoza, "Gojaznost");
        }
    }
}

void snimi_analize(FILE *out, struct analiza_st analize[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%s %s %.2f %s\n",
            analize[i].ime,
            analize[i].prezime,
            analize[i].bmi,
            analize[i].dijagnoza
        );
    }
}
