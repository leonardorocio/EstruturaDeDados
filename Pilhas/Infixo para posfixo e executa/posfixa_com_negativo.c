#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"

void fecha_parenteses(Pilha *p, char *posfixo, int *index) {
	int empilhado;
	while( le_topo(*p, &empilhado) != ERRO_PILHA_VAZIA && empilhado != '(') {
		desempilha(p, &empilhado);
		posfixo[*index] = empilhado;
		(*index)++;
	}
}

int precedencia(char operador) {
	if (operador == '(') {
		return 0;
	}
	else if (operador == '+' || operador == '-') {
		return 1;
	}
	else {
		return 2;
	}
}

void organiza_operadores(Pilha *p, char caracter, char *posfixo, int *index, int *sinal) {
	int empilhado;
	le_topo(*p, &empilhado);
	if (pilha_vazia(*p) || empilhado == '(') {
		if (!(*sinal)) {
			empilha(p, caracter);
		} else {
			posfixo[(*index)++] = '_';
		}
	}
	else {
		while (le_topo(*p, &empilhado) != ERRO_PILHA_VAZIA && precedencia(empilhado) >= precedencia(caracter)) {
			desempilha(p, &empilhado);
			posfixo[*index] = empilhado;
			(*index)++;
		}
		empilha(p, caracter); 
	}
}

int executa_operacao(int n1, int n2, char c) {
	switch(c) {
		case '+':
			return n1 + n2;
		case '-':
			return n2 - n1;
		case '*':
			return n1 * n2;
		case '/':
			return n2 / n1;
	}
}

int eh_sinal_negativo(char *infixo, int *pos, char caracter) {
	if ((infixo[(*pos) - 1] == '(' || (*pos) == 0) && caracter == '-') {
		return 1;
	}
	return 0;
}

int calcula_operando(char *posfixo, int *index, int *sinal) {
	int n = 0;
	while (posfixo[(*index)] >= '0' && posfixo[(*index)] <= '9') {
		n = n * 10 + (int) (posfixo[(*index)] - '0');
		(*index)++;
	}
	(*index)--;
	n = (*sinal) == 1 ? n * (-1) : n;
	(*sinal) = 0;
	return n;
}

int executa_expressao(char posfixo[]) {
	Pilha p;
	inicializa_pilha(&p, strlen(posfixo));
	int i, n1, n2, resultado, zero_ascii = 48, sinal = 0;
	for (i = 0; posfixo[i] != '\0'; i++) {
		if (posfixo[i] == ' ')
			continue;
		if (posfixo[i] == '_') {
			sinal = 1;
			continue;
		}
		if (posfixo[i] >= '0' && posfixo[i] <= '9') {
			int n = calcula_operando(posfixo, &i, &sinal);
			empilha(&p, n);
		} else {
			desempilha(&p, &n1);
			desempilha(&p, &n2);
			int resultado = executa_operacao(n1, n2, posfixo[i]);
			empilha(&p, resultado);
		}	
	}
	desempilha(&p, &resultado);
	return resultado;
}

void converte_expressao(char infixo[]) {
	Pilha p;
	char posfixo[strlen(infixo) * 2];
	inicializa_pilha(&p, strlen(infixo));
	int *signs = calloc(strlen(infixo), sizeof(int));
	int i, erro = 0, index = 0, sinal = 0;
	for (i = 0; infixo[i] != '\0' && !(erro); i++) {
		char caracter = infixo[i];
		switch(caracter) {
			case '0' ... '9':
				posfixo[index++] = caracter;
				break;
			case '(':
				empilha(&p, caracter);
				break;
			case ')':
				fecha_parenteses(&p, posfixo, &index);
				if (pilha_vazia(p)) {
					printf("')' sem '('");
					erro = 1;
				} else {
					int aux;
					desempilha(&p, &aux); // Apenas pro lixo;
				}
				posfixo[index++] = ' ';
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				sinal = eh_sinal_negativo(infixo, &i, caracter);
				organiza_operadores(&p, caracter, posfixo, &index, &sinal);
				posfixo[index++] = ' ';
				break;
			default:
				printf("Erro. Caracter inválido: %c\n", caracter);
				erro = 1;
		}
	}
	posfixo[index++] = ' ';
	
	if (!(erro)) {
		fecha_parenteses(&p, posfixo, &index);
		if (pilha_vazia(p)) {
			posfixo[index] = '\0';
			printf("%s\n", posfixo);
			printf("Resultado: %d\n", executa_expressao(posfixo));
		} else {
			printf("Erro: '(' não foi fechado");
		}
	}
}

int main(int argc, char *argv[]) {
	char *entrada = malloc(sizeof(char) * 255);
	scanf("%[^\n]", entrada);
	converte_expressao(entrada);
}
