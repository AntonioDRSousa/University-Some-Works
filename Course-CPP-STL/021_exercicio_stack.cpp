// Neste programa voc� continua a trabalhar com pilhas.
// Voc� deve fazer um programa para resolver o seguinte problema:
//    Dado um string que representa a sequ�ncia de par�nteses de uma
//    express�o aritm�tica, quer-se saber se a sequ�ncia est� correta ou n�o.
//    A ideia � ler o string, caracter a caracter. Se for '(' deve ser empilhado.
//    Se for ')', ent�o deve-se desempilhar.
//    Se, ao final, a pilha n�o estiver vazia ou se, antes de terminar o string,
//    a pilha ficar vazia, ent�o a sequ�ncia est� errada. Para cada string em
//    uma linha deve ser impresso 'S' se estiver correto ou 'N', caso contr�rio.
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
