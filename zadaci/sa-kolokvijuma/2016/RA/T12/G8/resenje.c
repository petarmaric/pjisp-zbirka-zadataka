#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

int main() {
    int a[MAX_SIZE], prosti[MAX_SIZE];
    int i, j, n;

    do {
        printf("Unesite dimenziju niza n: ");
        scanf("%d", &n);        
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    // a)

    int broj_prostih = 0, je_prost, min_idx, temp;

    for(i = 0;i < n;i++) {
        je_prost = 1;

        if(a[i] == 1) {
            je_prost = 0;
        } else {
            for(j = 2;pow(j, 2) <= a[i];j++) {
                if(a[i] % j == 0) {
                    je_prost = 0;
                    break;
                }
            }
        }

        if(je_prost) {
            prosti[broj_prostih] = a[i];
            broj_prostih++;
        }
    }

    for(i = 0;i < broj_prostih;i++) {
        min_idx = i;

        for(j = i + 1;j < broj_prostih;j++) {
            if(prosti[j] < prosti[min_idx]) {
                min_idx = j;
            }
        }

        if(min_idx != i) {
            temp = prosti[i];
            prosti[i] = prosti[min_idx];
            prosti[min_idx] = temp;
        }
    }

    printf("[");
    for(i = 0;i < broj_prostih;i++) {
        if(i > 0) {
            printf(", ");
        }

        printf("%d", prosti[i]);
    }
    printf("]\n");

    // b)

    int broj_blizanaca = 0;

    for(i = 0;i < broj_prostih - 1;i++) {
        if(prosti[i + 1] - prosti[i] == 2) {
            broj_blizanaca++;
        }
    }

    printf("%d\n", broj_blizanaca);

    return 0;
} 
