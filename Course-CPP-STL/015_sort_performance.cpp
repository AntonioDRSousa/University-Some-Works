// Este programa mostra as facilidades do uso de sort.
// 1. Explore a efici�ncia da ordena��o, criando o maior vetor que conseguir e
//    observe o tempo de execu��o.
// 2. Compare o tempo de execu��o do sort para um vetor j� ordenado com o tempo
//    de execu��o do sort para um vetor pseudoaleat�rio. 
//
// Escreva brevemente suas conclus�es aqui:
//vetor ordenado -> 281 segundos
//vetor pseudo-aleatorio -> 433 segundos
//Conclui-se que � mais r�pido ordenar pelo sort um vetor ordenado do que um vetor n�o ordenado
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

vector<int> v;
int main()
{   
    int t;
    //Altere o valor abaixo, veja at� onde voc� consegue aument�-lo
    const long long int TAM = 1000000000;

    //Inser��o de valores j� ordenados
    for (int i=1; i<= TAM; i++) v.push_back(i);
    cout << "vetor ordenado criado, chamando o sort..." << endl;
    t = -time(NULL);
    sort(v.begin(), v.end());
    t += time(NULL);
    cout << "fim da ordenacao 1. tempo = " << t << " segundos" << endl;
    
    v.clear();
    srand(time(NULL));
    
    //Inser��o de valores aleat�rios
    for (int i=1; i<= TAM; i++) v.push_back(rand());
    cout << "vetor aleatorio criado, chamando o sort..." << endl;
    t = -time(NULL);
    sort(v.begin(), v.end());
    t += time(NULL);
    cout << "fim da ordenacao 2. tempo = " << t << " segundos" << endl;

    return 0;
}
