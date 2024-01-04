// Este programa demonstra como funcionam os métodos basicos do vector
// 1. Rode o programa como ele está.
// 2. Acrescente o código para ir retirando os elementos do final 
//    do vector enquanto não for o elemento de valor 5 e depois mostre o 
//    elemento do final.

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i;
    vector<int> v;
    for(i = 1;i<=10;i++) { 
    	v.push_back(i); 
    }
    cout << "Primeiro elemento: " << v.front() << endl;
    cout << "Ultimo elemento: " << v.back() << endl;
    while(v.back()!=5){
    	v.pop_back();  
    	cout << "Removendo ultimo elemento" << endl;
    }
    cout << "Ultimo elemento: " << v.back() << endl;
    
    /* TO DO: a fazer 2.*/
    
    return 0;
}
