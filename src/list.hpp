#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>

template <typename T>
struct Block{
    T dado;
    Block<T> *prox;
};

template <typename T>
struct List{
    Block<T>* cabeca;
    Block<T>* cauda;
    int qtd;
    int collisions;
};

template <typename T>
void FLVazia(List<T> *lista){
    lista->cabeca = new Block<T>;
    lista->cauda = lista->cabeca;
    lista->cauda->prox = nullptr;
    lista->qtd = 0;
    lista->collisions=0;
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