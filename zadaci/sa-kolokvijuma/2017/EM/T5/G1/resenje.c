#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GRAD 2+1
#define MAX_TIP_GORIVA 10+1

#define ERROR_MAGIC_NUM -666.999

typedef struct gorivo_st {
    char grad[MAX_GRAD];
    char tip_goriva[MAX_TIP_GORIVA];
    double cena;

    struct gorivo_st *next;
} GORIVO;

void init_list(GORIVO **head) {
    *head = NULL;
}

void add_to_list(GORIVO *new, GORIVO **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

GORIVO *create_new_item(char grad[], char tip_goriva[], double cena) {
    GORIVO *new = (GORIVO *)malloc(sizeof(GORIVO));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->grad, grad);
    strcpy(new->tip_goriva, tip_goriva);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, GORIVO **head) {
    char grad[MAX_GRAD];
    char tip_goriva[MAX_TIP_GORIVA];
    double cena;

    while(fscanf(in, "%s %s %lf", grad, tip_goriva, &cena) != EOF) {
        GORIVO *new = create_new_item(grad, tip_goriva, cena);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, GORIVO *x) {
    fprintf(
        out, "%6.2f %s %s\n",
        x->cena, x->grad, x->tip_goriva
    );
}

void save_list_to(FILE *out, GORIVO *head) {
    if(head != NULL) {
        save_item_to(out, head);
        save_list_to(out, head->next);
    }
}

void destroy_list(GORIVO **head) {
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

int count_gorivo(GORIVO *head, char tip_goriva[]) {
    int count = 0;

    while(head != NULL) {
        if (strcmp(head->tip_goriva, tip_goriva) == 0) {
            count++;
        }

        head = head->next;
    }

    return count;
}

double sum_gorivo(GORIVO *head, char tip_goriva[]) {
    double sum = 0;

    while(head != NULL) {
        if (strcmp(head->tip_goriva, tip_goriva) == 0) {
            sum += head->cena;
        }

        head = head->next;
    }

    return sum;
}

double avg_gorivo(GORIVO *head, char tip_goriva[]) {
    int count = count_gorivo(head, tip_goriva);
    if (count == 0) {
        return ERROR_MAGIC_NUM;
    } else {
        return sum_gorivo(head, tip_goriva) / count;
    }
}

int main(int arg_num, char *args[]) {
    if (arg_num != 4) {
        printf("USAGE: %s TIP_GORIVA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *tip_goriva = args[1];
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    GORIVO *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(out, head);

    double avg = avg_gorivo(head, tip_goriva);
    if (avg == ERROR_MAGIC_NUM) {
        fprintf(out, "\nNOT FOUND!\n");
    } else {
        fprintf(out, "\nAVG = %6.2lf\n", avg);
    }

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
