#include <stdio.h>
#include <stdlib.h>

void calcula_hora(int totalMinutos, int *ph, int *pm);

int main() {
	int minutos, *pHora, *pMinuto;
	pHora = malloc(sizeof(int));
	pMinuto = malloc(sizeof(int));
	scanf("%d", &minutos);
	calcula_hora(minutos, pHora, pMinuto);
	printf("%d:%d", *pHora, *pMinuto);
	return 0;
}

void calcula_hora(int totalMinutos, int *ph, int *pm) {
	*ph = totalMinutos / 60;
	*pm = totalMinutos % 60;
}
