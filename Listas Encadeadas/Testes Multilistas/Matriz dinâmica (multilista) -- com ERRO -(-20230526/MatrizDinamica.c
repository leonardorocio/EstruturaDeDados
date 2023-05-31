#include "MatrizDinamica.h"
#include <stdio.h>

void inicializa_matriz( MatrizDinamica *p, int l, int c ){
	p->lin = l;
	p->col = c;
	int i, j, valor;
	inicializa_lista(&p->matriz, sizeof(Lista));
	Lista linha;
	for( i = 0 ; i < l ; i++ ){	
		inicializa_lista( &linha, sizeof(int) );
		for( j = 0 ; j < c ; j++ ){
			valor = 99;
			insere_fim( &linha, &valor );
		}
		insere_fim( &p->matriz, &linha );
	}
}

void mostra_inteiro( void *x ){
	printf("%d\n", *(int*)x);
}

void mostra_matriz( MatrizDinamica m ){
	int i, j, valor;
	Lista linha;
	inicializa_lista(&linha, sizeof(int));
	printf("Matriz %dx%d:\n", m.lin, m.col);
	for( i = 0 ; i < m.lin ; i++ ){
		le_valor( m.matriz, &linha, i );
		mostra_lista( linha, mostra_inteiro );
		printf("\n");
	}
}

int modifica( MatrizDinamica *m, int i, int j, int valor ){
	if( i >= m->lin || i < 0 || j >= m->col || j < 0 )
		return ERRO_COORD_INVALIDA;
	
	Lista linha;
	if( le_valor( m->matriz, &linha, i ) == ERRO_POS_INVALIDA)
		return ERRO_COORD_INVALIDA;
	
	if( modifica_valor( linha, &valor, j ) == ERRO_POS_INVALIDA)
		return ERRO_COORD_INVALIDA;
	
	return 1; // Sucesso.
}

