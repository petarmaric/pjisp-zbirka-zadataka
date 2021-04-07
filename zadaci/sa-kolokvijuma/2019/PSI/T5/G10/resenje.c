#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30+1

typedef struct slatkis_st {
    char naziv[MAX];
    double secer;
    unsigned gramaza;
    char vrsta[MAX];

    struct slatkis_st *next;
} SLATKIS;

void init_list(SLATKIS **head) {
    *head = NULL;
}

void add_to_list(SLATKIS *new, SLATKIS **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

SLATKIS *create_new_item(char naziv[], double secer, unsigned gramaza, char vrsta[]) {
    SLATKIS *new = (SLATKIS *)malloc(sizeof(SLATKIS));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->secer = secer;
    new->gramaza = gramaza;
    strcpy(new->vrsta, vrsta);

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, SLATKIS **head) {
    char naziv[MAX];
    double secer;
    unsigned gramaza;
    char vrsta[MAX];

    while(fscanf(in, "%s %lf %u %s", naziv, &secer, &gramaza, vrsta) != EOF) {
        SLATKIS *new = create_new_item(naziv, secer, gramaza, vrsta);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, SLATKIS *x) {
    fprintf(
        out, "%s %u %.2lf\n",
        x->naziv, x->gramaza, x->secer
    );
}

void save_list_to(FILE *out, SLATKIS *head, char vrsta[]) {
    if(head != NULL) {
        if(strcmp(head->vrsta, vrsta) == 0) {
            save_item_to(out, head);
        }
        save_list_to(out, head->next, vrsta);
    }
}

void destroy_list(SLATKIS **head) {
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

SLATKIS* get_najsladji_SLATKIS(SLATKIS *head, char vrsta[]) {
    if (head == NULL) { // list is empty
        return NULL;
    }

    SLATKIS *best = NULL;
    while(head != NULL) {
        if (strcmp(head->vrsta, vrsta) == 0) {
            // Gledamo samo namirnice koje su odgovarajuce vrste
            if (best == NULL) {
                // Pre ovoga nije bilo SLATKISA koji su odgovarajuce vrste
                best = head;
            } else if(head->gramaza*head->secer/100 > best->gramaza*best->secer/100) {
                // Nadjen bolji SLATKIS, koji je odgovarajuce vrste
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

    SLATKIS *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head, vrsta);

    SLATKIS *best = get_najsladji_SLATKIS(head, vrsta);
    if (best != NULL) {
        fprintf(out, "\nSlatkis sa najvise secera je: %s", best->naziv);
        fprintf(out, "\nKolicina secera je: %.2lf\n", best->gramaza*best->secer/100);
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
