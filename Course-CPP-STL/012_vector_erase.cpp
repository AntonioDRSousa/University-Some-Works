// Este programa demonstra como funciona o método erase
// 1. Rode o programa como ele está.
// 2. Acrescente o código para apagar do vector v apenas os números ímpares
//	  usando o erase. Tome cuidado para não pular elementos durante a
//	  iteração, pois sempre que você apagar um elemento do vector, o
//    elemento seguinte toma sua posição.
// 3. Depois, acrescente o código para apagar do vector w quaisquer
//	  elementos que estejam entre pares de números consecutivos.
//	  Certifique-se de usar a forma do erase que apaga intervalos,
//	  ao invés de um elemento por vez.
//	  Exemplo: O vetor w sugerido deverá se tornar:
//				1 2 2 6 7 8 8 10

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int main()
{
    int i;
    int a[] = {20, 11, 15, 10, 9, 40, 13, 34, 43, 99, 100, 1};
    vector<int> v(a, a+12);
    
    //Acrescente código aqui!

    ////////////////////////
    
    for(i = 0;i<v.size();i++) cout << v[i] << " "; cout << endl;

    //----------------------------------------
    	
    int b[] = {1, 2, 3, 4, 5, 2, 6, 7, 8, 9, 8, 10};
    vector<int> w(b, b+12);
    
    //Acrescente código aqui!

    ////////////////////////
    
    for(i = 0;i<w.size();i++) cout << w[i] << " "; cout << endl;

	for(i=0;i<v.size();){
   		if(v[i]%2==1){
   			v.erase(v.begin()+i);
   			continue;
   		}
   		i++;
   	}
    for(i = 0;i<v.size();i++) cout << v[i] << " "; cout << endl;

	int n;
	int k,j;
	for(i=0;i<w.size();i++){
		n=w[i];
		for(j=i+1;j<w.size();j++){
			if(w[j]==w[i]){
				w.erase(w.begin()+i+1,w.begin()+j);
			}
		}
	}
    for(i = 0;i<w.size();i++) cout << w[i] << " "; cout << endl;
    return 0;
}
