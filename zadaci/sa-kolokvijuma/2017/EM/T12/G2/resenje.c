#include <stdio.h>

#define MAX_SIZE 10

int last(int n) {
    return n % 10;
}

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
            if (last(A[i]) == last(A[j])) {
                printf("last(A[%d]) == last(A[%d]) == %d\n", i, j, last(A[i]));
                count++;
            }
        }
    }

    printf("\ncount = %d\n", count);

    return 0;
}
