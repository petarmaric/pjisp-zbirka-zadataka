#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 20 + 1

typedef struct vatromet_st
{
    char naziv[MAX_NAZIV];
    unsigned glasnoca;
    unsigned cena;

    struct vatromet_st *left;
    struct vatromet_st *right;
} vatromet;

void init_tree(vatromet **root)
{
    *root = NULL;
}

void add_to_tree(vatromet *new, vatromet **root)
{
    if (*root == NULL)
    {
        *root = new;
    }
    else if (new->cena <= (*root)->cena)
    {
        add_to_tree(new, &((*root)->left));
    }
    else
    {
        add_to_tree(new, &((*root)->right));
    }
}

vatromet *create_new_item(char naziv[], unsigned glasnoca, unsigned cena)
{
    vatromet *new = (vatromet *)malloc(sizeof(vatromet));
    if (new == NULL)
    {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->glasnoca = glasnoca;
    new->cena = cena;
    new->left = NULL;
    new->right = NULL;

    return new;
}

void read_tree_from(FILE *in, vatromet **root)
{
    char naziv[MAX_NAZIV];
    unsigned glasnoca;
    unsigned cena;

    while (fscanf(in, "%s %u %u", naziv, &glasnoca, &cena) != EOF)
    {
        vatromet *new = create_new_item(naziv, glasnoca, cena);
        add_to_tree(new, root);
    }
}

void save_item_to(FILE *out, vatromet *x)
{
    fprintf(out, "%u %s %u\n", x->cena, x->naziv, x->glasnoca);
}

void save_tree_to(FILE *out, vatromet *root, unsigned max_glasnoca)
{
    if (root == NULL)
    {
        return;
    }
    save_tree_to(out, root->left, max_glasnoca);
    if (root->glasnoca <= max_glasnoca)
    {
        save_item_to(out, root);
    }
    save_tree_to(out, root->right, max_glasnoca);
}

void destroy_tree(vatromet **root)
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

double bang_for_buck(vatromet *root)
{
    return ((double)root->glasnoca) / root->cena;
}

vatromet *get_najbolji_vatromet(vatromet *root, unsigned max_glasnoca)
{
    if (root == NULL)
    {
        return NULL;
    }

    vatromet *best = NULL;
    if (root->glasnoca <= max_glasnoca)
    {
        best = root;
    }

    vatromet *left = get_najbolji_vatromet(root->left, max_glasnoca);
    if (left != NULL && (best == NULL || left->cena < best->cena))
    {
        best = left;
    }

    vatromet *right = get_najbolji_vatromet(root->right, max_glasnoca);
    if (right != NULL && (best == NULL || right->cena < best->cena))
    {
        best = right;
    }

    return best;
}

int main(int arg_num, char *args[])
{
    if (arg_num != 4)
    {
        printf("USAGE: %s MAX_GLASNOCA IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    unsigned max_glasnoca = atoi(args[1]);
    char *in_filename = args[2];
    char *out_filename = args[3];

    FILE *in = safe_fopen(in_filename, "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    vatromet *root;
    init_tree(&root);

    read_tree_from(in, &root);
    save_tree_to(out, root, max_glasnoca);

    vatromet *best = get_najbolji_vatromet(root, max_glasnoca);
    if (best != NULL)
    {
        fprintf(
            out,
            "\nNajbolji vatromet sa odnosom glasnoce prema ceni od %.2lf je:\n",
            bang_for_buck(best));
        save_item_to(out, best);
    }

    destroy_tree(&root);

    fclose(in);
    fclose(out);

    return 0;
}
