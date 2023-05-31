#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void mostra_fila( FilaEnc l, void (*mostra)(void *) ){
	if( l.ini == NULL)
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista (%d elementos):\n", l.qtd );
		Elemento *p = l.ini;
		int cont = 0; // cont é o índice do elemento dentro da lista.
		while( p != NULL ){
			printf("[%d] ", cont);
			mostra( p->info ); // Invocação por callback
			p = p->proximo;
			cont++;
		}
	}
	printf("--------------------------------\n");
}

void inicializa_fila( FilaEnc *f, int t ){
	f->tamInfo = t;
	f->ini = NULL;
	f->qtd = 0;
	f->fim = NULL;
}

int inserir(FilaEnc *p, void *info) {
//	if( f->ini == NULL )
//		return insere_inicio( p, info );

	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
    	return 0; // Erro, falta de memória!
    	
	if (fim == NULL) {
		fim = novo;
	} else {
		fim->proximo = novo;
		novo->proximo = NULL;
		p->fim = novo;
	}

	p->qtd++;
	return 1;
}

int remover(FilaEnc *p, void *info) {
	if( p->ini == NULL )
		return ERRO_LISTA_VAZIA;

	Elemento *aux = p->ini;
	memcpy( info, aux->info, p->tamInfo );
	p->ini = aux->proximo;
	free( aux->info );
	free( aux );
	p->qtd--;
	return 1;
}
