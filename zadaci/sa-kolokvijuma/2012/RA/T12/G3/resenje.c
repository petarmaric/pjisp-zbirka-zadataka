#include <stdio.h>

#define MAX_SIZE 30

int main() 
{
    int X[MAX_SIZE];
    int A[MAX_SIZE];
    int B[MAX_SIZE/2];
    int n;
    int i;
    int j=0,k=0,sum=0;
    double SRVA;
    do 
    {
        printf("Unesite broj elemenata niza:");
        scanf("%d", &n);
    } while(n<=1 || n > MAX_SIZE);

    for(i=0; i<n; i++) 
    {
        printf("X[%d]=", i);
        scanf("%d", &X[i]);
    }
    for(i=0;i<n;i++)
    {
        if(X[i]%2==0) A[j]=X[i], j++;//parni elementi
        if(i%2!=0) B[k]=X[i], k++;//neparni indeks
    }
    
    for(i=0; i<j; i++) 
    {
        sum+=A[i];
    }
    SRVA=(double)sum/j;

    printf("\n\n");
    puts("Elementi niza A:");
    for(i=0; i<j; i++) 
    {
        printf("\nA[%d]=%d", i, A[i]);
    }
    printf("\n\n");

    puts("Elementi niza B:");
    for(i=0; i<k; i++) 
    {
        printf("\nB[%d]=%d", i, B[i]);
    }
    printf("\n\n");

    printf("\nSRVA=%.2lf\n\n",SRVA);

    return 0;
}
