#include <iostream>
using namespace std;

// Estrutura de um nó da lista
struct Node {
    int info;
    Node* next;
};

// Criar lista vazia
Node* criarLista() {
    return NULL;
}

// Inserir elemento no início da lista
void inserirElemento(Node*& head, int valor) {
    Node* novo = new Node;
    novo->info = valor;
    novo->next = head;
    head = novo;
}

// Percorrer lista e mostrar elementos
void percorrerLista(Node* head) {
    if (head == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }
    Node* atual = head;
    cout << "Elementos da lista: ";
    while (atual != NULL) {
        cout << atual->info << " ";
        atual = atual->next;
    }
    cout << endl;
}

// Contar elementos da lista
int contarElementos(Node* head) {
    int contador = 0;
    Node* atual = head;
    while (atual != NULL) {
        contador++;
        atual = atual->next;
    }
    return contador;
}

// Liberar memória da lista (quando for recriar)
void liberarLista(Node*& head) {
    Node* atual = head;
    while (atual != NULL) {
        Node* temp = atual;
        atual = atual->next;
        delete temp;
    }
    head = NULL;
}

// Programa principal com menu
int main() {
    Node* lista = criarLista();
    int opcao, valor;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1 - Criar lista vazia" << endl;
        cout << "2 - Inserir elemento" << endl;
        cout << "3 - Mostrar lista" << endl;
        cout << "4 - Contar elementos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                liberarLista(lista); // limpa a lista se já existia
                lista = criarLista();
                cout << "Lista criada (vazia)!" << endl;
                break;
            case 2:
                cout << "Digite o valor: ";
                cin >> valor;
                inserirElemento(lista, valor);
                cout << "Elemento inserido!" << endl;
                break;
            case 3:
                percorrerLista(lista);
                break;
            case 4:
                cout << "Numero de elementos: " << contarElementos(lista) << endl;
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                liberarLista(lista); // liberar memória ao sair
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}
