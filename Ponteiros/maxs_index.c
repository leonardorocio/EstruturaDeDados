#include <stdio.h>
#include <stdlib.h>

void max_index(int v[], int tam, int *pMax, int *pIndex);

int main() {
	int *v, *pMax, *pIndex, tam, i;
	scanf("%d", &tam);
	v = malloc(sizeof(int) * tam);
	pMax = malloc(sizeof(int));
	pIndex = malloc(sizeof(int));
	
	for (i = 0; i < tam; i++) {
		printf("%d: ", i);
		scanf("%d", &v[i]);
	}
	
	max_index(v, tam, pMax, pIndex);
	printf("Value: %d and Index: %d", *pMax, *pIndex);
}

void max_index(int v[], int tam, int *pMax, int *pIndex) {
	*pMax = v[0];
	int i;
	for (i = 0; i < tam; i++) {
		if (v[i] > *pMax) {
			*pMax = v[i];
			*pIndex = i;
		}
	}
}
