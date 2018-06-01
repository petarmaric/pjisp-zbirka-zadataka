#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIMBOL 2+1
#define MAX_IME 20+1
#define MAX_VRSTA 20+1

typedef struct element_st {
    char simbol[MAX_SIMBOL];
    char ime[MAX_IME];
    unsigned tezina;
    char vrsta[MAX_VRSTA];

    struct element_st *next;
} ELEMENT;

void init_list(ELEMENT **head) {
    *head = NULL;
}

void add_to_list(ELEMENT *new, ELEMENT **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

ELEMENT *create_new_item(char simbol[], char ime[], unsigned tezina,
char vrsta[]) {
    ELEMENT *new = (ELEMENT *)malloc(sizeof(ELEMENT));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->simbol, simbol);
    strcpy(new->ime, ime);
    new->tezina = tezina;
    strcpy(new->vrsta, vrsta);

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, ELEMENT **head) {
    char simbol[MAX_SIMBOL];
    char ime[MAX_IME];
    unsigned tezina;
    char vrsta[MAX_VRSTA];

    while(fscanf(in, "%s %s %u %s", simbol, ime, &tezina, vrsta) != EOF) {
        ELEMENT *new = create_new_item(simbol, ime, tezina, vrsta);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, ELEMENT *x) {
    fprintf(
        out, "%-2s %3u %s\n",
        x->simbol, x->tezina, x->vrsta
    );
}

void save_list_to(FILE *out, ELEMENT *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(ELEMENT **head) {
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

ELEMENT *get_najtezi_element(ELEMENT *head, char vrsta[]) {
    if (head == NULL) { // list is empty
        return NULL;
    }

    ELEMENT *best = NULL;
    while(head != NULL) {
        if (strcmp(head->vrsta, vrsta) == 0) {
            // Gledamo samo hem. element koji je odgovarajuce vrste
            if (best == NULL) {
                // Pre ovoga nije bilo hem. elemenata koji su odgovarajuce vrste
                best = head;
            } else if (head->tezina > best->tezina) {
                // Nadjen tezi hem. element, koji je odgovarajuce vrste
                best = head;
            }
        }

        head = head->next;
    }

    return best;
}

int main(int arg_num, char *args[]) {
    if (arg_num != 4) {
        printf("USAGE: %s VRSTA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *vrsta = args[1];
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    ELEMENT *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    ELEMENT *best = get_najtezi_element(head, vrsta);
    if (best == NULL) {
        fprintf(out, "\nU uzorku nije pronadjen nijedan %s!\n", vrsta);
    } else {
        fprintf(
            out, "\nNajtezi %s je %s (%s), atomska tezina %u\n",
            best->vrsta, best->ime, best->simbol, best->tezina
        );
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
