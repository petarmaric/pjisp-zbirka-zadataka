#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 8+1
#define MAX_ZASTICENA 11+1

typedef struct zivotinja_st { 
    char naziv[MAX_NAZIV];
    double prosecna_starost;
    int broj_jedinki ;
    char zasticena[MAX_ZASTICENA];
    struct zivotinja_st *sledeci;
}ZIVOTINJA;

void init_list(ZIVOTINJA **head) {
    *head = NULL;
}

void add_to_list(ZIVOTINJA *new, ZIVOTINJA **head) {    
    if(*head == NULL) { 
        *head = new;
        return;
    }
    add_to_list(new,&((*head)->sledeci));
}

ZIVOTINJA *create_new_item(char naziv[], double ps, int broj_jed) {
    ZIVOTINJA *new = (ZIVOTINJA *)malloc(sizeof(ZIVOTINJA));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }

    strcpy(new->naziv, naziv);
    new->prosecna_starost = ps;
    new->broj_jedinki = broj_jed;

    if(broj_jed < 300)
        strcpy(new->zasticena,"zasticena");
    else
        strcpy(new->zasticena,"nezasticena");

    new->sledeci = NULL;

    return new;
}

void read_list_from(FILE *in, ZIVOTINJA **head) {
    char tmp_naziv[MAX_NAZIV];
    double tmp_ps;
    int tmp_broj_jed;

    while(fscanf(in,"%lf %s %d",&tmp_ps,tmp_naziv,&tmp_broj_jed) != EOF)
    {
        ZIVOTINJA *new = create_new_item(tmp_naziv, tmp_ps, tmp_broj_jed);
        add_to_list(new, head);
    }
}

void save_item_to(ZIVOTINJA *x) {
    printf("\t%s %.1lf %d %s\n", 
        x->naziv, x->prosecna_starost,
        x->broj_jedinki, x->zasticena);
}

void save_list_to(ZIVOTINJA *head) {
    if(head != NULL) {
        save_item_to(head);
        save_list_to(head->sledeci);
    }
}

void destroy_list(ZIVOTINJA **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->sledeci));
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

void najugrozenija(ZIVOTINJA *head)
{
        if(head==NULL)
            return;

        ZIVOTINJA *ugrozena=head;

        while(head!=NULL)
        {
            if(head->broj_jedinki < ugrozena->broj_jedinki)
                ugrozena=head;

            head = head->sledeci;
        }

        printf("\n\tTrenutno najugrozenija zivotinja je:\n");
        save_item_to(ugrozena);
}

//primer poziva ./a.out zivotinje.txt
int main(int arg_num, char *args[]) {
    if (arg_num != 2) {
        printf("Pogresan unos argumenata\n");
        exit(11);
    }

    FILE *in  = safe_fopen(args[1],"r", 1);

    ZIVOTINJA *head;
    init_list(&head);

    read_list_from(in, &head);
    save_list_to(head);

    najugrozenija(head);

    destroy_list(&head);

    fclose(in);

    return 0;
}
