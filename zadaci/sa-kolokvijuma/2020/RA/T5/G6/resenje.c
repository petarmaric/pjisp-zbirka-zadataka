#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXN 31

typedef struct film{
    char naziv[MAXN];
    double cena;
    unsigned broj;
    struct film *sledeci;
}FILM;

FILM* kreiraj_cvor(char naziv[], double cena, unsigned broj){

    FILM *novi = malloc(sizeof(FILM));
    if(novi == NULL){
        printf("Nema dovoljno memorije!\n");
        exit(2);
    }

   strcpy(novi->naziv, naziv);
   novi->cena = cena;
   novi->broj = broj;
   novi->sledeci = NULL;

   return novi;
}

FILM* dodaj_u_listu(FILM *glava, char naziv[], double cena, unsigned broj){

    FILM *novi = kreiraj_cvor(naziv, cena, broj);

    if(glava == NULL){
        glava = novi;
    }else if(strcmp(glava->naziv, naziv) > 0){
        novi->sledeci = glava;
        glava = novi;
    }else{
        FILM *tek = glava;
        FILM *pret = glava;
        
        while(tek!= NULL && strcmp(tek->naziv, naziv) < 0){
            pret = tek;
            tek = tek->sledeci;
        }

        novi->sledeci = pret->sledeci;
        pret->sledeci = novi;
    }

    return glava;
}

void ucitaj(FILM **glava, char *dat){

    FILE *ulazna = fopen(dat, "r");
    if(ulazna == NULL){
        printf("Datoteka %s ne moze biti otvorena!\n", dat);
        exit(1);
    }
    
    char naziv[MAXN];
    double cena;
    unsigned broj;
    
    while(fscanf(ulazna, "%s %lf %u", naziv, &cena, &broj)!=EOF)
        *glava = dodaj_u_listu(*glava, naziv, cena, broj);

    fclose(ulazna);
}

void ispisi(FILM *glava){

    double ukupna = 0, trenutna;
    
    while(glava){
        trenutna = glava->cena * glava->broj;
        ukupna += trenutna;
        printf("Naziv filma: %s, ukupna zarada: %.2lf\n", glava->naziv, 
        trenutna);
        glava = glava->sledeci;
    }
    
    printf("\nUkupna ostvarena zarada je: %.2lf\n", ukupna);
}

void destroy(FILM **glava){

    if(*glava){
        destroy(&((*glava)->sledeci));
        free(*glava);
        *glava = NULL;
    }
}

int main(int brArg, char *arg[]){

    if (brArg!=2){
        printf("Nije unet tacan broj argumenata!\n");
        exit(1);
    }
    
    char *dat = arg[1];
    FILM *glava = NULL;
    
    ucitaj(&glava, dat);
    ispisi(glava);
    izbrisi_listu(&glava);
    
    return 0;
}
