// Neste programa você vai fazer um exercício com lista de prioridade.
// O algoritmo básico para método Huffman de compactação de dados
// consiste em criar uma lista de prioridades para as frequências 
// dos n símbolos e depois fazer n-1 passos onde, a cada passo, são
// retirados os dois menores elementos da lista e é adicionada sua soma.
// Faça o programa para essa ideia e imprima o topo da lista a cada
// operação.

#include <queue>
#include <iostream>

using namespace std;

int main()
{
	//Altere a priority_queue abaixo para que elementos
	//menores tenham mais prioridade
	
	priority_queue<int, vector<int>, greater<int> > pq; 
    for (int i=1; i<=20; i++)
    {  pq.push(i); cout << i << " ";
    }
    cout << endl;

	cout<<endl<<endl;
	int x;
    for(int i=1; i<pq.size();i++){
    	x=pq.top();
    	pq.pop();
    	x+=pq.top();
    	pq.pop();
    	pq.push(x);
    	cout<<pq.top()<<endl;
    }

    return 0;
}
