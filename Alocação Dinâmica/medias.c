#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float *acimaDaMedia(float *v, int n, int *pIndex);
float calculaMedia(float *v, int n);

int main() {
	float *v;
	int n;
	scanf("%d", &n);
	v = malloc(sizeof(float) * n);
	int i;
	for (i = 0; i < n; i++) {
		scanf("%f", &v[i]);
	}
	int *pIndex = malloc(sizeof(int));
	float *mds = acimaDaMedia(v, n, pIndex);
	for (i = 0; i < (*pIndex) - 1; i++) {
		printf("%d: %f\n", i, mds[i]);
	}
	return 0;
}

float calculaMedia(float *v, int n) {
	int i;
	float media, soma = 0;
	for (i = 0; i < n; i++) {
		soma += v[i];
	}
	media = soma / n;
	return media;
}

float *acimaDaMedia(float *v, int n, int *pIndex) {
	float *acimaMedia = malloc(sizeof(float));
	float media = calculaMedia(v, n);
	*pIndex = 1;
	int i;
	for (i = 0; i < n; i++) {
		if (v[i] > media) {
			acimaMedia[*pIndex - 1] = v[i];
			acimaMedia = realloc(acimaMedia, sizeof(acimaMedia) + sizeof(float));
			(*pIndex)++;
		}
	}
	return acimaMedia;
}
