#include <stdio.h>
#include <stdlib.h>

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

    int j;
    int count = 0;
    printf("\n");
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if (abs(A[i]) == abs(A[j])) {
                printf("abs(A[%d]) == abs(A[%d]) == %d\n", i, j, abs(A[i]));
                count++;
            }
        }
    }

    printf("\ncount = %d\n", count);

    return 0;
}
