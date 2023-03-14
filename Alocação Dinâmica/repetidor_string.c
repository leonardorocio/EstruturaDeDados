#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor(char *s, int n);

int main() {
	char *s;
	s = calloc(100, sizeof(char));
	// Se for usar malloc, fazer s[0] = '\0'
	int n;
	scanf("%s", s);
	scanf("%d", &n);
	char *repetida = repetidor(s, n);
	printf("%s", repetida);
	free(repetida);
	return 0;
}

char *repetidor(char *s, int n) {
	char *repeat = calloc((strlen(s) * n) + 1, sizeof(char));
	int i;
	printf("%s", repeat);
	for (i = 0; i < n; i++) {
		strcat(repeat, s);
	}
	return repeat;
}
