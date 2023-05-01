#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *dados;
	int ini, fim;
	int capacidade;
} FilaRuim;

void inicializa_filar(FilaRuim *f, int size) {
	f->dados = malloc(sizeof(int) * size);
	f->ini = 0;
	f->fim = 0;
	f->capacidade = size;
}

int filar_vazia(FilaRuim f) {
	return f.fim == 0;
}

void reorganiza_array(int *dados, int fim) {
	int i;
	for (i = 0; i < fim - 1; i++) {
		dados[i] = dados[i+1];
		printf("%d e %d\n", dados[i], dados[i+1]);
	}
}

int filar_cheia(FilaRuim f) {
	return f.fim == f.capacidade - 1;
}

int inserir_ruim(FilaRuim *f, int v) {
	if (filar_cheia(*f))
		return -1;
		
	int final = (f->fim) % f->capacidade;
	f->dados[final] = v;
	f->fim++;
	return 1;
}

int remover_ruim(FilaRuim *p, int *info){
	if( filar_vazia( *p ) )
		return -2;
	
	*info = p->dados[p->ini];
	reorganiza_array(p->dados, p->fim);
	p->fim--;
	
	return 1;
}

void mostra_filar(FilaRuim f) {
	int i = f.ini, cont;
	for (cont = 0; cont < f.fim; cont++) {
		printf("[%d]: %d\n", i, f.dados[i]);
		i = (i + 1) % f.capacidade;
	}
}


