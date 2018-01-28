#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 16+1

typedef struct planeta_st {
    char naziv[MAX_NAZIV];
    int x;
    int y;
    int z;
    struct planeta_st *next;
} PLANETA;

void init_list(PLANETA **head) {
    *head = NULL;
}

void add_to_list(PLANETA *new, PLANETA **head) {
    if(*head == NULL) { // list is empty
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

PLANETA *create_new_item(char naziv[], int x, int y, int z) {
    PLANETA *new = (PLANETA *)malloc(sizeof(PLANETA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->x = x;
    new->y = y;
    new->z = z;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, PLANETA **head) {
    char tmp_naziv[MAX_NAZIV];
    int tmp_x;
    int tmp_y;
    int tmp_z;

    while(fscanf(in, "%s %d %d %d", tmp_naziv, &tmp_x, &tmp_y, &tmp_z) != EOF) {
        PLANETA *new = create_new_item(tmp_naziv, tmp_x, tmp_y, tmp_z);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, PLANETA *x) {
    fprintf(
        out, "%s %d %d %d\n",
        x->naziv, x->x, x->y, x->z
    );
}

void destroy_list(PLANETA **head) {
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

double udaljenost(PLANETA *a, PLANETA *b) {
    return sqrt(
        pow(a->x - b->x, 2) +
        pow(a->y - b->y, 2) +
        pow(a->z - b->z, 2)
    );
}

void find_max_udaljenost(PLANETA *head, PLANETA **p1, PLANETA **p2) {
    *p1 = head;
    *p2 = head->next;

    PLANETA *a;
    PLANETA *b;
    for(a = head; a != NULL; a = a->next) {
        for(b = a->next; b != NULL; b = b->next) {
            if (udaljenost(a, b) > udaljenost(*p1, *p2)) {
                *p1 = a;
                *p2 = b;
            }
        }
    }
}

int main(int arg_num, char *args[]) {
    if (arg_num != 3) {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    PLANETA *head;
    init_list(&head);

    read_list_from(in, &head);

    PLANETA *p1;
    PLANETA *p2;
    find_max_udaljenost(head, &p1, &p2);
    save_item_to(out, p1);
    save_item_to(out, p2);
    fprintf(out, "%.2f\n", udaljenost(p1, p2));

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
