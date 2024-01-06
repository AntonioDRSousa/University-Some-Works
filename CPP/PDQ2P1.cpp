/*A tarefa é:
a) implementar, com Programação Dinâmica, a seguinte recorrência:
	
	T[i,j] = 0,  se i < 0 ou j < 0
	       = 1,  se i=0, j >= 0,
		   = T[i, j-2] + i+j, se i > 0 e j par
		   = T[i-1, j-1] + T[i-1,j] + T[i+1, j+1], se i > 0 e j ímpar.
    
b) Imprimir a tabela para o cálculo de T[n][m]
*/
#include<iostream>
using namespace std;
int i, j, n, m, T[1025][1025];
  
int main(){
    while(true){
        cout<<endl<<"n, m = ";  cin >> n>>m;
        if(n<0 || m<0){ //flag
        	break;
       	}
        
        // Preenchimento de T[n,m]
        int x,y;
        x=m+(m%2)+1;
        y=n+(m%2)+1;

        for(i=0;i<x;i++){
            T[0][i]=1;
        }
        
        for(i=1;i<y+1;i++){
            for(j=0;j<x;j+=2){
                if((j-2)<0){
                    T[i][j]=i+j;
                }
                else{
                    T[i][j]=T[i][j-2]+i+j;
                }
            }
        }
        
        for(i=1;i<y;i++){
            for(j=1;j<x;j+=2){
                if((i-1)<0){
                    T[i][j]=T[i+1][j+1];
                }
                else if((j-1)<0){
                    T[i][j]=T[i-1][j]+T[i+1][j+1];
                }
                else{
                    T[i][j]=T[i-1][j-1]+T[i-1][j]+T[i+1][j+1];
                }
           }
       }
       

		//Impressão de T[*][*] 
		for(i=0;i<y;i++){
            for(j=0;j<x;j++){
                cout<<T[i][j]<<" ";
            }
            cout<<endl;
        }
		cout<<endl;
        cout<<T[n][m]<<endl;     
	}
	return 0;	
}

