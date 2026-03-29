“#include <stdio.h>
#include <math.h> 

double f(double t) {
    return t * t * t * t * sin(t) * exp(-0.5 * t * t) + log(t + 1);
}

double trapezios(double (*func)(double), double a, double b, int n) {
    double soma = 0.0;
    double delta_t = (b - a) / n; 

    soma = soma + func(a) + func(b); 

    for (int i = 1; i < n; i++) {
        double x = a + i * delta_t;
        soma += 2 * func(x); 
    }

    soma = soma * delta_t / 2;
    return soma;
}

int main() {
    double a, b; 
    int n; 

    printf("Digite o limite inferior a: ");
    scanf("%lf", &a);

    printf("Digite o limite superior b: ");
    scanf("%lf", &b);

    printf("Digite o número de divisões n: ");
    scanf("%d", &n);

    double resultado = trapezios(f, a, b, n);

    printf("Resultado da integral de f(t) = t^4 * sin(t) * exp(-0.5 * t^2) + ln(t + 1) entre %.2f e %.2f usando o método dos trapézios: %.6f\n", a, b, resultado);
    return 0;
}

