#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 30

struct tacka_st {
    double x;
    double y;
    double z;
    double udaljenost_od_pocetka;
};

FILE *safe_fopen(char *, char *, int);
void ucitaj_tacke(FILE *, struct tacka_st *, int *);
void ispisi_tacke(FILE *, struct tacka_st *, int);
void ispisi_tacku(FILE *, struct tacka_st);

struct tacka_st najbliza_pocetku(struct tacka_st *, int);
struct tacka_st najdalja_od_pocetka(struct tacka_st *, int);

double udaljenost(struct tacka_st, struct tacka_st);
double udaljenost_od_pocetka(struct tacka_st);
double zapremina_kocke(double);

int main(int args_num, char **args) {
    struct tacka_st tacke[MAX_SIZE], pripadaju_krugu[MAX_SIZE];
    int n, m;

    if(args_num != 4) {
        printf("Primer poziva: ./a.out tacke.txt tacke_formatirano.txt 5");
        exit(EXIT_FAILURE);
    }

    FILE *pin = safe_fopen(args[1], "r", EXIT_FAILURE);
    ucitaj_tacke(pin, tacke, &n);
    fclose(pin);

    // a)
    
    FILE *pout = safe_fopen(args[2], "w", EXIT_FAILURE);
    ispisi_tacke(pout, tacke, n);
    fclose(pout);
    
    // b)
    
    double zapremina_koord_kocke = zapremina_kocke(
                                       udaljenost(najbliza_pocetku(tacke, n),
                                                  najdalja_od_pocetka(tacke, n)
                                       )
                                   );
    
    // c)
    
    double zapremina_arg_kocke = zapremina_kocke(atof(args[3]));
    char naziv[strlen("sracunata") +
               strlen("_kocka_minus_") +
               strlen("argument") +
               strlen("_kocka.txt") + 1];
               
    if(zapremina_koord_kocke > zapremina_arg_kocke) {
        strcpy(naziv, "sracunata_kocka_minus_argument_kocka.txt");
    } else {
        strcpy(naziv, "argument_kocka_minus_sracunata_kocka.txt");
    }
    
    pout = safe_fopen(naziv, "w", EXIT_FAILURE);
    fprintf(pout, "Zapremina sracunate kocke: %.2lf\n", zapremina_koord_kocke);
    fprintf(pout, "Zapremina argument kocke: %.2lf\n", zapremina_arg_kocke);
    fprintf(pout, "Razlika u zapreminama: %.2lf\n", 
            fabs(zapremina_arg_kocke - zapremina_koord_kocke));
    
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

    while(fscanf(pin, "%lf %lf %lf", &ptacke[i].x,
                                     &ptacke[i].y,
                                     &ptacke[i].z) != EOF) {
        ptacke[i].udaljenost_od_pocetka = udaljenost_od_pocetka(ptacke[i]);
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

void ispisi_tacku(FILE *pout, struct tacka_st t) {
    fprintf(pout, "(%.2lf, %.2lf, %.2lf), %.2lf\n", t.x, 
                                                    t.y, 
                                                    t.z, 
                                                    t.udaljenost_od_pocetka);
}

struct tacka_st najbliza_pocetku(struct tacka_st *ptacke, int n) {
    int i;
    struct tacka_st najbliza_tacka = ptacke[0];
    double min_udaljenost = udaljenost_od_pocetka(najbliza_tacka);
    
    for(i = 1;i < n;i++) {
        if(udaljenost_od_pocetka(ptacke[i]) < min_udaljenost) {
            min_udaljenost = udaljenost_od_pocetka(ptacke[i]);
            najbliza_tacka = ptacke[i];
        }
    }
    
    return najbliza_tacka;
}

struct tacka_st najdalja_od_pocetka(struct tacka_st *ptacke, int n) {
    int i;
    struct tacka_st najdalja_tacka = ptacke[0];
    double max_udaljenost = udaljenost_od_pocetka(najdalja_tacka);
    
    for(i = 1;i < n;i++) {
        if(udaljenost_od_pocetka(ptacke[i]) > max_udaljenost) {
            max_udaljenost = udaljenost_od_pocetka(ptacke[i]);
            najdalja_tacka = ptacke[i];
        }
    }
    
    return najdalja_tacka;
}

double udaljenost(struct tacka_st t1, struct tacka_st t2) {
    return sqrt(pow(t1.x - t2.x, 2) + 
                pow(t1.y - t2.y, 2) + 
                pow(t1.z - t2.z, 2));
}

double udaljenost_od_pocetka(struct tacka_st t) {
    return sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2));
}

double zapremina_kocke(double a) {
    return pow(a, 3);
}
