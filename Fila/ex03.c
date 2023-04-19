#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

typedef struct {
	Pilha p1, p2;
} FilaPilha;

void mostra_fila_pilha(FilaPilha fp) {
	int i;
	if (!pilha_vazia(fp.p2)) {
		printf("Dados da Fila:\n");
		for (i = fp.p2.topo; i >= 0; i--) {
			printf("[%d]: %d\n", fp.p2.topo - i, fp.p2.dados[i]);
		}
		printf("---------------\n");
	} else {
		if( pilha_vazia( fp.p1 ) )
			printf("Fila vazia!\n");
		else {
			printf("Dados da Fila:\n");
			int i;
			for( i = 0 ; i <= fp.p1.topo ; i++ )
				printf("[%d] %d\n", i, fp.p1.dados[i] );
			printf("---------------\n");
		}
	}
}

int inserir_fila_pilha(FilaPilha *fp, int v) {
	if (pilha_cheia(fp->p1)) {
		return -1;
	}

	if (!pilha_vazia(fp->p2)) {
		troca_pilha(&fp->p1, &fp->p2);
	}
	empilha(&fp->p1, v);
	return 1;
}

int troca_pilha(Pilha *dest, Pilha *src) {
	if (pilha_vazia(*src) || pilha_cheia(*dest)) {
		return -1;
	}
	int x;
	while(!pilha_vazia(*src)) {
		desempilha(src, &x);
		empilha(dest, x);
	}
	return 1;
}


int remover_fila_pilha(FilaPilha *fp, int *v) {
	if (!pilha_vazia(fp->p1)) {
		troca_pilha(&fp->p2, &fp->p1);
	}
	desempilha(&fp->p2, v);
	return 1;
}

void inicializa_fila_pilha(FilaPilha *fp, int size) {
	inicializa_pilha(&fp->p1, size);
	inicializa_pilha(&fp->p2, size);
}

int fila_pilha_vazia(FilaPilha fp) {
	return fp.p2.topo == -1;
}

int fila_pilha_cheia(FilaPilha fp) {
	return fp.p2.topo == fp.p2.capacidade - 1;
}

void desaloca_fila_pilha(FilaPilha *fp) {
	desaloca_pilha(&fp->p1);
	desaloca_pilha(&fp->p2);
} 

