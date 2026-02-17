#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX 100

// ===== PROTÓTIPOS =====
void mostrarNivel(float IT);
void cadastrar();
void listar();
void comparar();
void apagarJogador();
void pesquisarJogador();

// ===== STRUCT =====
typedef struct {
    char nome[50];
    char time[50];
    char paisTime[50];       // País do time
    int anoTime;
    char nacionalidade[50];
    char posicao[30];

    float A2, A3, D2, D3;
    float I, C, R, F;
    float IT;
} Jogador;

// ===== VARIÁVEIS GLOBAIS =====
Jogador jogadores[MAX];
int total = 0;

// ===== CALCULO DO IMPACTO =====
void calcularImpacto(Jogador *j) {
    j->IT = 2*j->A2 + 3*j->A3 +
            1.5*j->D2 + 1.5*j->D3 +
            1.2*j->I + j->C +
            j->R + 1.2*j->F;
}

// ===== SALVAR ARQUIVO =====
// ===== SALVAR ARQUIVO =====
void salvarArquivo() {
    FILE *f = fopen("jogadores.dat", "wb"); // 'wb' cria ou sobrescreve o arquivo binário
    if (f == NULL) {
        printf("ERRO: Nao foi possivel criar o arquivo de dados!\n");
        return;
    }

    // Grava primeiro a quantidade total de jogadores
    fwrite(&total, sizeof(int), 1, f);
    // Depois grava o array inteiro de uma vez
    fwrite(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

// ===== CARREGAR ARQUIVO =====
void carregarArquivo() {
    FILE *f = fopen("jogadores.dat", "rb"); // 'rb' abre para leitura binária
    if (f == NULL) {
        // Se o arquivo nao existe, apenas ignora (primeira execucao)
        total = 0; 
        return;
    }

    // Le a quantidade total que foi salva
    if (fread(&total, sizeof(int), 1, f) != 1) {
        total = 0;
    }
    // Le os dados dos jogadores existentes
    fread(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

// ===== CARREGAR ARQUIVO =====
void carregarArquivo() {
    FILE *f = fopen("jogadores.dat", "rb");
    if (f == NULL) return;

    fread(&total, sizeof(int), 1, f);
    fread(jogadores, sizeof(Jogador), total, f);

    fclose(f);
}

// ===== MOSTRAR NIVEL =====
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

// ===== CADASTRAR JOGADOR =====
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

// ===== LISTAR JOGADORES =====
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

// ===== COMPARAR JOGADORES =====
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

// ===== APAGAR JOGADOR =====
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

// ===== PESQUISAR JOGADOR =====
// =================== PESQUISA AVANÇADA ===================
void pesquisarJogadorAvancado() {
    if (total == 0) {
        printf("\nNenhum jogador cadastrado.\n");
        return;
    }

    int modo;
    printf("\n=== MENU DE PESQUISA ===\n");
    printf("1 - Por Time (Hierarquia: Pais > Time > Temporada)\n");
    printf("2 - Por Nacionalidade do Jogador\n");
    printf("Escolha: ");
    scanf("%d", &modo);

    if (modo == 1) {
        // --- PASSO 1: ESCOLHER O PAÍS ---
        char listaPaises[MAX][50];
        int qP = 0;
        printf("\n=== SELECIONE O PAIS DO TIME ===\n");
        for (int i = 0; i < total; i++) {
            int existe = 0;
            for (int j = 0; j < qP; j++) if (strcmp(jogadores[i].paisTime, listaPaises[j]) == 0) existe = 1;
            if (!existe) {
                printf("[%d] %s\n", qP + 1, jogadores[i].paisTime);
                strcpy(listaPaises[qP++], jogadores[i].paisTime);
            }
        }

        int selP;
        printf("Escolha o numero: ");
        scanf("%d", &selP);
        if (selP < 1 || selP > qP) return;
        char paisEscolhido[50];
        strcpy(paisEscolhido, listaPaises[selP - 1]);

        // --- PASSO 2: ESCOLHER O TIME ---
        char listaTimes[MAX][50];
        int qT = 0;
        printf("\n=== TIMES EM: %s ===\n", paisEscolhido);
        for (int i = 0; i < total; i++) {
            if (strcmp(jogadores[i].paisTime, paisEscolhido) == 0) {
                int existeT = 0;
                for (int j = 0; j < qT; j++) if (strcmp(jogadores[i].time, listaTimes[j]) == 0) existeT = 1;
                if (!existeT) {
                    printf("[%d] %s\n", qT + 1, jogadores[i].time);
                    strcpy(listaTimes[qT++], jogadores[i].time);
                }
            }
        }

        int selT;
        printf("Escolha o numero: ");
        scanf("%d", &selT);
        if (selT < 1 || selT > qT) return;
        char timeEscolhido[50];
        strcpy(timeEscolhido, listaTimes[selT - 1]);

        // --- PASSO 3: ESCOLHER A TEMPORADA ---
        int listaAnos[MAX], qA = 0;
        printf("\n=== TEMPORADAS DO %s ===\n", timeEscolhido);
        for (int i = 0; i < total; i++) {
            if (strcmp(jogadores[i].time, timeEscolhido) == 0) {
                int existeA = 0;
                for (int j = 0; j < qA; j++) if (jogadores[i].anoTime == listaAnos[j]) existeA = 1;
                if (!existeA) {
                    printf("[%d] Temporada %d\n", qA + 1, jogadores[i].anoTime);
                    listaAnos[qA++] = jogadores[i].anoTime;
                }
            }
        }

        int selA;
        printf("Escolha o numero: ");
        scanf("%d", &selA);
        if (selA < 1 || selA > qA) return;
        int anoEscolhido = listaAnos[selA - 1];

        // --- EXIBIÇÃO FINAL ---
        Jogador temp[MAX]; int qTemp = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(jogadores[i].time, timeEscolhido) == 0 && jogadores[i].anoTime == anoEscolhido)
                temp[qTemp++] = jogadores[i];
        }

        // Ordenação PG > SG > SF > PF > C
        for (int x = 0; x < qTemp - 1; x++) {
            for (int y = 0; y < qTemp - x - 1; y++) {
                int p1 = 99, p2 = 99;
                if (strcasecmp(temp[y].posicao, "PG") == 0) p1 = 1;
                else if (strcasecmp(temp[y].posicao, "SG") == 0) p1 = 2;
                else if (strcasecmp(temp[y].posicao, "SF") == 0) p1 = 3;
                else if (strcasecmp(temp[y].posicao, "PF") == 0) p1 = 4;
                else if (strcasecmp(temp[y].posicao, "C") == 0) p1 = 5;

                if (strcasecmp(temp[y+1].posicao, "PG") == 0) p2 = 1;
                else if (strcasecmp(temp[y+1].posicao, "SG") == 0) p2 = 2;
                else if (strcasecmp(temp[y+1].posicao, "SF") == 0) p2 = 3;
                else if (strcasecmp(temp[y+1].posicao, "PF") == 0) p2 = 4;
                else if (strcasecmp(temp[y+1].posicao, "C") == 0) p2 = 5;

                if (p1 > p2 || (p1 == p2 && temp[y].IT < temp[y+1].IT)) {
                    Jogador aux = temp[y]; temp[y] = temp[y+1]; temp[y+1] = aux;
                }
            }
        }

        printf("\n=== ELENCO: %s (%d) ===\n", timeEscolhido, anoEscolhido);
        for (int i = 0; i < qTemp; i++) {
            printf("%-3s | %-20s | IT: %6.2f | ", temp[i].posicao, temp[i].nome, temp[i].IT);
            mostrarNivel(temp[i].IT);
        }

    } else if (modo == 2) {
        // --- PESQUISA POR NACIONALIDADE ---
        char listaNac[MAX][50];
        int qN = 0;
        printf("\n=== SELECIONE A NACIONALIDADE ===\n");
        for (int i = 0; i < total; i++) {
            int existe = 0;
            for (int j = 0; j < qN; j++) if (strcmp(jogadores[i].nacionalidade, listaNac[j]) == 0) existe = 1;
            if (!existe) {
                printf("[%d] %s\n", qN + 1, jogadores[i].nacionalidade);
                strcpy(listaNac[qN++], jogadores[i].nacionalidade);
            }
        }

        int selN;
        printf("Escolha o numero: ");
        scanf("%d", &selN);
        if (selN < 1 || selN > qN) return;
        char nacEscolhida[50];
        strcpy(nacEscolhida, listaNac[selN - 1]);

        // Coletar e ordenar por força (IT)
        Jogador temp[MAX]; int qTemp = 0;
        for (int i = 0; i < total; i++) {
            if (strcmp(jogadores[i].nacionalidade, nacEscolhida) == 0) temp[qTemp++] = jogadores[i];
        }

        for (int x = 0; x < qTemp - 1; x++) {
            for (int y = 0; y < qTemp - x - 1; y++) {
                if (temp[y].IT < temp[y+1].IT) {
                    Jogador aux = temp[y]; temp[y] = temp[y+1]; temp[y+1] = aux;
                }
            }
        }

        printf("\n=== JOGADORES DE NACIONALIDADE: %s ===\n", nacEscolhida);
        for (int i = 0; i < qTemp; i++) {
            printf("%-20s | %-15s | IT: %6.2f\n", temp[i].nome, temp[i].time, temp[i].IT);
        }
    } else {
        printf("Opcao invalida!\n");
    }
}
// ===== MAIN =====
int main() {

    int opcao;

    carregarArquivo();

    do {
        printf("\n=== SISTEMA DE GERENCIAMENTO DE JOGADORES ===\n");
        printf("1 - Cadastrar jogador\n");
        printf("2 - Listar jogadores\n");
        printf("3 - Comparar jogadores\n");
        printf("4 - Apagar jogador\n");
        printf("5 - Pesquisar jogador\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: comparar(); break;
            case 4: apagarJogador(); break;
            case 5: pesquisarJogadorAvancado(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}
