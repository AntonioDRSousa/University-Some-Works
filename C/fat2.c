#include<stdio.h>

unsigned int fat(int);

int i=0;

int main(void){
	int n;
	printf("Digite um numero: ");
	scanf("%d",&n);
	printf("\n%d! = %u\n",n,fat(n));
	printf("%d\n",i);
	return 0;
}

unsigned int fat(int x){
	i++;
	if(x==0){
		return 1;
	}
	else{
		return x*fat(x-1);
	}
}


		
	
