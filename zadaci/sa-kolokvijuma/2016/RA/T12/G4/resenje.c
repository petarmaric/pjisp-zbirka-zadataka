#include <stdio.h>
#include <math.h>
#define MAX_SIZE 20

int main() {
  int array[MAX_SIZE], i, n, sum = 0, count = 0;
  float solution[MAX_SIZE];

  do {
      printf("Uneti velicinu niza: ");
      scanf("%d", &n);
  } while(n <= 0 || n > MAX_SIZE);

  for(i = 0;i < n;i++) {
    do {
      printf("niz[%d] = ", i+1);
      scanf(" %d", &array[i]);
    } while (n<=0);

    sum += array[i];

    if((i+1) % 2 == 0 && array[i] % 3 == 0)
      count++;
  }

  printf("\nHs = %.2f\n", sum*1.0/n);
  printf("Ukupan broj elemenata na parnim indeksima"); 
  printf("(indeksi pocinju od 1) deljivih sa 3 iznosi %d.\n", count);

  for (i = 0; i < n; i++) {
    if(array[i]<15) {
      solution[i] = 4.0 / array[i]*array[i] + 3.0 / (array[i] + 1);
    } else if (array[i] <= 30) {
      solution[i] = 4 * pow(array[i], 1.0/3) + 4 * array[i] - 3;
    } else {
      solution[i] = pow(array[i], 5);
    }
  }

  printf("A: [" );
  for(i = 0;i < n;i++) {
      if(i > 0) {
          printf(", ");
      }
      printf("%d", array[i]);
  }
  printf("]\n");

  printf("B: [" );
  for(i = 0;i < n;i++) {
      if(i > 0) {
          printf(", ");
      }
      printf("%.2f", solution[i]);
  }
  printf("]\n");

  return 0;
}
