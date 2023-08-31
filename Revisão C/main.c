#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
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
	return 0;
}
