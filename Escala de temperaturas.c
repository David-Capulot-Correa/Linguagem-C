#include <stdio.h>

int main() {
    int op;
    float temp, C, F, K;

    printf("Escolha a escala de entrada:\n");
    printf("1-Celsius\n2-Fahrenheit\n3-Kelvin\nEscolha: ");
    scanf("%d", &op);

    printf("Digite o valor da temperatura: ");
    scanf("%f", &temp);

    if (op == 1) { // De Celsius para outras
        F = (temp * 9 / 5) + 32;
        K = temp + 273.15;
        printf("Fahrenheit: %.2f\nKelvin: %.2f\n", F, K);
    } 
    else if (op == 2) { // De Fahrenheit para outras
        C = (temp - 32) * 5 / 9;
        K = C + 273.15;
        printf("Celsius: %.2f\nKelvin: %.2f\n", C, K);
    } 
    else if (op == 3) { // De Kelvin para outras
        C = temp - 273.15;
        F = (C * 9 / 5) + 32;
        printf("Celsius: %.2f\nFahrenheit: %.2f\n", C, F);
    }

    return 0;
}