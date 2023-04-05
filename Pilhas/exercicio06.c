#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

int valida_expressao(char *expressao){
	Pilha p;
	inicializa_pilha(&p, strlen(expressao));
	int i;
	for (i = 0; expressao[i] != '\0'; i++) {
		if (expressao[i] == '(') {
			empilha(&p, expressao[i]);
		} 
		
		if (expressao[i] == ')') {
			if (pilha_vazia(p)) {
				return 0;
			} else {
				int aux;
				desempilha(&p, &aux);
			}
		}
	}
	return pilha_vazia(p);
}
