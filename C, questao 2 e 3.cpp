#include <iostream>
using namespace std;

// definicao do no
struct NO{
    public:
    int info;
    NO* prox;
    NO* ant;
};

// definicao da lista dupla encadeada
class ListaDupla
{ private: // atributos
    NO* inicio;
    NO* fim;
    int tamanho;
  public: // construtor
  ListaDupla(){
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
  }
  // metodos
    bool ListaVaziaLD();
    void InserirInicioLD(int k);
    void InserirFimLD(int k);
    void repete(int x, int y);
    void ImprimirLD();
    void menu();
    void deletar(int k);
};

ListaDupla lista; // cria um objeto da classe ListaDupla

// define se a lista esta vazia
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
    NO *novo; // novo no
    novo = new NO; // aloca memoria para o novo no
    novo->info = k; // atribui o valor ao novo no
    novo->ant = NULL; // o anterior do novo no sera NULL
    // se a lista estiver vazia, o novo no sera o inicio e o fim
    if(lista.ListaVaziaLD()) {
        novo->prox = NULL;
        inicio = fim = novo;
    }else // se a lista nao estiver vazia, insere no inicio
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
    NO *novo; // novo no
    novo = new NO; // aloca memoria para o novo no
    novo->info = k; // atribui o valor ao novo no
    novo->prox = NULL; // o proximo do novo no sera NULL
    // se a lista estiver vazia, o novo no sera o inicio e o fim
    if(lista.ListaVaziaLD()){
        novo->ant = NULL;
        inicio = fim = novo;
    }
    else{ // se a lista nao estiver vazia, insere no fim
        novo->ant = fim;
        fim->prox = novo;
        fim = novo;
    }
    cout << novo->ant << endl;
    tamanho++;
    lista.menu();
}

void ListaDupla::ImprimirLD(){
    NO* aux; // no auxiliar
    // percorre a lista imprimindo os elementos
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
    NO *aux; // no auxiliar
    // percorre a lista procurando o elemento
    aux = inicio;
    while(aux != NULL){
        if(aux->info == x){
            cout << "Numero ja existe na lista!" << endl;
            system("pause");
            return lista.menu();
        }
        aux = aux->prox;
    }
    // caso nao encontre, insere
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

//menu de opcoes   
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

//logica para deletar um elemento
void ListaDupla::deletar(int k){
    NO *aux; //no auxiliar
    aux = inicio;
    // percorre a lista procurando o elemento
    while(aux != NULL){ //enquanto nao chegar no fim da lista
        if(aux->info == k){ //se encontrar o elemento
            if(aux == inicio){ //se for o primeiro elemento
                // substitui o inicio pelo proximo
                inicio = aux->prox;
                if(inicio != NULL){
                    inicio->ant = NULL;
                } else {
                    fim = NULL;
                }
            } else if(aux == fim){ //se for o ultimo elemento
                // substiui o fim pelo anterior
                fim = aux->ant;
                if(fim != NULL){
                    fim->prox = NULL;
                } else {
                    inicio = NULL; // lista ficou vazia
                }
            } else {
                // se for um elemento do meio, conecta o anterior com o proximo
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }
            delete aux; //deleta o auxiliar
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
