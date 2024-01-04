// Neste você vai fazer a seguinte aplicação:
//  Dada uma lista ordenada de inteiros qualquer, elimine os elementos cuja posição
//  seja igual a um dos valores da lista.
//  Depois rode seu programa para a lista l criada (1 3 5 7 8)
//  Devem restar apenas (3,7).

#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> l;  
    l.push_back(1); l.push_back(3); l.push_back(5); l.push_back(7); l.push_back(8);
    list<int>::iterator it = l.begin();
  	for( ; it != l.end(); it++ ) cout << *it << " " << " ";
   	cout << endl;
   	for(it=l.begin() ; it != l.end(); it++ ){
   		l.erase(it);
	}
	for( ; it != l.end(); it++ ) cout << *it << " " << " ";
	return 0;
   
}
