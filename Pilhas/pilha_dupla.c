#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	int *dados;
	int topo1, topo2;
	int capacidade;
} PilhaDupla;

void inicializa(PilhaDupla *p, int capacidade) {
	p->capacidade = capacidade;
	p->topo1 = -1;
	p->topo2 = capacidade;
	p->dados = malloc(sizeof(int) * capacidade);
}

int pilha1_vazia(PilhaDupla p) {
	return p.topo1 == -1;
}

int pilha2_vazia(PilhaDupla p) {
	return p.topo2 == p.capacidade;
}

int pilhas_cheias(PilhaDupla p) {
	return (p.topo1 + 1 == p.topo2);
}

int empilha1(PilhaDupla *p, int valor) {
	if (pilhas_cheias(*p)) {
		return 0;
	}
	
	p->topo1++;
	p->dados[p->topo1] = valor;
	return 1;
}

int empilha2(PilhaDupla *p, int valor) {
	if (pilhas_cheias(*p)) {
		return 0;
	}
	
	p->topo2--;
	p->dados[p->topo2] = valor;
	return 1;
}

int desempilha1(PilhaDupla *p, int *valor) {
	if (pilha1_vazia(*p)) {
		return 0;
	}
	
	*valor = p->dados[p->topo1];
	p->topo1--;
	return 1;
}

int desempilha2(PilhaDupla *p, int *valor) {
	if (pilha2_vazia(*p)) {
		return 0;
	}
	
	*valor = p->dados[p->topo2];
	p->topo2++;
	return 1;
}


