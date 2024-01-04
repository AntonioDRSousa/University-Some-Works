// Este programa apresenta facilidades para criação de 
// substrings, usando o método substr.
// 1. Rode o programa como ele está.
// 2. Cheque o que ocorre se algum parâmetro do substr for 
// maior que o tamanho do string.
// Resposta:
//		Se o parâmetro da esquerda for maior que o tamanho da string
//      o programa terminará apresentando a seguinte mensagem:								
//		terminate called after throwing an instance of 'std::out_of_range'
//      what():  basic_string::substr: __pos (which is 21) > this->size() (which is 18)
//      Se oparâmetro da direita for maior que o tamanho da string 
//      então o programa irá imprimir a string do parâmetro da esquerda até o final
//
// 3. Acrescente código para verificar todas as substrings
//    da string dada e encontrar o tamanho da maior
//    substring que não contiver vogais. Para a string s,
//    deve imprimir 6, pela substring "rld, W".
//
//    Dica: Use a função find_first_of para achar as
//			vogais. Para achar os tamanhos das substrings
//			sem vogais faça o seguinte: Para cada vogal
//			que achar, mantenha o índice da vogal anterior
//			guardado, subtraia o índice novo do índice guardado e 
//			diminua 1. Quando achar um tamanho maior, atualize
//			a variável maiortamanho.
#include <iostream>
using namespace std;

int main()
{
     string s = "Hello World, World";
     string sub;
     int indiceVogal1=0,indiceVogal2=0,temp;
     cout << s.substr(1,4) << endl;
     cout << s.substr(1) << endl;

     int maiortamanho = 0;
     //Acrescente código aqui!
    while(indiceVogal1 !=string::npos || indiceVogal2 !=string::npos){
		indiceVogal1=s.find_first_of("aeiou",indiceVogal1+1);
		if((indiceVogal1 - indiceVogal2) > maiortamanho){
		    	maiortamanho=indiceVogal1 - indiceVogal2-1;
	 			}
	 	indiceVogal2=s.find_first_of("aeiou",indiceVogal1+1);
	 	indiceVogal1=indiceVogal2;
     // 
	 }
	 cout << maiortamanho << endl;
     
     return 0;
}
