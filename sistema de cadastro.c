#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define ARQUIVO "cadastro.txt"

typedef struct {
    char nome[50];
    int idade;
    char email[50];
} Pessoa;

Pessoa pessoas[MAX];
int total = 0;

//  FUNÇÕES

void salvar() {
    FILE *f = fopen(ARQUIVO, "w");

    if (f == NULL) {
        printf("Erro ao salvar!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        fprintf(f, "%s;%d;%s\n",
                pessoas[i].nome,
                pessoas[i].idade,
                pessoas[i].email);
    }

    fclose(f);
}

void carregar() {
    FILE *f = fopen(ARQUIVO, "r");

    if (f == NULL) return;

    while (fscanf(f, "%49[^;];%d;%49[^\n]\n",
                  pessoas[total].nome,
                  &pessoas[total].idade,
                  pessoas[total].email) == 3) {
        total++;
    }

    fclose(f);
}

void cadastrar() {

    if (total >= MAX) {
        printf("Limite atingido!\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", pessoas[total].nome);

    printf("Idade: ");
    scanf("%d", &pessoas[total].idade);

    printf("Email: ");
    scanf(" %[^\n]", pessoas[total].email);

    total++;
    salvar();

    printf("Pessoa cadastrada!\n");
}

void listar() {

    if (total == 0) {
        printf("Nenhum cadastro encontrado.\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("\nID: %d\n", i);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Email: %s\n", pessoas[i].email);
    }
}

void editar() {
    int id;

    listar();
    printf("\nDigite o ID para editar: ");
    scanf("%d", &id);

    if (id < 0 || id >= total) {
        printf("ID invalido!\n");
        return;
    }

    printf("Novo nome: ");
    scanf(" %[^\n]", pessoas[id].nome);

    printf("Nova idade: ");
    scanf("%d", &pessoas[id].idade);

    printf("Novo email: ");
    scanf(" %[^\n]", pessoas[id].email);

    salvar();
    printf("Cadastro atualizado!\n");
}

void deletar() {
    int id;

    listar();
    printf("\nDigite o ID para deletar: ");
    scanf("%d", &id);

    if (id < 0 || id >= total) {
        printf("ID invalido!\n");
        return;
    }

    for (int i = id; i < total - 1; i++) {
        pessoas[i] = pessoas[i + 1];
    }

    total--;

    salvar();
    printf("Cadastro removido!\n");
}

//  MAIN 

int main() {

    int opcao;

    carregar();

    do {
        printf("\n===== SISTEMA DE CADASTRO =====\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Editar\n");
        printf("4 - Deletar\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: deletar(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

