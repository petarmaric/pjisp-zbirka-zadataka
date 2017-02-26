#include <stdio.h>
#include <math.h>

#define MAX_SIZE 40

int main() {
    double a[MAX_SIZE];
    double variances[MAX_SIZE];
    int i, n;

    double sum = 0, avg_orig, sigma;

    int first = 1;

    do {
        printf("Array size: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    for(i = 0;i < n;i++) {
        sum += a[i];
    }

    avg_orig = sum / n;

    for(i = 0;i < n;i++) {
        variances[i] = pow(a[i] - avg_orig, 2);
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", variances[i]);
    }
    printf("]\n");

    
    for(i = 0, sum = 0;i < n;i++) {
        sum += variances[i];
    }

    sigma = sqrt(sum / n);

    printf("[");
    for(i = 0;i < n;i++) {
        if(a[i] >= (avg_orig - sigma) && a[i] <= (avg_orig + sigma)) {
            if(!first) {
                printf(", ");
            } else {
                first = 0;
            }

            printf("%.2lf", a[i]);
        }
    }
    printf("]\n");

    return 0;
}
