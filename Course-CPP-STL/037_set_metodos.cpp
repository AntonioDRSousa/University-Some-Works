// Neste programa você vai usar alguns dos principais métodos do set:
// size(), count(), clear(), empty(), erase() e find().
// 1. Rode o programa como está.
// 2. Modifique o programa para o conjunto S conter apenas os
//    5 primeiros elementos do vetor mi.
// 3. Acrescente código para retornar quantos elementos existem
//    no conjunto S usando um dos métodos acima.
// 4. Imprima o retorno de count(75), count(23) e count(25) para
//    o conjunto S. Quais são os únicos valores possíveis que a
//    função count() pode retornar para um set qualquer?
//    Resposta: 1 ou 0, isso porque o set não possui elementos repetidos
//
// 6. Acrescente código para o seguinte:
//      * Apagar o elemento 23 e imprimir o conjunto
//      * Apagar ATÉ o elemento 42 (exceto o 42) e imprimir o conjunto
//      (Dica: Use os métodos find() e erase())
//      * Verificar se o conjunto está vazio, e se não estiver, esvaziá-lo
//         sem usar a função erase.

#include <iostream>
#include <set>
using namespace std;

void print(set<int> s) {
    set<int>::iterator it = s.begin();
    cout << "S = { ";
    while(it != s.end()) {
         cout << *it << " "; ++it;
    }
    cout << "}" << endl;
}

int main() 
{
	int mi[] = {75,23,65,42,13,97,57,19};
	set<int> S(mi,mi+5);
	cout<<S.size()<<endl;
	cout<<endl;
	cout<<S.count(75)<<endl;
	cout<<S.count(23)<<endl;
	cout<<S.count(25)<<endl;
	print(S);
	S.erase(23);
	print(S);
	S.erase(S.begin(),S.find(42));
	print(S);
	if(!S.empty()){
		S.clear();
	}
	print(S);
	return 0;
}
