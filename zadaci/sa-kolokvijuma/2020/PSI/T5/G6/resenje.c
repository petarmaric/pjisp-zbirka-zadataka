#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 31

typedef struct pice{
    char naziv[MAXN];
    double cena;
    unsigned kolicina;
    struct pice *sledeci;
}PICE;

PICE* dodaj_u_listu(PICE *glava, char naziv[], double cena, unsigned kolicina){
    
    if(glava == NULL){
        glava = malloc(sizeof(PICE));
        
        if(glava == NULL){
            printf("Nema dovoljno memorije!\n");
            exit(2);
        }
        
        strcpy(glava->naziv, naziv);
        glava->cena = cena;
        glava->kolicina = kolicina;
        glava->sledeci = NULL;
    }else{
        glava->sledeci = dodaj_u_listu(glava->sledeci, naziv, cena, kolicina);
    }
    return glava;
}

void ucitaj(PICE **glava, char *dat){
    
    FILE *ulazna = fopen(dat, "r");
    if(ulazna == NULL){
        printf("Datoteka %s ne moze biti otvorena!\n", dat);
        exit(1);
    }
    
    char naziv[MAXN];
    double cena;
    unsigned kolicina;
    while(fscanf(ulazna, "%s %lf %u", naziv, &cena, &kolicina)!=EOF)
        *glava = dodaj_u_listu(*glava, naziv, cena, kolicina);
    
    fclose(ulazna);
}

void ispisi(PICE *glava, double novac){
    
    double ukupna = 0;
    while(glava){
        ukupna += glava->cena * glava->kolicina;
        glava = glava->sledeci;
    }
    
    if(novac >= ukupna)
        printf("Kupovina je obavljena.\n");
    else
        printf("Nema dovoljno novca, kupovina se ne može u celosti obaviti.\n");
}

void destroy(PICE **glava){
    
    if(*glava){
        destroy(&((*glava)->sledeci));
        free(*glava);
        *glava = NULL;
    }
}

int main(int brArg, char *arg[]){
    
    if (brArg!=3){
        printf("Nije unet tacan broj argumenata!\n");
        exit(1);
    }
    
    char *dat = arg[1];
    double novac = atof(arg[2]);
    PICE *glava = NULL;
    
    ucitaj(&glava, dat);
    ispisi(glava, novac);    
    destroy(&glava);    

    return 0;
}
