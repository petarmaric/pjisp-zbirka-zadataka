#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30

#define MAX_NAME 31

struct tim_st {
    char naziv_tima[MAX_NAME];
    int gol_razlika;
    unsigned broj_bodova;
};

FILE *safe_fopen(char *, char *, int);
void ucitaj_iz_fajla(FILE *, struct tim_st *, int *);
void ispis_u_fajl(FILE *, struct tim_st *, int, int, int);

unsigned suma_bodova(struct tim_st *, int);
double prosek_bodova(struct tim_st *, int);
void u_intervalu(struct tim_st *, struct tim_st *, int, int *, unsigned);
void sortiranje(struct tim_st *, int);
unsigned racunanje_bodova(unsigned, unsigned, unsigned);

int main(int args_num, char **args) {
    struct tim_st tabela[MAX_SIZE];
    int n;

    if(args_num != 4) {
        puts("Primer poziva: ./a.out statistika.txt tabela.txt 25");
        exit(EXIT_FAILURE);
    }

    FILE *pin = safe_fopen(args[1], "r", EXIT_FAILURE);

    // a)

    ucitaj_iz_fajla(pin, tabela, &n);

    fclose(pin);

    // b)

    struct tim_st timovi_u_intervalu[MAX_SIZE];
    int m;

    char naziv[strlen("izmedju_proseka_i_") + 
                      strlen(args[3]) + 
                      strlen("_bodova.txt")];
    strcpy(naziv, "izmedju_proseka_i_");
    strcat(naziv, args[3]);
    strcat(naziv, "_bodova.txt");

    FILE *pout = safe_fopen(naziv, "w", EXIT_FAILURE);

    u_intervalu(timovi_u_intervalu, tabela, n, &m, atoi(args[3]));
    ispis_u_fajl(pout, timovi_u_intervalu, 0, m, m);

    fclose(pout);

    // c)

    pout = safe_fopen(args[2], "w", EXIT_FAILURE);

    sortiranje(tabela, n);

    ispis_u_fajl(pout, tabela, 0, 3, n);
    fprintf(pout, "-------------------\n");
    ispis_u_fajl(pout, tabela, 3, 5, n);
    fprintf(pout, "-------------------\n");
    ispis_u_fajl(pout, tabela, 5, n - 3, n);
    fprintf(pout, "-------------------\n");
    ispis_u_fajl(pout, tabela, n - 3, n, n);

    fclose(pout);

    return 0;
}

FILE *safe_fopen(char *pname, char *pmode, int error_code) {
    FILE *pf = fopen(pname, pmode);

    if(pf == NULL) {
        printf("Datoteka sa imenom %s nije uspesno otvorena.\n", pname);
        exit(error_code);
    }

    return pf;
}

void ucitaj_iz_fajla(FILE *pin, struct tim_st *ptimovi, int *pn) {
    int i = 0;
    unsigned pobede, nereseno, porazi;

    while(fscanf(pin, "%s %d %u %u %u", ptimovi[i].naziv_tima,
                                        &ptimovi[i].gol_razlika,
                                        &pobede,
                                        &nereseno,
                                        &porazi) != EOF) {
        ptimovi[i].broj_bodova = racunanje_bodova(pobede, nereseno, porazi);
        i++;
    }

    *pn = i;
}

void ispis_u_fajl(FILE *pout, struct tim_st *ptimovi, 
                  int od_tima, int do_tima, int n) {
    int i;

    if(od_tima >= 0 && do_tima <= n) {
        for(i = od_tima;i < do_tima;i++) {
            fprintf(pout, "%s %d %u\n", ptimovi[i].naziv_tima,
                                        ptimovi[i].gol_razlika,
                                        ptimovi[i].broj_bodova);
        }
    }
}

unsigned suma_bodova(struct tim_st *ptimovi, int n) {
    int i;
    unsigned s = 0;

    for(i = 0;i < n;i++) {
        s += ptimovi[i].broj_bodova;
    }

    return s;
}

double prosek_bodova(struct tim_st *ptimovi, int n) {
    return (double)suma_bodova(ptimovi, n) / n;
}

void u_intervalu(struct tim_st *ptimovi_u_intervalu, struct tim_st *ptimovi, 
                 int n, int *pm, unsigned gornja_granica) {
    int i;
    double donja_granica = prosek_bodova(ptimovi, n);

    for(i = 0;i < n;i++) {
        if(ptimovi[i].broj_bodova >= donja_granica && 
           ptimovi[i].broj_bodova <= gornja_granica) {
            ptimovi_u_intervalu[*pm] = ptimovi[i];
            (*pm)++;
        }
    }
}

void sortiranje(struct tim_st *ptimovi, int n) {
    int i, j;
    struct tim_st tmp;

    for(i = 0;i < n - 1;i++) {
        for(j = i + 1;j < n;j++) {
            if(ptimovi[i].broj_bodova < ptimovi[j].broj_bodova || 
              (ptimovi[i].broj_bodova == ptimovi[j].broj_bodova && 
               ptimovi[i].gol_razlika < ptimovi[j].gol_razlika)) {
                tmp = ptimovi[i];
                ptimovi[i] = ptimovi[j];
                ptimovi[j] = tmp;
            }
        }
    }
}

unsigned racunanje_bodova(unsigned pobede, unsigned nereseno, unsigned porazi) {
    return 3 * pobede + 1 * nereseno + 0 * porazi;
}
