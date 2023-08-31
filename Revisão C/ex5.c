#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
	if (n <= 1) {
		return 1;
	} else {
		return n * fatorial(n - 1);
	}
}

int main() {
	int n;
	printf("Digite o total de degraus:\n");
	scanf("%d", &n);
	int fatoriais[n+1];
	int i, ones = n, twos = 0, total = 0;
	for (i = 0; i <= n; fatoriais[i] = fatorial(i), i++);
	while (ones >= 0) {
		total += fatoriais[n] / (fatoriais[ones] * fatoriais[twos]);
		n--;
		ones -= 2;
		twos++;
	}
	printf("%d", total);
	return 0;
}
