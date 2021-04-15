#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct auto_st {
  char model[21];
  char servis[21];
  unsigned budzet;
  unsigned kubikaza;
}AUTO;

FILE* otvori(char *ime, char *mode){
  FILE* fp = fopen(ime, mode);
  
  if(fp==NULL) {
    printf("Doslo je do greske prilikom otvaranja datoteke %s", 
      ime);
    exit(EXIT_FAILURE);
  }
  return fp;

}

int ucitaj(FILE* in, AUTO* auti) {
  int i = 0;
  
  while(fscanf(in, "%s %s %u %u", auti[i].model, 
          auti[i].servis, 
          &auti[i].kubikaza, 
          &auti[i].budzet)!=EOF) {
    i++;
  }
  
  return i;

}
void ispisi_auto(AUTO automobil) {
  printf("%s %s %u %u\n", automobil.model, 
        automobil.servis, 
        automobil.kubikaza,
        automobil.budzet);
}

void ispisi(AUTO* auti, int n) {
  int i;
  for(i=0;i<n;i++) {
    if(auti[i].kubikaza < 1300 && 
      strcmp(auti[i].servis, "MALI")== 0 && 
      auti[i].budzet >= 5000) {
        ispisi_auto(auti[i]);
    } else if(auti[i].kubikaza < 1300 && 
      strcmp(auti[i].servis, "VELIKI")== 0 && 
      auti[i].budzet >= 10000) {
        ispisi_auto(auti[i]);
    }
     else if(auti[i].kubikaza >= 1300 && 
      auti[i].kubikaza < 1800 && 
      strcmp(auti[i].servis, "MALI")== 0 && 
      auti[i].budzet >= 8000) {
        ispisi_auto(auti[i]);

    } else if(auti[i].kubikaza >= 1300 && 
      auti[i].kubikaza < 1800 && 
      strcmp(auti[i].servis, "VELIKI")== 0 && 
      auti[i].budzet >= 15000) {
        ispisi_auto(auti[i]);
    }
     else if (auti[i].kubikaza >= 1800 && 
      strcmp(auti[i].servis, "MALI")== 0 && 
      auti[i].budzet >= 12000) {
        ispisi_auto(auti[i]);
     } else if (auti[i].kubikaza >= 1800 && 
      strcmp(auti[i].servis, "VELIKI")== 0 && 
      auti[i].budzet >= 25000) {
        ispisi_auto(auti[i]);
     }
  }
}

int main(int brArg, char* args[]) {

  if(brArg!=2) {
    printf("Program nije dobro pozvan");
    exit(EXIT_FAILURE);
  }
  
  FILE *in = otvori(args[1], "r");
  AUTO auti[20];
  int n = ucitaj(in, auti);
  ispisi(auti, n);
  
  fclose(in);
  return 0;
}

