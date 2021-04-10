#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20 + 1
#define MAX_PROIZVODJAC 12 + 1

typedef struct brownie_st
{
    char naziv[MAX_NAZIV];
    unsigned kolicina;
    double cena;
    char proizvodjac[MAX_PROIZVODJAC];

    struct brownie_st *left;
    struct brownie_st *right;
} BROWNIE;

void init_tree(BROWNIE **root)
{
    *root = NULL;
}

void add_to_tree(BROWNIE *new, BROWNIE **root)
{
    if (*root == NULL)
    {
        *root = new;
    }
    else if (strcmp(new->naziv, (*root)->naziv) < 0)
    {
        add_to_tree(new, &((*root)->left));
    }
    else
    {
        add_to_tree(new, &((*root)->right));
    }
}

BROWNIE *create_new_item(
    char naziv[],
    unsigned kolicina,
    double cena,
    char proizvodjac[])
{
    BROWNIE *new = (BROWNIE *)malloc(sizeof(BROWNIE));
    if (new == NULL)
    {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->kolicina = kolicina;
    new->cena = cena;
    strcpy(new->proizvodjac, proizvodjac);
    new->left = NULL;
    new->right = NULL;

    return new;
}

double price(BROWNIE *x)
{
    return x->cena * x->kolicina / 100;
}

void read_tree_from(FILE *in, BROWNIE **root, double *ukupna_cena)
{
    char naziv[MAX_NAZIV];
    unsigned kolicina;
    double cena;
    char proizvodjac[MAX_PROIZVODJAC];

    while (
        fscanf(
            in,
            "%s %u %lf %s",
            naziv,
            &kolicina,
            &cena,
            proizvodjac) != EOF)
    {
        BROWNIE *new = create_new_item(naziv, kolicina, cena, proizvodjac);
        add_to_tree(new, root);
        *ukupna_cena += price(new);
    }
}

void save_item_to(FILE *out, BROWNIE *x)
{
    fprintf(
        out, "%s %u %.3lf\n",
        x->naziv, x->kolicina, price(x));
}

void save_tree_to(FILE *out, BROWNIE *root)
{
    if (root != NULL)
    {
        save_tree_to(out, root->left);
        save_item_to(out, root);
        save_tree_to(out, root->right);
    }
}

void destroy_tree(BROWNIE **root)
{
    if (*root != NULL)
    {
        destroy_tree(&((*root)->left));
        destroy_tree(&((*root)->right));
        free(*root);
        *root = NULL;
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

void print_price_to(FILE *out, double ukupna_cena)
{
    fprintf(out, "\nUkupna cena namirnica je: %.3lf\n", ukupna_cena);
}

void print_best_to(FILE *out, char *proizvodjac, char *best)
{
    fprintf(
        out,
        "Namirnica sa najvecom gramazom proizvodjaca %s je: %s\n",
        proizvodjac,
        best);
}

BROWNIE *get_najveca_gramaza(BROWNIE *root, char proizvodjac[])
{
    if (root == NULL)
    {
        return NULL;
    }

    BROWNIE *best = NULL;
    if (strcmp(root->proizvodjac, proizvodjac) == 0)
    {
        best = root;
    }

    BROWNIE *left = get_najveca_gramaza(root->left, proizvodjac);
    if (left != NULL)
    {
        if (best == NULL || left->kolicina > best->kolicina)
        {
            best = left;
        }
    }
    BROWNIE *right = get_najveca_gramaza(root->right, proizvodjac);
    if (right != NULL)
    {
        if (best == NULL || right->kolicina > best->kolicina)
        {
            best = right;
        }
    }

    return best;
}

int main(int arg_num, char *args[])
{
    if (arg_num != 4)
    {
        printf("USAGE: %s IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *in_filename = args[1];
    char *out_filename = args[2];
    char *proizvodjac = args[3];

    FILE *in = safe_fopen(in_filename, "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    BROWNIE *root;
    init_tree(&root);

    double ukupna_cena = 0;
    read_tree_from(in, &root, &ukupna_cena);

    save_tree_to(out, root);
    print_price_to(out, ukupna_cena);

    BROWNIE *best = get_najveca_gramaza(root, proizvodjac);
    if (best != NULL)
    {
        print_best_to(out, proizvodjac, best->naziv);
    }

    destroy_tree(&root);

    fclose(in);
    fclose(out);

    return 0;
}
