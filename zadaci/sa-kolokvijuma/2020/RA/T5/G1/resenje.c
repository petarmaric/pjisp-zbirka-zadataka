#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20+1

typedef struct obrok_st {
    char naziv[MAX];
    char vrsta[MAX];
    unsigned gramaza;
    unsigned kalorije;

    struct obrok_st *next;
} OBROK;

void init_list(OBROK **head) {
    *head = NULL;
}

void add_to_list(OBROK *new, OBROK **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

OBROK *create_new_item(char naziv[], unsigned gramaza, unsigned kalorije, char vrsta[]) {
    OBROK *new = (OBROK *)malloc(sizeof(OBROK));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->gramaza = gramaza;
    new->kalorije = kalorije;
    strcpy(new->vrsta, vrsta);

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, OBROK **head) {
    char naziv[MAX];
    unsigned gramaza;
    unsigned kalorije;
    char vrsta[MAX];

    while(fscanf(in, "%s %s %u %u", naziv, vrsta, &gramaza, &kalorije) != EOF) {
        OBROK *new = create_new_item(naziv, gramaza, kalorije, vrsta);
        add_to_list(new, head);
    }
}

void save_item(OBROK *x, char* vrsta) {
    if(strcmp(vrsta, x->vrsta) == 0){
        printf(
            "%s %u %u\n",
            x->naziv, x->gramaza, x->kalorije
        );
    }
}

void save_list(OBROK *head, char* vrsta) {
    if(head != NULL) {
        save_item(head, vrsta);
        save_list(head->next, vrsta);
    }
}

void destroy_list(OBROK **head) {
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

OBROK *get_najbolja_OBROK(OBROK *head, char vrsta[]) {
    if (head == NULL) {
        return NULL;
    }

    OBROK *best = NULL;
    while(head != NULL) {
        if (strcmp(head->vrsta, vrsta) == 0) {
            if (best == NULL) {
                best = head;
            } else if (head->gramaza * head->kalorije / 100 < best->gramaza * best->kalorije / 100) {
                best = head;
            }
        }

        head = head->next;
    }

    return best;
}

int main(int arg_num, char *args[]) {
    if (arg_num != 3) {
        printf("USAGE: %s VRSTA IN_FILENAME\n", args[0]);
        exit(11);
    }

    char *vrsta = args[1];
    char *in_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);

    OBROK *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list(head, vrsta);

    OBROK *best = get_najbolja_OBROK(head, vrsta);
    if (best != NULL) {
        printf("\nObrok sa najmanje kalorija je %s sa ukupno %d kalorija.\n", best->naziv, best->gramaza * best->kalorije / 100);
    }

    destroy_list(&head);

    fclose(in);

    return 0;
}
