#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 5

struct Aluno {
    char nome[100];
    char cpf[15];
    char telefone[20];
    char endereco[200];
};

void removerNovaLinha(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int validarCPF(char *cpf) {
    if (strlen(cpf) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    return 1;
}

void formatarCPF(char *cpf, char *cpfFormatado) {
    sprintf(cpfFormatado, "%c%c%c.%c%c%c.%c%c%c-%c%c",
            cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5],
            cpf[6], cpf[7], cpf[8], cpf[9], cpf[10]);
}

void capturarCPF(char *cpfFormatado) {
    char cpf[12];
    do {
        printf("CPF (11 dígitos numéricos): ");
        fgets(cpf, sizeof(cpf), stdin);
        setbuf(stdin, NULL);
        removerNovaLinha(cpf);
    } while (!validarCPF(cpf));
    formatarCPF(cpf, cpfFormatado);
}

int validarTelefone(char *telefone) {
    int len = strlen(telefone);
    if (len != 10 && len != 11) return 0;
    for (int i = 0; i < len; i++) {
        if (!isdigit(telefone[i])) return 0;
    }
    return 1;
}

void formatarTelefone(char *telefone, char *telefoneFormatado) {
    int len = strlen(telefone);
    if (len == 10) {
        sprintf(telefoneFormatado, "(%c%c) %c%c%c%c-%c%c%c%c",
                telefone[0], telefone[1], telefone[2], telefone[3], telefone[4],
                telefone[5], telefone[6], telefone[7], telefone[8], telefone[9]);
    } else {
        sprintf(telefoneFormatado, "(%c%c) %c%c%c%c%c-%c%c%c%c",
                telefone[0], telefone[1], telefone[2], telefone[3], telefone[4],
                telefone[5], telefone[6], telefone[7], telefone[8], telefone[9], telefone[10]);
    }
}

void capturarTelefone(char *telefoneFormatado) {
    char telefone[12];
    do {
        printf("Telefone (10 ou 11 dígitos numéricos): ");
        fgets(telefone, sizeof(telefone), stdin);
        setbuf(stdin, NULL);
        removerNovaLinha(telefone);
    } while (!validarTelefone(telefone));
    formatarTelefone(telefone, telefoneFormatado);
}

void capturarEntrada(char *campo, int tamanho, char *mensagem) {
    do {
        printf("%s", mensagem);
        fgets(campo, tamanho, stdin);
        setbuf(stdin, NULL);
        removerNovaLinha(campo);
    } while (strlen(campo) == 0);
}

int main() {
    struct Aluno alunos[TAM];

    for (int i = 0; i < TAM; i++) {
        printf("\nCadastro do aluno %d\n", i + 1);

        capturarEntrada(alunos[i].nome, sizeof(alunos[i].nome), "Nome: ");
        capturarCPF(alunos[i].cpf);
        capturarTelefone(alunos[i].telefone);
        capturarEntrada(alunos[i].endereco, sizeof(alunos[i].endereco), "Endereço: ");
    }

    printf("\n=== Alunos Cadastrados ===\n");
    for (int i = 0; i < TAM; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("CPF: %s\n", alunos[i].cpf);
        printf("Telefone: %s\n", alunos[i].telefone);
        printf("Endereço: %s\n", alunos[i].endereco);
    }

    return 0;
}
