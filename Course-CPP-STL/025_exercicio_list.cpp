// Neste programa são apresentados alguns métodos de
// tratamento de listas, sobretudo a diferença entre o insert e o assign.
// 1. Crie uma lista com todos os números de 1 a 16 fazendo um insert com a lista auxiliar (aux) e com o número 16.
// 2. Imprima a lista, usando o iterator, e mudando para exibir do fim para o começo.
// 3. Use o método insert para colocar cinco elementos "17" na lista e imprima o resultado.
// 4. Use o método assign para colocar cinco elementos "17" na lista e imprima o resultado.
// 5. Troque os elementos da lista com a lista auxiliar e veja o resultado.
// 6. Inverta a lista e a imprima lendo-a apenas uma vez.
//

#include <list>
#include <iostream>
using namespace std;

int main() 
{
	int i;
	list<int> l1,aux;
    
    list<int>::iterator it1 = l1.begin();
    
    for(i=1;i<16;++i) aux.push_back(i);

    l1.insert(l1.begin(),aux.begin(),aux.end());
    l1.insert(l1.end(),16);
    list<int>::reverse_iterator rit1 = l1.rbegin();
    while(rit1!=l1.rend()){
    	cout<<*(rit1++)<<" ";
    }
    cout<<endl<<endl;

    l1.insert(l1.end(),5,17);
    it1=l1.begin();
    cout<<"l1 = ";
    while(it1!=l1.end()){
    	cout<<*(it1++)<<" ";
    }
	cout<<endl<<endl;
	
    l1.assign(5,17);
    it1=l1.begin();
    cout<<"l1 = ";
	while(it1!=l1.end()){
    	cout<<*(it1++)<<" ";
    }
	cout<<endl<<endl;

	l1.swap(aux);
	list<int>:: iterator it2=aux.begin();
	it1=l1.begin();
	cout<<"l1 = ";
	while(it1!=l1.end()){
    	cout<<*(it1++)<<" ";
    }
	cout<<endl<<endl;
	cout<<"aux = ";
	while(it2!=aux.end()){
    	cout<<*(it2++)<<" ";
    }
	cout<<endl<<endl;

	l1.reverse();
	it1=l1.begin();
	cout<<"l1 = ";
	while(it1!=l1.end()){
    	cout<<*(it1++)<<" ";
    }
	cout<<endl<<endl;
    
    //Insira código aqui!
    
    //

	return 0;
}
