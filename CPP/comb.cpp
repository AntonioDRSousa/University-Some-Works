#include<iostream>
#include<stdio.h>
using namespace std;

int p[105];
int np=-1;
int n=32;
int q=5;
int cont=0;

void comb(int t){
	int i,j;
	for(i=t;i<=n;i++){
		if(cont==50){
			break;
		}
			
		np++; 
		p[np]=i;
		if(np==(q-1)){
			cont++;				
			for(j=0;j<q;j++){
				cout<<p[j]<<" ";
			}
			cout<<endl;	
		}
		else{
			comb(i+1);
		}
		np--;
	}
}

int main(){

	for(register int i=0;i<105;i++){
		p[i]=0;
	}
	
	cout<<"Primeiras 50 COMBINACOES"<<endl;
	comb(1);
	return 0;
}
