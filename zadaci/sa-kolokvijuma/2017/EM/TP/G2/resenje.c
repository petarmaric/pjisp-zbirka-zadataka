#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 13+1
#define MAX_VRSTA 10+1

typedef struct namirnica_st {
    char naziv[MAX_NAZIV];
    unsigned kolicina;
    char vrsta[MAX_VRSTA];

    struct namirnica_st *left;
    struct namirnica_st *right;
} NAMIRNICA;

void init_tree(NAMIRNICA **root) {
    *root = NULL;
}

void add_to_tree(NAMIRNICA *new, NAMIRNICA **root) {
    if(*root == NULL) { // tree is empty
        *root = new;
    } else if (new->kolicina >= (*root)->kolicina) {
        add_to_tree(new, &((*root)->left));
    } else {
        add_to_tree(new, &((*root)->right));
    }
}

NAMIRNICA *create_new_item(char naziv[], unsigned kolicina, char vrsta[]) {
    NAMIRNICA *new = (NAMIRNICA *)malloc(sizeof(NAMIRNICA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->kolicina = kolicina;
    strcpy(new->vrsta, vrsta);

    new->left = NULL;
    new->right = NULL;

    return new;
}

void read_tree_from(FILE *in, NAMIRNICA **root) {
    char naziv[MAX_NAZIV];
    unsigned kolicina;
    char vrsta[MAX_VRSTA];

    while(fscanf(in, "%s %u %s", naziv, &kolicina, vrsta) != EOF) {
        NAMIRNICA *new = create_new_item(naziv, kolicina, vrsta);
        add_to_tree(new, root);
    }
}

void save_item_to(FILE *out, NAMIRNICA *x) {
    fprintf(
        out, "%3u %-13s %s\n",
        x->kolicina, x->naziv, x->vrsta
    );
}

void save_tree_to(FILE *out, NAMIRNICA *root) {
    if(root != NULL) {
        save_tree_to(out, root->left);
        save_item_to(out, root);
        save_tree_to(out, root->right);
    }
}

void destroy_tree(NAMIRNICA **root) {
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

NAMIRNICA *get_najbolja_namirnica(NAMIRNICA *root) {
    if (root == NULL) { // tree is empty
        return NULL;
    }

    // Stablo je uredjeno po kljucu "kolicina", u opadajucem redosledu.
    // Stoga se namirnica sa najvise vitamina C sigurno nalazi u krajnje levom
    // listu.

    if (root->left == NULL) {
        // ovaj "root" je krajnje levi list, posto nema levo dete
        return root;
    }

    // Trazi dalje, *sigurno* ima namirnica sa jos vise vitamina C
    return get_najbolja_namirnica(root->left);
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

    NAMIRNICA *root;
    init_tree(&root);

    read_tree_from(in, &root);
    save_tree_to(out, root);

    NAMIRNICA *best = get_najbolja_namirnica(root);
    if (best != NULL) {
        fprintf(out, "\nNamirnica sa najvise vitamina C je:\n");
        save_item_to(out, best);
    }

    destroy_tree(&root);

    fclose(in);
    fclose(out);

    return 0;
}
