#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "DisjointSet.h"

void componentes_conexos(int size, int mat[size][size]) {
	DisjointSet s;
	inicializa_set(&s);
	int i, x, j, y;
	for (i = 1; i <= size; i++) {
		x = i;
		cria_set(&s, &x);
	}
	for (i = 1; i <= size; i++) {
		x = i;
		for (j = 1; j <= size; j++) {
			y = j;
			if (mat[i-1][j-1] && busca_set(&s, &x) != busca_set(&s, &y)) {
				unir_sets(&s, &x, &y);
			}
		}
	}
	mostra_todos_sets(s);
}

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	FILE *entrada = fopen("matriz.txt", "r");
	int size, a, b, i, j, t;
	fscanf(entrada, "%d", &t); // Número de casos de teste
	while(t--) {
		fscanf(entrada, "%d", &size); // Número de vértices (tamanho da matriz)
		int m[size][size];
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				fscanf(entrada, j == size - 1 ? "%d\n" : "%d ", &m[i][j]); // Entradas da matriz
			}
		}
		componentes_conexos(size, m);
	}
	fclose(entrada);
	return 0;
}
