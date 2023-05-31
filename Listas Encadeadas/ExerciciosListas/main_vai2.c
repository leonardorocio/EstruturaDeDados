#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void mostra_inteiro(void *x);
void concatena(Lista *l1, Lista *l2);
int busca(Lista *l, void *info, int (*compara) (void*, void*));
int compara(void *a, void *b);
Lista busca_todos(Lista *l, void *info, int (*compara) (void*, void*));
void mostra_invertido_com_pilha(Lista l, void (*mostra) (void*));
void mostra_invertido_recursivo(Lista l, void (*mostra) (void*));
void mostra_invertido_iterativo(Lista l, void (*mostra) (void*));

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
	
//	x = 10;
//	insere_inicio(&l1, &x);
//	insere_inicio(&l2, &x);
	
//	mostra_lista(l1, mostra_inteiro);
//	mostra_invertido_recursivo(l1, mostra_inteiro);
 	mostra_invertido_com_pilha(l1, mostra_inteiro);
//	mostra_invertido_iterativo(l1, mostra_inteiro);

//	Lista b1 = busca_todos(&l1, &x, compara);
//	Lista b2 = busca_todos(&l2, &x, compara);
//	printf("%d e %d\n", b1, b2);
	
//	concatena(&l1, &l2);
//	mostra_lista(b1, mostra_inteiro);
//	mostra_lista(b2, mostra_inteiro);
	
//	FilaEnc f;
//	inicializa_fila(&f, sizeof(int));
//	
//	mostra_fila(f, mostra_inteiro);
//	
//	int y = 10;
//	inserir(&f, &y);
//	y = 20;
//	inserir(&f, &y);
//	y = 30;
//	inserir(&f, &y);
//	
//	mostra_fila(f, mostra_inteiro);
//	
//	remover(&f, &y);
////	
//	mostra_fila(f, mostra_inteiro);
}

void mostra_inteiro(void *x) {
	int *a = x;
	printf("%d\n", *a);
}

void concatena(Lista *l1, Lista *l2) {
	Elemento *aux1 = l1->cabeca;
	while(aux1 != NULL && aux1->proximo != NULL) {
		aux1 = aux1->proximo;
	}
	
	Elemento *aux2 = l2->cabeca;
	int x;
	while(l2->qtd) {
		remove_inicio(l2, &x);
		insere_fim(l1, &x);
	}
}

int compara(void *a, void *b) {
	int *x = a, *y = b;
	return (*x) - (*y);
}

int busca(Lista *l, void *info, int (*compara) (void*, void*)) {
	if (l->qtd == 0)
		return ERRO_LISTA_VAZIA;
	
	Elemento *aux = l->cabeca;
	int q = 0, found = compara(aux->info, info);
	while(aux->proximo != NULL && found != 0) {
		aux = aux->proximo;
		found = compara(aux->info, info);
		q++;
	}
	return found == 0 ? q : -1;
}

Lista busca_todos(Lista *l, void *info, int (*compara) (void*, void*)) {
	Lista lista_retorno;
	inicializa_lista(&lista_retorno, sizeof(int));
	if (l->qtd == 0)
		return lista_retorno;
	
	Elemento *aux = l->cabeca;
	int found, pos = 0;
	while(aux != NULL) {
		found = compara(aux->info, info);
		if (found == 0) {
			insere_fim(&lista_retorno, &pos);
		}
		aux = aux->proximo;
		pos++;
	}
	return lista_retorno;
}

void mostra_invertido_recursivo(Lista l, void (*mostra) (void*)) {
	if (l.cabeca == NULL) {
		printf("Lista invertida:\n");
	} else {
		void *val = l.cabeca->info;
		l.cabeca = l.cabeca->proximo;
		mostra_invertido_recursivo(l, mostra_inteiro);
		mostra_inteiro(val);
	}
}

void mostra_invertido_com_pilha(Lista l, void (*mostra) (void*)) {
	Pilha p;
	inicializa_pilha(&p, l.qtd);
	
	int contador = 0, valor;
	Elemento *aux = l.cabeca;
	while(aux != NULL) {
		valor = * ((int*) aux->info);
		empilha(&p, valor);
		aux = aux->proximo;
	}
	
	printf("Lista invertida:\n");
	while (!pilha_vazia(p)) {
		desempilha(&p, &valor);
		printf("%d\n", valor);
	}
}

void mostra_invertido_iterativo(Lista l, void (*mostra) (void*)) {
	int i, j, val;
	for (i = l.qtd - 1; i >= 0; i--) {
		le_valor(l, &val, i);
		printf("%d\n", val);
	}
}
