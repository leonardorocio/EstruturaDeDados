#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Libs\Fila.c"
#include "..\..\Libs\Pilha.c"

void bfs(int size, int m[size][size], int a, int b) {
	int *vs = calloc(size, sizeof(int));
	int *va = calloc(size, sizeof(int));
	Fila f;
	inicializa_fila(&f, size);
	vs[a] = 1;
	inserir(&f, a);
	int achou = 0, x, i;
	while( !fila_vazia(f) && !achou ) {
		remover(&f, &x);
		if (x == b) {
			achou = 1;
		} else {
			for (i = 1; i <= size; i++) {
				if (m[x-1][i-1]) {
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
		printf("B (%d) não é alcançável a partir de A (%d)\n", b, a);
	}
}

int main(int argc, char *argv[]) {
	FILE *entrada = fopen("matriz.txt", "r");
	int size, a, b, i, j, t;
	fscanf(entrada, "%d", &t);
	while(t--) {
		fscanf(entrada, "%d", &size);
		int m[size][size];
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				fscanf(entrada, j == size - 1 ? "%d\n" : "%d ", &m[i][j]);
			}
		}
		fscanf(entrada, "%d %d", &a, &b);
		bfs(size, m, a, b);
	}
	fclose(entrada);
	return 0;
}
