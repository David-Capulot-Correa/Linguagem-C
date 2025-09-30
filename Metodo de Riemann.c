#include <stdio.h>
#include <math.h>  // Necessário para a função exp()

// Função que queremos integrar
double f(double t) {
    return 4 * (1 - exp(-2 * t));  // A nova função: 4 * (1 - exp(-2 * t))
}

// Função para calcular a integral usando o método de Riemann
double riemann(double (*func)(double), double a, double b, int n, char tipo) {
    double soma = 0.0;
    double largura = (b - a) / n;  // Largura de cada subintervalo

    for (int i = 0; i < n; i++) {
        double x;

        // Escolher o ponto de amostragem dependendo do tipo de método
        if (tipo == 'e') {  // Método da soma à esquerda
            x = a + i * largura;
        } else if (tipo == 'd') {  // Método da soma à direita
            x = a + (i + 1) * largura;
        } else if (tipo == 'm') {  // Método da soma do meio
            x = a + (i + 0.5) * largura;
        }

        soma += func(x) * largura;  // Soma das áreas dos retângulos
    }

    return soma;
}

int main() {
    double a, b;  // Limites da integral
    int n;         // Número de divisões
    char tipo;     // Tipo de método (esquerda, direita ou meio)

    // Entrada de dados pelo usuário
    printf("Digite o limite inferior a: ");
    scanf("%lf", &a);

    printf("Digite o limite superior b: ");
    scanf("%lf", &b);

    printf("Digite o número de divisões n: ");
    scanf("%d", &n);

    printf("Escolha o tipo de Riemann (e = esquerda, d = direita, m = meio): ");
    scanf(" %c", &tipo);  // O espaço antes de %c é para capturar qualquer caractere residual na entrada

    // Chama a função riemann passando a função f, os limites de integração, número de subintervalos e o tipo
    double resultado = riemann(f, a, b, n, tipo);

    printf("Resultado da integral de f(t) = 4 * (1 - exp(-2 * t)) entre %.2f e %.2f usando Riemann: %.6f\n", a, b, resultado);
    return 0;
}

