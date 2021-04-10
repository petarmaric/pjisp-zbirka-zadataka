#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20 + 1

typedef struct igra_st
{
    char naziv[MAX_NAZIV];
    unsigned rang;
    char windows;
    char macos;
    char lin;

    struct igra_st *next;
} IGRA;

void init_list(IGRA **head)
{
    *head = NULL;
}

void add_to_list_sorted(IGRA *new, IGRA **head)
{
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    else if ((*head)->rang > new->rang)
    {
        new->next = *head;
        *head = new;
        return;
    }
    IGRA *pom = *head;

    while (pom->next != NULL && pom->next->rang < new->rang)
    {
        pom = pom->next;
    }
    new->next = pom->next;
    pom->next = new;
}

IGRA *create_new_item(
    char naziv[],
    unsigned rang,
    char windows,
    char macos,
    char lin)
{
    IGRA *new = (IGRA *)malloc(sizeof(IGRA));
    if (new == NULL)
    {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->rang = rang;
    new->windows = windows;
    new->macos = macos;
    new->lin = lin;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, IGRA **head)
{
    char naziv[MAX_NAZIV];
    unsigned rang;
    char windows;
    char macos;
    char lin;

    while (
        fscanf(
            in,
            "%s %u %c %c %c",
            naziv,
            &rang,
            &windows,
            &macos,
            &lin) != EOF)
    {
        IGRA *new = create_new_item(naziv, rang, windows, macos, lin);
        add_to_list_sorted(new, head);
    }
}

void print_item(IGRA *x)
{
    printf(
        "%u %s\n",
        x->rang, x->naziv);
}

void print_list(IGRA *head)
{
    if (head != NULL)
    {
        print_item(head);
        print_list(head->next);
    }
}

void destroy_list(IGRA **head)
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

void print_najbolja_IGRA(IGRA *head)
{
    if (head == NULL)
    {
        return;
    }

    printf("\nNajbolje rangirana igra je %s ", head->naziv);
    printf("i podrzana je na sledecim operativnim sistemima:\n");
    if (head->windows == '+')
    {
        printf("Windows\n");
    }
    if (head->macos == '+')
    {
        printf("MacOS\n");
    }
    if (head->lin == '+')
    {
        printf("Linux\n");
    }
}

int main(int arg_num, char *args[])
{
    if (arg_num != 2)
    {
        printf("USAGE: %s IN_FILENAME\n", args[0]);
        exit(11);
    }

    char *in_filename = args[1];

    FILE *in = safe_fopen(in_filename, "r", 1);

    IGRA *head;
    init_list(&head);

    read_list_from(in, &head);
    print_list(head);

    print_najbolja_IGRA(head);

    destroy_list(&head);

    fclose(in);

    return 0;
}
