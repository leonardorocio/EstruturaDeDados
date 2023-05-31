#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

//Privado------------------------

Elemento *aloca_elemento( void *info, int tam ) {
	Elemento *p = malloc( sizeof(Elemento) );
	if( p == NULL )
		return NULL; // Erro, falta de memória!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de memória!
	}
	memcpy(p->info, info, tam);
	return p; // Sucesso!
}

//-------------------------------


void inicializa_lista( Lista *p, int t ){
	p->tamInfo = t;
	p->cabeca = NULL;
	p->qtd = 0;
}

int lista_vazia ( Lista l ){
	return l.cabeca == NULL;
}

int insere_inicio( Lista *p, void *info ){
	Elemento *novo = aloca_elemento( info, p->tamInfo );
	if( novo == NULL )
		return 0; // Erro, falta de memória!

	novo->proximo = p->cabeca;
	p->cabeca = novo;
	p->qtd++;
	return 1; // Sucesso!
}

int remove_inicio( Lista *p, void *info ){
	if( lista_vazia( *p ) )
		return ERRO_LISTA_VAZIA;

	Elemento *aux = p->cabeca;
	memcpy( info, aux->info, p->tamInfo );
	p->cabeca = aux->proximo;
	free( aux->info );
	free( aux );
	p->qtd--;
	return 1; // Sucesso!
}

int inserir_fim(Lista *l, void *info) {
	if (lista_vazia(*l))
		return insere_inicio(l, info);
	Elemento *aux = l->cabeca;
	while(aux->proximo != NULL) {
		aux = aux->proximo;
	}
	Elemento *novo = aloca_elemento(info, l->tamInfo);
	if (novo == NULL)
		return 0;
	aux->proximo = novo;
	novo->proximo = NULL;
	l->qtd++;
	return 1;
}

int inserir_fim_qtd(Lista *l, void *info) {
	if (lista_vazia(*l))
		return insere_inicio(l, info);
	Elemento *aux = l->cabeca;
	int i = 0;
	while(i < l->qtd - 1) {
		aux = aux->proximo;
		i++;
	}
	Elemento *novo = aloca_elemento(info, l->tamInfo);
	if (novo == NULL)
		return 0;
	aux->proximo = novo;
	novo->proximo = NULL;
	l->qtd++;
	return 1;
}

int remove_fim(Lista *l, void *info) {
	if (lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if (l->qtd == 1) {
		return remove_inicio(l, info);
	}
	Elemento *aux = l->cabeca;
	while(aux->proximo->proximo != NULL) {
		aux = aux->proximo;
	}
	Elemento *ultimo = aux->proximo;
	memcpy(info, ultimo->info, l->tamInfo);
	free(ultimo->info);
	free(ultimo);
	aux->proximo = NULL;
	l->qtd--;
	return 1;
}

int remove_fim_qtd(Lista *l, void *info) {
	if (lista_vazia(*l))
		return ERRO_LISTA_VAZIA;
	if (l->qtd == 1) {
		return remove_inicio(l, info);
	}
	Elemento *aux = l->cabeca;
	int i = 0;
	while(i < l->qtd - 2) {
		aux = aux->proximo;
		i++;
	}
	Elemento *ultimo = aux->proximo;
	memcpy(info, ultimo->info, l->tamInfo);
	free(ultimo->info);
	free(ultimo);
	aux->proximo = NULL;
	l->qtd--;
	return 1;
}

void mostra_lista( Lista l, void (*mostra)(void *) ){
	if( lista_vazia( l ) )
		printf("Lista vazia!\n");
	else{
		printf("Dados da lista (%d elementos):\n", l.qtd );
		Elemento *p = l.cabeca;
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

void desaloca_lista(Lista *l) {
	Elemento *p = l->cabeca;
	while(p != NULL) {
		Elemento *prox = p->proximo;
		free(p->info);
		free(p);
		p = prox;
	}
	inicializa_lista(l, l->tamInfo);
}

