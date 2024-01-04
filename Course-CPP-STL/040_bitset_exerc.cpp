// Neste programa você deve resolver os seguintes problemas:
//    1. Reimplemente a funcionalidade de bitset.reset() sem utilizar
//       loops nem os comandos set ou reset. A função meu_reset deve alterar
//		 o bitset passada b para que o efeito seja igual a b.reset().
//    2. Escreva a função meu_set de forma que ela altere os n bits
//       menos significativos da bitset para 1, sem usar loops ou o
//		 comando set.
//			Exemplo: b = 0110101001
//					 meu_set(b, 5)
//					 b = 0110111111
//    3. Reimplemente a funcionalidade de bitset.flip() sem utilizar
//       loops, nem o operador ~, nem o comando flip. A função meu_flip
//       deve alterar o bitset passado b para que o efeito seja igual a b.flip().
//    4. Dados dois bitsets, contar o número de bits de mesma posição 
//       que sejam diferentes sem utilizar loops. O resultado para
//       este os bitsets b1 e b2 deve ser 12.
#include <iostream>
#include <bitset>
#include <string>
#include<math.h>
using namespace std;

template<int N>
void meu_reset(bitset<N> & b){
	b=0*b.to_ulong();
}

template<int N>
void meu_set(bitset<N> & b, int n) {
	unsigned long y=b.size();
	unsigned long z=b.to_ulong();
	unsigned long x;
	y=pow(2,y+1);
	x=y+pow(2,n+1)-1;
	x=x-z;
	x-=y;
	b=x;
}

template<int N>
void meu_flip(bitset<N> & b) {
	unsigned long y=b.size();
	unsigned long z=b.to_ulong();
	unsigned long x;
	x=pow(2,y+1)-1;
	x-=z;
	b=x;
}

int main() 
{
	bitset<8> bs(string("01011101"));
	cout << bs << endl;

	//Problema 1
	meu_reset<8>(bs);
	cout << bs << endl;

	//Problema 2
	meu_set<8>(bs, 4);
	cout << bs << endl;

	//Problema 3
	meu_flip<8>(bs);
	cout << bs << endl;

	//Problema 4
	bitset<20> b1(string("00010100010101000101")), 
               b2(string("01111111101010000001"));

	return 0;
}
