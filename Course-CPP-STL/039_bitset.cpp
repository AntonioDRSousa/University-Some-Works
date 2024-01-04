// Neste progama demonstramos como usar o básico do bitset
// 1. Complete a função imprime_binario para que imprima o
//    número a passado no formato binário (32-bit).
// 2. Complete a função imprime_decimal para que imprima a
//    string de bits passada no formato decimal. Por exemplo,
//    deve converter "01011" para 11.
// 3. Complete a função teste_palindromo para que retorne TRUE
//    caso os bits da bitset passada constituam um palíndromo,
//    isto é, uma bitset que pode ser lida igualmente de trás
//    para frente.
//		10101 é um palíndromo
//		00000 é um palíndromo
//		00100 é um palíndromo
//		00011 não é um palíndromo
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void imprime_binario(unsigned long a) {
	bitset<32> b(a);
	cout << b << endl;
}

void imprime_decimal(string a) {
	bitset<32> b(a);

	cout<<b.to_ulong()<<endl;
}

template<int N>
bool teste_palindromo(const bitset<N> & b) {
	for(int i=0;i<b.size();i++){
		if(b[i]!=b[b.size()-i-1]){
			return false;
		}
	}
	return true;
}

int main() 
{
	imprime_binario(16);
	imprime_decimal("01011");

	bitset<10> b1(string("0110110110")); //Palíndromo
	bitset<10> b2(string("0110110111")); //Não é palíndromo
	// Descomente esse trecho para fazer a questão 3
	cout << boolalpha;
	cout << teste_palindromo<10>(b1) << endl;
	cout << teste_palindromo<10>(b2) << endl;

	return 0;
}
