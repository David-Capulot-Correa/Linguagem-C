#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX 100

void mostrarNivel(float IT);
void cadastrar();
void listar();
void comparar();
void apagarJogador();
void pesquisarJogador();

typedef struct {
    char nome[50];
    char time[50];
    char paisTime[50];
    int anoTime;
    char nacionalidade[50];
    char posicao[30];

    float A2, A3, D2, D3;
    float I, C, R, F;
    float IT;
} Jogador;

Jogador jogadores[MAX];
int total = 0;

void calcularImpacto(Jogador *j) {
    j->IT = 2*j->A2 + 3*j->A3 +
            1.5*j->D2 + 1.5*j->D3 +
            1.2*j->I + j->C +
            j->R + 1.2*j->F;
}

void salvarArquivo() {
    FILE *f = fopen("jogadores.dat", "wb");
    if (f == NULL) {
        printf("ERRO: Nao foi possivel criar o arquivo de dados!\n");
        return;
    }

    fwrite(&total, sizeof(int), 1, f);
    fwrite(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

void carregarArquivo() {
    FILE *f = fopen("jogadores.dat", "rb");
    if (f == NULL) {
        total = 0; 
        return;
    }

    if (fread(&total, sizeof(int), 1, f) != 1) {
        total = 0;
    }

    fread(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

void carregarArquivo() {
    FILE *f = fopen("jogadores.dat", "rb");
    if (f == NULL) return;

    fread(&total, sizeof(int), 1, f);
    fread(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

void mostrarNivel(float IT) {
    if (IT < 12)
        printf("1. Totalmente Iniciante\n");
    else if (IT < 24)
        printf("2. Fundamentos Basicos\n");
    else if (IT < 36)
        printf("3. Fundamentos Consistentes\n");
    else if (IT < 48)
        printf("4. Jogador Funcional\n");
    else if (IT < 60)
        printf("5. Jogador Competitivo\n");
    else if (IT < 72)
        printf("6. Jogador Completo\n");
    else if (IT < 84)
        printf("7. Jogador de Alto Impacto\n");
    else if (IT < 96)
        printf("8. Elite Nacional\n");
    else if (IT < 108)
        printf("9. Elite Internacional\n");
    else if (IT < 120)
        printf("10. All-Star\n");
    else if (IT < 132)
        printf("11. Franchise Player\n");
    else if (IT < 144)
        printf("12. Icone Historico\n");
    else
        printf("13. Lenda do Esporte - O GOAT\n");
}

void cadastrar() {
    if (total >= MAX) {
        printf("Limite atingido!\n");
        return;
    }

    Jogador j;

    printf("\nNome do jogador: ");
    scanf(" %[^\n]", j.nome);

    printf("Time: ");
    scanf(" %[^\n]", j.time);

    printf("Pais do time: ");
    scanf(" %[^\n]", j.paisTime);

    printf("Ano do time: ");
    scanf("%d", &j.anoTime);

    printf("Nacionalidade: ");
    scanf(" %[^\n]", j.nacionalidade);

    printf("Posicao: ");
    scanf(" %[^\n]", j.posicao);

    printf("\nDigite as habilidades (1 a 12)\n");

    printf("Ataque 2: ");
    scanf("%f", &j.A2);

    printf("Ataque 3: ");
    scanf("%f", &j.A3);

    printf("Defesa 2: ");
    scanf("%f", &j.D2);

    printf("Defesa 3: ");
    scanf("%f", &j.D3);

    printf("Inteligencia: ");
    scanf("%f", &j.I);

    printf("Controle: ");
    scanf("%f", &j.C);

    printf("Rebote: ");
    scanf("%f", &j.R);

    printf("Fisico: ");
    scanf("%f", &j.F);

    calcularImpacto(&j);

    printf("\n=== CADASTRO FINALIZADO ===\n");
    printf("Impacto Total: %.2f\n", j.IT);
    mostrarNivel(j.IT);

    jogadores[total] = j;
    total++;

    salvarArquivo();

    printf("\nJogador salvo com sucesso!\n");
}

void listar() {
    if (total == 0) {
        printf("\nNenhum jogador cadastrado.\n");
        return;
    }

    printf("\n=== LISTA DE JOGADORES ===\n");

    for (int i = 0; i < total; i++) {
        printf("\n%d - %s\n", i, jogadores[i].nome);
        printf("Time: %s (%s, %d)\n", jogadores[i].time, jogadores[i].paisTime, jogadores[i].anoTime);
        printf("Nacionalidade: %s\n", jogadores[i].nacionalidade);
        printf("Posicao: %s\n", jogadores[i].posicao);
        printf("\n--- HABILIDADES ---\n");
        printf("Ataque 2: %.2f\n", jogadores[i].A2);
        printf("Ataque 3: %.2f\n", jogadores[i].A3);
        printf("Defesa 2: %.2f\n", jogadores[i].D2);
        printf("Defesa 3: %.2f\n", jogadores[i].D3);
        printf("Inteligencia: %.2f\n", jogadores[i].I);
        printf("Controle: %.2f\n", jogadores[i].C);
        printf("Rebote: %.2f\n", jogadores[i].R);
        printf("Fisico: %.2f\n", jogadores[i].F);
        printf("\nImpacto Total: %.2f\n", jogadores[i].IT);
        mostrarNivel(jogadores[i].IT);
        printf("--------------------------\n");
    }
}

void comparar() {
    if (total < 2) {
        printf("\nÉ necessário ter pelo menos 2 jogadores cadastrados para comparar.\n");
        return;
    }

    int a, b;

    listar();

    printf("\nEscolha o numero do primeiro jogador: ");
    scanf("%d", &a);

    printf("Escolha o numero do segundo jogador: ");
    scanf("%d", &b);

    if (a < 0 || a >= total || b < 0 || b >= total) {
        printf("Indice invalido!\n");
        return;
    }

    printf("\n=== COMPARACAO COMPLETA ===\n");

    printf("%-20s | %-10s | %-10s | %-6s | %-12s | %-6s | %-6s | %-6s | %-6s | %-6s | %-6s | %-6s | %-6s\n",
           "Nome", "Time", "Pais", "Ano", "Nacionalidade", "A2", "A3", "D2", "D3", "Int", "Con", "Reb", "Fis");

    printf("%-20s | %-10s | %-10s | %-6d | %-12s | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f\n",
           jogadores[a].nome, jogadores[a].time, jogadores[a].paisTime, jogadores[a].anoTime, jogadores[a].nacionalidade,
           jogadores[a].A2, jogadores[a].A3, jogadores[a].D2, jogadores[a].D3,
           jogadores[a].I, jogadores[a].C, jogadores[a].R, jogadores[a].F);

    printf("%-20s | %-10s | %-10s | %-6d | %-12s | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f | %-6.2f\n",
           jogadores[b].nome, jogadores[b].time, jogadores[b].paisTime, jogadores[b].anoTime, jogadores[b].nacionalidade,
           jogadores[b].A2, jogadores[b].A3, jogadores[b].D2, jogadores[b].D3,
           jogadores[b].I, jogadores[b].C, jogadores[b].R, jogadores[b].F);

    printf("\nImpacto Total: %s = %.2f | %s = %.2f\n",
           jogadores[a].nome, jogadores[a].IT,
           jogadores[b].nome, jogadores[b].IT);

    printf("Nivel: %s - ", jogadores[a].nome); mostrarNivel(jogadores[a].IT);
    printf("Nivel: %s - ", jogadores[b].nome); mostrarNivel(jogadores[b].IT);

    if (jogadores[a].IT > jogadores[b].IT)
        printf("\nMelhor jogador pelo Impacto Total: %s\n", jogadores[a].nome);
    else if (jogadores[b].IT > jogadores[a].IT)
        printf("\nMelhor jogador pelo Impacto Total: %s\n", jogadores[b].nome);
    else
        printf("\nEmpate tecnico!\n");
}

void apagarJogador() {
    int indice;

    listar();

    printf("\nDigite o número do jogador que deseja apagar: ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= total) {
        printf("Indice invalido!\n");
        return;
    }

    for (int i = indice; i < total - 1; i++) {
        jogadores[i] = jogadores[i + 1];
    }

    total--;

    salvarArquivo();

    printf("Jogador apagado com sucesso!\n");
}
