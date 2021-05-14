#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REZERVISAO 26
#define MAX_NAZIV_BALETA 9

typedef struct balet {
    unsigned sediste;
    char nazivBaleta[MAX_NAZIV_BALETA];
	char rezervisao[MAX_REZERVISAO];
    unsigned cena;
    struct balet *next;
}BALET;

void init_list(BALET **head) {
    *head = NULL;
}

char *lower(char str[])
{
    int i;
	
    for(i=0; i<strlen(str); i++)
    {
        if(str[i] >= 65 && str[i] <= 90)
            str[i] = str[i]+32;
    }

    return str;
}

void add_to_list(BALET *new, BALET **head) {
    if(*head == NULL) { 
        *head = new;
        return;
    } 
    
    if((*head)->sediste > new->sediste) {
        new->next = *head;
        *head = new;
    } else {
        BALET* tek = *head;
        BALET* pret = *head;
        while(tek != NULL && tek->sediste < new->sediste) {
            pret = tek;
            tek = tek->next;
        }
        new -> next = pret -> next;
        pret -> next = new;
    }    
}

BALET *create_new_item(unsigned sediste, char nazivBaleta[], 
char rezervisao[], unsigned cena) {
    BALET *new = (BALET*)malloc(sizeof(BALET));
    if (new == NULL) {
        printf("Nema dovoljno memorije!\n");
        exit(21);
    }

	new->sediste = sediste;
	strcpy(new->rezervisao, rezervisao);
    strcpy(new->nazivBaleta, nazivBaleta);
    new->cena = cena;

    new->next = NULL;

    return new;
}

void read_list_from(FILE *in, BALET **head) {
    unsigned sediste;
	char rezervisao[MAX_REZERVISAO];
    char nazivBaleta[MAX_NAZIV_BALETA];
    unsigned cena;
    
    while(fscanf(in, "%u %s %s %u", &sediste, nazivBaleta, rezervisao, &cena)
		!= EOF) {
        BALET *new = create_new_item(sediste, nazivBaleta, rezervisao, cena);
        add_to_list(new, head);
    }
}
void save(int postoji, BALET *head, char naziv[]){
	char nazivBaleta[MAX_NAZIV_BALETA];
	if(postoji==1){
		while(head != NULL) {
		  	strcpy(nazivBaleta,head->nazivBaleta); 
	   		if (strcmp(lower(naziv),
			lower(head->nazivBaleta)) == 0) {
	   			printf("Sediste: %u \t Rezervisao: %s \t Cena: %u din\n",
				head->sediste, head->rezervisao, head->cena);
	   		}
	   		head = head->next;
	   	}
	}
}

void save_item_to(int *postoji, unsigned ukupnaCena, 
char naziv[], unsigned brojKarata) {
	if(*postoji==1){ 
		printf("\nUkupno prodatih karata za balet "
        "pod nazivom %s je %u.\n"
        "Ukupna zarada je %u dinara.\n\n", 
		    naziv, brojKarata, ukupnaCena);
	}
	else{
		printf("\nZa unete podatke od strane korisnika"
        " ne postoje podaci.\n\n");
	}
}

void destroy_list(BALET **head) {
    if(*head != NULL) {
        destroy_list(&((*head)->next));
        free(*head);
        *head = NULL;
    }
}

FILE *safe_fopen(char *filename, char *mode, int error_code) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("Nije moguce otvoriti datoteku '%s'!\n", filename);
        exit(error_code);
    }
    return fp;
}


void algoritam(char naziv[], BALET *head, int *postoji){
	unsigned ukupnaCena = 0;	
	unsigned brojKarata = 0;
	char nazivBaleta[MAX_NAZIV_BALETA];
	char nB[MAX_NAZIV_BALETA];
	
	
	if (head == NULL) { 
        return;	
    }
	

	while(head != NULL) {
		strcpy(nazivBaleta,head->nazivBaleta);  
		  
	   	if (strcmp(lower(naziv),lower(nazivBaleta)) == 0) {
			strcpy(nB, head->nazivBaleta);
			ukupnaCena += head->cena;
     		brojKarata++;
			*postoji=1;
			
        }	
		head = head->next;

	}
	save_item_to(postoji, ukupnaCena, nB, brojKarata);
}

int main(int arg_num, char *args[]) {
    if (arg_num != 2) {
        printf("Program treba pozvati na sledeci nacin: "
        "%s nazivUlazneDatoteke.txt\n", args[0]);
        exit(11);
    }
    
    int postoji=0;
    char *in_filename = args[1];

    FILE *in  = safe_fopen(in_filename,  "r", 1);

	char naziv[MAX_NAZIV_BALETA];

	printf("\nNaziv baleta: ");
	scanf("%s", naziv);

    BALET *head;
    init_list(&head);

    read_list_from(in, &head);
    
    algoritam(naziv, head, &postoji);
    save(postoji, head, naziv);
    destroy_list(&head);

    fclose(in);

    return 0;
}
