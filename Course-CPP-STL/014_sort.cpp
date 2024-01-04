// Este programa mostra as facilidades do uso de sort.
// 1. Rode o programa como est�.
// 2. Mude o vetor de inteiro para char e crie o vetor com as vogais mai�sculas e
//    min�sculas.
// 3. Modifique a ordena��o para as letras min�sculas virem antes das mai�sculas.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<char> v;

void print() 
{   for(int i = 0; i < v.size(); i++) 
    {   cout << v[i] << " ";
    }
    cout << endl;
}

//bool custom(int a, int b) { return a < b; }
bool custom(char a,char b){
	if((islower(a) && islower(b)) || (isupper(a) && isupper(b))){
		return a<b;
	}
	return islower(a);
	
}

int main()
{   //v.push_back(3);    v.push_back(2);    v.push_back(10);    v.push_back(8);
    //v.push_back(1);    v.push_back(5);    v.push_back(9);
    register int i;
    for(i=65;i<=90;i++){
    	v.push_back(i);
    }
    for(i=97;i<=122;i++){
    	v.push_back(i);
   	}
    
    print();
    sort(v.begin(), v.end());
    print();
    sort(v.begin(), v.end(), greater<int>());
    print();
    sort(v.begin(), v.end(), custom);
    print();

    return 0;
}

