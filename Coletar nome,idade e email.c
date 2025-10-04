#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 100

struct cliente {
    char nome[81];
    int idade;
    char email[41];
};

typedef struct cliente Cliente;
typedef Cliente* Hash[tam];

int funcao_Esp(char* nome) {
    int soma = 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        soma += nome[i];
    }
    return (soma % tam);
}

Cliente* insere_Esp(Hash tab, char* nome, int idade, char* email) {
    int h = funcao_Esp(nome);
    while (tab[h] != NULL) {
        if (strcmp(tab[h]->nome, nome) == 0)
            break;
        h = (h + 1) % tam;
    }
    if (tab[h] == NULL) {
        tab[h] = (Cliente*) malloc(sizeof(Cliente));
        strcpy(tab[h]->nome, nome);
    }
    tab[h]->idade = idade;
    strcpy(tab[h]->email, email);
    return tab[h];
}

void remove_Esp(Hash tab, char* nome) {
    int h = funcao_Esp(nome);
    while (tab[h] != NULL) {
        if (strcmp(tab[h]->nome, nome) == 0) {
            free(tab[h]);
            tab[h] = NULL;
            printf("\n O Cliente foi excluido da Lista!");
            return;
        }
        h = (h + 1) % tam;
    }
    printf("\n O Cliente nao foi encontrado na Lista");
}

Cliente* busca_Esp(Hash tab, char* nome) {
    int h = funcao_Esp(nome);
    while (tab[h] != NULL) {
        if (strcmp(tab[h]->nome, nome) == 0)
            return tab[h];
        h = (h + 1) % tam;
    }
    return NULL;
}

void listarClientes(Hash tab) {
    printf("\n A Lista de Clientes Registrados sao:\n");
    for (int i = 0; i < tam; i++) {
        if (tab[i] != NULL) {
            printf("Nome: %s, Idade: %d, Email: %s\n", tab[i]->nome, tab[i]->idade, tab[i]->email);
        }
    }
}

int exibirMenu() {
    int escolha;
    printf("\nMenu:\n");
    printf("1. Inserir Novo Cliente na lista\n");
    printf("2. Remover Cliente da Lista\n");
    printf("3. Buscar Cliente na Lista\n");
    printf("4. Listar Todos os Clientes da Lista\n");
    printf("5. Sair do Menu\n");
    printf("Escolha uma das opcoes: ");
    scanf("%d", &escolha);
    getchar();
    return escolha;
}

int main() {
    Hash tabela;
    for (int i = 0; i < tam; i++) {
        tabela[i] = NULL;
    }

    int escolha;
    int idade;
    char nome[81];
    char email[41];
    Cliente* cliente;

    do {
        escolha = exibirMenu();

        switch (escolha) {
            case 1:
                printf("Digite o Nome Completo do cliente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                printf("Digite a idade do cliente: ");
                scanf("%d", &idade);
                getchar();
                printf("Digite o email do cliente: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = '\0';
                insere_Esp(tabela, nome, idade, email);
                break;
            case 2:
                printf("Digite o Nome Completo do cliente a ser removido: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                remove_Esp(tabela, nome);
                break;
            case 3:
                printf("Digite o Nome Completo do cliente a ser buscado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0';
                cliente = busca_Esp(tabela, nome);
                if (cliente != NULL) {
                    printf("\nCliente encontrado:\nNome: %s;\nIdade: %d;\nEmail: %s;\n",cliente->nome, cliente->idade, cliente->email);
                } else {
                    printf("Cliente nao encontrado na Lista\n");
                }
                break;
            case 4:
                listarClientes(tabela);
                break;
            case 5:
                printf("Saindo... \n");
                break;
            default:
                printf("essa opcao não existe (as opcoes vai de 1 a 5). Tente escolher novamente.\n");
        }
    } while (escolha != 5);

    return 0;
}

