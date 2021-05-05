#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAZIV 13+1

typedef struct artikal_st {
    int serijski_broj;    
    char naziv[MAX_NAZIV];
    unsigned kolicina;
    double jedinicna_cena;
    double ukupna_cena;
    struct artikal_st *sledeci;
} ARTIKAL;

void init_list(ARTIKAL **head) {
    *head = NULL;
}

void add_to_list(ARTIKAL *new, ARTIKAL **head) {
    ARTIKAL *tek,*pret1;
    int nakraj=1;
    if(*head == NULL) {
        *head = new;
        return;
    }
    pret1=*head;
    tek=*head;

    if(new->serijski_broj < tek->serijski_broj)
    {
        new->sledeci=*head;
        *head=new;
        return;
    }

    while(tek != NULL)
    {
        if(new->serijski_broj < tek->serijski_broj)
        {
            nakraj=0;
            break;
        }
        pret1=tek;
        tek = tek->sledeci;
    }

    if(nakraj == 1)
        pret1 -> sledeci = new;
    else
    {
        new->sledeci = pret1->sledeci;
        pret1->sledeci = new;
    }
}

ARTIKAL *create_new_item(int ser_br, char naz[], unsigned kol, double jed_c){
    ARTIKAL *new = (ARTIKAL *)malloc(sizeof(ARTIKAL));
    if (new == NULL) {
        printf("Not enough RAM!\n");
        exit(21);
    }
    new->serijski_broj = ser_br;
    strcpy(new->naziv, naz);
    new->kolicina = kol;
    new->jedinicna_cena = jed_c;
    new->ukupna_cena = kol * jed_c;

    new->sledeci = NULL;

    return new;
}

void read_list_from(FILE *in, ARTIKAL **head) {
    int tmpSerBr;
    char tmpNaz[MAX_NAZIV];
    unsigned tmpKol;
    double tmpJedC;

    while(fscanf(in,"%lf %u %s %d",&tmpJedC,&tmpKol,tmpNaz,&tmpSerBr) != EOF)
    {
        ARTIKAL *new = create_new_item(tmpSerBr, tmpNaz, tmpKol, tmpJedC);
        add_to_list(new, head);
    }
}

void save_item_to(ARTIKAL *x) {
    printf("\t%d %s %.2lf\n", x->serijski_broj, x->naziv, x->ukupna_cena);
}

void save_list_to(ARTIKAL *head) {
    if(head != NULL) {
        save_item_to(head);
        save_list_to(head->sledeci);
    }
}

void destroy_list(ARTIKAL **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->sledeci));
        free(*head);
        *head = NULL;
    }
}

void korpa(ARTIKAL * head,double budzet)
{
    int kupljeno=0;

    if (head==NULL)
        return;

    while(head != NULL) {
        if(budzet-head->ukupna_cena >= 0)
        {
            kupljeno++;
            budzet-=head->ukupna_cena;
            save_item_to(head);
        }
        head = head->sledeci;
    }

    if(kupljeno == 0)
    {
        printf("Nemate dovoljno novca za kupovinu");
        printf(" nijednog od proizvoda iz ponude!\n");
        exit(333);
    }else
    {
        printf("\n\tUspesno ste kupili %d proizvoda.\n\t",kupljeno);
        printf("Na racunu vam je ostalo %.2lf din.\n",budzet);
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


//primer poziva ./a.out 22800 artikli.txt
int main(int arg_num, char *args[]) {
    if (arg_num != 3) {
        printf("Pogresan unos argumenata\n");
        exit(11);
    }

    if(atof(args[1]) < 0)
    {
        printf("Budzet mora biti pozitivan broj!\n");
        exit(22);
    }

    FILE *in  = safe_fopen(args[2],"r", 1);

    ARTIKAL *head;
    init_list(&head);

    read_list_from(in, &head);

    korpa(head,atof(args[1]));

    destroy_list(&head);

    fclose(in);

    return 0;
}
