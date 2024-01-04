// Neste programa demonstramos como usar o básico e os iterators do map
// 1. Rode o programa como está.
// 2. Acrescente código para imprimir o tamanho do mapa após imprimir cada
//    cada elemento. O que acontece ao procurar por um elemento não mapeado?
//  Resposta:O programa imprime o valor 0 e o tamanho do map aumenta em um
//
// 3. Mude o último loop para imprimir os elementos usando o método find.          
//    E agora, o que acontece quando o mapeamento não está definido?
//  Resposta:O elemento do mapa vai printar 0, e o tamanho é incrementado a cada novo elemento desconhecido que escrevemos
//
// 4. Remova o bloco de comentários do código. Qual o critério para a ordenação dos elementos no map?
//  Resposta:Não existe nenhum critério
//

#include <map>
#include <iostream>
using namespace std;

int main()
{
    map<string, int> m;
    string s;
 	m["zero"] = 0;
    m["um"] = 1;
    m["dois"] = 2;
    m["tres"] = 3;
    m["quatro"] = 4;
    
    //-- Remova este bloco de comentários para os exercícios 3 e 4! --
    
    map<string, int>::iterator iter = m.begin();

    while (iter != m.end())
    {
        cout << iter->first << " = " << iter->second << endl;
        ++iter;
    }
    
    
    while (cin >> s) {
		iter=m.find(s); 
		cout << iter->second << endl;
		cout << m.size() << endl;
	 }

    return 0;
}
