#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30
#define MAX_NAME 21

typedef struct merenje {
    char deo_zgrade[MAX_NAME];
    double temp_ujutru;
    double temp_podne;
    double temp_uvece;
} MERENJE;

typedef struct prosecna_temp {
    char deo_zgrade[MAX_NAME];
    double prosecna_temp;
} PROSECNA_TEMP;

FILE *safe_fopen(char *, char *);
void ucitaj_merenja(FILE *, MERENJE[], int *);
double izr_pros_temp(double, double, double);
void izracunaj_prosecne_temperature(MERENJE [], PROSECNA_TEMP [], int);
void ispisi_prosecne_temperature(PROSECNA_TEMP [], int);
double nadji_maks_prosecnu_temp(PROSECNA_TEMP [], int);

int main(int argc, char **args) {
    MERENJE merenja[MAX_SIZE];
    PROSECNA_TEMP prosecne_temp[MAX_SIZE];
    int n;

    if(argc != 2) {
        printf("Primer poziva programa: ./merenja merenja.txt\n");
        exit(EXIT_FAILURE);
    }

    FILE *in = safe_fopen(args[1], "r");

    ucitaj_merenja(in, merenja, &n);
    izracunaj_prosecne_temperature(merenja, prosecne_temp, n);
    ispisi_prosecne_temperature(prosecne_temp, n);
    double maks_prosecna_temp = nadji_maks_prosecnu_temp(prosecne_temp, n);
    printf("Najveca prosecna temperatura u zgradi je %.1lf stepeni.\n", 
        maks_prosecna_temp);

    fclose(in);
    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *filename, char *mode) {
    FILE *f = fopen(filename, mode);

    if(f == NULL) {
        printf("Greska prilikom otvaranja datoteke %s!\n", filename);
        exit(EXIT_FAILURE);
    }

    return f;
}

void ucitaj_merenja(FILE *in, MERENJE merenja[], int *pn) {
    int i = 0;

    while(fscanf(in, "%s %lf %lf %lf", 
                  merenja[i].deo_zgrade,
                 &merenja[i].temp_ujutru,
                 &merenja[i].temp_podne,
                 &merenja[i].temp_uvece
    ) != EOF) {
        i++;
    }

    *pn = i;
}

double izr_pros_temp(
    double temp_ujutru,
    double temp_podne, 
    double temp_uvece
) {
    return (temp_ujutru + temp_podne + temp_uvece) / 3;
}

void izracunaj_prosecne_temperature(
    MERENJE merenja[],
    PROSECNA_TEMP prosecne_temp[],
    int n
) {
    int i;

    for(i = 0;i < n;i++) {
        strcpy(prosecne_temp[i].deo_zgrade, merenja[i].deo_zgrade);
        prosecne_temp[i].prosecna_temp = izr_pros_temp(merenja[i].temp_ujutru,
                                                       merenja[i].temp_podne,
                                                       merenja[i].temp_uvece
                                         );
    }
}

void ispisi_prosecne_temperature(PROSECNA_TEMP prosecne_temperature[], int n) {
    int i;

    for(i = 0;i < n;i++) {
        printf("%s %.1lf\n",
            prosecne_temperature[i].deo_zgrade,
            prosecne_temperature[i].prosecna_temp
        );
    }

    printf("\n");
}

double nadji_maks_prosecnu_temp(PROSECNA_TEMP prosecne_temperature[], int n) {
    int i;

    double maks_prosecna_temp = prosecne_temperature[0].prosecna_temp;
    for(i = 1;i < n;i++) {
        if(prosecne_temperature[i].prosecna_temp > maks_prosecna_temp) {
            maks_prosecna_temp = prosecne_temperature[i].prosecna_temp;
        }
    }

    return maks_prosecna_temp;
}
