#include <stdio.h>

int main() {
    char nomes[5][50];
    int i;

    for(i = 0; i < 5; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf("%s", nomes[i]);
    }

    printf("\nNomes armazenados:\n");

    for(i = 0; i < 5; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
