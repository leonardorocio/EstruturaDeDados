#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Pilha.h"

void teste() {
	if (1 == 1)
		return;
		
	printf("OPA");
}

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
	//	int teste = eh_palindrome("teste");
	//	printf("%s", teste ? "Palidromo": "Não Palindromo");
	
	// Exercicio 05
	//	inverte_frase("AMU MEGASNEM ATERCES");

	// Exercicio 06
	//	int teste = valida_expressao("((((((()))))))");
	//	printf("%d", teste);

	// Exercicio 07

	// Trabalho Pilhas
	
	printf("Digite uma expressao numerica (sem espacos): \n");
	char *entrada = malloc(sizeof(char) * 255);
	scanf("%[^\n]", entrada);
//	converte_expressao("(5+9)*2+6*5");
//	converte_expressao("(5+9)*((2+6)*5)");
//	
	converte_expressao(entrada);

	return 0;
}




