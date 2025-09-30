#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
    #include <windows.h>
    void setColor() {
        system("color 1E");
    }
#else
    void setColor() {
        printf("\033[1;93;44m");
    }
#endif

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializar(void) {
    return NULL;
}

Lista* inserir(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

Lista* inserirPosicao(Lista* l, int pos, int v) {
    int cont = 1;
    Lista* p = l;
    Lista* novo = (Lista*)malloc(sizeof(Lista));

    if (pos <= 0) {
        printf("Posição inválida!\n");
        return l;
    }

    if (pos == 1) {
        return inserir(l, v);
    }

    while (p != NULL && cont < pos - 1) {
        p = p->prox;
        cont++;
    }

    if (p == NULL) {
        printf("Posição inválida!\n");
        free(novo);
        return l;
    }

    novo->info = v;
    novo->prox = p->prox;
    p->prox = novo;

    return l;
}

Lista* inserirFim(Lista* l, int v) {
    Lista* p = l;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = NULL;

    if (l == NULL) {
        return novo;
    }

    while (p->prox != NULL) {
        p = p->prox;
    }

    p->prox = novo;
    return l;
}

Lista* retira(Lista* l, int v) {
    Lista* anterior = NULL;
    Lista* p = l;

    while (p != NULL && p->info != v) {
        anterior = p;
        p = p->prox;
    }

    if (p == NULL) {
        printf("Elemento %d não encontrado!\n", v);
        return l;
    }

    if (anterior == NULL) {
        l = p->prox;
    } else {
        anterior->prox = p->prox;
    }

    free(p);
    return l;
}

void imprimir(Lista* l) {
    Lista* p;
    if (l == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Elementos:\n");
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
}

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    setColor();

    Lista* listaFinal = inicializar();
    int opcao, valor, posicao;

    do {
        limparTela();

        printf("Menu de comandos: \n");
        printf("1 - Adicionar novo elemento no início da lista\n");
        printf("2 - Adicionar novo elemento no meio da lista\n");
        printf("3 - Adicionar novo elemento no final da lista\n");
        printf("4 - Excluir um elemento da lista\n");
        printf("5 - Imprimir a lista\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo elemento: ");
                scanf("%d", &valor);
                listaFinal = inserir(listaFinal, valor);
                break;

            case 2:
                printf("Digite o novo elemento: ");
                scanf("%d", &valor);
                printf("Digite a posição: ");
                scanf("%d", &posicao);
                listaFinal = inserirPosicao(listaFinal, posicao, valor);
                break;

            case 3:
                printf("Digite o elemento: ");
                scanf("%d", &valor);
                listaFinal = inserirFim(listaFinal, valor);
                break;

            case 4:
                printf("Digite o elemento: ");
                scanf("%d", &valor);
                listaFinal = retira(listaFinal, valor);
                break;

            case 5:
                imprimir(listaFinal);
                break;

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

        if (opcao != 6) {
            printf("Pressione qualquer tecla para continuar...");
            getchar();
            getchar();
        }
    } while (opcao != 6);

    return 0;
}
