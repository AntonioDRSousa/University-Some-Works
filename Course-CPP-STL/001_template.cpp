// Este programa mostra a facilidade de Template.
// 1. Rode o programa da forma que está.
// 2. Altere a função soma para usar o esquema de template
// 3. Acrescente código para ler, duas a duas, as variáveis 'c' e 'd',
//    'e' e 'f', 'g' e 'h' apresentando o resultado da função soma das
//    duas variáveis lidas logo em seguida.
//    Você pode usar a leitura e a impressão da soma de 'a' e 'b' como
//    exemplo.

#include <iostream>
using namespace std;

//Altere esta função!
template<typename T>
T soma(T a, T b)
{
    return a + b;
}

int main() 
{   int a, b;
    long long int c, d;
    double e, f;
    string g, h;
    cin >> a >> b;
    cin >> c >> d;
    cin >> e >> f;
    cin >> g >> h;
    cout << soma<int>(a,b) <<endl;
    cout << soma<long long int>(c,d) <<endl;
    cout << soma<double>(e,f) <<endl;
    cout << soma<string>(g,h) <<endl;
    //Acrescente código aqui!
    
    //
	return 0;
}
