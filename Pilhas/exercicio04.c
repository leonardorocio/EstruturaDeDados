#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Pilha.h"

int eh_palindrome(char palavra[]) {
	Pilha p1;
	inicializa_pilha(&p1, strlen(palavra));
	int i, aux;
	for (i = 0; palavra[i] != '\0'; i++) {
		empilha(&p1, palavra[i]);
	}
	
	i = 0;
	while(!(pilha_vazia(p1))) {
		desempilha(&p1, &aux);
		if (palavra[i] != aux) {
			return 0;
		}
		i++;
	}
	return 1;
}
