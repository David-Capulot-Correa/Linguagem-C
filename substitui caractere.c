#include <stdio.h>

int main() {
    char str[100];
    int contador = 0;
    int i;

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'b';
            contador++;
        }
    }

    printf("Caracteres modificados: %d\n", contador);
    printf("String resultante: %s", str);

    return 0;
}
