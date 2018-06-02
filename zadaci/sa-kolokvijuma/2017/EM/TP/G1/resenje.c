#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 10+1
#define MAX_VRSTA 20+1

typedef struct restoran_st {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    double ocena;

    struct restoran_st *left;
    struct restoran_st *right;
} RESTORAN;

void init_tree(RESTORAN **root) {
    *root = NULL;
}

void add_to_tree(RESTORAN *new, RESTORAN **root) {
    if(*root == NULL) { // tree is empty
        *root = new;
    } else if (new->ocena >= (*root)->ocena) {
        add_to_tree(new, &((*root)->left));
    } else {
        add_to_tree(new, &((*root)->right));
    }
}

RESTORAN *create_new_item(char naziv[], char vrsta[], double ocena) {
    RESTORAN *new = (RESTORAN *)malloc(sizeof(RESTORAN));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    strcpy(new->vrsta, vrsta);
    new->ocena = ocena;

    new->left = NULL;
    new->right = NULL;

    return new;
}

void read_tree_from(FILE *in, RESTORAN **root) {
    char naziv[MAX_NAZIV];
    char vrsta[MAX_VRSTA];
    double ocena;

    while(fscanf(in, "%s %s %lf", naziv, vrsta, &ocena) != EOF) {
        RESTORAN *new = create_new_item(naziv, vrsta, ocena);
        add_to_tree(new, root);
    }
}

void save_item_to(FILE *out, RESTORAN *x) {
    fprintf(
        out, "%3.1f %-10s %s\n",
        x->ocena, x->naziv, x->vrsta
    );
}

void save_tree_to(FILE *out, RESTORAN *root) {
    if(root != NULL) {
        save_tree_to(out, root->left);
        save_item_to(out, root);
        save_tree_to(out, root->right);
    }
}

void destroy_tree(RESTORAN **root) {
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

RESTORAN *get_najgori_restoran(RESTORAN *root) {
    if (root == NULL) { // tree is empty
        return NULL;
    }

    // Stablo je uredjeno po kljucu "ocena", u opadajucem redosledu.
    // Stoga se najgore ocenjen restoran sigurno nalazi u krajnje desnom listu.

    if (root->right == NULL) {
        // ovaj "root" je krajnje desni list, posto nema desno dete
        return root;
    }

    // Trazi dalje, *sigurno* ima jos gorih restorana
    return get_najgori_restoran(root->right);
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

    RESTORAN *root;
    init_tree(&root);

    read_tree_from(in, &root);
    save_tree_to(out, root);

    RESTORAN *worst = get_najgori_restoran(root);
    if (worst != NULL) {
        fprintf(out, "\nNajgore ocenjen restoran u gradu je:\n");
        save_item_to(out, worst);
    }

    destroy_tree(&root);

    fclose(in);
    fclose(out);

    return 0;
}
