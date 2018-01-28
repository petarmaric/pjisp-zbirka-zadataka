#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV_GRAD 2+1
#define MAX_NAZIV_BIOSKOP 10+1
#define MAX_NAZIV_FILM 8+1
#define MAX_NAZIV_ZANR 9+1

typedef struct projekcija_st {
    char grad[MAX_NAZIV_GRAD];
    char bioskop[MAX_NAZIV_BIOSKOP];
    char film[MAX_NAZIV_FILM];
    char zanr[MAX_NAZIV_ZANR];
    double cena;
    struct projekcija_st *left;
    struct projekcija_st *right;
} PROJEKCIJA;

void init_tree(PROJEKCIJA **root) {
    *root = NULL;
}

void add_to_tree(PROJEKCIJA *new, PROJEKCIJA **root) {
    if(*root == NULL) { // tree is empty
        *root = new;
    } else if (new->cena <= (*root)->cena) {
        add_to_tree(new, &((*root)->left));
    } else {
        add_to_tree(new, &((*root)->right));
    }
}

PROJEKCIJA *create_new_item(char grad[], char bioskop[], char film[],
char zanr[], double cena) {
    PROJEKCIJA *new = (PROJEKCIJA *)malloc(sizeof(PROJEKCIJA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->grad, grad);
    strcpy(new->bioskop, bioskop);
    strcpy(new->film, film);
    strcpy(new->zanr, zanr);
    new->cena = cena;

    new->left = NULL;
    new->right = NULL;

    return new;
}

void read_tree_from(FILE *in, PROJEKCIJA **root) {
    char tmp_grad[MAX_NAZIV_GRAD];
    char tmp_bioskop[MAX_NAZIV_BIOSKOP];
    char tmp_film[MAX_NAZIV_FILM];
    char tmp_zanr[MAX_NAZIV_ZANR];
    double tmp_cena;

    while(fscanf(
        in, "%s %s %s %s %lf",
         tmp_grad,
         tmp_bioskop,
         tmp_film,
         tmp_zanr,
        &tmp_cena
    ) != EOF) {
        PROJEKCIJA *new = create_new_item(
            tmp_grad, tmp_bioskop, tmp_film, tmp_zanr, tmp_cena
        );
        add_to_tree(new, root);
    }
}

void save_item_to(FILE *out, PROJEKCIJA *x) {
    fprintf(
        out, "%2s %-10s %-8s %-9s %6.2f\n",
        x->grad, x->bioskop, x->film, x->zanr, x->cena
    );
}

void save_tree_to(FILE *out, PROJEKCIJA *root) {
    if(root != NULL) {
        save_tree_to(out, root->left);
        save_item_to(out, root);
        save_tree_to(out, root->right);
    }
}

void destroy_tree(PROJEKCIJA **root) {
    if(*root != NULL) {
        destroy_tree(&((*root)->left));
        destroy_tree(&((*root)->right));
        free(*root);
        *root = NULL;
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

PROJEKCIJA *get_najpovoljnija_projekcija(PROJEKCIJA *root, char grad[],
char zanr[]) {
    if (root == NULL) { // tree is empty
        return NULL;
    }

    PROJEKCIJA *best = NULL;
    if (strcmp(root->grad, grad) == 0 && strcmp(root->zanr, zanr) == 0) {
        // Gledamo samo projekcije koje su OK
        best = root;
    }

    PROJEKCIJA *left = get_najpovoljnija_projekcija(root->left, grad, zanr);
    if (left != NULL) {
        // Nadjena OK projekcija u levom podstablu
        if (best == NULL || left->cena < best->cena) {
            // Nadjena povoljnija projekcija, koja je OK
            best = left;
        }
    }

    // Posto stablo nije uredjeno po sva 3 kriterijuma, postoji mogucnost da se
    // trazena projekcija nalazi i u desnom podstablu
    PROJEKCIJA *right = get_najpovoljnija_projekcija(root->right, grad, zanr);
    if (right != NULL) {
        // Nadjena OK projekcija u desnom podstablu
        if (best == NULL || right->cena < best->cena) {
            // Nadjena povoljnija projekcija, koja je OK
            best = right;
        }
    }

    return best;
}

int main(int arg_num, char *args[]) {
    if (arg_num != 5) {
        printf("USAGE: %s GRAD ZANR IN_FILENAME OUT_FILENAME\n", args[0]);
        exit(11);
    }

    char *grad = args[1];
    char *zanr = args[2];
    char *in_filename = args[3];
    char *out_filename = args[4];

    FILE *in  = safe_fopen(in_filename,  "r", 1);
    FILE *out = safe_fopen(out_filename, "w", 2);

    PROJEKCIJA *root;
    init_tree(&root);

    read_tree_from(in, &root);
    save_tree_to(out, root);

    PROJEKCIJA *best = get_najpovoljnija_projekcija(root, grad, zanr);
    if (best == NULL) {
        fprintf(
            out, "\nNiko ne projektuje %s filmove u %s!\n",
            zanr, grad
        );
    } else {
        fprintf(
            out, "\nNajpovoljnija projekcija za %s filmove u %s je:\n%s %.2f\n",
            zanr, grad, best->film, best->cena
        );
    }

    destroy_tree(&root);

    fclose(in);
    fclose(out);

    return 0;
}
