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

void organiza_operadores(Pilha *p, char caracter, char *posfixo, int *index) {
	int empilhado;
	le_topo(*p, &empilhado);
	if (pilha_vazia(*p) || empilhado == '(') {
		empilha(p, caracter);
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

int executa_expressao(char posfixo[]) {
	Pilha p;
	inicializa_pilha(&p, strlen(posfixo));
	int i, n1, n2, resultado, zero_ascii = 48;
	for (i = 0; posfixo[i] != '\0'; i++) {
		if (posfixo[i] >= '0' && posfixo[i] <= '9') {
			empilha(&p, posfixo[i] - zero_ascii);
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
	char posfixo[strlen(infixo)];
	inicializa_pilha(&p, strlen(infixo));
	int i, erro = 0, index = 0;
	for (i = 0; infixo[i] != '\0' && !(erro); i++) {
		char caracter = infixo[i];
		switch(caracter) {
			case '0' ... '9':
				posfixo[index] = caracter;
				index++;
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
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				organiza_operadores(&p, caracter, posfixo, &index);
				break;
			default:
				printf("Erro. Caracter inválido: %c\n", caracter);
				erro = 1;
		}
	}
	
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
