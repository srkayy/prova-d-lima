#include <iostream>
#include <limits>
using namespace std;

typedef struct Reg {
    int infor;
    Reg *prox;
} No;

typedef struct TipoPilha {
    No *Topo;
    int tamanho;
} Pilha;

void inicializarPilha(Pilha &p) {
    p.Topo = NULL;
    p.tamanho = 0;
}

void empilhar(Pilha &p, int valor) {
    No *novo = new No;
    novo->infor = valor;
    novo->prox = p.Topo;
    p.Topo = novo;
    p.tamanho++;
    cout << "Inserido: " << valor << endl;
}

void desempilhar(Pilha &p) { // renomeada para evitar qualquer colisão
    if (p.Topo == NULL) {
        cout << "Pilha vazia, nada a remover!" << endl;
        return;
    }
    No *rem = p.Topo;
    p.Topo = rem->prox;
    cout << "Removido: " << rem->infor << endl;
    delete rem;
    p.tamanho--;
}

void listarPilha(const Pilha &p) {
    if (p.Topo == NULL) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "Pilha (topo->base): ";
    No *at = p.Topo;
    while (at != NULL) {
        cout << at->infor << " ";
        at = at->prox;
    }
    cout << endl << "Total: " << p.tamanho << endl;
}

bool buscarElemento(const Pilha &p, int valor) {
    No *at = p.Topo;
    while (at != NULL) {
        if (at->infor == valor) return true;
        at = at->prox;
    }
    return false;
}

void esvaziarPilha(Pilha &p) {
    No *at = p.Topo;
    while (at != NULL) {
        No *tmp = at;
        at = at->prox;
        delete tmp;
    }
    p.Topo = NULL;
    p.tamanho = 0;
}

int main() {
    Pilha p;
    inicializarPilha(p);

    int opcao, valor;
    do {
        cout << "\n===== MENU PILHA =====" << endl;
        cout << "1 - Empilhar (push)" << endl;
        cout << "2 - Desempilhar (pop)" << endl;
        cout << "3 - Listar pilha" << endl;
        cout << "4 - Buscar elemento" << endl;
        cout << "5 - Esvaziar pilha" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";

        // Validação: garante leitura correta de inteiro
        while (!(cin >> opcao)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Digite um numero: ";
        }

        switch (opcao) {
            case 1:
                cout << "Valor: ";
                while (!(cin >> valor)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Digite um numero: ";
                }
                empilhar(p, valor);
                break;
            case 2:
                desempilhar(p);
                break;
            case 3:
                listarPilha(p);
                break;
            case 4:
                cout << "Valor a buscar: ";
                while (!(cin >> valor)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Digite um numero: ";
                }
                if (buscarElemento(p, valor)) cout << "Encontrado!" << endl;
                else cout << "Nao encontrado!" << endl;
                break;
            case 5:
                esvaziarPilha(p);
                cout << "Pilha esvaziada." << endl;
                break;
            case 0:
                esvaziarPilha(p);
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }
    } while (opcao != 0);

    return 0;
}
