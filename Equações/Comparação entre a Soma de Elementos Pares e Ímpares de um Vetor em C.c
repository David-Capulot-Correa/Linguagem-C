#include <stdio.h>

int main() {
    int V[50];
    int M, i;
    int somaPares = 0, somaImpares = 0;

    printf("Digite o tamanho do vetor (maximo 50): ");
    scanf("%d", &M);

    if (M > 50 || M <= 0) {
        printf("Tamanho invalido!\n");
        return 0;
    }

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < M; i++) {
        printf("V[%d] = ", i);
        scanf("%d", &V[i]);

        if (V[i] % 2 == 0) {
            somaPares += V[i];
        } else {
            somaImpares += V[i];
        }
    }

    printf("Soma dos pares = %d\n", somaPares);
    printf("Soma dos impares = %d\n", somaImpares);

    if (somaPares == somaImpares) {
        printf("A soma dos elementos pares é IGUAL a soma dos elementos impares.\n");
    } else {
        printf("A soma dos elementos pares é DIFERENTE da soma dos elementos impares.\n");
    }

    return 0;
}
