#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"
#include "Fila.h"
#include "Pilha.h"

typedef struct {
	int *dados;
	int ini, fim;
	int capacidade;
} FilaRuim;

typedef struct {
	Pilha p1, p2;
} FilaPilha;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Fila f1;
	inicializa_fila( &f1, 4);
//	mostra_fila( f1 );
//	
	inserir( &f1, 3 );
//	mostra_fila( f1 );
//	
	inserir( &f1, 6 );
//	mostra_fila( f1 );
////	
	inserir( &f1, 9 );
//	mostra_fila( f1 );
////	
	inserir( &f1, 12 );
//	mostra_fila( f1 );

	// Exercicio 01
//	mostra_fila(f1);
//	printf("\n");
//	inverte_fila(&f1);
//	mostra_fila(f1);
//	
	// Exercicio 02
//	FilaRuim fr;
//	inicializa_filar(&fr, 5);
//	inserir_ruim(&fr, 7);
//	inserir_ruim(&fr, 5);
//	inserir_ruim(&fr, 3);
//	inserir_ruim(&fr, 8);
//	mostra_filar(fr);
//	printf("\n");
//	
//	int x;
//	remover_ruim(&fr, &x);
//	mostra_filar(fr);
//	printf("\n");
//	remover_ruim(&fr, &x);
//	mostra_filar(fr);

//	// Exercicio 03
//	FilaPilha fp;
//	inicializa_fila_pilha(&fp, 4);
//	inserir_fila_pilha(&fp, 7);
//	inserir_fila_pilha(&fp, 3);
//	inserir_fila_pilha(&fp, 5);
//	inserir_fila_pilha(&fp, 8);
//	mostra_fila_pilha(fp);
//	
//	int x;
//	remover_fila_pilha(&fp, &x);
////	printf("%d\n", x);
//	mostra_fila_pilha(fp);
//
//	inserir_fila_pilha(&fp, 10);
//	mostra_fila_pilha(fp);
////	
//	remover_fila_pilha(&fp, &x);
////	printf("%d\n", x);
//	mostra_fila_pilha(fp);
//////	
//	remover_fila_pilha(&fp, &x);
////	printf("%d\n", x);
//	mostra_fila_pilha(fp);
////	
//	remover_fila_pilha(&fp, &x);
////	printf("%d\n", x);
////	mostra_fila_pilha(fp);
//////	
//	remover_fila_pilha(&fp, &x);
////	printf("%d\n", x);
////	mostra_fila_pilha(fp);

	// Exercicio 04
	Deque d;
	inicializa_deque(&d, 5);
	inserir_fim(&d, 3);
	inserir_fim(&d, 4);
	inserir_fim(&d, 5);
	mostra_deque(d);
	
	int x;
	remover_inicio(&d, &x);
	mostra_deque(d);
	
	inserir_inicio(&d, 10);
	mostra_deque(d);
	
	remover_fim(&d, &x);
	mostra_deque(d);
	
	inserir_inicio(&d, 7);
	mostra_deque(d);
	
	remover_fim(&d, &x);
	mostra_deque(d);
	
	remover_inicio(&d, &x);
	mostra_deque(d);
	
	
	return 0;
}
