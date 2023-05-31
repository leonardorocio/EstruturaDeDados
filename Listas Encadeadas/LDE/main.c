#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_inteiro(void *x);

int main(int argc, char *argv[]) {
	LDE l;
	inicializa_lista(&l, sizeof(int));
	
	int x = 10;
	insere_fim(&l, &x);
	insere_fim(&l, &x);
	insere_fim(&l, &x);
	x = 20;
	insere_fim(&l, &x);
	x = 30;
	insere_pos(&l, &x, 1);
	
//	mostra_lista(l, mostra_inteiro);
	
//	remove_pos(&l, &x, 3);
	
//	mostra_lista(l, mostra_inteiro);

	mostra_lista_invertida(l, mostra_inteiro);
	return 0;
}

void mostra_inteiro(void *x) {
	int *a = x;
	printf("%d\n", *a);
}
