// Este programa demonstra como funcionam os iterators do vector.
// 1. Rode o programa como ele está.
// 2. Acrescente o código que percorra o vector com um reverse_iterator 
//     adicionando a distância percorida ao valor apontado.
//    O vetor dado (1 2 3 4 5 6 7 8 9 10) deverá se tornar
//                 (10 10 10 10 10 10 10 10 10 10).
// 3. Acrescente o código que percorra o vector com um iterator 
//     multiplicando o valor apontado com a distância percorrida. 
//    O vetor obtido (10 10 10 10 10 10 10 10 10 10) deverá se tornar
//                   (0 10 20 30 40 50 60 70 80 90).

#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int i;
    vector<int> v;
    for(i = 1;i<=10;i++) { v.push_back(i); }
    
    /* TO DO: a fazer: 2.*/ 
    /* TO DO: a fazer: 3.*/ 

    vector<int>::iterator it = v.begin();
    while(it != v.end()) cout << *(it++) << " ";
    cout << endl;
    
    vector<int>::reverse_iterator rit = v.rend();
    while(rit != v.rend()) cout << *(rit++) << " ";
    cout << endl;

	cout<<endl<<endl;
    vector<int>::reverse_iterator rit1=v.rbegin();
    while(rit1!=v.rend()){
    	*(rit1)+=(rit1-v.rbegin());
    	cout<<*(rit1++)<<" ";
    	//rit1++;
    }
	cout<<endl<<endl;

	vector<int>::iterator it1=v.begin();
    while(it1!=v.end()){
    	*(it1)*=(it1-v.begin());
    	cout<<*(it1++)<<" ";
    	//it1++;
    }
    cout<<endl;
    
    
    return 0;
}
