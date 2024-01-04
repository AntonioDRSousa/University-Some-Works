// Crie um sort personalizado com os seguintes critérios:
// Todos os valores ímpares terão que vir antes dos pares
// Os pares devem estar em ordem crescente e os ímpares em ordem decrescente
// Exemplo: 
// Antes do sort customizado: 3, 2, 10, 8, 1, 5, 9
// Depois do sort customizado: 9, 5, 3, 1, 2, 8, 10

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool custom(int a, int b) { 
     /* TO DO: a fazer sort*/
     if(a%2!=0 && b%2!=0){
     	return a>b;	
     }
     else if(a%2==0 && b%2==0){
     	return a<b;
     }
     else{
     	return (a%2)>(b%2);
     }
     //return true;
}

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(10);
    v.push_back(8);
    v.push_back(1);
    v.push_back(5);
    v.push_back(9);
    
    for(int i = 0; i < v.size(); i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    sort(v.begin(), v.end(), custom);
    
    for(int i = 0; i < v.size(); i++) 
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

