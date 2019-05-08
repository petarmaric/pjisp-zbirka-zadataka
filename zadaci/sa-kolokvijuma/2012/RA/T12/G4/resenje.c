#include <stdio.h>

#define MAX_SIZE 30

int main()
{
    int A[MAX_SIZE];
    int pom;
    int n;
    int i;
    do {
        printf("Unesite broj elemenata niza:");
        scanf("%d", &n);
    } while(n<=1 || n > MAX_SIZE);

    for(i=0; i<n; i++) 
    {
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }
    for(i=0;i<=n/2;i++)
    {
        pom=A[i];
        A[i]=A[n-1-i];
        A[n-1-i]=pom;
    }
    for(i=0; i<n; i++) 
    {
        printf("\nA[%d]=%d", i,A[i]);
    }
    printf("\n");
    return 0;
}
