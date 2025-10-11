#include <stdio.h>

int main() {
    float num1, num2, resultado;
    char operacao;

    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    printf("\nEscolha a operação desejada:\n");
    printf("+  para soma\n");
    printf("-  para subtração\n");
    printf("*  para multiplicação\n");
    printf("/  para divisão\n");
    printf("Operação: ");
    scanf(" %c", &operacao); // espaço antes de %c para ignorar o ENTER anterior

    switch (operacao) {
        case '+':
            resultado = num1 + num2;
            printf("\nResultado: %.2f + %.2f = %.2f\n", num1, num2, resultado);
            break;

        case '-':
            resultado = num1 - num2;
            printf("\nResultado: %.2f - %.2f = %.2f\n", num1, num2, resultado);
            break;

        case '*':
            resultado = num1 * num2;
            printf("\nResultado: %.2f * %.2f = %.2f\n", num1, num2, resultado);
            break;

        case '/':
            if (num2 != 0) {
                resultado = num1 / num2;
                printf("\nResultado: %.2f / %.2f = %.2f\n", num1, num2, resultado);
            } else {
                printf("\nErro: divisão por zero não é permitida!\n");
            }
            break;

        default:
            printf("\nOperação inválida!\n");
            break;
    }

    return 0;
}
