#include <stdio.h>

#define MAX_SIZE 15

int main() {
	int A[MAX_SIZE];
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

	int j, tmp;
	for(i=0; i<n-1; i++) {
		for(j=i+1; j<n; j++) {
			if (A[i] < A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}

	printf("\nmax = %d + %d = %d", A[0], A[1], A[0] + A[1]);

	return 0;
}
