#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TENTATIVAS 6


void desenharForca(int erros) {
    printf("\n");

    if (erros == 0) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else if (erros == 1) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else if (erros == 2) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else if (erros == 3) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else if (erros == 4) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else if (erros == 5) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" /    |\n");
        printf("      |\n");
        printf("=========\n");
    }
    else {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
        printf("=========\n");
    }
}


int main() {

    char palavras[][20] = {"computador", "programacao", "teclado", "internet", "algoritmo"};
    int totalPalavras = 5;

    srand(time(NULL));
    int indice = rand() % totalPalavras;

    char palavra[20];
    strcpy(palavra, palavras[indice]);

    int tamanho = strlen(palavra);

    char descoberta[20];
    for (int i = 0; i < tamanho; i++) {
        descoberta[i] = '_';
    }
    descoberta[tamanho] = '\0';

    int erros = 0;
    char letra;
    int acertou;

    while (erros < MAX_TENTATIVAS && strcmp(palavra, descoberta) != 0) {

        desenharForca(erros);

        printf("\nPalavra: %s\n", descoberta);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - erros);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        acertou = 0;

        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                descoberta[i] = letra;
                acertou = 1;
            }
        }

        if (!acertou) {
            erros++;
        }
    }

    desenharForca(erros);

    if (strcmp(palavra, descoberta) == 0) {
        printf("\n🎉 Voce ganhou! A palavra era: %s\n", palavra);
    } else {
        printf("\n💀 Voce perdeu! A palavra era: %s\n", palavra);
    }

    return 0;
}
