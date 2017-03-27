#include <stdio.h>
#define MAX_SIZE 20

int main(){
  int array[MAX_SIZE], i, n, min, even_count = 0, even_sum = 0;

  do {
      printf("Uneti velicinu niza: ");
      scanf("%d", &n);
  } while(n <= 0 || n > MAX_SIZE);

  for(i = 0;i < n;i++) {
    printf("niz[%d] = ", i+1);
    scanf(" %d", &array[i]);
  }

  min = array[0];

  for(i = 0; i < n; i++) {
    if(array[i] < min)
      min = array[i];
  }

  for (i = 0; i < n; i++) {
    array[i]-=min;

    if(array[i] % 2 == 0) {
      even_sum+=array[i];
      even_count++;
    }
  }

  printf("\n[" );
  for(i = 0;i < n;i++) {
      if(i > 0) {
          printf(", ");
      }
      printf("%d", array[i]);
  }
  printf("]\n");

  printf("Srednja vrednost parnih elemenata niza iznosi");
  printf("%.2f\n", even_sum * 1.0 / even_count);

  int is_sorted = 1;
  for (i = 0; i < n - 1; i++) {
    if(array[i] > array[i+1]){
      is_sorted = 0;
      break;
    }
  }

  if(is_sorted)
    printf("Niz je sortiran u rastucem obliku.\n" );
  else
    printf("Niz nije sortiran u rastucem obliku.\n" );

  return 0;
}
