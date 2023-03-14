#include <stdio.h>
#include <stdlib.h>

float *clone(float *v, int n);

int main() {
	float *v;
	int i, n;
	scanf("%d", &n);
	v = malloc(sizeof(float) * n);
	for (i = 0; i < n; i++) {
		printf("%d: ", i);
		scanf("%f", &v[i]);
	}
	float *t = clone(v, n);
	for (i = 0; i < n; i++) {
		printf("%d: %f\n", i, t[i]);
	}
	free(v);
	free(t);
	return 0;
}

float *clone(float *v, int n) {
	float *t = malloc(sizeof(float) * n);
	int i;
	for(i = 0; i < n; i++) {
		t[i] = v[i];
	}
	return t;
}
