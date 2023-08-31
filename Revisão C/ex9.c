#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    //              4A3B2C1D2A
    char *string = "AAAABBBCCDAA";
    int size = strlen(string);
    int *result = calloc(size, sizeof(int));
    int i, k = 0, count = 1;
    for (i = 0; i < size; i++) {
        if (string[i] == string[i+1]) {
            count++;
        } else {
            result[k++] = count + 48;
            result[k++] = (int) string[i];
            count = 1;
        }
    }
    for (i = 0; i < size; i++) {
        printf("%c", (char) result[i]);
    }
    return 0;
}
