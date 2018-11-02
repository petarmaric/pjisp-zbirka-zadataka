#include <stdio.h>
#include <math.h>

int main() {
    int n;

    do {
        printf("Unesite broj clanova reda: ");
        scanf("%d", &n);
    } while(n<1);

    int i, j;
    double brojilac, imenilac, clan;
    double sum = 0;
    for(i=1; i<=n; i++) {
        brojilac = 1;

        imenilac = pow(2*i - 1, 2);

        clan = brojilac/imenilac;
        printf("clan[i=%d] = %lf\n", i, clan);

        sum += clan;
    }

    printf("\nsum = %lf\n", sum);

    double pi = sqrt(sum * 8);
    printf("\npi = %lf\n", pi);

    return 0;
}
