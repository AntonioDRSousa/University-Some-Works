// Neste programa apresentamos o m�todo splice para tratamento de listas.
// 1. Use uma chamada do m�todo splice para transferir o �ltimo elemento de L2
//	  para a segunda posi��o de L1, e imprima as listas em seguida.
// 2. Use uma chamada do m�todo splice para transferir toda a lista L3, em ordem
//    inversa, para o come�o da lista L2, e imprima as listas em seguida.
// 3. Use uma chamada do m�todo splice para rotacionar a lista L2 tr�s posi��es
//    para a direita. Isto �, o �ltimo elemento passa a ser o terceiro, o pen�ltimo
//    passa a ser o segundo, e o antepen�ltimo passa a ser o primeiro. Imprima as						
//    listas ap�s isso.
// 4. Use uma chamada do m�todo splice para transferir toda a lista L2 para o final
//    da lista L1, e imprima as listas uma �ltima vez.

#include <list>
#include <iostream>
using namespace std;

list<int> l1, l2, l3;

void imprime() { 
	list<int>::iterator it,ult,penult,antpenult;
	it = l1.begin(); cout << "Lista 1: "; 
	for( ; it != l1.end(); ++it) { cout << *it << " "; }  
	cout << endl; 
	it = l2.begin(); cout << "Lista 2: "; 
	for( ; it != l2.end(); ++it) { cout << *it << " "; }  
	cout << endl; 
	it = l3.begin(); cout << "Lista 3: "; 
	for( ; it != l3.end(); ++it) { cout << *it << " "; }  
	cout << endl; 
}

int main()
{
	list<int>::iterator it,it2,ult,penult,antpenult;
	l1.push_back(10); l1.push_back(30); l1.push_back(40); l1.push_back(50);
	l2.push_back(55); l2.push_back(45); l2.push_back(20);
	l3.push_back(15); l3.push_back(25); l3.push_back(35);

	/*Acrescente chamadas 'splice' e 'imprime' aqui*/
	imprime();
	it=l1.begin();
	it++;
	it2=l2.end();
	l1.splice(it,l2,--it2);
	imprime();
	l3.reverse();
	l2.splice(l2.begin(),l3);
	imprime();
	ult=l2.end();
	--ult;
	penult=ult;
	penult--;
	antpenult=penult;
	antpenult--;
	l2.splice(l2.begin(),l2,antpenult,l2.end());
	imprime();
	l1.splice(l1.begin(),l2);
	imprime();
    return 0;
}
