#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ex02.c"

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
	mostra_fila(f1);
	printf("\n");
	inverte_fila(&f1);
	mostra_fila(f1);
	
	// Exercicio 02
	FilaRuim fr;
	inicializa_fila(&fr, 5);
	inserir_ruim(&fr, 7);
	inserir_ruim(&fr, 5);
	inserir_ruim(&fr, 3);
	inserir_ruim(&fr, 8);
	mostra_filar(fr);
	
	int x;
	remover_ruim(&fr, &x);
	mostra_filar(fr);
	remover_ruim(&fr, &x);
	mostra_filar(fr);
//	

//	int x;
//	remover( &f1, &x );
//	printf("X = %d\n", x);
//	mostra_fila( f1 );
//	remover( &f1, &x );
//	printf("X = %d\n", x);
//	mostra_fila( f1 );
	
//	inserir( &f1, 15 );
//	inserir( &f1, 18 );
//	mostra_fila( f1 );
	return 0;
}
