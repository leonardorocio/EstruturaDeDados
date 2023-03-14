#include <stdio.h>
#include <stdlib.h>

#define PI 3.14

void ap_circulo(float raio, float *pCirculo, float *pArea);

int main() {
	float *raio, *pCirculo, *pArea;
	raio = malloc(sizeof(float));
	pCirculo = malloc(sizeof(float));
	pArea = malloc(sizeof(float));
	scanf("%f", raio);
	ap_circulo(*raio, pCirculo, pArea);
	printf("Area: %f e Perimetro: %f", *pCirculo, *pArea);
	return 0;
}

void ap_circulo(float raio, float *pCirculo, float *pArea) {
	*pCirculo = 2 * PI * raio;
	*pArea = PI * (raio * raio);
}
