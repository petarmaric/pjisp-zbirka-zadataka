#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NIZ 30
#define MAX_IME 20+1

struct pacijent_st {
    char ime[MAX_IME];
    char prezime[MAX_IME];
    double holesterol;
    unsigned pritisak;
    double secer;
};

struct analiza_st {
    char upozorenje;
    char ime[MAX_IME];
    char prezime[MAX_IME];
};

typedef enum {HOLESTEROL, PRITISAK, SECER} TIP_ANALIZE;


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_pacijente(FILE *in, struct pacijent_st pacijenti[], int *n);
int analiza_ok(struct pacijent_st pacijent, TIP_ANALIZE tip_analize);
void transform(struct pacijent_st pacijenti[], struct analiza_st analize[],
int n, TIP_ANALIZE tip_analize);
void snimi_analize(FILE *out, struct analiza_st analize[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s TIP_ANALIZE IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(1);
    }

    char *tip_analize_str = args[1];
    char *in_filename = args[2];
    char *out_filename = args[3];

    TIP_ANALIZE tip_analize;
    if(strcmp(tip_analize_str, "holesterol") == 0) {
        tip_analize = HOLESTEROL;
    } else if (strcmp(tip_analize_str, "pritisak") == 0) {
        tip_analize = PRITISAK;
    } else if (strcmp(tip_analize_str, "secer") == 0) {
        tip_analize = SECER;
    } else {
        printf("Nepoznat tip analize '%s'!", tip_analize_str);
        exit(42);
    }

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct pacijent_st pacijenti[MAX_NIZ];
    struct analiza_st analize[MAX_NIZ];
    int n;

    ucitaj_pacijente(in, pacijenti, &n);
    transform(pacijenti, analize, n, tip_analize);
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
        in, "%s %s %lf %u %lf",
         pacijenti[*n].ime,
         pacijenti[*n].prezime,
        &pacijenti[*n].holesterol,
        &pacijenti[*n].pritisak,
        &pacijenti[*n].secer
    ) != EOF) {
        (*n)++;
    }
}

int analiza_ok(struct pacijent_st p, TIP_ANALIZE tip_analize) {
    switch (tip_analize) {
        case HOLESTEROL: return p.holesterol < 5.2;
        case PRITISAK:   return (p.pritisak >= 90) && (p.pritisak < 120);
        case SECER:      return (p.secer >= 3.9) && (p.secer < 5.6);
    }
}

void transform(struct pacijent_st pacijenti[], struct analiza_st analize[],
int n, TIP_ANALIZE tip_analize) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(analize[i].ime, pacijenti[i].ime);
        strcpy(analize[i].prezime, pacijenti[i].prezime);

        analize[i].upozorenje = analiza_ok(pacijenti[i], tip_analize) ? '-':'+';
    }
}

void snimi_analize(FILE *out, struct analiza_st analize[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%c %s %s\n",
            analize[i].upozorenje,
            analize[i].ime,
            analize[i].prezime
        );
    }
}
