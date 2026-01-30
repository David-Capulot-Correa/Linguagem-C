#include <stdio.h>

int main() {
    int n;
    long long fatorial = 1;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Não existe fatorial de número negativo!\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            fatorial *= i;
        }

        printf("%d! = %lld\n", n, fatorial);
    }

    return 0;
}

