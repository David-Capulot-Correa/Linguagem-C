#include <stdio.h>

int main() {
    int numero;
    int opcao;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    printf("\nEscolha uma opção:\n");
    printf("1 - Saber se o número é par ou ímpar\n");
    printf("2 - Saber se o número corresponde a um ano bissexto\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        if (numero % 2 == 0) {
            printf("\nO número %d é PAR.\n", numero);
        } else {
            printf("\nO número %d é ÍMPAR.\n", numero);
        }

    } else if (opcao == 2) {
        if ((numero % 400 == 0) || (numero % 4 == 0 && numero % 100 != 0)) {
            printf("\nO ano %d é BISSEXTO.\n", numero);
        } else {
            printf("\nO ano %d NÃO é bissexto.\n", numero);
        }

    } else {
        printf("\nOpção inválida!\n");
    }

    return 0;
}
