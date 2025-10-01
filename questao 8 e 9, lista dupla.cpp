#include <iostream>
using namespace std;

struct NO{
    public:
    int info;
    NO* prox;
    NO* ant;
};

class ListaDupla
{ private:
    NO* inicio;
    NO* fim;
    int tamanho;
  public:
  ListaDupla(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
}
    bool ListaVaziaLD();
    void InserirInicioLD(int k);
    void InserirFimLD(int k);
    void repete(int x, int y);
    void ImprimirLD();
};


// parte importante para a questão
void ListaDupla::InserirInicioLD(int k){
    NO *novo;
    novo = new NO;
    novo->info = k;
    novo->ant = NULL;
    if(ListaVaziaLD()) {
        novo->prox = NULL;
        inicio = fim = novo;
        ListaDupla::ListaVaziaLD() = false;
    else
    {
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;;
    }
    tamanho++;
}

void ListaDupla::InserirFimLD(int k){
    NO *novo;
    novo = new NO;
    novo->info = k;
    novo->prox = NULL;
    if(ListaVaziaLD()){
        novo->ant = NULL;
        inicio = fim = novo;
    }
    else{
        novo->prox = fim;
        fim->prox = novo;
        fim = novo;
    }
    tamanho++;
}

void ListaDupla::ImprimirLD(){
    NO* aux;
    aux = inicio;
    while(aux != NULL){
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
}

void ListaDupla::repete(int x, int y){
    NO* aux;
    aux = inicio;
    while(aux != NULL){
        if(aux->info == x){
            break;
        }
        aux = aux->prox;
    }
    switch(y){
        case 1:
            lista.InserirInicioLD(x);
            break;
        case 2:
            lista.InserirFimLD(x);
            break;
    }
}

void menu(){
    cout << "Escolha: " << endl;
    cout << "1 - Inserir no inicio" << endl;
    cout << "2 - Inserir no fim" << endl;
    cout << "3 - Imprimir lista" << endl;
    cout << "4 - Sair" << endl;
    int escolha;
    cin >> escolha;
    switch(escolha){
        case 1:
            int numero;
            cin >> numero;
            lista.repete(numero, 1);
            break;
        case 2:
            int numero;
            cin >> numero;
            lista.repete(numero, 2);
            break;
        case 3:
            lista.ImprimirLD();
            break;
        case 4:
            exit(0);
        default:
            cout << "Opcao invalida!" << endl;
            menu();
            break;
    }
}

int main(){
    ListaDupla lista;
    menu();
}