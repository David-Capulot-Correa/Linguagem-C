#include <stdio.h>

int main() {
    int i;

    printf("Números inteiros positivos divisíveis por 4 e menores que 200:\n");

    for (i = 1; i < 200; i++) {
        if (i % 4 == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
