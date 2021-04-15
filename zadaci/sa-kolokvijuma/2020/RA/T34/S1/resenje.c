#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GRAD 31
#define MAX_ZONA 7
#define MAX_REGISTRACIJA 9
#define MAX_MESTA 20

struct parking {
    char grad[MAX_GRAD];
    char zona[MAX_ZONA]; 
    char registracijaVozila[MAX_REGISTRACIJA];
    unsigned brojProvedenihSati;
};

FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitavanjeVozila(FILE *in, struct parking p[], int *n);
void cenePoZoni(struct parking c[], int n);

int main(int arg_num, char **args){
    if (arg_num != 2) {
        printf("Program treba pozvati na sledeci nacin: "
               "%s nazivUlazneDatoteke.txt\n", args[0]);
        exit(1);
    }

    char *in_filename = args[1];
    FILE *in  = safe_fopen(in_filename, "r", 1);

    struct parking p[MAX_MESTA];

    int n;

    ucitavanjeVozila(in, p, &n);
    cenePoZoni(p, n);

    fclose(in);
    return 0;
}

FILE *safe_fopen(char filename[], char mode[], int error_code){
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        printf("Nije moguce otvoriti datoteku '%s'!", filename);
        exit(error_code);
    }

    return fp;
}

void ucitavanjeVozila(FILE *in, struct parking p[], int *n){
    *n = 0;
    while(fscanf(in, "%s %s %s %u", 
              p[*n].grad,
              p[*n].zona,
              p[*n].registracijaVozila,
              &p[*n].brojProvedenihSati
         )
    != EOF) {
        (*n)++;
    }
}

void cenePoZoni(struct parking c[], int n){
    unsigned crvena=0, zuta=0, zelena=0;
    int i;

    for(i=0; i<n; i++) {
        if (strcmp(c[i].zona,"crvena")==0) {
            crvena+=c[i].brojProvedenihSati*60;
        } else if (strcmp(c[i].zona,"zuta")==0) {
            zuta+=c[i].brojProvedenihSati*55;
        } else if (strcmp(c[i].zona,"zelena")==0) {
            zelena+=c[i].brojProvedenihSati*40;
        }
    }

    printf("\nUkupna cena parkinga za vozila u crvenoj zoni je %u dinara.",
        crvena);
    printf("\nUkupna cena parkinga za vozila u zutoj zoni je %u dinara.",
        zuta);
    printf("\nUkupna cena parkinga za vozila u zelenoj zoni je %u dinara.\n",
        zelena);

}


