#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void preenche_pilha(Pilha *p, int quantidade) {
	int tamanho = 10;
	inicializa_pilha(p, tamanho);
	int i;
	for (i = 0; i < quantidade; i++) {
		empilha(p, rand() % 10);
	}
}

void concatena(Pilha *p1, Pilha *p2) {
	
	while( !(pilha_cheia(*p1)) && !(pilha_vazia(*p2)) ) {
		int aux;
		desempilha(p2, &aux);
		empilha(p1, aux);
	}
	
	mostra_pilha(*p2);
	mostra_pilha(*p1);
}
