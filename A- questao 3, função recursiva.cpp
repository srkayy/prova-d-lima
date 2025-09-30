#include <stdio.h>

// Função recursiva que mostra o processo
int produto(int a, int b) {
    if (b == 1) {
        // Caso base: apenas retorna 'a'
        printf("= %d\n", a);
        return a;
    }

    // Imprime o passo da expansão
    printf("= produto(%d, %d) + %d\n", a, b - 1, a);

    int parcial = produto(a, b - 1); // chamada recursiva
    int resultado = parcial + a;

    // Mostra a substituição com o valor parcial
    printf("= %d + %d\n", parcial, a);

    return resultado;
}

int main() {
    int a, b;

    printf("Digite dois numeros: ");
    scanf("%d %d", &a, &b);

    printf("\nExpansao da recursao:\n");
    int resultado = produto(a, b);

    printf("\nResultado final: %d\n", resultado);

    return 0;
}
