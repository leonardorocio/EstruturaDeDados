#include "Lista.h"

#define ERRO_COORD_INVALIDA -1
#define ERRO_SET_EXISTENTE -1
#define ERRO_SET_INEXISTENTE -1

typedef struct {
	Lista sets;
} DisjointSet;

int compara(void *a, void *b);
void mostra_int(void *x);
void inicializa_set(DisjointSet *s);
int busca_set(DisjointSet *s, void *x);
int cria_set(DisjointSet *s, void *x);
void mostra_set(DisjointSet s, int pos);
void deleta_set(DisjointSet *s, int pos);
int unir_sets(DisjointSet *s, void *x, void *y);
void mostra_todos_sets(DisjointSet s);
void desaloca_set(DisjointSet *s);
