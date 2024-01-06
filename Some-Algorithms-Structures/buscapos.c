#include<stdio.h>

int buscapos(int L[],int c,int posins){
	int i=0,f=10;
	int m;
	while(i<=f){
		m=(i+f)/2;
		printf("meio = %d\n",m);
		if(L[m]==c){
			printf("achei");
			return m;
		}
		else if(L[m]<c){
			i=m+1;
			printf("inicio = %d final = %d\n",i,f);
		}
		else{
			f=m-1;
			printf("final = %d inicio = %d\n",f,i);
		}
	}
	posins=i;
	return -1;
}

int main(){
	int i,c,pos,posins;
	int v[10];
	printf("Digite o vetor: ");
	for(i=0;i<10;i++){
		scanf("%d",&v[i]);
	}
	printf("\n\nVetor: ");
	for(i=0;i<10;i++){
		printf("%d ",v[i]);
	}
	printf("\nDigite a chave: ");
	scanf("%d",&c);
	pos=buscapos(v,c,posins);
	printf("fiz a busca.......");
	printf("posicao: %d\n",posins);
	return 0;
}
