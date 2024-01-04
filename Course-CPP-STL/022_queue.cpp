// Neste programa usaremos os métodos básicos de filas.
// Suponha que temos um robô empilhador e três pilhas de caixas.
// O número de caixas em cada uma é dado pelos inteiros a, b e c.
// O robô recebe uma sequência de comandos e deve executá-los na
// ordem. O lote de comandos é dado numa string, e cada caracter
// representa uma instrução:
//   - O caracter 'A' faz o robô retirar uma caixa de a e colocá-la
//     em b.
//   - O caracter 'B' faz o robô retirar uma caixa de b e colocá-la
//     em c.
//   - O caracter 'C' faz o robô retirar uma caixa de c e colocá-la
//     em a.
// 
// Note que o número de caixas jamais pode se tornar negativo.
// Acrescente loops para gerar a fila de instruções a partir da
// string, e para processar as instruções uma a uma. Use a função
// imprime passando a última instrução executada para mostrar os
// valores a cada passo.
//
// e.g.: Se começarmos com a = 5, b = 2, c = 0,
//		 a sequência de instruções BBBCAAACB deve resultar
//       em a = 4, b = 2, c = 1
#include <iostream>
#include <queue>
#include<string>
using namespace std;

int a, b, c;
//back->ultimo el da fil, push->adic el fim fil, pop->rem el prim fil, front->prim el, size,empty
void imprime(char instrucao) {
	cout << "Instrucao " << instrucao << " executada" << endl;
	cout << "a = " << a << " | b = " << b << " | c = " << c << endl;
}

int main()
{
    int i;
    string entrada;
    char x;
    queue<char> instrucoes;   //////////////ESTA DANDO ERRO
    cin >> entrada;
   

   a = 5; b = 2; c = 0; 

    //Acrescente código aqui
    for(i=0;i<entrada.length();i++){
    	x=entrada[i];
    	if(x=='A'||x=='B'||x=='C'){
    		instrucoes.push(entrada[i]);
    	}
    }
    while(!instrucoes.empty()){
    	x=instrucoes.front();
    	if(x=='A'){
    		if(a!=0){
    			a-=1;
    			b+=1;
    		}
    	}
    	else if(x=='B'){
    		if(b!=0){
    			b-=1;
    			c+=1;
    		}
    	}
    	else if(x=='C'){
    		if(c!=0){
    			c-=1;
    			a+=1;
    		}
    	}

    	imprime(x);
    	instrucoes.pop();
    }

    return 0;
}
