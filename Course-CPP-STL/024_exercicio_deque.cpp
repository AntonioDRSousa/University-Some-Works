// Neste programa voc� vai fazer um exerc�cio usando Deques.
// Trata-se da simula��o de um jogo:
// � dada uma sequ�ncia de n�meros e o jogo ser� jogado por
// 2 jogadores. Cada jogador, ao in�cio do jogo, escolhe uma
// das pontas do deque, para tirar 1, 2 ou 3 elementos a cada
// turno. Quando terminar o deque termina o jogo.
// Quem tirar mais pontos vence.
// Voc� pode inventar uma estrat�gia qualquer e mostrar a evolu��o
// do jogo. No futuro voc� pode pensar em uma estrat�gia �tima para
// o primeiro jogador.  O deque ter� 10 elementos, j� gerados.

#include <iostream>
#include <deque>
#include<stdlib.h>
using namespace std;

int main()
{   int i,j,k;  deque<int> dq;

	int jogador[2]; //lado escolhido pelos jogadores
	int pts[2]={0,0}; //pontuacao dos jogadores
	int n;
	
    for (i=0; i<10;i++) dq.push_back(rand()%100-50);
    for (i=0; i<10;i++) cout << dq[i] << " ";  cout <<endl;
    
    cout<<"Digite um numero par para escolher o lado direito, e impar para escolher o lado esquerdo"<<endl;
    cin>>n;
    jogador[0]=n%2;jogador[1]=(n+1)%2;
    
    for(i=0;!dq.empty();(i++)%2){
    	cout<<endl<<endl;
    	cout<<"Lado "<<endl;
    	if(jogador[i]==0){
    		cout<<"Direito"<<endl;
    	}
    	else{
    		cout<<"Esquerda"<<endl;
    	}
    	while(true){
    		cout<<"Digite 1,2,3: ";
    		cin>>n;
    		if(n>=1 && n<=3){
    			break;
    		}
    		cout<<"numero invalido"<<endl;
    	}
    	cout<<"n= "<<n<<endl;
    	for(j=1;j<=n;j++){
    		if(dq.empty()){
    			break;
    		}
    		else if(jogador[i]==0){
    			pts[i]+=dq.back();
    			dq.pop_back();
    		}
    		else{
    			pts[i]+=dq.front();
    			dq.pop_front();
    		}
    	}
    	for (k=0; k<dq.size();k++) cout << dq[k] << " ";  cout <<endl;
    }
    
    cout<<"Pontuacoes: "<<endl;
    cout<<"Jogador 1 -> "<<pts[0]<<endl;
    cout<<"Jogador 2 -> "<<pts[1]<<endl;
    if(pts[0]>pts[1]){
    	cout<<"Jogador 1 Venceu"<<endl;
    }
    else if(pts[1]>pts[0]){
    	cout<<"Jogador 2 Venceu"<<endl;
    }
    else{
    	cout<<"Empate"<<endl;
    }		
    		

	return 0;
}
