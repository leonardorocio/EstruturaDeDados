#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

void inicializa_fila(Fila *f) {
	f->ini = 0;
	f->n = 0;
}

int fila_vazia(Fila f) {
	return f.n == 0;
}

int fila_cheia(Fila f) {
	return f.n == MAX;
}

int inserir(Fila *f, int v) {
	if (fila_cheia(*f))
		return ERRO_FILA_CHEIA;
		
	int fim = (f->ini + f->n) % MAX;
	f->dados[fim] = valor
	f->n++;
	return 1;
}

int remover(Fila *f, int *info){
	if( fila_vazia(*f))
		return ERRO_FILA_VAZIA;
	int fim = (f->ini + f->n) % MAX;
	f->dados[fim] = valor
	f->n--;
	return 1;
};

void mostra_fila(Fila f) {
	int i = f.inicio, cont;
	for (cont = 0; cont < f.n; cont++) {
		printf("[%d]: %d\n", i, f.dados[i]);
		i = (i + 1) % MAX;
	}
}
