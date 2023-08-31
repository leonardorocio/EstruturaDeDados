#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int v[MAX] = {2, 4, 6, 2, 5};
	int incl = v[0];
	int excl = 0, excl_new = 0, i;
	for (i = 1; i < MAX; i++) {
		// Máximo atual excluindo i
		excl_new = max(excl, incl);
		
		// Máximo atual incluindo i
		incl = excl + v[i];
		excl = excl_new;
	}
	printf("Resultado: %d", max(excl, incl));
	return 0;
}
