#include <stdio.h>

#define MAX_SIZE 30

int main() {
    int a[MAX_SIZE][MAX_SIZE], at[MAX_SIZE][MAX_SIZE];
    int i, j, n;
    
    do {
        printf("Uneti dimenziju kvadratne matrice n: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);
    
    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    int suma_glavne = 0, suma_sporedne = 0;
    double kolicnik_dijagonala;
    
    for(i = 0;i < n;i++) {
        suma_glavne += a[i][i];
        suma_sporedne += a[i][n - i - 1];
    }
    
    kolicnik_dijagonala = (double)suma_glavne / suma_sporedne;
    
    printf("%.2lf\n\n", kolicnik_dijagonala);
    
    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            at[i][j] = a[j][i];
        }
    }
    
    for(i = 0;i < n;i++) {
        for(j = 0;j < n;j++) {
            printf("%d\t", at[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

