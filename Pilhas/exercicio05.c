#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include <string.h>

void inverte_frase(char frase[]) {
	char *palavra = calloc(strlen(frase), sizeof(char));
	int pos, count = 0;
	for (pos = 0; frase[pos] != '\0'; pos++) {
		if (frase[pos] != ' ') {
			palavra[count] = frase[pos];
			count++;
		}
		 
		if (frase[pos] == ' ' || frase[pos+1] == '\0') {
			inverte(palavra);
			printf("%s ", palavra);
			free(palavra);
			palavra = calloc(strlen(frase), sizeof(char));
			count = 0;
		}
	}
}
