#include <iostream>
using namespace std;

// Nó da fila
typedef struct Reg {
    int infor;
    Reg *prox;
} No;

// Estrutura da fila
typedef struct TipoFila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

// Inicializar fila
void inicializarFila(Fila &f) {
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
}

// a) Inserir elemento (enqueue)
void enfileirar(Fila &f, int valor) {
    No *novo = new No;
    novo->infor = valor;
    novo->prox = NULL;

    if (f.fim == NULL) { // fila vazia
        f.inicio = novo;
        f.fim = novo;
    } else {
        f.fim->prox = novo;
        f.fim = novo;
    }

    f.tamanho++;
    cout << "Elemento " << valor << " inserido na fila!" << endl;
}

// b) Excluir elemento (dequeue)
void desenfileirar(Fila &f) {
    if (f.inicio == NULL) {
        cout << "Fila vazia, nada a remover!" << endl;
        return;
    }
    No *rem = f.inicio;
    f.inicio = rem->prox;
    if (f.inicio == NULL) { // fila ficou vazia
        f.fim = NULL;
    }
    cout << "Elemento " << rem->infor << " removido da fila!" << endl;
    delete rem;
    f.tamanho--;
}

// c) Listar conteúdo da fila
void listarFila(Fila f) {
    if (f.inicio == NULL) {
        cout << "Fila vazia!" << endl;
        return;
    }
    cout << "Conteudo da fila (inicio -> fim): ";
    No *atual = f.inicio;
    while (atual != NULL) {
        cout << atual->infor << " ";
        atual = atual->prox;
    }
    cout << endl << "Total de elementos: " << f.tamanho << endl;
}

// d) Verificar se elemento está presente
bool buscarElemento(Fila f, int valor) {
    No *atual = f.inicio;
    while (atual != NULL) {
        if (atual->infor == valor) return true;
        atual = atual->prox;
    }
    return false;
}

// Esvaziar fila
void esvaziarFila(Fila &f) {
    No *atual = f.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        delete temp;
    }
    f.inicio = NULL;
    f.fim = NULL;
    f.tamanho = 0;
}

// Programa principal
int main() {
    Fila f;
    inicializarFila(f);

    int opcao, valor;

    do {
        cout << "\n===== MENU FILA =====" << endl;
        cout << "1 - Inserir elemento (enqueue)" << endl;
        cout << "2 - Remover elemento (dequeue)" << endl;
        cout << "3 - Listar fila" << endl;
        cout << "4 - Buscar elemento" << endl;
        cout << "5 - Esvaziar fila" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                enfileirar(f, valor);
                break;
            case 2:
                desenfileirar(f);
                break;
            case 3:
                listarFila(f);
                break;
            case 4:
                cout << "Digite o valor a buscar: ";
                cin >> valor;
                if (buscarElemento(f, valor))
                    cout << "Elemento " << valor << " encontrado!" << endl;
                else
                    cout << "Elemento " << valor << " NAO encontrado!" << endl;
                break;
            case 5:
                esvaziarFila(f);
                cout << "Fila esvaziada!" << endl;
                break;
            case 0:
                cout << "Saindo..." << endl;
                esvaziarFila(f);
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
