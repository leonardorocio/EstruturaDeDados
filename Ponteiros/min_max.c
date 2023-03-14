#include <stdio.h>
#include <stdlib.h>

void min_max(int v[], int tam, int *pMax, int *pMin);

int main() {
	int tam, *v, *pMax, *pMin, i;
	pMax = malloc(sizeof(int));
	pMin = malloc(sizeof(int));
	scanf("%d", &tam);
	int size = sizeof(int) * tam;
	v = malloc(size);
	for (i = 0; i < tam; i++) {
		printf("%d: ", i);
		scanf("%d", &v[i]);
	}
	min_max(v, tam, pMax, pMin);
	printf("\nMin: %d e Max: %d", *pMin, *pMax);
}

void min_max(int v[], int tam, int *pMax, int *pMin) {
	*pMax = v[0];
	*pMin = v[0];
	int i;
	for (i = 0; i < tam; i++) {
		if (v[i] > *pMax) {
			*pMax = v[i];
		}
		if (v[i] < *pMin) {
			*pMin = v[i];
		}
	}
}

