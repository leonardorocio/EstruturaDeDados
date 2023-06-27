#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "Fila.h"
#include "arvore_n_aria.h"

void caminho_minimo(int size, int m[size][size], int a) {
	int *vs = calloc(size+1, sizeof(int));
	Fila f;
	inicializa_fila(&f, size);
	Arvore arv;
	inicializa_Arvore(&arv, a);
	vs[a] = 1;
	inserir(&f, a);
	int x, i;
	while( !fila_vazia(f)) {
		remover(&f, &x);
			for (i = 1; i <= size; i++) {
				if (m[x-1][i-1]) {
					if (!vs[i]) {
						vs[i] = 1;
						insere_filho(arv, x, i);
						inserir(&f, i);
					}
				}
			}
		}
	gera_xml(arv);
	system("PAUSE");
	}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	FILE *entrada = fopen("matriz.txt", "r");
	int size, a, i, j, t;
	fscanf(entrada, "%d", &t); // Número de casos de teste
	while(t--) {
		fscanf(entrada, "%d", &size); // Número de vértices (tamanho da matriz)
		int m[size][size];
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				fscanf(entrada, j == size - 1 ? "%d\n" : "%d ", &m[i][j]); // Entradas da matriz
			}
		}
		fscanf(entrada, "%d", &a); // Vértice inicial e Vértice Final
		caminho_minimo(size, m, a);
	}
	fclose(entrada);
	return 0;
}
