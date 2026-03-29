#include <stdio.h>

int main() {
    char str1[100], str2[100];

    // Leitura das duas strings
    printf("Digite a primeira palavra: ");
    scanf("%s", str1);
    printf("Digite a segunda palavra: ");
    scanf("%s", str2);

    // Impressão das strings completas
    printf("\nVocê digitou: %s e %s\n", str1, str2);

    // Impressão da segunda letra (índice 1)
    printf("A segunda letra da primeira string é: %c\n", str1[10]);
    printf("A segunda letra da segunda string é: %c\n", str2[1]);

    return 0;
}
