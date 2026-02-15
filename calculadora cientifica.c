#include <stdio.h>
#include <math.h>

// ----------- Funções -----------

float soma(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b == 0) {
        printf("Erro: divisao por zero!\n");
        return 0;
    }
    return a / b;
}

float potencia(float base, float expoente) {
    return pow(base, expoente);
}

float raiz(float numero) {
    if (numero < 0) {
        printf("Erro: raiz de numero negativo!\n");
        return 0;
    }
    return sqrt(numero);
}

long long fatorial(int n) {
    if (n < 0) {
        printf("Erro: fatorial de numero negativo!\n");
        return 0;
    }

    long long resultado = 1;

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

// ----------- Main -----------

int main() {

    int opcao;
    float a, b;
    int n;

    do {
        printf("\n===== CALCULADORA CIENTIFICA =====\n");
        printf("1 - Soma\n");
        printf("2 - Subtracao\n");
        printf("3 - Multiplicacao\n");
        printf("4 - Divisao\n");
        printf("5 - Potencia\n");
        printf("6 - Raiz Quadrada\n");
        printf("7 - Fatorial\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Digite dois numeros: ");
                scanf("%f %f", &a, &b);
                printf("Resultado: %.2f\n", soma(a, b));
                break;

            case 2:
                printf("Digite dois numeros: ");
                scanf("%f %f", &a, &b);
                printf("Resultado: %.2f\n", subtracao(a, b));
                break;

            case 3:
                printf("Digite dois numeros: ");
                scanf("%f %f", &a, &b);
                printf("Resultado: %.2f\n", multiplicacao(a, b));
                break;

            case 4:
                printf("Digite dois numeros: ");
                scanf("%f %f", &a, &b);
                printf("Resultado: %.2f\n", divisao(a, b));
                break;

            case 5:
                printf("Base e expoente: ");
                scanf("%f %f", &a, &b);
                printf("Resultado: %.2f\n", potencia(a, b));
                break;

            case 6:
                printf("Digite um numero: ");
                scanf("%f", &a);
                printf("Resultado: %.2f\n", raiz(a));
                break;

            case 7:
                printf("Digite um numero inteiro: ");
                scanf("%d", &n);
                printf("Resultado: %lld\n", fatorial(n));
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
