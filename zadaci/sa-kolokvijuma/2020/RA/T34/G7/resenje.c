#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct tim_st {
  char drzava[21];
  char vrsta[21];
  float publika;
  float ziri;
}TIM;

FILE* otvori(char *ime, char *mode){
  FILE* fp = fopen(ime, mode);
  
  if(fp==NULL) {
    printf("Doslo je do greske prilikom otvaranja datoteke %s",
    ime);
    exit(EXIT_FAILURE);
  }
  return fp;

}

int ucitaj(FILE* in, TIM* timovi) {
  int i = 0;
  
  while(fscanf(in, "%s %s %f %f", timovi[i].drzava, 
          timovi[i].vrsta, 
          &timovi[i].publika, 
          &timovi[i].ziri)!=EOF) {
    i++;
  }
  
  return i;

}

void ispisi(TIM* timovi, int n, float granica) {
  int i, brojac = 0;
  float suma = 0;
  for(i=0;i<n;i++) {
    if(timovi[i].publika + timovi[i].ziri > granica) {
     printf("%s %s %.1f %.1f\n", timovi[i].drzava, 
               timovi[i].vrsta, 
               timovi[i].publika, 
               timovi[i].ziri);
     suma += timovi[i].publika + timovi[i].ziri;
     brojac++;
    } 
  }
  printf("Prosecna ocena timova koji su prosli u sledeci " 
      "krug takmicenja je: %.2f\n", suma/brojac);
}

int main(int brArg, char* args[]) {

  if(brArg!=3) {
    printf("Program nije dobro pozvan");
    exit(EXIT_FAILURE);
  }
  
  FILE *in = otvori(args[1], "r");
  TIM timovi[20];
  int n = ucitaj(in, timovi);
  ispisi(timovi, n, atof(args[2]));
  
  fclose(in);
  return 0;
}
