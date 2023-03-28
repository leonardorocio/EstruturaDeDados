#include <stdio.h>
#include <stdlib.h>
#include "pilhas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Pilha p;
	inicializa_pilha(&p);
	empilha(&p, 10);
	empilha(&p, 20);
	empilha(&p, 30);
	mostra_pilha(p);
//	int retorno;
//	desempilha(&p, &retorno);
//	mostra_pilha(p);
	int n;
	printf("Digite um número: ");
	scanf("%d", &n);
	
	do {
		int resto = n % 2;
		empilha(&p, resto);
		n /= 2;
	} while(n > 0);
	
	while( !pilha_vazia(p)) {
		int temp;
		desempilha(&p, &temp);
		printf("%d", temp);
	}
	return 0;
}
