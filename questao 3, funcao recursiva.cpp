#include <stdio.h>

// Fun��o recursiva para calcular produto(a, b) com explica��es detalhadas
int produto(int a, int b) {
    if (b == 1) {
        // Caso base
        printf("produto(%d,%d) = %d\n", a, b, a);
        printf("// Chegamos no caso base: b = 1, ent�o o resultado � %d\n\n", a);
        printf("Retorna %d para produto(%d,%d)\n\n", a, a, b);
        return a;
    } else {
        // Imprime a chamada recursiva
        printf("produto(%d,%d) = (produto(%d,%d) + %d)\n", a, b, a, b-1, a);
        printf("// Estamos chamando produto(%d,%d), que depende de produto(%d,%d) + %d\n\n", a, b, a, b-1, a);

        // Chamada recursiva
        int parcial = produto(a, b - 1);

        // Calcula o resultado da chamada atual
        int resultado = parcial + a;

        // Imprime a expans�o da soma para esta chamada
        printf("             = (");
        for (int i = 0; i < b; i++) {
            printf("%d", a);
            if (i < b - 1) printf(" + ");
        }
        printf(")\n");
        printf("// Expans�o final da soma: somando %d %d vezes\n", a, b);

        // Imprime o retorno para o chamador
        printf("Retorna %d para produto(%d,%d)\n\n", resultado, a, b);

        return resultado;
    }
}

int main() {
    int a, b;

    // L� os n�meros do usu�rio
    printf("Digite dois numeros (a e b): ");
    scanf("%d %d", &a, &b);

    if (b <= 0) {
        printf("Este algoritmo funciona apenas para b >= 1.\n");
    } else {
        // Chama a fun��o recursiva
        produto(a, b);
    }

    return 0;
}
