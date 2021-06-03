#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1


typedef struct ekipa_st{
    char naziv[MAX_NAZIV];
    char grad[MAX_NAZIV];
    int bodovi;
    struct ekipa_st *sledeci;
}CVOR;


FILE* otvaranje_datoteke(char* putanja, char* rezim){
    
    FILE* fajl = fopen(putanja, rezim);
    if (fajl == NULL){
        printf("Nije moguce otvoriti %s", putanja);
        exit(EXIT_FAILURE);
    }

    return fajl;
}


CVOR* napravi_novi(char naziv[], char grad[], int bodovi){

    CVOR* novi = (CVOR*)malloc(sizeof(CVOR));
    if (novi == NULL){
        printf("Nema dovoljno RAM memorije!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novi->naziv, naziv);
    strcpy(novi->grad, grad);
    novi->bodovi = bodovi;
    novi->sledeci = NULL;

    return novi;

}


void povezi_novi(CVOR* novi, CVOR** glava){

    if (*glava == NULL){
        *glava = novi;
        return;
    }
    
    CVOR* prethodni =*glava;
    CVOR* trenutni = *glava;
    while(trenutni != NULL && trenutni->bodovi > novi->bodovi){
        prethodni=trenutni;
        trenutni=trenutni->sledeci;
    }
    
    if (trenutni == *glava){
        novi->sledeci=trenutni;
        *glava=novi;
    }else{
        prethodni->sledeci=novi;
        novi->sledeci=trenutni;
    }
}


void ucitaj(FILE* fajl, CVOR** glava){

    char naziv[MAX_NAZIV];
    char grad[MAX_NAZIV];
    int bodovi;
    
    while(fscanf(fajl, "%s %s %d", naziv, grad, &bodovi) != EOF ){
        CVOR* novi = napravi_novi(naziv, grad, bodovi);    
        povezi_novi(novi, glava);    
    }    
}


void ispisi(CVOR* glava){

    while(glava != NULL){
        printf("%s %s %d\n", glava->naziv, glava->grad, glava->bodovi);
        glava = glava->sledeci;
    }
}


void pronadji_ekipu(char* naziv, CVOR* glava){
    
    int ukupno=0, pozicija=-1;
    while(glava!=NULL){
    
        ukupno++;
        if(strcmp(glava->naziv, naziv)==0)
            pozicija = ukupno;
            
        glava = glava->sledeci;
    }
    
    if(pozicija == -1)
        printf("\nEkipa %s ne postoji u bazi!\n", naziv);
    else if (pozicija <= ukupno/2)
        printf("\nEkipa %s se nalazi u gornjoj polovini tabele!\n", naziv);
    else
        printf("\nEkipa %s se nalazi u donjoj polovini tabele!\n", naziv);
    
}


void obrisi_listu(CVOR** glava){
    
    CVOR* temp;
    while(*glava != NULL){
        temp = *glava; 
        *glava = (*glava)->sledeci;
        free(temp);
    }
}


int main(int brArg, char* arg[]){
    
    if (brArg !=3){
        printf("Uneli ste pogresan broj argumenata!\n");
        exit(EXIT_FAILURE);
    }

    CVOR* glava = NULL;
    
    FILE* ulaz = otvaranje_datoteke(arg[1], "r");
    char *naziv = arg[2];
    
    ucitaj(ulaz, &glava);
    ispisi(glava);
    pronadji_ekipu(naziv, glava);

    obrisi_listu(&glava);
    fclose(ulaz);

    return 0;
}

