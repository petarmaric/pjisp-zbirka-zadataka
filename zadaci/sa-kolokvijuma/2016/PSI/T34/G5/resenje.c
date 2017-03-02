#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 30

struct tacka_st {
    double x;
    double y;
};

FILE *safe_fopen(char *, char *, int);
void ucitaj_tacke(FILE *, struct tacka_st *, int *);
void ispisi_tacke(FILE *, struct tacka_st *, int);
void ispisi_tacku(FILE *, struct tacka_st);

unsigned prebroj_trouglove(struct tacka_st *, int);
struct tacka_st pronadji_teziste(struct tacka_st *, int);
void pripada_krugu(struct tacka_st *, struct tacka_st *, 
                   int, int *, struct tacka_st, double);

int obrazuju_trougao(struct tacka_st, struct tacka_st, struct tacka_st);
double udaljenost(struct tacka_st, struct tacka_st);

int main(int args_num, char **args) {
    struct tacka_st tacke[MAX_SIZE], pripadaju_krugu[MAX_SIZE];
    int n, m;

    if(args_num != 3) {
        printf("Primer poziva: ./a.out tacke.txt 5");
        exit(EXIT_FAILURE);
    }

    FILE *pin = safe_fopen(args[1], "r", EXIT_FAILURE);
    ucitaj_tacke(pin, tacke, &n);
    fclose(pin);

    // a)

    char naziv[strlen("pripada_krugu_poluprecnika_") + 
               strlen(args[2]) + 
               strlen(".txt") + 1];
    strcpy(naziv, "pripada_krugu_poluprecnika_");
    strcat(naziv, args[2]);
    strcat(naziv, ".txt");

    double r = atof(args[2]);
    struct tacka_st teziste = pronadji_teziste(tacke, n);

    FILE *pout = safe_fopen(naziv, "w", EXIT_FAILURE);
    fprintf(pout, "Krug poluprecnika %.2lf sa centrom u tacki ", r);
    ispisi_tacku(pout, teziste);
    fprintf(pout, "\n");

    // b)

    pripada_krugu(pripadaju_krugu, tacke, n, &m, teziste, r);
    ispisi_tacke(pout, pripadaju_krugu, m);

    fclose(pout);

    // c)

    pout = safe_fopen("trouglovi.txt", "w", EXIT_FAILURE);
    fprintf(pout, "Broj trouglova: %u\n", prebroj_trouglove(tacke, n));

    fclose(pout);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *pname, char *pmode, int error_code) {
    FILE *pf = fopen(pname, pmode);

    if(pf == NULL) {
        printf("Datoteka sa imenom %s nije uspesno otvorena.\n", pname);
        exit(error_code);
    }

    return pf;
}

void ucitaj_tacke(FILE *pin, struct tacka_st *ptacke, int *pn) {
    int i = 0;

    while(fscanf(pin, "%lf %lf", &ptacke[i].x,
                                 &ptacke[i].y) != EOF) {
        i++;
    }

    *pn = i;
}

void ispisi_tacke(FILE *pout, struct tacka_st *ptacke, int n) {
    int i;

    for(i = 0;i < n;i++) {
        ispisi_tacku(pout, ptacke[i]); 
    }
}

void ispisi_tacku(FILE *pout, struct tacka_st tacka) {
    fprintf(pout, "(%.2lf, %.2lf)\n", tacka.x, tacka.y);
}

unsigned prebroj_trouglove(struct tacka_st *ptacke, int n) {
    int i, j, k;
    unsigned broj_trouglova = 0;

    for(i = 0;i < n;i++) {
        for(j = i + 1;j < n;j++) {
            for(k = j + 1;k < n;k++) {
                if(obrazuju_trougao(ptacke[i],
                                    ptacke[j],
                                    ptacke[k])) {
                    broj_trouglova++;
                }            
            }
        }
    }

    return broj_trouglova;
}

struct tacka_st pronadji_teziste(struct tacka_st *ptacke, int n) {
    int i;
    double suma_x = 0, suma_y = 0;

    struct tacka_st tezisna_tacka;

    for(i = 0;i < n;i++) {
        suma_x += ptacke[i].x;
        suma_y += ptacke[i].y;
    }

    tezisna_tacka.x = suma_x / n;
    tezisna_tacka.y = suma_y / n;

    return tezisna_tacka;
}

void pripada_krugu(struct tacka_st *ppripada, struct tacka_st *ptacke, 
                   int n, int *pm, struct tacka_st centar, double r) {
    int i, j = 0;

    for(i = 0;i < n;i++) {
        if(udaljenost(ptacke[i], centar) <= r) {
            ppripada[j] = ptacke[i];
            j++;
        }
    }

    *pm = j;
}

int obrazuju_trougao(struct tacka_st t1, 
                     struct tacka_st t2, 
                     struct tacka_st t3) {
    double a = udaljenost(t1, t2);
    double b = udaljenost(t2, t3);
    double c = udaljenost(t1, t3);

    return (a + b > c) && (b + c > a) && (c + a > b);
}

double udaljenost(struct tacka_st t1, struct tacka_st t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}
