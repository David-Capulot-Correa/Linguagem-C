#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_TITULO 100
#define TAM_AUTOR 100
#define TAM_NOME 100
#define DIAS_EMPRESTIMO 7
#define MULTA_POR_DIA 2

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int anoPublicacao;
    int emprestado;
    char nomeCliente[TAM_NOME];
    Data dataEmprestimo;
    Data dataDevolucaoPrevista;
} Livro;


int anoBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    return 0;
}

int diasNoMes(int mes, int ano) {
    int diasMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (mes == 2 && anoBissexto(ano))
        return 29;

    return diasMes[mes - 1];
}

int dataValida(Data d) {

    if (d.ano < 1) return 0;
    if (d.mes < 1 || d.mes > 12) return 0;
    if (d.dia < 1 || d.dia > diasNoMes(d.mes, d.ano)) return 0;

    return 1;
}

int converterParaDias(Data d) {
    return d.ano * 365 + d.mes * 30 + d.dia;
}


void cadastrarLivro() {

    FILE *arquivo = fopen("livros.dat", "ab");
    if (!arquivo) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    Livro livro;

    printf("ID: ");
    scanf("%d", &livro.id);

    printf("Titulo: ");
    scanf(" %[^\n]", livro.titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livro.autor);

    printf("Ano de publicacao: ");
    scanf("%d", &livro.anoPublicacao);

    livro.emprestado = 0;

    fwrite(&livro, sizeof(Livro), 1, arquivo);
    fclose(arquivo);

    printf("Livro cadastrado com sucesso!\n");
}


void listarLivros() {

    FILE *arquivo = fopen("livros.dat", "rb");
    if (!arquivo) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    Livro livro;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {

        printf("\n--------------------------\n");
        printf("ID: %d\n", livro.id);
        printf("Titulo: %s\n", livro.titulo);
        printf("Autor: %s\n", livro.autor);
        printf("Ano: %d\n", livro.anoPublicacao);

        if (livro.emprestado) {
            printf("Status: Emprestado\n");
            printf("Cliente: %s\n", livro.nomeCliente);
            printf("Data emprestimo: %02d/%02d/%d\n",
                   livro.dataEmprestimo.dia,
                   livro.dataEmprestimo.mes,
                   livro.dataEmprestimo.ano);
        } else {
            printf("Status: Disponivel\n");
        }
    }

    fclose(arquivo);
}


void emprestarLivro() {

    FILE *arquivo = fopen("livros.dat", "rb+");
    if (!arquivo) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    int id;
    printf("ID do livro: ");
    scanf("%d", &id);

    Livro livro;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {

        if (livro.id == id) {

            if (livro.emprestado) {
                printf("Livro ja emprestado!\n");
                fclose(arquivo);
                return;
            }

            livro.emprestado = 1;

            printf("Nome do cliente: ");
            scanf(" %[^\n]", livro.nomeCliente);

            do {
                printf("Data do emprestimo (dd/mm/aaaa): ");
                scanf("%d/%d/%d",
                      &livro.dataEmprestimo.dia,
                      &livro.dataEmprestimo.mes,
                      &livro.dataEmprestimo.ano);

                if (!dataValida(livro.dataEmprestimo))
                    printf("Data invalida! Tente novamente.\n");

            } while (!dataValida(livro.dataEmprestimo));

            livro.dataDevolucaoPrevista = livro.dataEmprestimo;
            livro.dataDevolucaoPrevista.dia += DIAS_EMPRESTIMO;

            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);

            printf("Emprestimo realizado!\n");
            fclose(arquivo);
            return;
        }
    }

    printf("Livro nao encontrado.\n");
    fclose(arquivo);
}

void devolverLivro() {

    FILE *arquivo = fopen("livros.dat", "rb+");
    if (!arquivo) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    int id;
    printf("ID do livro: ");
    scanf("%d", &id);

    Livro livro;

    while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {

        if (livro.id == id) {

            if (!livro.emprestado) {
                printf("Livro ja esta disponivel.\n");
                fclose(arquivo);
                return;
            }

            Data dataDevolucao;

            do {
                printf("Data real de devolucao (dd/mm/aaaa): ");
                scanf("%d/%d/%d",
                      &dataDevolucao.dia,
                      &dataDevolucao.mes,
                      &dataDevolucao.ano);

                if (!dataValida(dataDevolucao))
                    printf("Data invalida!\n");

            } while (!dataValida(dataDevolucao));

            int diasPrevistos = converterParaDias(livro.dataDevolucaoPrevista);
            int diasReais = converterParaDias(dataDevolucao);

            if (diasReais > diasPrevistos) {
                int atraso = diasReais - diasPrevistos;
                printf("Livro devolvido com %d dias de atraso.\n", atraso);
                printf("Multa: R$ %d\n", atraso * MULTA_POR_DIA);
            } else {
                printf("Livro devolvido no prazo.\n");
            }

            livro.emprestado = 0;
            strcpy(livro.nomeCliente, "");

            fseek(arquivo, -sizeof(Livro), SEEK_CUR);
            fwrite(&livro, sizeof(Livro), 1, arquivo);

            fclose(arquivo);
            return;
        }
    }

    printf("Livro nao encontrado.\n");
    fclose(arquivo);
}


int main() {

    int opcao;

    do {
        printf("\n===== SISTEMA DE BIBLIOTECA =====\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Emprestar livro\n");
        printf("4 - Devolver livro\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrarLivro(); break;
            case 2: listarLivros(); break;
            case 3: emprestarLivro(); break;
            case 4: devolverLivro(); break;
            case 0: printf("Encerrando sistema...\n"); break;
            default: printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}

