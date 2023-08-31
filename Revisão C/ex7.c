#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"

void mostra_int(void* x) {
	printf("%d\n", *((int*) x));
}

int intersecao(Lista l1, Lista l2) {
	Elemento *n1 = l1.cabeca;
	Elemento *n2 = l2.cabeca;
	int count1 = conta_elementos(l1);
	int count2 = conta_elementos(l2);
	int t;
	if (count1 > count2) {
		t = count1 - count2;
		while(t--) {
			n1 = n1->proximo;
		}
	} else if (count1 < count2) {
		t = count2 - count1;
		while(t--) {
			n2 = n2->proximo;
		}
	}

	while (n1 != NULL && n2 != NULL) {
		if (n1 == n2) {
			break;
		}

		n1 = n1->proximo;
		n2 = n2->proximo;
	}
	
	return *((int*)n1->info);
}

int main() {
	Lista l1, l2;
	inicializa_lista(&l1, sizeof(int));
	inicializa_lista(&l2, sizeof(int));
	
	int x = 3;
	insere_fim(&l1, &x);
	x = 7;
	insere_fim(&l1, &x);
	
	x = 99;
	insere_fim(&l2, &x);
	x = 1;
	insere_fim(&l2, &x);
	
	x = 8;
	Elemento *no = aloca_elemento(&x, sizeof(int));
	insere_fim_no(&l1, no);
	insere_fim_no(&l2, no);
	x = 10;
	no = aloca_elemento(&x, sizeof(int));
	insere_fim_no(&l1, no);
	insere_fim_no(&l2, no);
	
	mostra_lista(l1, mostra_int);
	mostra_lista(l2, mostra_int);

	printf("O ponto de interseção é no nó: %d", intersecao(l1, l2));
	
	return 0;
}
