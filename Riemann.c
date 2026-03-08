#include <stdio.h>
#include <math.h>

double f(double t) {
    return 4 * (1 - exp(-2 * t)); 
}


double riemann(double (*func)(double), double a, double b, int n, char tipo) {
    double soma = 0.0;
    double largura = (b - a) / n;

    for (int i = 0; i < n; i++) {
        double x;


        if (tipo == 'e') {  
            x = a + i * largura;
        } else if (tipo == 'd') {  
            x = a + (i + 1) * largura;
        } else if (tipo == 'm') {  
            x = a + (i + 0.5) * largura;
        }

        soma += func(x) * largura;  
    }

    return soma;
}

int main() {
    double a, b;  
    int n;      
    char tipo;    


    printf("Digite o limite inferior a: ");
    scanf("%lf", &a);

    printf("Digite o limite superior b: ");
    scanf("%lf", &b);

    printf("Digite o número de divisões n: ");
    scanf("%d", &n);

    printf("Escolha o tipo de Riemann (e = esquerda, d = direita, m = meio): ");
    scanf(" %c", &tipo);  

    double resultado = riemann(f, a, b, n, tipo);

    printf("Resultado da integral de f(t) = 4 * (1 - exp(-2 * t)) entre %.2f e %.2f usando Riemann: %.6f\n", a, b, resultado);
    return 0;
}

