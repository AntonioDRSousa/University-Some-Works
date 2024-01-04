// Este programa apresenta facilidades para cria��o de 
// substrings, usando o m�todo substr.
// 1. Rode o programa como ele est�.
// 2. Cheque o que ocorre se algum par�metro do substr for 
// maior que o tamanho do string.
// Resposta:
//		Se o par�metro da esquerda for maior que o tamanho da string
//      o programa terminar� apresentando a seguinte mensagem:								
//		terminate called after throwing an instance of 'std::out_of_range'
//      what():  basic_string::substr: __pos (which is 21) > this->size() (which is 18)
//      Se opar�metro da direita for maior que o tamanho da string 
//      ent�o o programa ir� imprimir a string do par�metro da esquerda at� o final
//
// 3. Acrescente c�digo para verificar todas as substrings
//    da string dada e encontrar o tamanho da maior
//    substring que n�o contiver vogais. Para a string s,
//    deve imprimir 6, pela substring "rld, W".
//
//    Dica: Use a fun��o find_first_of para achar as
//			vogais. Para achar os tamanhos das substrings
//			sem vogais fa�a o seguinte: Para cada vogal
//			que achar, mantenha o �ndice da vogal anterior
//			guardado, subtraia o �ndice novo do �ndice guardado e 
//			diminua 1. Quando achar um tamanho maior, atualize
//			a vari�vel maiortamanho.
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
     //Acrescente c�digo aqui!
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
