#include <stdio.h>
#include <stdlib.h>
#include "DisjointSet.h"

int main(int argc, char *argv[]) {
//	MatrizDinamica m;
//	
//	inicializa_matriz( &m, 3, 4);
//	modifica( &m, 0, 0, 100 );
//	modifica( &m, 1, 0, 100 );
//	modifica( &m, 2, 0, 100 );
//	mostra_matriz( m );

	DisjointSet s;
	inicializa_set(&s);
	
	int x = 1, y = 2;
	cria_set(&s, &x);
	x = 2;
	cria_set(&s, &x);
	x = 3;
	cria_set(&s, &x);
	x = 4;
	cria_set(&s, &x);
	
	unir_sets(&s, &x, &y);
//	
	cria_set(&s, &x);
	
	mostra_todos_sets(s);
	
	return 0;
}
