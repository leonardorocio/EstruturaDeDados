#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char *entrada = malloc(sizeof(char) * 255);
	scanf("%[^\n]", entrada);
	converte_expressao(entrada);
}
