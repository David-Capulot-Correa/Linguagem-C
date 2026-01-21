#include <stdio.h>

int main() {
    float altura,peso;

    printf("Digite a sua altura (m): ");
    scanf("%f", &altura);

  peso = (72.7 * altura) - 58;

    printf("Seu IMC e: %.2f\n", peso);

    return 0;
}