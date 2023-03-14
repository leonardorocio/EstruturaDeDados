#include <stdio.h>
#include <stdlib.h>

void troca_float(float *x, float *y);

int main() {
	float *x, *y;
	x = malloc(sizeof(float));
	y = malloc(sizeof(float));
	scanf("%f%f", x, y);
	printf("x: %f e y: %f\n", *x, *y);
	troca_float(x, y);
	printf("x: %f e y: %f\n", *x, *y);
	return 0;
}

void troca_float(float *x, float *y) {
	float flag = *x;
	*x = *y;
	*y = flag;
}
