#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função recursiva para imprimir a lista
void imprimir(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    printf("%d -> ", lista->valor);
    imprimir(lista->prox);
}

// Função recursiva para buscar um elemento
int buscar(No* lista, int valor) {
    if (lista == NULL) {
        return 0; // não encontrado
    }
    if (lista->valor == valor) {
        return 1; // encontrado
    }
    return buscar(lista->prox, valor);
}

// Função recursiva para excluir um elemento
No* excluir(No* lista, int valor) {
    if (lista == NULL) {
        return NULL; // lista vazia
    }
    if (lista->valor == valor) {
        No* temp = lista->prox;
        free(lista);
        return temp; // remove nó atual
    }
    lista->prox = excluir(lista->prox, valor);
    return lista;
}

// Função para inserir nó no início (para facilitar testes)
No* inserir(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

int main() {
    No* lista = NULL;
    int opcao, valor;

    // Inserindo alguns elementos iniciais
    lista = inserir(lista, 5);
    lista = inserir(lista, 10);
    lista = inserir(lista, 20);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir lista\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Excluir elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        // Proteção contra entradas inválidas
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while (getchar() != '\n'); // limpa buffer
            opcao = -1; // força continuar no menu
            continue;
        }

        switch (opcao) {
            case 1:
                printf("Lista: ");
                imprimir(lista);
                break;
            case 2:
                printf("Digite o valor para buscar: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida!\n");
                    while (getchar() != '\n');
                    break;
                }
                if (buscar(lista, valor))
                    printf("Valor %d encontrado na lista.\n", valor);
                else
                    printf("Valor %d nao encontrado.\n", valor);
                break;
            case 3:
                printf("Digite o valor para excluir: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida!\n");
                    while (getchar() != '\n');
                    break;
                }
                lista = excluir(lista, valor);
                printf("Elemento %d excluido (se existia).\n", valor);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
