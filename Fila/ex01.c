#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Fila.h"

void inverte_fila(Fila *f) {
	Pilha p;
	inicializa_pilha(&p, f->capacidade);
	int info;
	while(!fila_vazia(*f)) {
		remover(f, &info);
		empilha(&p, info);
	}
	while(!pilha_vazia(p)) {
		desempilha(&p, &info);
		inserir(f, info);
	}
}
