#include <stdio.h>
#include <stdlib.h>
#include "../../Libs/Lista.h"

void concatena(Lista *l1, Lista *l2) {
	if (!l2->qtd)
		return;
	
	Elemento *aux1 = l1->cabeca;
	while(aux1 != NULL || aux1->proximo != NULL) {
		aux1 = aux1->proximo;
	}
	
	Elemento *aux2 = l2->cabeca;
	int x;
	while(aux2 != NULL || aux2->proximo != NULL) {
		remove_inicio(l2, &x);
		insere_fim(l1, &x);
		aux2 = aux2->proximo;
	}
	 
} 
