#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 3

int main(int argc, char const *argv[]) {
    int v[MAX] = {3, 2, 1};
    int ps_size = pow(2, 3);
    int i, j;
    for (i = 0; i < ps_size; i++) {
        for (j = 0; j < MAX; j++) {
            if (i & (1 << j)) {
                printf("%d", v[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
