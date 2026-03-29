#include <stdio.h>

int main() {
    int i, quantidade, codigo;
    float nota1, nota2, media;

    printf("Digite a quantidade de alunos: ");
    scanf("%d", &quantidade);

    for (i = 1; i <= quantidade; i++) {
        printf("\nAluno %d\n", i);

        printf("Digite o codigo do aluno: ");
        scanf("%d", &codigo);

        printf("Digite a primeira nota: ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: ");
        scanf("%f", &nota2);

        media = (nota1 + nota2) / 2;

        printf("Codigo do aluno: %d\n", codigo);
        printf("Media: %.2f\n", media);
    }

    printf("\nCalculo de medias finalizado.\n");

    return 0;
}
