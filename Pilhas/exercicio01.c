#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

void inteiro_pra_binario(int numero) {
	Pilha p;
	inicializa_pilha(&p, 32);
	do {
		int resto = numero % 2;
		empilha(&p, resto);
		numero /= 2;
	} while (numero > 0);
	
	int aux;
	while( !(pilha_vazia(p))) {
		desempilha(&p, &aux);
		printf("%d", aux);
	}
}

