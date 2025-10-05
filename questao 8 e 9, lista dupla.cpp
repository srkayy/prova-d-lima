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
    void menu();
    void deletar(int k);
};

ListaDupla lista;

bool ListaDupla::ListaVaziaLD(){
    return (inicio == NULL && fim == NULL);
}
//--------------------------------------------
// relevante para a questão 2
//--------------------------------------------
void ListaDupla::InserirInicioLD(int k){
    //no *vassoura = inicio;
    //for(int i = 0; i < tamanho; i++){
    //    if(vassoura->info == k){
    //        cout << "Numero ja existe na lista!" << endl;
    //        system("pause");
    //        return lista.menu();
    //    }
    //    vassoura = vassoura->prox;
    //}
    NO *novo;
    novo = new NO;
    novo->info = k;
    novo->ant = NULL;
    if(lista.ListaVaziaLD()) {
        novo->prox = NULL;
        inicio = fim = novo;
    }else
    {
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
    }
    tamanho++;
    lista.menu();
}
//--------------------------------------------

void ListaDupla::InserirFimLD(int k){
    NO *novo;
    novo = new NO;
    novo->info = k;
    novo->prox = NULL;
    if(lista.ListaVaziaLD()){
        novo->ant = NULL;
        inicio = fim = novo;
    }
    else{
        novo->ant = fim;
        fim->prox = novo;
        fim = novo;
    }
    cout << novo->ant << endl;
    tamanho++;
    lista.menu();
}

void ListaDupla::ImprimirLD(){
    NO* aux;
    aux = inicio;
    while(aux != NULL){
        cout << aux->info << " ";
        aux = aux->prox;
    }
    cout << endl;
    system("pause");
    lista.menu();
}

//--------------------------------------------
// relevante para a questão 2
//--------------------------------------------
void ListaDupla::repete(int x, int y){
    NO *aux;
    aux = inicio;
    while(aux != NULL){
        if(aux->info == x){
            cout << "Numero ja existe na lista!" << endl;
            system("pause");
            return lista.menu();
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
    lista.menu();
}
//--------------------------------------------

void ListaDupla::menu(){
    system("cls");
    cout << "Escolha: " << endl;
    cout << "1 - Inserir no inicio" << endl;
    cout << "2 - Inserir no fim" << endl;
    cout << "3 - Imprimir lista" << endl;
    cout << "4 - Deletar elemento" << endl;
    cout << "5 - Sair" << endl;
    int escolha;
    int numero;
    cin >> escolha;
    switch(escolha){
        case 1:
            cin >> numero;
            lista.repete(numero, 1);
            break;
        case 2: 
            cin >> numero;
            lista.repete(numero, 2);
            break;
        case 3:
            lista.ImprimirLD();
            break;
        case 4:
            cin >> numero;
            lista.deletar(numero);
            break;
        case 5:
            exit(0);
        default:
            cout << "Opcao invalida!" << endl;
            lista.menu();
            break;
    }
}

void ListaDupla::deletar(int k){
    NO *aux;
    aux = inicio;
    while(aux != NULL){
        if(aux->info == k){
            if(aux == inicio){
                inicio = aux->prox;
                if(inicio != NULL){
                    inicio->ant = NULL;
                } else {
                    fim = NULL;
                }
            } else if(aux == fim){
                fim = aux->ant;
                if(fim != NULL){
                    fim->prox = NULL;
                } else {
                    inicio = NULL;
                }
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            delete aux;
            tamanho--;
            cout << "Elemento " << k << " deletado." << endl;
            system("pause");
            return lista.menu();
        }
        aux = aux->prox;
    }
    cout << "Elemento " << k << " nao encontrado." << endl;
    system("pause");
    lista.menu();
}

int main(){
    lista.menu();
    return 0;
}
