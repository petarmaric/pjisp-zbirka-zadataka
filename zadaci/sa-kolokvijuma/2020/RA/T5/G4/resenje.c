#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IME 21
#define MAX_NASLOV 31

typedef struct cvor_st{
    char ime[MAX_IME];
    char prezime[MAX_IME];
    char naslov[MAX_NASLOV];
    char zanr[MAX_IME];
    int cena;
    struct cvor_st* sledeci;
}CVOR;

FILE* open_file(char* ime, char* mode) {

    FILE* fp = fopen(ime, mode);
    if(fp==NULL) {
        printf("Greska pri otvaranju datoteke %s", ime);
        exit(42);
    }
    return fp;
}

void init(CVOR** glava) {
    *glava = NULL;
}

CVOR* create_node(char* ime, char* prezime, char* naslov, char* zanr, 
int cena) {
    CVOR* tmp = malloc(sizeof(CVOR));
    if(tmp==NULL){
        printf("Ne moze se zauzeti memorija");
        exit(123);
    }
    strcpy(tmp->ime, ime);
    strcpy(tmp->prezime, prezime);
    strcpy(tmp->naslov, naslov);
    strcpy(tmp->zanr, zanr);
    tmp->cena = cena;
    tmp->sledeci = NULL;
    return tmp; 
}

void add_sorted(CVOR** glava, CVOR* novi) {

   CVOR* trenutni;
    if(*glava==NULL || (*glava)->cena >= novi->cena) {
        novi->sledeci = *glava;
        *glava = novi;
    } else {
        trenutni = *glava;
        while(trenutni->sledeci!=NULL && trenutni->sledeci->cena < novi->cena)
        {
            trenutni = trenutni->sledeci;
        }
        novi->sledeci = trenutni->sledeci;
        trenutni->sledeci = novi;
    }
}

void read(FILE* in, CVOR** glava) {
    char ime[MAX_IME];
    char prezime [MAX_IME];
    char naslov[MAX_NASLOV];
    int cena;
    char zanr[MAX_IME];
    while(fscanf(in, "%s %s %s %s %d", ime, prezime, naslov, zanr, &cena)!=EOF)
    {
        CVOR* new = create_node(ime, prezime, naslov, zanr, cena);
        add_sorted(glava, new);
    }
}

void write(FILE* out, CVOR* glava) {
    while(glava != NULL) {
        fprintf(out, "%s %s %d %s\n", glava->prezime, glava->ime, glava->cena,
         glava->naslov);
        glava = glava->sledeci;
    }
}

void clear(CVOR** glava) {
    if(*glava == NULL) {
        return;
    }
    clear(&((*glava)->sledeci));
    free(*glava);
    *glava = NULL;
}

int pronadji_zanr(CVOR* glava, char* zanr) {
    if(glava == NULL) {
        return;
    }
    int s = 0;
    
    while(glava != NULL) {
        if(strcmp(glava->zanr, zanr) == 0) {
            s += glava->cena;
        }
        glava = glava->sledeci;
    }
    return s;
}

int main(int brArg, char* args[]) {
    
    if(brArg!=3) {
        printf("Program nije dobro pozvan");
        exit(42);
    }
    
    FILE* in = open_file(args[1], "r");
    CVOR* glava;
    init(&glava);
    read(in, &glava);
    write(stdout, glava);
    int suma = pronadji_zanr(glava, args[2]);
    if(suma != 0) {
        fprintf(stdout, "Knjige zanra %s kostaju ukupno %d din.\n",
        args[2], suma);
    } else {
        fprintf(stdout, "Ne postoje knjige zanra %s.\n", args[2]);
    }
    fclose(in);
    clear(&glava);
    return 0;
}
