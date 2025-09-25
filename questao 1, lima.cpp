#include <stdio.h>  
 
// Caso recursivo: n * fatorial de (n-1)
    // Exemplo: f1(5) = 5 * f1(4) = 5 * 4 *x// Função 1: Calcula o fatorial de um número usando recursividade
    // O fatorial de um número n (representado por n!) é o produto de todos os números inteiros positivos de 1 até n
    // Exemplo: 5! = 5 × 4 × 3 × 2 × 1 = 120 f1(3) = ... = 5 * 4 * 3 * 2 * 1 * 1
int f1(int n) {
    // Caso base: se n for 0, retorna 1 (fatorial de 0 é 1)
    if (n == 0)
    return (1);
    else
     // CASO RECURSIVO: Quando n é maior que 0
    // A função chama a si mesma com o argumento (n-1) - isso é a RECURSIVIDADE
    // A multiplicação n * f1(n-1) significa: "n multiplicado pelo fatorial de (n-1)"
    // A recursão continua até chegar ao caso base (n == 0), então desfaz a pilha de chamadas
   
    return(n * f1(n-1));
}

// Função 2: Calcula uma sequência matemática recursiva
int f2(int n) {
    // Primeiro caso base: se n for 0, retorna 1
    if (n == 0)
    return (1);
    // Segundo caso base: se n for 1, retorna 1
    if (n == 1)
    return (1);
    else
    // Caso recursivo: f2(n) = f2(n-1) + 2 * f2(n-2)
    // Exemplo: f2(5) = f2(4) + 2*f2(3)
    return(f2(n-1)+ 2 * f2(n-2));
}

// Função 3: Função recursiva que imprime cada número duas vezes e depois "Zero"
int f3(int n) {
    // Caso base: quando n chega a 0, imprime "Zero"
    if (n == 0)
    printf("Zero ");
    else
    {
    // Caso recursivo: imprime o número atual duas vezes
    printf("%d ",n);   // Primeira impressão do número
    printf("%d ",n);   // Segunda impressão do mesmo número
    // Chama a função recursivamente com n-1
    f3(n-1);          // Vai imprimir os números menores recursivamente
    }
    return 0; // Retorno adicionado apenas para evitar warning do compilador
}

// Função principal onde o programa começa a executar
int main() {
    // Declara três variáveis inteiras para armazenar os valores de entrada
    int v1, v2, v3;
    
    // ========== TESTE DA FUNÇÃO f1 (FATORIAL) ==========
    printf("=== TESTE DA FUNCAO f1 ===\n");
    printf("Digite 3 valores para f1: ");
    // Lê três valores inteiros do usuário e armazena nas variáveis v1, v2, v3
    scanf("%d %d %d", &v1, &v2, &v3);
    
    // Chama f1 com o primeiro valor e imprime o resultado
    printf("f1(%d) = %d\n", v1, f1(v1));
    // Chama f1 com o segundo valor e imprime o resultado
    printf("f1(%d) = %d\n", v2, f1(v2));
    // Chama f1 com o terceiro valor e imprime o resultado
    printf("f1(%d) = %d\n", v3, f1(v3));
    
    // ========== TESTE DA FUNÇÃO f2 (SEQUÊNCIA) ==========
    printf("\n=== TESTE DA FUNCAO f2 ===\n");
    printf("Digite 3 valores para f2: ");
    // Lê três novos valores do usuário (sobrescrevendo os anteriores)
    scanf("%d %d %d", &v1, &v2, &v3);
    
    // Chama f2 com cada um dos três valores e imprime os resultados
    printf("f2(%d) = %d\n", v1, f2(v1));
    printf("f2(%d) = %d\n", v2, f2(v2));
    printf("f2(%d) = %d\n", v3, f2(v3));
    
    // ========== TESTE DA FUNÇÃO f3 (IMPRESSÃO) ==========
    printf("\n=== TESTE DA FUNCAO f3 ===\n");
    printf("Digite 3 valores para f3: ");
    // Lê três novos valores do usuário
    scanf("%d %d %d", &v1, &v2, &v3);
    
    // Testa f3 com o primeiro valor
    printf("f3(%d) = ", v1);  // Imprime o cabeçalho
    f3(v1);                   // Chama f3 que vai imprimir a sequência
    printf("\n");             // Pula para a próxima linha
    
    // Repete o processo para o segundo valor
    printf("f3(%d) = ", v2);
    f3(v2);
    printf("\n");
    
    // Repete o processo para o terceiro valor
    printf("f3(%d) = ", v3);
    f3(v3);
    printf("\n");

    // Retorna 0 indicando que o programa terminou com sucesso
    return 0;
}