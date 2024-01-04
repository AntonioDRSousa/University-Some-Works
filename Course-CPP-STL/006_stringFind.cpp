// Este programa apresenta facilidades para busca de substrings,
// usando o comando find. Neste exemplo, suponha um sistema de
// cadastro de usuário e queremos proibir nomes que contenham
// palavras vulgares.
// 1. Rode o programa como ele está. Perceba que todos os nomes são aceitos.
// 2. Altere a função Verifica para retornar FALSO quando for passado qualquer
//    nome que contenha uma das substrings em palavrasProibidas, independente
//    de letras maiúsculas ou minúsculas.
//    
//    e.g.: Rato, JAVALI, frescobol e hAsKeLL seriam nomes rejeitados

#include <iostream>
#include <algorithm>
using namespace std;

//Use esta função para transformar uma string em caracteres minúsculos
string minusculo(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

//Altere a função abaixo!
bool Verifica(string nome, string palavrasProibidas[], int numPalavrasProibidas) {
	int pos;
	string s=minusculo(nome);
	for(int i=0;i<numPalavrasProibidas;i++){
		pos=s.find(palavrasProibidas[i]);
		if(pos!=string::npos){
			return false;
		}
	}
	return true;
}
//////////////

int main()
{
     string nome;
     cout << "Digite o nome de usuario desejado: ";
     cin >> nome;
     string palavrasProibidas[] = {"java", "cobol", "haskell", "r"};
     int numPalavrasProibidas = 4;

     if (Verifica(nome, palavrasProibidas, numPalavrasProibidas)) {
     	cout << "O nome digitado foi aceito." << endl;
     } else {
     	cout << "Erro: O nome digitado e invalido!" << endl;
     }
     return 0;
}
