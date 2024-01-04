// Altere o programa abaixo para que, usando APENAS chamadas do método resize, seja
// gerado a partir do vetor v, um vetor decrescente com 9 elementos, que inicie com
// elemento 9 e termine com o elemento 1. Imprima o vetor em seguida usando iterator.

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int i;
    vector<int> v;
    for(i=0;i<9;i++){
    	v.resize(i+1,9-i);
    }

    vector<int> :: iterator it=v.begin();
    while(it!=v.end()){
    	cout<<*(it++)<<" ";
    }
    cout<<endl;
    
    return 0;
}
