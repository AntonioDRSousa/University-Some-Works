// Neste programa você vai trabalhar com a lista de prioridade.
// Um dos métodos de ordenação conhecidos chama-se Heapsort.
// Você pode simular o Heapsort inserindo os elementos de um
// conteiner em uma lista de prioridade e depois removendo-os
// um a um.
// 1. Rode o programa como está.
// 2. Use a priority_queue "pq" para ordenar o vetor V em ordem DECRESCENTE.
// 3. Use a priority_queue "pq2" para ordenar o vetor W em ordem CRESCENTE.
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

void imprime(vector<int> & X) {
	vector<int>::iterator it;
	for(it=X.begin(); it!=X.end(); ++it)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	int a[] = {8, 2, 9, 1, 0, 7, 3, 6, 4, 5};
	int b[] = {90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
	vector<int> V(a,a+10), W(b,b+10);
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int> > pq2;

	//Sort aqui
	vector<int>::iterator it1=V.begin();
	vector<int>::iterator it2=W.begin();
	while(it1!=V.end()){
		pq.push(*(it1));
		it1++;
	}
	while(it2!=W.end()){
		pq2.push(*(it2));
		it2++;
	}

	
	for(int i=0;!pq.empty();i++){
		V[i]=pq.top();
		pq.pop();
	}
	for(int i=0;!pq2.empty();i++){
		W[i]=pq2.top();
		pq2.pop();
	}	

	imprime(V);
	imprime(W);
    return 0;
}
