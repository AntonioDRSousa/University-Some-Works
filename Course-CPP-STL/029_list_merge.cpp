// Neste programa apresentamos o método Merge para tratamento de listas.
// 1. Rode o programa como está.
// 2. Faça o Merge das listas sem usar o comando Merge.
#include <list>
#include <iostream>
#include<queue>
using namespace std;

void imprime(list<char> l, string nome) {  
list<char>::iterator it = l.begin();  cout << nome << " Lista: ";
		for( ; it != l.end(); ++it) { cout << *it << " "; }  
		cout << endl; 
}

int main()
{
	list<char> l1, l2;
	for(int i = 0 ; i < 15 ; ++i) 
	{ if(i%3==0)  l1.push_back(i+65); 
      if (i%2==0) l2.push_back(i+65); }
	imprime(l1, "1ª"); 
	imprime(l2, "2ª");
	
	priority_queue<int> pq;
	while(!l1.empty()){
		pq.push(l1.front());
		l1.pop_front();
	}
	while(!l2.empty()){
		pq.push(l2.front());
		l2.pop_front();
	}
	l1.clear(); l2.clear();
	while(!pq.empty()){
		l2.push_front(pq.top());
		pq.pop();
	}
	imprime(l1, "1ª");
	imprime(l2, "2ª");

    return 0;
}
