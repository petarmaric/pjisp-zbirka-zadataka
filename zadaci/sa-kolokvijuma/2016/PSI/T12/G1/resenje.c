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

	int min = A[0];
	int max = A[0];
	for(i=1; i<n; i++) {
		if(A[i] < min) {
			min = A[i];
		} else if (A[i] > max) {
			max = A[i];
		}
	}

	printf("\nmax = %d - %d = %d", max, min, max-min);

	return 0;
}
