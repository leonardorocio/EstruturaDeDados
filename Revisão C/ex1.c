#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define MAX 4

int main() {
	// Ainda tá bugado KKKKKKKKKKKKK
	int v[MAX] = {10, 15, 3, 7};
	int *freq = calloc(N, sizeof(int));
	int i, k = 17 , found = 0;
	for (i = 0; i < MAX && !found; i++) {
		int cmp = k - v[i]; 
		if (!freq[v[i]]){
			freq[v[i]]++;
		}
		if (freq[cmp] && freq[cmp] > 1) {
			found = 1;
		}
	}
	printf(found ? "Achou" : "Não achou");
	return 0;
}
