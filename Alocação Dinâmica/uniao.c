#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2, int *p3);

int main() {
	int *v1, *v2, *p3, n1, n2, i, j;
	printf("Vetor 1: \n");
	printf("Tamanho: \n");
	scanf("%d", &n1);
	printf("Valores: \n");
	v1 = malloc(sizeof(int) * n1);
	for (i = 0; i < n1; i++) {
		scanf("%d", &v1[i]);
	}
	
	printf("Vetor 2: \n");
	printf("Tamanho: \n");
	scanf("%d", &n2);
	printf("Valores: \n");
	v2 = malloc(sizeof(int) * n2);
	for (i = 0; i < n2; i++) {
		scanf("%d", &v2[i]);
	}
	
	p3 = malloc(sizeof(int));
	int *unidos = uniao(v1, n1, v2, n2, p3);
	int visitados[*p3];
	for (i = 0; i < *p3; visitados[i] = 0, i++);
	for (i = 0; i < *p3; i++) {
		if (visitados[i]) {
			continue;
		}
			
		for (j = i; j < *p3; j++) {
			if (unidos[i] == unidos[j]) {
				visitados[j] = 1;
			}
		}
		printf("%d ", unidos[i]);
	}
	return 0;
}

int *uniao(int *v1, int n1, int *v2, int n2, int *p3) {
	int *unidos = malloc(sizeof(n1) * sizeof(int) + sizeof(n2) * sizeof(int));
	int i;
	*p3 = 0;
	for (i = 0; i < n1; i++) {
		unidos[*p3] = v1[i];
		(*p3)++;
	}
	
	for (i = 0; i < n2; i++) {
		unidos[*p3] = v2[i];
		(*p3)++;
	}
	return unidos;
}
