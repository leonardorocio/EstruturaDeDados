#include <stdio.h>
#include <stdlib.h>

#define MAX 6

int maior(int t[], int st, int end) {
	int i, maior = t[st];
	for (i = st; i < end; i++) {
		if (t[i] > maior) {
			maior = t[i];
		}
	}
	return maior;
}

int main() {
	int v[MAX] = {10, 5, 2, 7, 8, 7};
	int k = 3, s = MAX - 3;
	int r[s+1];
	int i;
	for (i = 0; i <= s; i++) {
		r[i] = maior(v, i, i+k);
		printf("%d\n", r[i]);
	}
	return 0;
}
