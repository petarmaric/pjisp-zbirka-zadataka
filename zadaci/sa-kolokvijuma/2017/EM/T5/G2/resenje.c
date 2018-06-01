#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 10+1
#define MAX_VRSTA 20+1

typedef struct restoran_st {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    double ocena;

    struct restoran_st *next;
} RESTORAN;

void init_list(RESTORAN **head) {
    *head = NULL;
}

void add_to_list(RESTORAN *new, RESTORAN **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

RESTORAN *create_new_item(char naziv[], char vrsta[], double ocena) {
    RESTORAN *new = (RESTORAN *)malloc(sizeof(RESTORAN));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    strcpy(new->vrsta, vrsta);
    new->ocena = ocena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, RESTORAN **head) {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    double ocena;

    while(fscanf(in, "%s %s %lf", naziv, vrsta, &ocena) != EOF) {
        RESTORAN *new = create_new_item(naziv, vrsta, ocena);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, RESTORAN *x) {
    fprintf(
        out, "%3.1f %-10s %s\n",
        x->ocena, x->naziv, x->vrsta
    );
}

void save_list_to(FILE *out, RESTORAN *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(RESTORAN **head) {
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

RESTORAN *get_najbolji_restoran(RESTORAN *head, char vrsta[]) {
    if (head == NULL) { // list is empty
        return NULL;
    }

    RESTORAN *best = NULL;
    while(head != NULL) {
        if (strcmp(head->vrsta, vrsta) == 0) {
            // Gledamo samo restoran koji je odgovarajuce vrste
            if (best == NULL) {
                // Pre ovoga nije bilo restorana koji su odgovarajuce vrste
                best = head;
            } else if (head->ocena > best->ocena) {
                // Nadjen bolji restoran, koji je odgovarajuce vrste
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

    RESTORAN *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    RESTORAN *best = get_najbolji_restoran(head, vrsta);
    if (best == NULL) {
        fprintf(out, "\nU gradu ne postoji %s restoran!\n", vrsta);
    } else {
        fprintf(
            out, "\nNajbolje ocenjen %s restoran u gradu je:\n",
            best->vrsta
        );
        save_item_to(out, best);
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
