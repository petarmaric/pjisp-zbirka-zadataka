#include <stdio.h>

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

        imenilac = i * (i+1) * (i+2);

        clan = brojilac/imenilac;
        printf("clan[i=%d] = %lf\n", i, clan);

        sum += clan;
    }

    printf("\nsum = %lf\n", sum);

    return 0;
}
