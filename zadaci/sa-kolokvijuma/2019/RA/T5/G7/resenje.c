#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 30 + 1

typedef struct ukras_st
{
    char naziv_prodavnice[MAX_NAZIV];
    char naziv_ukrasa[MAX_NAZIV];
    char vrsta_ukrasa[MAX_NAZIV];
    double cena;

    struct ukras_st *next;
} UKRAS;

void init_list(UKRAS **head)
{
    *head = NULL;
}

void add_to_list(UKRAS *new, UKRAS **head)
{
    if (*head == NULL)
    {
        *head = new;
        return;
    }

    add_to_list(new, &((*head)->next));
}

UKRAS *create_new_item(
    char naziv_prodavnice[],
    char naziv_ukrasa[],
    char vrsta_ukrasa[],
    double cena)
{
    UKRAS *new = (UKRAS *)malloc(sizeof(UKRAS));
    if (new == NULL)
    {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv_prodavnice, naziv_prodavnice);
    strcpy(new->naziv_ukrasa, naziv_ukrasa);
    strcpy(new->vrsta_ukrasa, vrsta_ukrasa);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, UKRAS **head)
{
    char naziv_prodavnice[MAX_NAZIV];
    char naziv_ukrasa[MAX_NAZIV];
    char vrsta_ukrasa[MAX_NAZIV];
    double cena;

    while (
        fscanf(
            in,
            "%s %s %s %lf",
            naziv_prodavnice, naziv_ukrasa, vrsta_ukrasa, &cena) != EOF)
    {
        UKRAS *new = create_new_item(
            naziv_prodavnice,
            naziv_ukrasa,
            vrsta_ukrasa,
            cena);
        add_to_list(new, head);
    }
}

void save_item_to(FILE *out, UKRAS *x)
{
    if (x != NULL)
    {
        fprintf(
            out, "%.2lf %s %s\n",
            x->cena, x->naziv_ukrasa, x->naziv_prodavnice);
    }
}

void destroy_list(UKRAS **head)
{
    if (*head != NULL)
    {
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

FILE *safe_fopen(char *filename, char *mode, int error_code)
{
    FILE *fp = fopen(filename, mode);
    if (fp == NULL)
    {
        printf("Can't open '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}

double najbolja_cena(UKRAS *head, UKRAS **ukras, char *vrsta_ukrasa)
{
    if (head == NULL)
    {
        return 0;
    }

    while (head != NULL)
    {
        if (strcmp(head->vrsta_ukrasa, vrsta_ukrasa) == 0)
        {
            if (*ukras == NULL)
            {
                *ukras = head;
            }
            else if (head->cena < (*ukras)->cena)
            {
                *ukras = head;
            }
        }

        head = head->next;
    }

    if (*ukras == NULL)
    {
        return 0;
    }

    return (*ukras)->cena;
}

void print_to_file(FILE *out, UKRAS *head)
{
    UKRAS *jelka = NULL;
    UKRAS *lampioni = NULL;
    UKRAS *lampice = NULL;

    double cena_lampice = najbolja_cena(head, &lampice, "lampice");
    double cena_lampiona = najbolja_cena(head, &lampioni, "lampioni");
    double cena_jelke = najbolja_cena(head, &jelka, "jelka");

    if (cena_jelke > cena_lampice && cena_jelke > cena_lampiona)
    {
        save_item_to(out, jelka);
        if (cena_lampice > cena_lampiona)
        {
            save_item_to(out, lampice);
            save_item_to(out, lampioni);
        }
        else
        {
            save_item_to(out, lampioni);
            save_item_to(out, lampice);
        }
    }
    else if (cena_lampice > cena_jelke && cena_lampice > cena_lampiona)
    {
        save_item_to(out, lampice);
        if (cena_jelke > cena_lampiona)
        {
            save_item_to(out, jelka);
            save_item_to(out, lampioni);
        }
        else
        {
            save_item_to(out, lampioni);
            save_item_to(out, jelka);
        }
    }
    else
    {
        save_item_to(out, lampioni);
        if (cena_jelke > cena_lampice)
        {
            save_item_to(out, jelka);
            save_item_to(out, lampice);
        }
        else
        {
            save_item_to(out, lampice);
            save_item_to(out, jelka);
        }
    }

    fprintf(
        out, "\nUkupna cena je: %.2lf",
        cena_jelke + cena_lampice + cena_lampiona);
}

int main(int arg_num, char *args[])
{
    if (arg_num != 3)
    {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];

    FILE *in = safe_fopen(in_filename, "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    UKRAS *head;
    init_list(&head);

    read_list_from(in, &head);
    print_to_file(out, head);

    destroy_list(&head);

    fclose(in);
    fclose(out);

    return 0;
}
