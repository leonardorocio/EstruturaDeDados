#include <stdio.h>
#include <stdlib.h>

int *buscaNegativos(int *v, int n, int *pSize);
int *buscaPositivos(int *v, int n, int *pSize);
void imprimeVetor(int *v, int n);

int main() {
	int *v, *pPos, *pNeg, size, i;
	scanf("%d", &size);
	v = malloc(sizeof(int) * size);
	pPos = malloc(sizeof(int));
	pNeg = malloc(sizeof(int));
	for (i = 0; i < size; i++) {
		scanf("%d", &v[i]);
	}
	int *negativos = buscaNegativos(v, size, pNeg);
	int *positivos = buscaPositivos(v, size, pPos);
	printf("Vetor 1: \n");
	imprimeVetor(v, size);
	printf("Vetor 2: \n");
	imprimeVetor(negativos, *pNeg);
	printf("Vetor 3: \n");
	imprimeVetor(positivos, *pPos);
	return 0;
}

void imprimeVetor(int *v, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d\n", v[i]);
	}
}

int* buscaNegativos(int *v, int n, int *pSize) {
	int i;
	int *negativos = malloc(sizeof(int));
	*pSize = 0;
	for (i = 0; i < n; i++) {
		if (v[i] < 0) {
			negativos[*pSize] = v[i];
			negativos = realloc(negativos, sizeof(negativos) + sizeof(int));
			(*pSize)++;
		}
	}
	return negativos;
}

int* buscaPositivos(int *v, int n, int *pSize) {
	int i;
	*pSize = 0;
	int *positivos = malloc(sizeof(int));
	for (i = 0; i < n; i++) {
		if (v[i] > 0) {
			positivos[*pSize] = v[i];
			positivos = realloc(positivos, sizeof(positivos) + sizeof(int));
			(*pSize)++;
		}
	}
	return positivos;
}

