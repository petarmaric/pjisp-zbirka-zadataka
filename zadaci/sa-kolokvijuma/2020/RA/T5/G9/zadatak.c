#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 10

typedef struct magacin {
    unsigned sifraMagacina;
    unsigned sifraProizvoda;
    char nazivProizvoda[MAX_NAZIV];
    unsigned cena;
    struct magacin *next;
}MAGACIN;

void init_list(MAGACIN **head) {
    *head = NULL;
}

void add_to_list(MAGACIN *new, MAGACIN **head) {
    if(*head == NULL) { 
        *head = new;
        return;
    } 
 
    if((*head)->sifraMagacina > new->sifraMagacina) {
        new->next = *head;
        *head = new;
    } else {
        MAGACIN* tek = *head;
        MAGACIN* pret = *head;
        while(tek != NULL && tek->sifraMagacina < new->sifraMagacina) {
            pret = tek;
            tek = tek->next;
        }
        new -> next = pret -> next;
        pret -> next = new;
    }  
}

void print(MAGACIN *head){
    if (head == NULL) { 
        return;
    }

    while(head != NULL) {
        printf("\n%d %d %s %d", head->sifraMagacina, 
        head->sifraProizvoda, 
        head->nazivProizvoda, head->cena);
        head = head->next;
    }
}

MAGACIN *create_new_item(unsigned sifraMagacina, 
unsigned sifraProizvoda, char nazivProizvoda[], unsigned cena) {
    MAGACIN *new = (MAGACIN*)malloc(sizeof(MAGACIN));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    new->sifraMagacina = sifraMagacina;
    new->sifraProizvoda = sifraProizvoda;
    strcpy(new->nazivProizvoda, nazivProizvoda);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, MAGACIN **head) {
    unsigned sifraMagacina;
    unsigned sifraProizvoda;
    char nazivProizvoda[MAX_NAZIV];
    unsigned cena;
    
    while(fscanf(in, "%u %u %s %u", &sifraMagacina,
    &sifraProizvoda, nazivProizvoda, &cena) != EOF) {
        MAGACIN *new = create_new_item(sifraMagacina,
        sifraProizvoda, nazivProizvoda, cena);
        add_to_list(new, head);
    }
}

void save_item_to(int postoji, char nazivProizvoda[], unsigned sifraMagacina,
unsigned sifraProizvoda, unsigned ukupnaVrednost, unsigned brojProizvoda) {

    if(postoji==1){
        printf("\nUkupno proizvoda sa sifrom %u, "
        "pod nazivom %s u magacinu sa sifrom %u ima "
        "%u.\nUkupna vrednost proizvoda je %u dinara.", 
            sifraProizvoda, nazivProizvoda,
            sifraMagacina, brojProizvoda, ukupnaVrednost);
    }
    else{
        printf("\nNe postoji magacin i proizvod za unete podatke.");
    }
}

void destroy_list(MAGACIN **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

FILE *safe_fopen(char *filename, char *mode, int error_code) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Nije moguce otvoriti datoteku '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

void algoritam(MAGACIN *head, unsigned sm, unsigned sp){
    unsigned brojProizvoda = 0;
    unsigned ukupnaVrednost = 0;
    char nazivProizvoda[MAX_NAZIV];
    int postoji=0;

    if (head == NULL) { 
        return;    
    }
    
    while(head != NULL) {      
        if (head->sifraMagacina==sm && head->sifraProizvoda==sp) {
            postoji=1;
            strcpy(nazivProizvoda, head->nazivProizvoda);
            ukupnaVrednost += head->cena;
            brojProizvoda++;
        }    
        head = head->next;
    }
    save_item_to(postoji, nazivProizvoda, sm,
    sp, ukupnaVrednost, brojProizvoda);
}

int main(int arg_num, char *args[]) {
    if (arg_num != 2) {
        printf("Program treba pozvati na sledeci nacin:"
        "%s nazivUlazneDatoteke.txt\n", args[0]);
        exit(11);
    }

    char *in_filename = args[1];

    FILE *in  = safe_fopen(in_filename,  "r", 1);

    unsigned sifraMagacina, sifraProizvoda;

    MAGACIN *head;
    init_list(&head);
    read_list_from(in, &head);
    print(head);
    
    printf("\n\nUnesite sifru magacina: ");
    scanf("%u", &sifraMagacina);
    printf("Unesite sifru proizovoda: ");
    scanf("%u", &sifraProizvoda);

    algoritam(head, sifraMagacina, sifraProizvoda);
    destroy_list(&head);

    fclose(in);

    return 0;
}
