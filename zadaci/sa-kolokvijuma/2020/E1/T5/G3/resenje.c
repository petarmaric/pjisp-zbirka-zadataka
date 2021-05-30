#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20+1


typedef struct lego_st {
    char naziv[MAX_NAZIV];
    char kolekcija[MAX_NAZIV];
    unsigned br_kockica;

    struct lego_st *next;
} LEGO;

void init_list(LEGO **head) {
    *head = NULL;
}

void add_to_list(LEGO *new, LEGO **head) {
    if(*head == NULL || new->br_kockica > (*head)->br_kockica) {
        new->next = *head;
        *head = new;
    } else {
        LEGO *tmp = *head;

        while(tmp->next != NULL &&
              new->br_kockica < tmp->next->br_kockica) {
            tmp = tmp->next;
        }

        new->next = tmp->next;
        tmp->next = new;
    }
}

LEGO *create_new_item(char naziv[], char kolekcija[], unsigned br_kockica) {
    LEGO *new = (LEGO *)malloc(sizeof(LEGO));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    strcpy(new->kolekcija, kolekcija);
    new->br_kockica = br_kockica;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, LEGO **head) {
    char naziv[MAX_NAZIV];
    char kolekcija[MAX_NAZIV];
    unsigned br_kockica;

    while(fscanf(in, "%s %s %u", naziv, kolekcija,  &br_kockica) != EOF) {
        LEGO *new = create_new_item(naziv, kolekcija, br_kockica);
        add_to_list(new, head);
    }
}

void save_list_to(FILE *out, LEGO *head, char kolekcija[]) {
    LEGO *tmp = head;

    int exists = 0;
    while(tmp != NULL) {
        if(strcmp(kolekcija, tmp->kolekcija) == 0){
            exists = 1;
            break;
        }

        tmp = tmp->next;
    }

    if (exists == 1){
        fprintf(out, "Setovi kolekcije %s:\n\n", kolekcija);
        while(tmp != NULL) {
            if(strcmp(kolekcija, tmp->kolekcija) == 0){
                fprintf(
                    out, "%u %s\n",
                    tmp->br_kockica, tmp->naziv
                );
            }

            tmp = tmp->next;
        }
    } else {
        fprintf(out, "Ne postoji kolekcija %s!\n", kolekcija);
    }
}

void destroy_list(LEGO **head) {
    LEGO *tmp;

    while(*head != NULL) {
        tmp = *head;

        *head = (*head)->next;
        tmp->next = NULL;
        free(tmp);
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

int main(int arg_num, char *args[]) {
    if (arg_num != 4) {
        printf("USAGE: %s KOLEKCIJA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *kolekcija = args[1];
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    LEGO *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head, kolekcija);

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
