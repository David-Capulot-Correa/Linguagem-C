#include <stdio.h>

float calcular(float a, float b, char operador) {
    if (operador == '+') {
        return a + b;
    } 
    else if (operador == '-') {
        return a - b;
    } 
    else if (operador == '*') {
        return a * b;
    } 
    else if (operador == '/') {
        if (b != 0)
            return a / b;
        else
            return 0;
    } 
    else {
        return 0;
    }
}

int main() {
    float num1, num2, resultado;
    char op;

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Digite o segundo numero: ");
    scanf("%f", &num2);

    resultado = calcular(num1, num2, op);

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
