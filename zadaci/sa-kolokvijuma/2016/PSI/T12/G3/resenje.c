#include <stdio.h>

#define MAX_SIZE 15

int main() {
	int A[MAX_SIZE];
	int kvadrati[MAX_SIZE];
	int n;

	do {
		printf("Unesite broj elemenata niza (max %d): ", MAX_SIZE);
		scanf("%d", &n);
	} while(n<2 || n > MAX_SIZE);

	int i;
	for(i=0; i<n; i++) {
		printf("Unesite %d. clan niza: ", i+1);
		scanf("%d", &A[i]);
	}

	printf("\n");
	for(i=0; i<n; i++) {
		printf("A[%d] = %d\n", i, A[i]);
	}

	printf("\n");
	for(i=0; i<n; i++) {
		int cif_des = A[i] / 10;
		int cif_jed  = A[i] % 10;
		kvadrati[i] = cif_des * cif_des + cif_jed * cif_jed;
		
		printf("zbir(A[%d]) = %d\n", i, kvadrati[i]);
	}

	int j;
	int count = 0;
	printf("\n");
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			if (kvadrati[i] == kvadrati[j]) {
				printf("zbir(A[%d]) == zbir(A[%d]) == %d\n", i, j, kvadrati[i]);
				count++;
			}
		}
	}

	printf("\ncount = %d\n", count);

	return 0;
}
