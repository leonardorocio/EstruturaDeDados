#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int compare(const void* a, const void* b) {
	return *((int*) a) - *((int*) b);
}

int main() {
	int v[MAX] = {1, 2, 0};
	qsort(v, MAX, sizeof(int), compare);
	int menor_ausente = 1, i;
	for (i = 0; i < MAX;  i++) {
		if (v[i] >= 0 && v[i] - menor_ausente == 0) {
			menor_ausente++;
		}
	}
	printf("%d", menor_ausente);
	return 0;
}
