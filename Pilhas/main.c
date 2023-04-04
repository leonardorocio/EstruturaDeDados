#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand(time(0));
	// Exercicio 01
	//	inteiro_pra_binario(13);
	
	// Exercicio 02
	//	Pilha p1, p2;
	//	preenche_pilha(&p1, 5);
	//	preenche_pilha(&p2, 6);	
	//	concatena(&p1, &p2);
	
	// Exercicio 03
	//	char str[] = "teste";
	//	inverte(str);
	//	printf("%s", str);
	
	// Exercicio 04
	int teste = eh_palindrome("teste");
	printf("%s", teste ? "Palidromo": "Não Palindromo");

	return 0;
}




