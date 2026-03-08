#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero inteiro positivo maior que 1: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Numero invalido.\n");
        return 0;
    }

    printf("Sequencia de Collatz:\n");

    while (n != 1) {
        printf("%d -> ", n);

        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }

    printf("1\n");

    return 0;
}
