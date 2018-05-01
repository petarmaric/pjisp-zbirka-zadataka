#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRAD 2+1
#define MAX_GORIVO 10+1
#define MAX_NIZ 30

struct gorivo_st {
    char grad[MAX_GRAD];
    char tip_goriva[MAX_GORIVO];
    double cena;
};

struct analiza_st {
    double nova_cena;
    double procenat_uvecanja_cene;
    char grad[MAX_GRAD];
    char tip_goriva[MAX_GORIVO];
};


FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_goriva(FILE *in, struct gorivo_st goriva[], int *n);
double odredi_novu_cenu(struct gorivo_st gorivo, double akciza);
double odredi_procenat_uvecanja_cene(double stara_cena, double nova_cena);
void transform(struct gorivo_st goriva[], struct analiza_st analize[], int n,
double akciza);
void snimi_analize(FILE *out, struct analiza_st analize[], int n);


int main(int arg_num, char **args) {
    if (arg_num != 4) {
        printf("USAGE: %s AKCIZA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(42);
    }

    double akciza = atof(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    struct gorivo_st goriva[MAX_NIZ];
    struct analiza_st analize[MAX_NIZ];
    int n;

    ucitaj_goriva(in, goriva, &n);
    transform(goriva, analize, n, akciza);
    snimi_analize(out, analize, n);

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

void ucitaj_goriva(FILE *in, struct gorivo_st goriva[], int *n) {
    *n = 0;
    while(fscanf(
        in, "%s %s %lf",
         goriva[*n].grad,
         goriva[*n].tip_goriva,
        &goriva[*n].cena
    ) != EOF) {
        (*n)++;
    }
}

double odredi_novu_cenu(struct gorivo_st gorivo, double akciza) {
    return gorivo.cena + akciza;
}
double odredi_procenat_uvecanja_cene(double stara_cena, double nova_cena) {
    return (nova_cena / stara_cena - 1) * 100;
}

void transform(struct gorivo_st goriva[], struct analiza_st analize[], int n,
double akciza) {
    int i;
    for(i=0; i<n; i++) {
        strcpy(analize[i].grad, goriva[i].grad);
        strcpy(analize[i].tip_goriva, goriva[i].tip_goriva);

        analize[i].nova_cena = odredi_novu_cenu(goriva[i], akciza);
        analize[i].procenat_uvecanja_cene = odredi_procenat_uvecanja_cene(
            goriva[i].cena, analize[i].nova_cena
        );
    }
}

void snimi_analize(FILE *out, struct analiza_st analize[], int n) {
    int i;
    for(i=0; i<n; i++) {
        fprintf(
            out, "%6.2f %5.2f %s %s\n",
            analize[i].nova_cena,
            analize[i].procenat_uvecanja_cene,
            analize[i].grad,
            analize[i].tip_goriva
        );
    }
}
