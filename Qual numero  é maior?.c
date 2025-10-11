
#include <stdio.h>

int main() {
    int n1, n2;

    printf("Digite o primeiro número: ");
    scanf("%d", &n1);

    printf("Digite o segundo número: ");
    scanf("%d", &n2);

    if (n1 > n2) {
        printf("O maior número é: %d\n", n1);
    } else if (n2 > n1) {
        printf("O maior número é: %d\n", n2);
    } else {
        printf("Os dois números são iguais.\n");
    }

    return 0;
}
