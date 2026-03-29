#include <stdio.h>

int main() {
    int origem, destino;
    float temp, resultado;

    printf("Escolha a escala de ORIGEM:\n");
    printf("1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\nEscolha: ");
    scanf("%d", &origem);

    printf("Digite a temperatura: ");
    scanf("%f", &temp);

    printf("\nEscolha a escala de DESTINO:\n");
    printf("1 - Celsius\n2 - Fahrenheit\n3 - Kelvin\nEscolha: ");
    scanf("%d", &destino);

    if (origem == 1 && destino == 2)
        resultado = (temp * 9 / 5) + 32;
    else if (origem == 1 && destino == 3)
        resultado = temp + 273.15;
        
    else if (origem == 2 && destino == 1)
        resultado = (temp - 32) * 5 / 9;
    else if (origem == 2 && destino == 3)
        resultado = ((temp - 32) * 5 / 9) + 273.15;

    else if (origem == 3 && destino == 1)
        resultado = temp - 273.15;
    else if (origem == 3 && destino == 2)
        resultado = (temp - 273.15) * 9 / 5 + 32;

    else if (origem == destino)
        resultado = temp;

    else {
        printf("Opcao invalida!\n");
        return 0;
    }

    printf("\nResultado: %.2f\n", resultado);

    return 0;
}
