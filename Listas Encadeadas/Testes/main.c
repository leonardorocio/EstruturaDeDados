#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int binary_search(int v[], int st, int ed, int x) {
	if (ed >= st) {
		int mid = (st + ed) / 2;
		
		if (v[mid] == x) {
			return mid; 
		} else if (v[mid] > x) {
			return binary_search(v, st, mid - 1, x); 
		} else {
			return binary_search(v, mid + 1, ed, x);
		}
	}
	return -1;
}


int main(int argc, char *argv[]) {
	
	// Vetor exemplo com as notas dos 10 alunos;
	float notas[10] = {8.3, 7.1, 5.0, 9.5, 10.0, 8.1, 7.4, 6.9, 8.0, 9.7};
	
	// Maior nota
	int i;
	float maior = notas[0];
	for (i = 0; i < 10; i++) {
		if (maior < notas[i]) {
			maior = notas[i];
		}
	}
	
	// Média das notas
	
	float soma = 0, media;
	for (i = 0; i < 10; i++) {
		soma += notas[i];
	}
	media = soma / 10;
	
	// Notas maiores que a média
	int maiores_q_media = 0;
	for (i = 0; i < 10; i++) {
		if (notas[i] > media) {
			maiores_q_media++;
		}
	}
	
}
