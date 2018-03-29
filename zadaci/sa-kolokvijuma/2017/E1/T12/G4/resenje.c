#include <stdio.h>

#define MAX_SIZE 10

int found(int n) {
    return n % 10;
}

int main() {
    int A[MAX_SIZE];
    int n;
    int x;

    do {
        printf("Unesite broj elemenata niza (max %d): ", MAX_SIZE);
        scanf("%d", &n);
    } while(n<2 || n > MAX_SIZE);

    printf("Unesite trazenu vrednost: ");
    scanf("%d", &x);

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
    for(i=0; i<n; i++) {
        if (A[i] == x) {
            printf("found(A[%d]) == %d\n", i, A[i]);
            count++;
        }
    }
    double chance = (double)count / n;

    printf("\nchance = %.3lf\n", chance);

    return 0;
}
