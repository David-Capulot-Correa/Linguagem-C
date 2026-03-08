#include <stdio.h>

int main() {
    float nota1, nota2, media;
    int aulas_ministradas, aulas_assistidas;
    float frequencia;

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite o número total de aulas ministradas: ");
    scanf("%d", &aulas_ministradas);

    printf("Digite o número de aulas assistidas: ");
    scanf("%d", &aulas_assistidas);


    media = (nota1 + nota2) / 2;
    frequencia = (aulas_assistidas * 100.0) / aulas_ministradas;

    printf("\nMédia final: %.2f", media);
    printf("\nFrequência: %.2f%%", frequencia);


    if (media >= 6.0 && frequencia >= 75.0) {
        printf("\nSituação: APROVADO ✅\n");
    } else {
        printf("\nSituação: REPROVADO ❌\n");
    }

    return 0;
}
