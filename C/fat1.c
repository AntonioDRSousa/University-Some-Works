#include<stdio.h>

int ler(void);
int fat(int);
void impr(int,int);


int main(void){
	int n,m;
	n=ler();
	m=fat(n);
	impr(n,m);
	return 0;
}

int ler(void){
	int x;
	for(;;){
		printf("Digite um numero inteiro maior ou igual a zero: ");
		scanf("%d",&x); //devemos tratar esse erro
		if(x>=0){
			return x;
		}
		else{
			printf("Digite novamente......");
		}
	}
}

int fat(int x){
	if(x==0){
		return 1;
	}
	else{
		return x*fat(x-1);
	}
}

void impr(int x,int y){
	printf("\n%d! = %d\n",x,y);
}
		
	
