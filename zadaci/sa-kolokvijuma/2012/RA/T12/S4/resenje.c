#include <stdio.h>

#define MAX_SIZE 30

int main() 
{
    int X[MAX_SIZE];
    int n,i;
    int sum=0;
    int br=0;
    double SRVX;
    do {
        printf("Unesite broj elemenata niza:");
        scanf("%d", &n);
    } while(n<=1 || n > MAX_SIZE);

    for(i=0; i<n; i++) {
        printf("X[%d]=", i);
        scanf("%d", &X[i]);
    }
   
    for(i=0; i<n; i++) {
        sum+=X[i];
    }
    SRVX=(double)sum/n;

    for(i=0;i<n;i++) 
        if(X[i]>SRVX) br++;
 
    printf("\n\n");
    puts("Elementi niza X:");
    for(i=0; i<n; i++) {
        printf("\nX[%d]=%d", i, X[i]);
    }
    printf("\n\n");

    printf("\nSRVX=%.2lf\n\n",SRVX);

    printf("\nBroj elemenata niza X vecih od srednje vrednosti je:%d\n\n",br);

    return 0;
}

