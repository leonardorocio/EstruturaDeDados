#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Libs/Fila.h"
#include "../../Libs/Pilha.h"

void bfs(int **m, int size, int a, int b) {
	int *vs = malloc(sizeof(int) * size);
	int *va = malloc(sizeof(int) * size);
	memset(vs, 0, sizeof(vs) * sizeof(int));
	memset(va, 0, sizeof(va) * sizeof(int));
	Fila f;
	inicializa_fila(&f, size);
	vs[a] = 1;
	inserir(&f, a);
	int achou = 0, x;
	while( !fila_vazia(f) && !achou) {
		remover(&f, &x);
		if (x == b) {
			achou = 1;
		} else {
			int i;
			for (i = 0; i < size; i++) {
				if (m[x][i]) {
					if (!vs[i]) {
						vs[i] = 1;
						va[i] = x;
						inserir(&f, i);
					}
				}
			}
		}
	}
	
	if (achou) {
		Pilha p;
		inicializa_pilha(&p, size);
		while(x != 0) {
			empilha(&p, x);
			x = va[x];
		}
		while( !pilha_vazia(p) ) {
			desempilha(&p, &x);
			printf("%d ", x);
		}
		printf("\n");
	} else {
		printf("B não é alcançável a partir de A");
	}
}

int main(int argc, char *argv[]) {
	printf("Olá");
//	FILE *entrada = fopen("matriz.txt", "r");
//	int size, a, b, i, j;
//	fscanf(entrada, "%d", &size);
//	int m[size][size];
//	for (i = 0; i < size; i++) {
//		for (j = 0; j < size; j++) {
//			fscanf(entrada, j == size - 1 ? "%d\n" : "%d ", &m[i][j]);
//		}
//	}
//	fscanf(entrada, "%d%d", &a, &b);
//	fclose(entrada);
	return 0;
}
