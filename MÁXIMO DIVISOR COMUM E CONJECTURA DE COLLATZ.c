#include <stdio.h>

int main() {
    int op, n, a, b, temp;

    while (1) {
        printf("Escolha a opção que voce deseja:");
        printf("\n1-MDC \n2-Collatz \n0-Sair ");
        printf("\nopção escolhida:");
        scanf("%d", &op);

        if (op == 0) break;

        if (op == 1) {
            printf("Digite de Dois numeros \n");
            printf("primeiro  numero: ");
            scanf("%d",&a);
            printf("segundo   numero: ");
            scanf("%d",&b);
            while (b != 0) {
                temp = b;
                b = a % b;
                a = temp;
            }
            printf("MDC: %d\n", a);
        } 
        else if (op == 2) {
            printf("Numero (>1): ");
            scanf("%d", &n);
            while (n > 1) {
                printf("%d ", n);
                if (n % 2 == 0) n = n / 2;
                else n = 3 * n + 1;
            }
            printf("1\n");
        }
    }
    return 0;
}