#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

// Estrutura para criar uma corrente de palavras
template <typename T>
struct Block{
    T dado;      // Dados da palavra
    Block<T> *prox;    // Ponteiro para próxima palavra
};

// Estrutura que armazena a cabeça e a cauda da corrente de palavras
template <typename T>
struct List{
    Block<T>* cabeca;  // Início da corrente
    Block<T>* cauda;   // Fim da corrente
    int qtd;           // Quantidade de elementos
};

// Esvazia uma lista de palavras
template <typename T>
void FLVazia(List<T> *lista){
    lista->cabeca = new Block<T>;
    lista->cauda = lista->cabeca;
    lista->cauda->prox = nullptr;
    lista->qtd = 0;
};

template <typename T>
void InsereLista(List<T> *lista, T dado){
    lista->cauda->prox= new Block<T>;
    lista->cauda->prox->dado=dado;
    lista->cauda=lista->cauda->prox;
    lista->cauda->prox=nullptr;
}

template <typename T>
void PrintLista(List<T> *lista){
    Block<T> *aux;
    aux=lista->cabeca;
    while (aux->prox!=nullptr){
        printf("%d, ",aux->prox->dado);
        aux=aux->prox;
    }
}

#endif