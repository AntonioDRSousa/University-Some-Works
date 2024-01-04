// Neste programa você continua a trabalhar com pilhas.
// Você deve fazer um programa para resolver o seguinte problema:
//    Dado um string que representa a sequência de parênteses de uma
//    expressão aritmética, quer-se saber se a sequência está correta ou não.
//    A ideia é ler o string, caracter a caracter. Se for '(' deve ser empilhado.
//    Se for ')', então deve-se desempilhar.
//    Se, ao final, a pilha não estiver vazia ou se, antes de terminar o string,
//    a pilha ficar vazia, então a sequência está errada. Para cada string em
//    uma linha deve ser impresso 'S' se estiver correto ou 'N', caso contrário.
//    Ex: "(()())"   -> S    
//        "(()()"    -> N   
//        "(()())("  -> N
//        ""         -> S
#include <iostream>
#include <stack>
#include<string>
using namespace std;
int main()   //falta resolver o problema para quando n tem caracter
{   stack<char> pilha;   char c;
    string s;    
    bool b=true;
	cin>>s;
	for(register int i=0;i<s.length();i++){
		c=s[i];
		if(c=='('){
			pilha.push(c);
		}
		else if(c==')'){
			if(pilha.empty()){
				b=false;
				break;
			}
			pilha.pop();
		}
	}
	if(!pilha.empty()){
		b=false;
	}

	if(b){
		cout<<'S'<<endl;
	}
	else{
		cout<<'N'<<endl;
	}
	
    
    return 0;
}
