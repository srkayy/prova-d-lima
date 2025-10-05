#include <iostream>
using namespace std;

// Estrutura do nó da lista
struct Node {
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class ListaDuplamenteEncadeada {
private:
    Node* head;
    Node* tail;
    int size;

public:
    ListaDuplamenteEncadeada() : head(nullptr), tail(nullptr), size(0) {}
    
    ~ListaDuplamenteEncadeada() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // a) Incluir elementos em qualquer posição
    void inserir(int valor, int posicao) {
        if (posicao < 0 || posicao > size) {
            cout << "Posicao invalida! Posicoes validas: 0 a " << size << endl;
            return;
        }
        
        Node* novoNo = new Node(valor);
        
        if (head == nullptr) {
            head = tail = novoNo;
        }
        else if (posicao == 0) {
            novoNo->next = head;
            head->prev = novoNo;
            head = novoNo;
        }
        else if (posicao == size) {
            tail->next = novoNo;
            novoNo->prev = tail;
            tail = novoNo;
        }
        else {
            Node* atual = head;
            for (int i = 0; i < posicao - 1; i++) {
                atual = atual->next;
            }
            
            novoNo->next = atual->next;
            novoNo->prev = atual;
            atual->next->prev = novoNo;
            atual->next = novoNo;
        }
        
        size++;
        cout << "Elemento " << valor << " inserido na posicao " << posicao << endl;
    }

    // b) Impressão do conteúdo da lista
    void imprimir() {
        if (head == nullptr) {
            cout << "Lista vazia!" << endl;
            return;
        }
        
        cout << "Lista (tamanho " << size << "): ";
        imprimirRecursivo(head);
        cout << endl;
    }

private:
    void imprimirRecursivo(Node* atual) {
        if (atual == nullptr) {
            return;
        }
        
        cout << atual->data;
        
        if (atual->next != nullptr) {
            cout << " <-> ";
        }
        
        imprimirRecursivo(atual->next);
    }

public:
    // c) Busca de um determinado elemento
    int buscar(int valor) {
        Node* atual = head;
        int posicao = 0;
        
        while (atual != nullptr) {
            if (atual->data == valor) {
                return posicao;
            }
            atual = atual->next;
            posicao++;
        }
        
        return -1;
    }

    void buscar() {
        if (head == nullptr) {
            cout << "Lista vazia! Nao eh possivel buscar." << endl;
            return;
        }
        
        int valor;
        cout << "Digite o valor a ser buscado: ";
        cin >> valor;
        
        int posicao = buscar(valor);
        if (posicao != -1) {
            cout << "Elemento " << valor << " encontrado na posicoo " << posicao << endl;
        } else {
            cout << "Elemento " << valor << " nao encontrado na lista!" << endl;
        }
    }

    // d) Exclusão de elementos em qualquer posição
    void excluir(int posicao) {
        if (posicao < 0 || posicao >= size) {
            cout << "Posicao invalida! Posicoes validas: 0 a " << size - 1 << endl;
            return;
        }
        
        Node* noExcluir;
        int valorExcluido;
        
        if (size == 1) {
            noExcluir = head;
            valorExcluido = noExcluir->data;
            head = tail = nullptr;
        }
        else if (posicao == 0) {
            noExcluir = head;
            valorExcluido = noExcluir->data;
            head = head->next;
            head->prev = nullptr;
        }
        else if (posicao == size - 1) {
            noExcluir = tail;
            valorExcluido = noExcluir->data;
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            Node* atual = head;
            for (int i = 0; i < posicao; i++) {
                atual = atual->next;
            }
            noExcluir = atual;
            valorExcluido = noExcluir->data;
            atual->prev->next = atual->next;
            atual->next->prev = atual->prev;
        }
        
        cout << "Elemento " << valorExcluido << " removido da posição " << posicao << endl;
        delete noExcluir;
        size--;
    }

    void excluir() {
        if (head == nullptr) {
            cout << "Lista vazia! Nao eh possivel excluir." << endl;
            return;
        }
        
        int posicao;
        cout << "Digite a posicao para excluir (0 a " << size - 1 << "): ";
        cin >> posicao;
        
        excluir(posicao);
    }

    void inserir() {
        int valor, posicao;
        cout << "Digite o valor a ser inserido: ";
        cin >> valor;
        cout << "Digite a posicao (0 a " << size << "): ";
        cin >> posicao;
        
        inserir(valor, posicao);
    }

    // Métodos auxiliares
    bool vazia() {
        return head == nullptr;
    }

    int getTamanho() {
        return size;
    }

    void limparLista() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
        cout << "Lista limpa completamente!" << endl;
    }
};

// Função para exibir o menu
void exibirMenu() {
    cout << "\n==========================================" << endl;
    cout << "        LISTA DUPLAMENTE ENCADEADA        " << endl;
    cout << "==========================================" << endl;
    cout << "1. Inserir elemento" << endl;
    cout << "2. Excluir elemento" << endl;
    cout << "3. Buscar elemento" << endl;
    cout << "4. Imprimir lista (inicio → fim)" << endl;
    cout << "5. Limpar toda a lista" << endl;
    cout << "6. Informacoes da lista" << endl;
    cout << "0. Sair" << endl;
    cout << "==========================================" << endl;
    cout << "Escolha uma opcao: ";
}

// Função principal interativa
int main() {
    ListaDuplamenteEncadeada lista;
    int opcao;
    
    cout << "Bem vindo a lista" << endl;
    
    do {
        exibirMenu();
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                lista.inserir();
                break;
                
            case 2:
                lista.excluir();
                break;
                
            case 3:
                lista.buscar();
                break;
                
            case 4:
                lista.imprimir();
                break;
                
            case 5:
                lista.limparLista();
                break;
                
            case 6:
                cout << "Tamanho da lista: " << lista.getTamanho() << endl;
                cout << "Estado: " << (lista.vazia() ? "Vazia" : "Com elementos") << endl;
                break;
                
            case 0:
                cout << "Saindo do programa. Ate mais!" << endl;
                break;
                
            default:
                cout << "Opcao invalida! Tente novamente." << endl;
                break;
        }
        
        // Pausa para visualização
        if (opcao != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
        
    } while (opcao != 0);
    
    return 0;
}
