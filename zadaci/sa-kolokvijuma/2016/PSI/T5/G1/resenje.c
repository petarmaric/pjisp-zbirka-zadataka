#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV_GRAD 2+1
#define MAX_NAZIV_VRSTA_MESA 20+1

typedef struct meso_st {
    char grad[MAX_NAZIV_GRAD];
    char vrsta_mesa[MAX_NAZIV_VRSTA_MESA];
    double cena;
    struct meso_st *next;
} MESO;

void init_list(MESO **head) {
    *head = NULL;
}

void add_to_list(MESO *new, MESO **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    } 
    
    add_to_list(new, &((*head)->next));
}

MESO *create_new_item(char grad[], char vrsta_mesa[], double cena) {
    MESO *new = (MESO *)malloc(sizeof(MESO));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->grad, grad);
    strcpy(new->vrsta_mesa, vrsta_mesa);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, MESO **head) {
    char tmp_grad[MAX_NAZIV_GRAD];
    char tmp_vrsta_mesa[MAX_NAZIV_VRSTA_MESA];
    double tmp_cena;
    
    while(fscanf(in, "%s %s %lf", tmp_grad, tmp_vrsta_mesa, &tmp_cena) != EOF) {
        MESO *new = create_new_item(tmp_grad, tmp_vrsta_mesa, tmp_cena);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, MESO *x) {
    fprintf(
        out, "%6.2lf %s %s\n", 
        x->cena, x->grad, x->vrsta_mesa
    );
}

void save_list_to(FILE *out, MESO *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(MESO **head) {
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

MESO *get_najpovoljnije_meso(MESO *head, char vrsta_mesa[]) {
    if (head == NULL) { // list is empty
        return NULL;
    }

    MESO *best = NULL;
    while(head != NULL) {
        if (strcmp(head->vrsta_mesa, vrsta_mesa) == 0) {
            // Gledamo samo meso koje je odgovarajuce vrste
            if (best == NULL) {
                // Pre ovoga sigurno nije bilo mesa koje je odgovarajuce vrste
                best = head;
            } else if (head->cena < best->cena) {
                // Nadjeno povoljnije meso, koje je odgovarajuce vrste
                best = head;
            }
        }
        
        head = head->next;
    }

    return best;
}

int main(int arg_num, char *args[]) {
    if (arg_num != 4) {
        printf("USAGE: %s VRSTA_MESA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *vrsta_mesa = args[1];
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    MESO *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    MESO *best = get_najpovoljnije_meso(head, vrsta_mesa);
    if (best == NULL) {
        fprintf(out, "\nNigde nema '%s'!\n", vrsta_mesa);
    } else {
        fprintf(out, "\nNajpovoljnija '%s' je:\n", vrsta_mesa);
        save_item_to(out, best);
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
