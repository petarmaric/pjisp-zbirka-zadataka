#include <stdio.h>

#define MAX_SIZE 30

int main() 
{
    int A[MAX_SIZE];
    int n;
    int i,j,k;
    do 
    {
        printf("Unesite broj elemenata niza:");
        scanf("%d", &n);
    } while(n<=1 || n > MAX_SIZE);

    for(i=0; i<n; i++) 
    {
        printf("A[%d]=", i);
        scanf("%d", &A[i]);
    }
    printf("\n");
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(A[i]==A[j])
            {
                n--;//smanjuje se broj elemenata niza
                for(k=j;k<n;k++)
                    A[k]=A[k+1];
                j--;//novi element na j-tom indeksu se mora ponovo testirati
            }
    for(i=0; i<n; i++) 
    {
        printf("\nA[%d]=%d", i,A[i]);
    }
    printf("\n");
    return 0;
}
