#include <stdio.h>
#include <stdlib.h>

#define MAXN 31
#define MAXF 21

typedef struct mobilni{
    char marka[MAXN];
    char model[MAXN];
    double cena;
}MOBILNI;

int ucitaj(MOBILNI mob[], char *dat){

    FILE *ulazna = fopen(dat, "r");
    if(ulazna == NULL){
        printf("Datoteka %s ne moze biti otvorena!\n", dat);
        exit(1);
    }

    int i = 0;
    while(fscanf(ulazna, "%s %s %lf", 
                mob[i].marka, mob[i].model, &mob[i].cena)!=EOF)
                i++;

    fclose(ulazna);
    
    return i;
}

void ispisi(MOBILNI mob[], int n, double cena){

    int i, ukupno=0;

    for(i=0; i<n; i++){
        if(mob[i].cena < cena){
            printf("Naziv marke: %s, naziv modela: %s, iznos: %.2lf\n", 
            mob[i].marka, mob[i].model, mob[i].cena);
            ukupno++;
        }
    }

    printf("\nUkupno postoji %d modela koji su jefiniji od %.2lf dinara.\n", 
    ukupno, cena);
}

int main(int brArg, char *arg[]){

    if (brArg!=3){
        printf("Nije unet tačan broj argumenata!\n");
        exit(1);
    }

    char *dat = arg[1];
    double cena = atof(arg[2]);
    MOBILNI mob[MAXF];

    int n = ucitaj(mob, dat);
    ispisi(mob, n, cena);

    return 0;
}
