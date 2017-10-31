#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int A[MAX_SIZE];
    int n;

    do {
        printf("Unesite broj elemenata niza (max %d): ", MAX_SIZE);
        scanf("%d", &n);
    } while(n<2 || n > MAX_SIZE);

    int i;
    for(i=0; i<n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("\n");
    for(i=0; i<n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    double AS_sum = 0;
    int AS_count = 0;
    for(i=0; i<n; i+=2) {
        AS_sum += A[i];
        AS_count++;
    }
    double AS = AS_sum / AS_count;
    printf("\nAS = %.2lf\n", AS);

    return 0;
}
