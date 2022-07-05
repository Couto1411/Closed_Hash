#include "hash.hpp"

int main(){
	List<Hash> Hash;
	List<int> numeros;
	FLVazia(&Hash);
	FLVazia(&numeros);
	int vetor[20]={1378, 3012, 600, 4700, 918, 175, 2051, 3653, 4558, 1210, 1468, 2724, 1055, 2143, 1136, 546, 3350, 1610, 3412, 1096};
	for (int i = 0; i < 20; i++){
		InsereLista(&numeros,vetor[i]);
		numeros.qtd+=1;
	}
	InsereHash(&Hash,&numeros);
	printLista(&Hash);
	buscaHash(&Hash,1377);
	buscaHash(&Hash,1378);
	removeHash(&Hash, 4557);
	removeHash(&Hash, 4558);
	printLista(&Hash);
	return 0;
}
