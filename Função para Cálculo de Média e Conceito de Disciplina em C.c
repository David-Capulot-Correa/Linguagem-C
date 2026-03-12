#include <stdio.h>

char calcularConceito(float p1, float p2, float t) {
    float media;
    media = (p1 + p2 + t) / 3;

    if (media >= 9.0) {
        return 'A';
    } 
    else if (media >= 7.5) {
        return 'B';
    } 
    else if (media >= 6.0) {
        return 'C';
    } 
    else {
        return 'D';
    }
}

int main() {
    float P1, P2, T;
    char conceito;

    printf("Digite a nota da P1: ");
    scanf("%f", &P1);

    printf("Digite a nota da P2: ");
    scanf("%f", &P2);

    printf("Digite a nota do trabalho final: ");
    scanf("%f", &T);

    conceito = calcularConceito(P1, P2, T);

    printf("Conceito final: %c\n", conceito);

    return 0;
}
