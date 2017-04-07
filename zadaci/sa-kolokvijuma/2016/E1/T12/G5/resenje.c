#include <stdio.h>
#include <math.h>

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
        printf("Unesite %d. clan niza: ", i+1);
        scanf("%d", &A[i]);
    }

    printf("\n");
    for(i=n-1; i>=0; i--) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    double KS_sum = 0;
    for(i=0; i<n; i++) {
        KS_sum += pow(A[i], 2);
    }
    double KS = sqrt(KS_sum / n);
    printf("\nKS = %.2lf\n", KS);

    double AS_sum = 0;
    int AS_count = 0;
    for(i=1; i<n; i+=2) {
        AS_sum += A[i];
        AS_count++;
    }
    double AS = AS_sum / AS_count;
    printf("AS = %.2lf\n", AS);

    return 0;
}
