#include <stdio.h>

int escolherNivel() {
    int nivel, pontos = 0;
    printf("   Niveis:\n");
    printf("   1 - Fraco (+1)\n");
    printf("   2 - Medio (+3)\n");
    printf("   3 - Bom (+5)\n");
    printf("   4 - Excelente (+10)\n");
    printf("   Escolha o nivel: ");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1: pontos = 1; break;
        case 2: pontos = 3; break;
        case 3: pontos = 5; break;
        case 4: pontos = 10; break;
        default: 
            printf("Nivel invalido, considerado Fraco.\n");
            pontos = 1;
    }
    return pontos;
}

int main() {
    int total = 0, habilidade, sub, sairHab, sairSub;

    printf("=== Criador de Jogador de Basquete ===\n");

    do {
        printf("\nEscolha uma habilidade:\n");
        printf("1 - Arremesso (base 5)\n");
        printf("2 - Defesa (base 4)\n");
        printf("3 - Passe (base 3)\n");
        printf("4 - Velocidade (base 4)\n");
        printf("5 - Drible (base 5)\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &habilidade);

        if(habilidade == 0) break;

        switch(habilidade) {
            case 1: // Arremesso
                total += 5;
                sairSub = 0;
                do {
                    printf("\n--- Arremesso ---\n");
                    printf("1 - Lance livre\n");
                    printf("2 - 3 pontos\n");
                    printf("3 - Bandeja\n");
                    printf("0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);

                    if(sub == 0) break;

                    total += escolherNivel();

                    printf("Deseja escolher outra sub-habilidade de Arremesso? (1-Sim / 0-Nao): ");
                    scanf("%d", &sairSub);

                } while(sairSub == 1);
                break;

            case 2: // Defesa
                total += 4;
                sairSub = 0;
                do {
                    printf("\n--- Defesa ---\n");
                    printf("1 - Marcacao individual\n");
                    printf("2 - Marcacao em zona\n");
                    printf("3 - Roubo de bola\n");
                    printf("0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);

                    if(sub == 0) break;

                    total += escolherNivel();

                    printf("Deseja escolher outra sub-habilidade de Defesa? (1-Sim / 0-Nao): ");
                    scanf("%d", &sairSub);

                } while(sairSub == 1);
                break;

            case 3: // Passe
                total += 3;
                sairSub = 0;
                do {
                    printf("\n--- Passe ---\n");
                    printf("1 - Passe curto\n");
                    printf("2 - Passe longo\n");
                    printf("3 - Assistencia criativa\n");
                    printf("0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);

                    if(sub == 0) break;

                    total += escolherNivel();

                    printf("Deseja escolher outra sub-habilidade de Passe? (1-Sim / 0-Nao): ");
                    scanf("%d", &sairSub);

                } while(sairSub == 1);
                break;

            case 4: // Velocidade
                total += 4;
                sairSub = 0;
                do {
                    printf("\n--- Velocidade ---\n");
                    printf("1 - Corrida reta\n");
                    printf("2 - Agilidade lateral\n");
                    printf("0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);

                    if(sub == 0) break;

                    total += escolherNivel();

                    printf("Deseja escolher outra sub-habilidade de Velocidade? (1-Sim / 0-Nao): ");
                    scanf("%d", &sairSub);

                } while(sairSub == 1);
                break;

            case 5: // Drible
                total += 5;
                sairSub = 0;
                do {
                    printf("\n--- Drible ---\n");
                    printf("1 - Drible simples\n");
                    printf("2 - Drible avancado\n");
                    printf("3 - Quebra de marcacao\n");
                    printf("0 - Voltar\n");
                    printf("Escolha: ");
                    scanf("%d", &sub);

                    if(sub == 0) break;

                    total += escolherNivel();

                    printf("Deseja escolher outra sub-habilidade de Drible? (1-Sim / 0-Nao): ");
                    scanf("%d", &sairSub);

                } while(sairSub == 1);
                break;

            default:
                printf("Opcao invalida!\n");
        }

        printf("\nDeseja escolher outra habilidade principal? (1-Sim / 0-Nao): ");
        scanf("%d", &sairHab);

    } while(sairHab == 1);

    printf("\n====================================\n");
    printf("Pontuacao final do jogador: %d pontos\n", total);
    printf("====================================\n");

    return 0;
}
