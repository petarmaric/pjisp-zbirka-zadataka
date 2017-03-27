#include <stdio.h>
#define MAX_SIZE 50

int main() {
  char DNA_part[MAX_SIZE];
  char DNA_part_parallel[MAX_SIZE];
  char base;
  int i, n, base_count = 0, h_bond = 0;

  do {
      printf("Uneti velicinu niza: ");
      scanf("%d", &n);
  } while(n <= 0 || n > MAX_SIZE);

  for(i = 0;i < n;i++) {
    do {
      printf("DNK[%d] = ", i+1);
      scanf(" %c", &DNA_part[i]);
    } while (!(DNA_part[i] == 'A' || DNA_part[i] == 'G' 
             || DNA_part[i] == 'T' || DNA_part[i] == 'C'));
  }

  do {
    printf("Uneti jednu DNK bazu: ");
    scanf(" %c", &base);
  } while (!(base == 'A' || base == 'G' || base == 'T' || base == 'C'));

  for (i = 0; i < n; i++) {
    if(DNA_part[i] == base)
      base_count++;

    if(DNA_part[i] == 'A') {
      h_bond+=2;
      DNA_part_parallel[i] = 'T';
    } else if(DNA_part[i] == 'T') {
      h_bond+=2;
      DNA_part_parallel[i] = 'A';
    } else if (DNA_part[i] == 'G') {
      h_bond+=3;
      DNA_part_parallel[i] = 'C';
    } else {
      h_bond+=3;
      DNA_part_parallel[i] = 'G';
    }


  }

  printf("Baza %c predstavlja ", base); 
  printf("%.0f%% ovog lanca DNK.\n", base_count * 1.0 / n * 100);

  printf("U unetom delu DNK nalazi se ukupno %d vodonicne veze.\n", h_bond);

  printf("Paralelan lanac unetom DNK izgleda ovako:\n[" );
  for(i = 0;i < n;i++) {
      if(i > 0) {
          printf(", ");
      }
      printf("%c", DNA_part_parallel[i]);
  }
  printf("]\n");

  return 0;
}
