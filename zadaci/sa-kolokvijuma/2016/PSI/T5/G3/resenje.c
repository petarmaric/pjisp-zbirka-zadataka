#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IGRA 10+1
#define MAX_ZANR 8+1
#define MAX_PLATFORMA 8+1

typedef struct igra_st {
    char igra[MAX_IGRA];
    char zanr[MAX_ZANR];
    char platforma[MAX_PLATFORMA];
    double cena;
    struct igra_st *next;
} IGRA;

void init_list(IGRA **head) {
    *head = NULL;
}

void add_to_list(IGRA *new, IGRA **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    } 
    
    add_to_list(new, &((*head)->next));
}

IGRA *create_new_item(char igra[], char zanr[], char platforma[], double cena) {
    IGRA *new = (IGRA *)malloc(sizeof(IGRA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->igra, igra);
    strcpy(new->zanr, zanr);
    strcpy(new->platforma, platforma);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, IGRA **head) {
    char tmp_igra[MAX_IGRA];
    char tmp_zanr[MAX_ZANR];
    char tmp_platforma[MAX_PLATFORMA];
    double tmp_cena;
    
    while(fscanf(in, "%s %s %s %lf", tmp_igra, tmp_zanr, tmp_platforma, &tmp_cena) != EOF) {
        IGRA *new = create_new_item(tmp_igra, tmp_zanr, tmp_platforma, tmp_cena);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, IGRA *x) {
    fprintf(
        out, "%-10s %-8s %-8s %5.2f\n", 
        x->igra, x->zanr, x->platforma, x->cena
    );
}

void save_list_to(FILE *out, IGRA *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(IGRA **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

FILE *safe_fopen(char *filename, char *mode, int error_code) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

IGRA *get_najpovoljnija_igra(IGRA *head, char zanr[], char platforma[]) {
    if (head == NULL) { // list is empty
        return NULL;
    }

    IGRA *best = NULL;
    while(head != NULL) {
        if (strcmp(head->zanr, zanr) == 0 && strcmp(head->platforma, platforma) == 0) { // Gledamo samo igre koje su OK
            if (best == NULL) { // Pre ovoga sigurno nije bilo igre koja je OK
                best = head;
            } else if (head->cena < best->cena) { // Nadjena povoljnija igra, koja je OK
                best = head;
            }
        }
        
        head = head->next;
    }

    return best;
}

int main(int arg_num, char *args[]) {
    if (arg_num != 5) {
        printf("USAGE: %s PLATFORMA ZANR IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *platforma = args[1];
    char *zanr = args[2];
    char *in_filename = args[3];
    char *out_filename = args[4];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    IGRA *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    IGRA *best = get_najpovoljnija_igra(head, zanr, platforma);
    if (best == NULL) {
        fprintf(out, "\nZa %s platformu ne postoje '%s' igre!\n", platforma, zanr);
    } else {
        fprintf(
            out, "\nNajpovoljnija '%s' igra za %s platformu je:\n%s %.2f\n",
            zanr, platforma, best->igra, best->cena
        );
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
