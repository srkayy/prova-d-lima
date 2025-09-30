#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função recursiva para imprimir os elementos da lista
void imprimir(No* lista) {
    if (lista == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d -> ", lista->valor);
    imprimir(lista->prox);
}

// Função recursiva para buscar um elemento
int buscar(No* lista, int x) {
    if (lista == NULL) {
        return 0;
    }
    if (lista->valor == x) {
        return 1;
    }
    return buscar(lista->prox, x);
}

// Função recursiva para excluir um elemento
No* excluir(No* lista, int x) {
    if (lista == NULL) {
        return NULL;
    }
    if (lista->valor == x) {
        No* temp = lista->prox;
        free(lista);
        return temp;
    }
    lista->prox = excluir(lista->prox, x);
    return lista;
}

// Função auxiliar para inserir no início da lista
No* inserir(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}

int main() {
    No* lista = NULL;
    int opcao, valor;

    // Criando lista inicial (15 -> 10 -> 5)
    lista = inserir(lista, 15);
    lista = inserir(lista, 10);
    lista = inserir(lista, 5);

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Imprimir lista\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Excluir elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Lista: ");
                imprimir(lista);
                break;

            case 2:
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);
                if (buscar(lista, valor)) {
                    printf("Elemento %d encontrado!\n", valor);
                } else {
                    printf("Elemento %d NAO encontrado.\n", valor);
                }
                break;

            case 3:
                printf("Digite o valor a excluir: ");
                scanf("%d", &valor);
                lista = excluir(lista, valor);
                printf("Lista apos exclusao: ");
                imprimir(lista);
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
