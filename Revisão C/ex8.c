#include <stdio.h>
#include <stdlib.h>
#include "Pilha.c"
#include <string.h>

int main() {
    Pilha p1;
    char *string = "([]) [[] ({})";
    inicializa_pilha(&p1, strlen(string));
    int i, balanced = 1;
    for (i = 0; string[i] != '\0' && balanced; i++) {
        if (string[i] == ' ') {
            continue;
        }

        if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
            int c = (int) string[i];
            empilha(&p1, c);
        } else if (string[i] == ')' || string[i] == ']' || string[i] == '}') {
            int x;
            desempilha(&p1, &x);
            if (string[i] - x > 2) {
                balanced = 0;
                break;
            }
        }
    }
    printf("%d", balanced && pilha_vazia(p1));
    return 0;
}