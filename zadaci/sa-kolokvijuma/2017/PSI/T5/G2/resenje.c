#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DRZAVA 3+1
#define MAX_GRAD 2+1
#define MAX_NAZIV 20+1

#define ERROR_MAGIC_NUM -666.999

typedef struct pizza_st {
    int cena;
    char drzava[MAX_DRZAVA];
    char grad[MAX_GRAD];
    char naziv[MAX_NAZIV];
    struct pizza_st *next;
} PIZZA;

void init_list(PIZZA **head) {
    *head = NULL;
}

void add_to_list(PIZZA *new, PIZZA **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

PIZZA *create_new_item(int cena, char drzava[], char grad[], char naziv[]) {
    PIZZA *new = (PIZZA *)malloc(sizeof(PIZZA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    new->cena = cena;
    strcpy(new->drzava, drzava);
    strcpy(new->grad, grad);
    strcpy(new->naziv, naziv);

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, PIZZA **head) {
    int cena;
    char drzava[MAX_DRZAVA];
    char grad[MAX_GRAD];
    char naziv[MAX_NAZIV];

    while(fscanf(in, "%d %s %s %s", &cena, drzava, grad, naziv) != EOF) {
        PIZZA *new = create_new_item(cena, drzava, grad, naziv);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, PIZZA *x) {
    fprintf(
        out, "%4d %s %s %s\n",
        x->cena, x->drzava, x->grad, x->naziv
    );
}

void save_list_to(FILE *out, PIZZA *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(PIZZA **head) {
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

int count_pizza(PIZZA *head, char drzava[], char naziv[]) {
    int count = 0;

    while(head != NULL) {
        if (strcmp(head->drzava, drzava) == 0 &&
            strcmp(head->naziv, naziv) == 0) {
            count++;
        }

        head = head->next;
    }

    return count;
}

int sum_pizza(PIZZA *head, char drzava[], char naziv[]) {
    int sum = 0;

    while(head != NULL) {
        if (strcmp(head->drzava, drzava) == 0 &&
            strcmp(head->naziv, naziv) == 0) {
            sum += head->cena;
        }

        head = head->next;
    }

    return sum;
}

double avg_pizza(PIZZA *head, char drzava[], char naziv[]) {
    double count = count_pizza(head, drzava, naziv);
    if (count == 0) {
        return ERROR_MAGIC_NUM;
    } else {
        return sum_pizza(head, drzava, naziv) / count;
    }
}

int main(int arg_num, char *args[]) {
    if (arg_num != 5) {
        printf("USAGE: %s DRZAVA NAZIV IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *drzava = args[1];
    char *naziv = args[2];
    char *in_filename = args[3];
    char *out_filename = args[4];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    PIZZA *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    double avg = avg_pizza(head, drzava, naziv);
    if (avg == ERROR_MAGIC_NUM) {
        fprintf(out, "\nNOT FOUND!\n");
    } else {
        fprintf(out, "\navg = %.2lf\n", avg);
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
