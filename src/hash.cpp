#include "hash.hpp"

void InsereHash(List<Hash> *hash, List<int> *vetor){
    int cont=0,key;
    Block<Hash> *aux;
    Block<int> *numeros;
    List<int> nova;
    Hash temp;
    hash->qtd=proxPrimo((2*vetor->qtd));

    // init hash
    aux=hash->cabeca;
    while (cont<=hash->qtd)
    {
        FLVazia(&nova);
        temp.key=cont;
        temp.list=nova;
        InsereLista(hash,temp);
        aux=aux->prox;
        cont++;
    }
    // init hash

    // preenche hash
    numeros=vetor->cabeca;
    while(numeros->prox!=nullptr)
    {
        key = HashKey(hash,numeros->prox->dado);
        aux=hash->cabeca;
        while (aux->prox->dado.key!=key)
            aux=aux->prox;
        InsereLista(&aux->prox->dado.list,numeros->prox->dado);
        numeros=numeros->prox;
    }
    // preenche hash
}

void buscaHash(List<Hash> *hash, int numero){
    Block<Hash> *aux;
    Block<int> *numeros;
    int key = HashKey(hash,numero);
    aux=hash->cabeca;
    while (aux->prox!=nullptr&&aux->prox->dado.key!=key)
        aux=aux->prox;
    numeros=aux->prox->dado.list.cabeca;
    while (numeros->prox!=nullptr&&numeros->prox->dado!=numero)
        numeros=numeros->prox;
    if (numeros->prox!=nullptr&&numeros->prox->dado==numero)
    {
        printf("O numero existe na lista, na lista de chave %d: \n",key);
        PrintLista(&aux->prox->dado.list);
        printf("\n");
    }
    else
        printf("O numero nao existe na lista.\n");
    
}

void removeHash(List<Hash> *hash, int numero){
    Block<Hash> *aux;
    Block<int> *numeros, *temp;
    int key = HashKey(hash,numero);
    aux=hash->cabeca;
    while (aux->prox->dado.key!=key)
        aux=aux->prox;
    numeros=aux->prox->dado.list.cabeca;
    while (numeros->prox!=nullptr&&numeros->prox->dado!=numero)
        numeros=numeros->prox;
    if (numeros->prox!=nullptr&&numeros->prox->dado==numero)
    {
        temp=numeros->prox;
        numeros->prox=numeros->prox->prox;
        free(temp);
    }
    else
        printf("O numero nao existe na lista.\n");
}

void printLista(List<Hash> *hash){
    Block<Hash> *aux;
    aux=hash->cabeca;
    while (aux->prox!=nullptr){
        printf("%d: ",aux->prox->dado.key);
        PrintLista(&aux->prox->dado.list);
        printf("\n");
        aux=aux->prox;
    }
}

int HashKey(List<Hash> *hash,int numero){
    return numero%hash->qtd;
}

bool ePrimo(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;
   
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int proxPrimo(int N)
{
    if (N <= 1)
        return 2;
 
    int prime = N;
    bool found = false;

    while (!found) {
        prime++;
        if (ePrimo(prime))
            found = true;
    }
 
    return prime;
}