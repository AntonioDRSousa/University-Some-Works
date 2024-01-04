// Neste programa demonstramos como usar o b�sico e os iterators do map
// 1. Rode o programa como est�.
// 2. Acrescente c�digo para imprimir o tamanho do mapa ap�s imprimir cada
//    cada elemento. O que acontece ao procurar por um elemento n�o mapeado?
//  Resposta:O programa imprime o valor 0 e o tamanho do map aumenta em um
//
// 3. Mude o �ltimo loop para imprimir os elementos usando o m�todo find.          
//    E agora, o que acontece quando o mapeamento n�o est� definido?
//  Resposta:O elemento do mapa vai printar 0, e o tamanho � incrementado a cada novo elemento desconhecido que escrevemos
//
// 4. Remova o bloco de coment�rios do c�digo. Qual o crit�rio para a ordena��o dos elementos no map?
//  Resposta:N�o existe nenhum crit�rio
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
    
    //-- Remova este bloco de coment�rios para os exerc�cios 3 e 4! --
    
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
