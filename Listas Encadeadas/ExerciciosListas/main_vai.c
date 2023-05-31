#include <stdio.h>
#include <stdlib.h>
#include "../../Libs/Lista.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void mostra_inteiro(void *x);
void concatena(Lista *l1, Lista *l2);

int main(int argc, char *argv[]) {
	Lista l1, l2;
	inicializa_lista(&l1, sizeof(int));
	inicializa_lista(&l2, sizeof(int));
	
	int x = 10;
	insere_inicio(&l1, &x);
	insere_inicio(&l2, &x);
	x = 20;
	insere_inicio(&l1, &x);
	insere_inicio(&l2, &x);
	x = 30;
	insere_inicio(&l1, &x);
	insere_inicio(&l2, &x);
	
	concatena(&l1, &l2);
	mostra_lista(l1, mostra_inteiro);
	mostra_lista(l2, mostra_inteiro);
	
	return 0;
}

void mostra_inteiro(void *x) {
	int *a = x;
	printf("%d\n", *a);
}

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
