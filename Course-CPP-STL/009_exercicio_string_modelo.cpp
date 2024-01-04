// Crie um programa que gere uma substring de um texto até a palavra
// passada como parâmetro. Aproveite para revisar stringstreams,
// separando essa substring em suas palavras. Ache as palavras de maior e
// menor comprimento, e imprima a diferença entre esses dois valores.         
//  Exemplo: 
//      texto: "curso STL UERJ"
//      Palavra passada: "UERJ"
//      Substring: "curso STL "
//      Diferença: 2.
//      ('STL' é a menor palavra, com 3 letras, e 'curso' é a maior, com 5.)

#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    string palavra;
    istringstream ss;
    string texto = "Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    string subs,temp;
    int maior=0,menor=100000000;
    string maiorP,menorP;
    cin >> palavra;
    int indice=texto.find(palavra);
    subs=texto.substr(0,indice);
    ss.str(subs);
	while(ss >> temp){
		if(temp.length()<menor){
			menor=temp.length();
			menorP=temp;
		}
		if(temp.length()>maior){
			maior=temp.length();
			maiorP=temp;
		}
	}
	cout << subs << endl;
	cout << "('" << menorP << "' eh a menor palavra,com " << menor <<" letras,e '" << maiorP <<"' eh a maior,com " << maior << ".)" << endl ;
	cout << "Diferenca: " << maior-menor << endl;  
    return 0;
}
