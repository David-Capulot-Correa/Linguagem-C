#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {

    char palavras[10][30] = {
        "programacao",
        "computador",
        "memoria",
        "algoritmo",
        "compilador",
        "estrutura",
        "variavel",
        "software",
        "hardware",
        "internet"
    };

    srand(time(NULL));
    int indice = rand() % 10;

    char palavra[30];
    int i = 0;

    while (palavras[indice][i] != '\0') {
        palavra[i] = palavras[indice][i];
        i++;
    }
    palavra[i] = '\0';

    int tamanho = strlen(palavra);

    char descoberta[30];
    for (i = 0; i < tamanho; i++) {
        descoberta[i] = '_';
    }
    descoberta[tamanho] = '\0';

    char usadas[26];
    int totalUsadas = 0;

    int erros = 0;
    int maxErros = 6;
    char letra;

    printf("===== JOGO DA FORCA =====\n");
    printf("Tema: Tecnologia\n");

    while (erros < maxErros) {

        int ganhou = 1;
        for (i = 0; i < tamanho; i++) {
            if (descoberta[i] == '_') {
                ganhou = 0;
                break;
            }
        }

        if (ganhou == 1) {
            break;
        }

        // DESENHO DA FORCA
        printf("\n  +---+\n");
        printf("  |   |\n");

        if (erros >= 1)
            printf("  O   |\n");
        else
            printf("      |\n");

        if (erros == 2)
            printf("  |   |\n");
        else if (erros == 3)
            printf(" /|   |\n");
        else if (erros >= 4)
            printf(" /|\\  |\n");
        else
            printf("      |\n");

        if (erros == 5)
            printf(" /    |\n");
        else if (erros >= 6)
            printf(" / \\  |\n");
        else
            printf("      |\n");

        printf("      |\n");
        printf("=========\n");

        printf("\nErros: %d\n", erros);
        printf("Palavra: %s\n", descoberta);

        printf("Letras usadas: ");
        for (i = 0; i < totalUsadas; i++) {
            printf("%c ", usadas[i]);
        }

        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);

        int repetida = 0;
        for (i = 0; i < totalUsadas; i++) {
            if (usadas[i] == letra) {
                repetida = 1;
            }
        }

        if (repetida == 1) {
            printf("Letra ja usada!\n");
            continue;
        }

        usadas[totalUsadas] = letra;
        totalUsadas++;

        int acertou = 0;

        for (i = 0; i < tamanho; i++) {
            if (palavra[i] == letra) {
                descoberta[i] = letra;
                acertou = 1;
            }
        }

        if (acertou == 0) {
            erros++;
        }
    }

    // DESENHO FINAL
    printf("\n  +---+\n");
    printf("  |   |\n");

    if (erros >= 1)
        printf("  O   |\n");
    else
        printf("      |\n");

    if (erros == 2)
        printf("  |   |\n");
    else if (erros == 3)
        printf(" /|   |\n");
    else if (erros >= 4)
        printf(" /|\\  |\n");
    else
        printf("      |\n");

    if (erros == 5)
        printf(" /    |\n");
    else if (erros >= 6)
        printf(" / \\  |\n");
    else
        printf("      |\n");

    printf("      |\n");
    printf("=========\n");

    if (erros == maxErros)
        printf("\nVoce perdeu!\n");
    else
        printf("\nParabens! Voce ganhou!\n");

    printf("Palavra correta: %s\n", palavra);

    return 0;
}
