#ifndef Hash_Functions
#define Hash_Functions

#include "list.hpp"

struct Hash{
    int key;
    List<int> list;
};


int proxPrimo(int N);
bool ePrimo(int n);
int HashKey(List<Hash> *hash,int numero);
void InsereHash(List<Hash> *hash, List<int> *vetor);
void printLista(List<Hash> *hash);
void buscaHash(List<Hash> *hash, int numero);
void removeHash(List<Hash> *hash, int numero);
#endif