#include <stdio.h>

// Função recursiva que calcula a soma de todos os números pares de 0 até n
int somaPares(int n) {
    // CASO BASE 1: Se n for negativo, retorna 0 (não há números pares para somar)
    if (n < 0) {
        return 0;
    }
    // CASO BASE 2: Se n for 0, retorna 0 (0 é par, mas 0 não altera a soma)
    if (n == 0) {
        return 0;
    }
    
    // Se n é PAR, adiciona n à soma e chama a função para n-2
    if (n % 2 == 0) {
        return n + somaPares(n - 2);
    } 
    // Se n é ÍMPAR, ignora n e chama a função para n-1
    else {
        return somaPares(n - 1);
    }
}

// Função auxiliar para mostrar o processo de soma (opcional)
void mostrarSomaPares(int n) {
    if (n < 0) {
        printf("0 = 0");
        return;
    }
    if (n == 0) {
        printf("0 = 0");
        return;
    }
    
    if (n % 2 == 0) {
        if (n == 2) {
            printf("0 + 2 = ");
        } else {
            mostrarSomaPares(n - 2);
            printf(" + %d", n);
        }
    } else {
        mostrarSomaPares(n - 1);
    }
}

int main() {
    int n;
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    
    int resultado = somaPares(n);
    
    printf("Soma dos numeros pares de 0 ate %d: ", n);
    mostrarSomaPares(n);
    printf(" = %d\n", resultado);
    
    return 0;
}