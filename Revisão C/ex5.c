#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	printf("Digite o total de degraus:\n");
	scanf("%d", &n);
	int fatoriais[n+1];
	int i, ones = n, twos = 0, total = 0;
	fatoriais[0] = 1;
	for (i = 1; i <= n; fatoriais[i] = fatoriais[i-1] * i, i++);
	while (ones >= 0) {
		total += fatoriais[n] / (fatoriais[ones] * fatoriais[twos]);
		n--;
		ones -= 2;
		twos++;
	}
	printf("%d", total);
	return 0;
}
