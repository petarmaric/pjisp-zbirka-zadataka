#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_IME_PREZIME 16
#define MAX_VRSTA 9
#define MAX_ODOBREN 3
#define MAX_NIZ 30

struct krediti {
    char ime[MAX_IME_PREZIME];
    char prezime[MAX_IME_PREZIME];
    char vrsta[MAX_VRSTA];
    char odobren[MAX_ODOBREN];
    unsigned iznos_kredita;
    unsigned ucesce;
    float kamata;
    unsigned broj_godina;
};

FILE *safe_fopen(char filename[], char mode[], int error_code);
void ucitaj_kredite(FILE *in, struct krediti krediti[], int *n);
void izlazni_podaci(struct krediti krediti[], int n, char vrsta_kredita[]);
void ispisi_kredit(FILE *out, struct krediti kredit);

int main(int arg_num, char **args) {
    if (arg_num != 3) {
        printf("Program treba pokrenuti sa: %s vrstaKredita krediti.txt\n",
        args[0]);
        exit(1);
    }

    char *vrsta_kredita = args[1];
    char *krediti_in_filename = args[2];

    FILE *in  = safe_fopen(krediti_in_filename,  "r", 1);
     
    struct krediti krediti[MAX_NIZ];
    
    int n = 0;

    ucitaj_kredite(in, krediti, &n);
    izlazni_podaci(krediti, n, vrsta_kredita);
    
    fclose(in);
    
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

void ucitaj_kredite(FILE *in, struct krediti krediti[], int *n){
    *n = 0;
    while(fscanf(
        in, "%s %s %s %s %u %u %f %u",
        krediti[*n].ime,
        krediti[*n].prezime,
        krediti[*n].vrsta,
        krediti[*n].odobren,
        &krediti[*n].iznos_kredita,
        &krediti[*n].ucesce,
        &krediti[*n].kamata,
        &krediti[*n].broj_godina
    ) != EOF) {
        (*n)++;
    }
}

void ispisi_kredit(FILE *out, struct krediti kredit) {
    fprintf(out, "%s %s %s %s %u %u %f %u\n", 
                    kredit.ime,
                    kredit.prezime,
                    kredit.vrsta,
                    kredit.odobren,
                    kredit.iznos_kredita,
                    kredit.ucesce,
                    kredit.kamata,
                    kredit.broj_godina);
}

void izlazni_podaci(struct krediti krediti[], int n, char vrsta_kredita[]) {
    int i;
    float zarada = 0;
    int postoji = 0;
    FILE *out;
    char vrsta[MAX_VRSTA];
    
    strcpy(vrsta, vrsta_kredita);
    out = safe_fopen(strcat(vrsta,".txt"), "w", 2);
    
    for(i=0; i<n; i++) {
        if(strcmp(krediti[i].vrsta, vrsta_kredita)== 0) {
            postoji = 1;
            if(strcmp(krediti[i].odobren, "da") == 0) {
                ispisi_kredit(out, krediti[i]);
                zarada += (krediti[i].iznos_kredita - krediti[i].ucesce)/100 
                * krediti[i].kamata * krediti[i].broj_godina;
            }
        }    
    }

    if(postoji == 0) {
        printf("Uneta vrsta kredita ne postoji");
        exit(11);
    } 
    else {
        if(zarada != 0) {
            fprintf(out, "\nUkupna zarada banke je %.2f din.", zarada);
        }
        else {
            fprintf(out, "\nNema odobrenih kredita.");
        }    
        fclose(out);
    }
}
