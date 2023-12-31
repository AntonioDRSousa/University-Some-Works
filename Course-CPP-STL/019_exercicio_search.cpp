// Voc� deve fazer um programa para resolver o seguinte problema,
// usando pesquisa bin�ria:
//    � dado um vetor V de m=100 n�meros positivos ordenados e quer-se saber
//    se existe um par de elementos no vetor cuja soma � um valor N dado.
//
//    Dica: Voc� pode verificar todos os n�meros menores (ou iguais) a N,
//	  e para cada um utilizar a busca bin�ria procurando o seu complemento,
//    isto �, para o n�mero v[i] buscar N-v[i].
//
//    Obs: j� foi colocada a gera��o do vetor V!

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v;

int main()
{   int i,N;
    for (i=1;i<=100;i++) v.push_back(rand()%300);
    sort(v.begin(), v.end());
    for (i=0;i<v.size();i++) cout << v[i] << " ";  cout << endl;
    
    //  Exerc�cio a ser feito 

    cin >> N; // Valor da soma desejado
	bool a=false;
	for(i=0;i<100;i++){
		if(v[i]>N){
			break;
		}
		a=binary_search(v.begin(),v.end(),N-v[i]);
		if(a){
			break;
		}
	}
	if(a){
		cout<<"Existe um par de elementos que que somando dao "<<N<<endl;
	}
	else{
		cout<<"Nao existe um par de elementos que que somando dao "<<N<<endl;
	}
    return 0;
}

