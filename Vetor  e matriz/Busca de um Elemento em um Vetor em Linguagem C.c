#include <stdio.h>

int main() {
    int A[50];
    int N, k;
    int i, encontrado = 0;

    printf("Digite a quantidade de elementos do vetor (maximo 50): ");
    scanf("%d", &N);

    if (N > 50 || N <= 0) {
        printf("Quantidade invalida!\n");
        return 0;
    }

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }

    printf("Digite o valor k que deseja buscar: ");
    scanf("%d", &k);

    printf("Posicoes onde %d foi encontrado:\n", k);

    for (i = 0; i < N; i++) {
        if (A[i] == k) {
            printf("%d ", i);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Elemento nao encontrado no vetor.");
    }

    return 0;
}
