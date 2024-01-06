#include<stdio.h>

int pa(int);

int main(void){
	int n,m;
	printf("Digite um numero: ");
	scanf("%d",&n);
	m=pa(n);
	printf("\nS(%d) = %d\n",n,m);
	return 0;
}

int pa(int x){
	if(x==1){
		return 1;
	}
	else{
		return x+pa(x-1);
	}
}
	
