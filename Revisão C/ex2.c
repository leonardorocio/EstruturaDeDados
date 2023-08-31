#include <stdio.h>
#include <stdlib.h>

#define MAX 3

int main() {
	int v[MAX] = {3, 2, 1};
	int t[MAX];
	int prod = 1, i;
	for (i = 0; i < MAX; prod *= v[i], i++);
	for (i = 0; i < MAX; i++) {
		t[i] = prod / v[i];
		printf("%d\n", t[i]);
	}
	return 0;
}
