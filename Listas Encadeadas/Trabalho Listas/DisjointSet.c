#include "DisjointSet.h"
#include <stdlib.h>
#include <stdio.h>

int compara(void *a, void *b) {
	int *x = a, *y = b;
	return (*x) - (*y);
}

void mostra_int(void *x) {
	int *a = x;
	printf("%d\n", *a);
}

void inicializa_set(DisjointSet *s) {
	inicializa_lista(&s->sets, sizeof(Lista));
}

int busca_set(DisjointSet *s, void *x) {
	Lista set;
	inicializa_lista(&set, sizeof(int));
	int i, j, found = 0, pos = -1;
	for (i = 0; i < s->sets.qtd && !found; i++) {
		le_valor(s->sets, &set, i);
		pos = busca(&set, x, compara);
		found = pos > -1 ? 1 : 0;
	}
	return s->sets.qtd > 0 && found ? i : -1;
}

int cria_set(DisjointSet *s, void *x) {
	if (busca_set(s, x) > -1) {
		return ERRO_SET_EXISTENTE;
	}
	
	Lista set;
	inicializa_lista(&set, sizeof(int));
	insere_fim(&set, x);
	insere_fim(&s->sets, &set);
	return 1;
}

void mostra_set(DisjointSet s, int pos) {
	Lista set;
	inicializa_lista(&set, sizeof(int));
	le_valor(s.sets, &set, pos);
	mostra_lista(set, mostra_int);
}

void deleta_set(DisjointSet *s, int pos) {
	Lista lista;
	remove_pos(&s->sets, &lista, pos);
}

int unir_sets(DisjointSet *s, void *x, void *y) {
	int x_pos = busca_set(s, x);
	int y_pos = busca_set(s, y);
	if (x_pos < 0 || y_pos < 0) {
		return ERRO_SET_INEXISTENTE;
	}
	
	Lista set1, set2;
	inicializa_lista(&set1, sizeof(int));
	inicializa_lista(&set2, sizeof(int));
	le_valor(s->sets, &set1, x_pos - 1);
	le_valor(s->sets, &set2, y_pos - 1);
	
	concatena(&set1, &set2);
	
	modifica_valor(s->sets, &set1, x_pos - 1);
	deleta_set(s, y_pos-1);
	return 1;
}

void mostra_todos_sets(DisjointSet s) {
	Lista set;
	int i;
	for (i = 0; i < s.sets.qtd; i++) {
		mostra_set(s, i);
	}
}

void desaloca_set(DisjointSet *s) {
	int i;
	for (i = 0; i < s->sets.qtd; i++) {
		deleta_set(s, i);
	}
	limpa_lista(&s->sets);
}
