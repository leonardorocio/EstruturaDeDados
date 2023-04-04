#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"


void inverte(char *s) {
	Pilha p;
	inicializa_pilha(&p, strlen(s));
	int i;
	for (i = 0; s[i] != 0; i++) {
		empilha(&p, s[i]);
	}
	
	for (i = 0; s[i] != 0; i++) {
		int aux;
		desempilha(&p, &aux);
		s[i] = aux;
	}
	
//	mostra_pilha(p);
	desaloca_pilha(&p);
}
