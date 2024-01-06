#include<stdio.h>

void mergesort(int v[],int,int);
void merge(int v[],int,int,int);

int main(){
	int n;
	register int i;
	printf("n = ");
	scanf("%d",&n);
	int v[n];
	for(i=0;i<n;i++){
		printf("V[%d] = ",i);
		scanf("%d",&v[i]);
	}
	mergesort(v,0,n-1);
	for(i=0;i<n;i++){
		printf("V[%d] = %d\n",i,v[i]);
	}
	return 0;
}

void mergesort(int v[],int inicio, int fim){
	int m;
	if(inicio<fim){
		m=(inicio/2)+(fim/2);
		mergesort(v,inicio,m);
		mergesort(v,m+1,fim);
		merge(v,inicio,m,fim);
	}
}

void merge(int v[], int inicio, int limite, int fim){
	int c[fim-inicio+1];
	int i,j,k;
	i=inicio;
	j=limite+1;
	for(k=1;k<=fim-inicio+1;){
		if((j>fim) || (i<=limite && v[i]<=v[j])){
			c[k]=v[i];
			i++;
		}
		else{
			c[k]=v[j];
			j++;
		}
	}
	v=c;
} 
