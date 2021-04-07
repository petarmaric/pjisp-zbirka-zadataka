#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_STRING 21

typedef struct igraci_st {
    char ime[MAX_STRING];
    int bodovi;
} IGRACI;

FILE *safe_fopen(char *, char *);
void ucitaj_igrace(IGRACI *, int);
void dodaj_bodove(IGRACI *, int, int);
void ispis_bodova(FILE *, IGRACI *, int);

int main(int argc, char *argv[]) {
  IGRACI igraci[MAX_SIZE];

  if(argc != 3) {
      printf("Primer poziva programa: ./%s 2 3\n", argv[0]);
      exit(1);
  }

  int broj_igraca = atoi(argv[1]);
  int broj_partija = atoi(argv[2]);
  FILE *out = safe_fopen("bodovi.txt", "w");

  ucitaj_igrace(igraci, broj_igraca);
  dodaj_bodove(igraci, broj_igraca, broj_partija);
  ispis_bodova(out, igraci, broj_igraca);

  fclose(out);

  return 0;
}

FILE *safe_fopen(char *filename, char *mode) {
    FILE *fp = fopen(filename, mode);

    if(fp == NULL) {
        printf("Datoteka %s nije uspesno otvorena!\n", filename);
        exit(1);
    }

    return fp;
}

void ucitaj_igrace(IGRACI *igraci, int broj_igraca) {
    int i;

    for(i = 0;i < broj_igraca;i++) {
        printf("Igrac %d: ", i + 1);
        
        // Moze ili gets(igraci[i].ime); ili scanf("%s", igraci[i].ime);
        fgets(igraci[i].ime, MAX_STRING, stdin);

        // Eliminisanje trailing newline-a (ne treba u slucaju gets ili scanf)
        igraci[i].ime[strlen(igraci[i].ime) - 1] = '\0';
        igraci[i].bodovi = 0;
    }

}

void dodaj_bodove(IGRACI *igraci, int broj_igraca, int broj_partija) {
    int i, j, bodovi;

    for(j = 0;j < broj_partija;j++) {
        printf("\nPartija %d\n", j + 1);
        for(i = 0;i < broj_igraca;i++) {
            printf("Igrac %s: ", igraci[i].ime);
            scanf("%d", &bodovi);
            igraci[i].bodovi += bodovi;
        }
    }
}

void ispis_bodova(FILE *out, IGRACI *igraci, int broj_igraca) {
    int i;

    for(i = 0;i < broj_igraca;i++) {
        fprintf(out, "%s %d\n", igraci[i].ime, igraci[i].bodovi);
    }
}
