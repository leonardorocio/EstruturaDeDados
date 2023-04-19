#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

#define ERRO_FILA_CHEIA -1
#define ERRO_FILA_VAZIA -1

void inicializa_deque(Deque *d, int size) {
	d->dados = malloc(sizeof(int) * size);
	d->inicio = 0;
	d->n = 0;
	d->capacidade = size;
}

int deque_cheio(Deque d) {
	return d.n == d.capacidade;
}

int deque_vazio(Deque d) {
	return d.n == 0;
}

int inserir_fim(Deque *d, int v) {
	if (deque_cheio(*d))
		return ERRO_FILA_CHEIA;
		
	int fim = (d->inicio + d->n) % d->capacidade;
	d->dados[fim] = v;
	d->n++;
	return 1;
}

int inserir_inicio(Deque *d, int v) {
	if (deque_cheio(*d))
		return ERRO_FILA_CHEIA;
		
	d->inicio = (d->capacidade + d->inicio - 1) % d->capacidade;
	d->dados[d->inicio] = v;
	d->n++;
	return 1;
}

int remover_inicio(Deque *d, int *v) {
	if( deque_vazio( *d ) )
		return ERRO_FILA_VAZIA;
	
	*v = d->dados[d->inicio];
	d->inicio = ( d->inicio + 1 ) % d->capacidade;
	d->n--;
	return 1;
}

int remover_fim(Deque *d, int *v) {
	if( deque_vazio( *d ) )
		return ERRO_FILA_VAZIA;
	
	*v = d->dados[d->n];
	d->n = (d->capacidade + d->n - 1) % d->capacidade;
	return 1;
}

void mostra_deque(Deque d) {
	int i = d.inicio, cont;
	for (cont = 0; cont < d.n; cont++) {
		printf("[%d]: %d\n", i, d.dados[i]);
		i = (i + 1) % d.capacidade;
	}
	printf("-------------------\n");
}

void desaloca_deque(Deque *d) {
	free(d->dados);
}
