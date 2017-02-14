#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CATEGORY 11
#define MAX_TYPE 8

typedef struct {
    char category[MAX_CATEGORY];
    char type[MAX_TYPE];
    unsigned transmission_speed;
    unsigned max_bandwidth;
    double price_per_meter;
} CABLE;

typedef struct node_st {
    CABLE inf;
    struct node_st *pleft;
    struct node_st *pright;
} NODE;

FILE *safe_fopen(const char *, const char *);
void read_file(FILE *, NODE **);
void print_cable(FILE *, CABLE);
void print_tree(FILE *, NODE *);
void print_similar(FILE *, NODE *, NODE *);
void print_by_type(FILE *, NODE *, const char *);

void init_tree(NODE **);
NODE *make_node(CABLE);
NODE *search_parent(NODE *, const char *);
NODE *search(NODE *, const char *);
void add_to_tree(NODE **, CABLE);
void destroy_tree(NODE **);


int main(int args_num, char **args) {
    NODE *proot;

    if(args_num != 5) {
        puts("USAGE: ./a.out ponuda.txt Cat5e 5 UTP");
        exit(EXIT_FAILURE);
    }

    // a)

    FILE *pin = safe_fopen(args[1], "r");

    init_tree(&proot);
    read_file(pin, &proot);
    fclose(pin);

    FILE *pout = safe_fopen("kablovi.txt", "w");

    print_tree(pout, proot);
    fclose(pout);

    // b)

    NODE *presult = search(proot, args[2]);

    if(presult != NULL) {
        char filename[strlen(args[2]) + strlen("_cena.txt") + 1];

        strcpy(filename, args[2]);
        strcat(filename, "_cena.txt");

        pout = safe_fopen(filename, "w");
        fprintf(pout, "%.2lf", presult->inf.price_per_meter * atof(args[3]));

        fclose(pout);

        pout = safe_fopen("odgovarajuci_kablovi.txt", "w");

        print_similar(pout, proot, presult);        

        fclose(pout);
    }

    // c)

    char filename[strlen(args[4]) + strlen(".txt") + 1];

    strcpy(filename, args[4]);
    strcat(filename, ".txt");

    pout = safe_fopen(filename, "w");
    print_by_type(pout, proot, args[4]);

    fclose(pout);

    destroy_tree(&proot);

    return EXIT_SUCCESS;
} 

FILE *safe_fopen(const char *name, const char *mode) {
    FILE *pf = fopen(name, mode);

    if(pf == NULL) {
        printf("File %s could not be opened. Program will now exit.\n", name);
        exit(EXIT_FAILURE);
    }

    return pf;
}

void read_file(FILE *pin, NODE **pproot) {
    CABLE temp;

    while(fscanf(pin, "%s %s %u %u %lf", temp.category,
                                         temp.type,
                                         &temp.transmission_speed,
                                         &temp.max_bandwidth,
                                         &temp.price_per_meter) != EOF) {
        add_to_tree(pproot, temp);
    }
}

void print_cable(FILE *pout, CABLE c) {
    fprintf(pout, "%s %s %u Mbps %u MHz %.2lf\n", c.category,
                                                  c.type,
                                                  c.transmission_speed,
                                                  c.max_bandwidth,
                                                  c.price_per_meter);
}

void print_tree(FILE *pout, NODE *proot) {
    if(proot != NULL) {
        print_tree(pout, proot->pleft);
        print_cable(pout, proot->inf);
        print_tree(pout, proot->pright);
    }
}

void print_similar(FILE *pout, NODE *proot, NODE *presult) {
    if(proot != NULL) {
        print_similar(pout, proot->pleft, presult);
        if(proot->inf.transmission_speed >= presult->inf.transmission_speed &&
           proot->inf.max_bandwidth >= proot->inf.max_bandwidth) {

            print_cable(pout, proot->inf); 
        }
        print_similar(pout, proot->pright, presult);
    }
}

void print_by_type(FILE *pout, NODE *proot, const char *type) {
    if(proot != NULL) {
        print_by_type(pout, proot->pleft, type);
        if(strstr(proot->inf.type, type) != NULL) {
            print_cable(pout, proot->inf);
        }
        print_by_type(pout, proot->pright, type);
    }
}

void init_tree(NODE **ppnode) {
    *ppnode = NULL;
}

NODE *make_node(CABLE c) {
    NODE *pnew = malloc(sizeof(NODE));

    if(pnew == NULL) {
        puts("Out of memory. Program will now exit.");
        exit(EXIT_FAILURE);
    }

    pnew->inf = c;
    pnew->pleft = NULL;
    pnew->pright = NULL;

    return pnew;
}

NODE *search_parent(NODE *proot, const char *category) {
    NODE *pcurrent = proot, *pprevious = NULL;

    while(pcurrent != NULL) {
        if(strcmp(category, pcurrent->inf.category) == 0) {
            break;
        }

        pprevious = pcurrent;

        if(strcmp(category, pcurrent->inf.category) < 0) {
            pcurrent = pcurrent->pleft;
        } else {
            pcurrent = pcurrent->pright;
        }
    }

    return pprevious;
}

NODE *search(NODE *proot, const char *category) {
    NODE *pcurrent = proot;

    while(pcurrent != NULL) {
        if(strcmp(category, pcurrent->inf.category) == 0) {
            break;
        }

        if(strcmp(category, pcurrent->inf.category) < 0) {
            pcurrent = pcurrent->pleft;
        } else {
            pcurrent = pcurrent->pright;
        }
    }

    return pcurrent;
}

void add_to_tree(NODE **pproot, CABLE c) {
    NODE *pparent = search_parent(*pproot, c.category);    
    NODE *pnew = make_node(c);

    if(pparent != NULL) {
        if(strcmp(c.category, pparent->inf.category) < 0) {
            pparent->pleft = pnew;
        } else {
            pparent->pright = pnew;
        }
    } else {
        *pproot = pnew;
    }
}

void destroy_tree(NODE **pproot) {
    if(*pproot != NULL) {
        destroy_tree(&(*pproot)->pleft);
        destroy_tree(&(*pproot)->pright);

        free(*pproot);
        *pproot = NULL;
    }
}
