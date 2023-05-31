#include "Lista.h"

#define ERRO_COORD_INVALIDA -1

typedef struct{
	Lista matriz;
	int lin, col;
} MatrizDinamica;

void inicializa_matriz( MatrizDinamica *p, int l, int c );
void mostra_matriz( MatrizDinamica m );
int modifica( MatrizDinamica *m, int i, int j, int valor );

