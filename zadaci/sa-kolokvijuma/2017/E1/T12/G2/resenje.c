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

    int count = 0;
    printf("\n");
    for(i=0; i<n-1; i++) {
        if (A[i] % 2 && A[i+1] % 2) {
            printf("odd(A[%d]) == odd(A[%d]) == %d\n", i, i+1, A[i] % 2);
            count++;
        }
    }

    printf("\ncount = %d\n", count);

    return 0;
}
