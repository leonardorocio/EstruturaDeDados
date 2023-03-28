#include "pilhas.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_pilha(Pilha *p) {
	p->topo = -1;
}

int pilha_vazia(Pilha p) {
	return p.topo == -1;
}

int pilha_cheia(Pilha p) {
	return p.topo == MAX_PILHA - 1;	
}

int empilha(Pilha *p, int valor) {
	if (pilha_cheia(*p)) {
		return ERRO_PILHA_CHEIA;
	}
	p->topo++;
	p->dados[p->topo] = valor;
	return 1;
}

int desempilha(Pilha *p, int *valor) {
	if (pilha_vazia(*p)) {
		return ERRO_PILHA_VAZIA;
	}
	*valor = p->dados[p->topo];
	p->topo--;
	return 1;
}

int le_topo(Pilha p, int *info) {
	if (pilha_vazia(p)) {
		return ERRO_PILHA_VAZIA;
	}
	
	*info = p.dados[p.topo];
	return 1;
}

void mostra_pilha(Pilha p) {
	if (pilha_vazia(p)) {
		printf("Pilha vazia!");
		return;
	} else {
		printf("Dados da Pilha: \n");
		int i;
		for (i = p.topo; i >= 0; i--) { // Virada normalmente?
			printf("%d\n", p.dados[i]);
		}
	}
}
