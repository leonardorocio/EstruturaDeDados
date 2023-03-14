#include <stdio.h>
#include <stdlib.h>

int*  busca_sequencial(int v[], int n, int chave, int* pIndex);

int main() {
	int *v, n, chave, i, *pIndex;
	pIndex = malloc(sizeof(int));
	scanf("%d%d", &n, &chave);
	v = malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		printf("%d: ", i);
		scanf("%d", &v[i]);
	}
	int *t = busca_sequencial(v, n, chave, pIndex);
	for (i = 0; i < *pIndex; i++) {
		printf("%d\n", t[i]);
	}
	return 0;
}

int*  busca_sequencial(int v[], int n, int chave, int *pIndex) {
	int i, counter = 1;
	int *indexes = malloc(sizeof(int));
	for (i = 0; i < n; i++) {
		if (v[i] == chave) {
			indexes[counter - 1] = i;
			indexes = realloc(indexes, sizeof(indexes) + sizeof(int));
			counter++;
		}
	}
	*pIndex = counter - 1;
	return indexes;
}
