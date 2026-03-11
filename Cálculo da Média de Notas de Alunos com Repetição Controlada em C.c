#include <stdio.h>

int main() {
    float nota1, nota2, media;
    char continuar;

    do {
        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        printf("A media do aluno é: %.2f\n", media);

        printf("Deseja calcular a media de outro aluno? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("Programa encerrado.\n");

    return 0;
}
