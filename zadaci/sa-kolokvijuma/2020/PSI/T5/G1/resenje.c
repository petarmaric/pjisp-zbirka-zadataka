#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IME 21
#define MAX_NASLOV 31

typedef struct cvor_st{
    char ime[MAX_IME];
    char prezime[MAX_IME];
    char naslov[MAX_NASLOV];
    int cena;
    int kopije;
    int zarada;
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

CVOR* create_node(char* ime, char* prezime, char* naslov, int cena,
int kopije) {
    CVOR* tmp = malloc(sizeof(CVOR));
    if(tmp==NULL){
        printf("Ne moze se zauzeti memorija");
        exit(123);
    }
    strcpy(tmp->ime, ime);
    strcpy(tmp->prezime, prezime);
    strcpy(tmp->naslov, naslov);
    tmp->cena = cena;
    tmp->kopije = kopije;
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
    char ime[MAX_IME], prezime[MAX_IME], naslov[MAX_NASLOV];
    int cena, kopije;
    while(fscanf(in, "%s %s %s %d %d", ime, prezime, naslov, &cena, &kopije)
    !=EOF){
        CVOR* new = create_node(ime, prezime, naslov, cena, kopije);
        add_sorted(glava, new);
    }
}

void write(FILE* out, CVOR* glava) {
    while(glava != NULL) {
        glava->zarada = glava->cena * glava->kopije;
        fprintf(out, "%s %s %s %d\n", glava->prezime, glava->ime,
            glava->naslov, glava->zarada);
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

CVOR* find_best_seller(CVOR* glava) {
    CVOR* best = NULL;
    
    while(glava != NULL) {
        if(best == NULL) {
            best = glava;
        } else if(glava->zarada > best->zarada) {
            best = glava;
        }
        glava = glava->sledeci;
    }
    return best;
}

int main(int brArg, char* args[]) {
    
    if(brArg!=2) {
        printf("Program nije dobro pozvan");
        exit(42);
    }
    
    FILE* in = open_file(args[1], "r");
    CVOR* glava;
    init(&glava);
    read(in, &glava);
    write(stdout, glava);
    CVOR* best = find_best_seller(glava);
    if(best != NULL) {
        fprintf(stdout, "Knjiga koja je zaradila najvise novca je "
            +"%s %s %s %d %d.\n", best->ime, best->prezime, best->naslov,
            best->cena, best->kopije);
    } else {
        fprintf(stdout, "Ne postoji knjiga koja je zaradila najvise novca.\n");
    }
    fclose(in);
    clear(&glava);
    return 0;
}
