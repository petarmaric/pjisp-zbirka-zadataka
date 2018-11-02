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
    for(i=0; i<n; i++) {
        brojilac = 1;

        double fakt = 1;
        for(j=2; j<=i; j++) {
            fakt *= j;
        }
        imenilac = fakt;

        clan = brojilac/imenilac;
        printf("clan[i=%d] = %lf\n", i, clan);

        sum += clan;
    }

    printf("\ne = %lf\n", sum);

    return 0;
}
