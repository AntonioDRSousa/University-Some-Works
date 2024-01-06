#include<stdio.h>
int main(){
	int soma=0;
	int x;
	printf("Digite uma sequência de números (um por linha)\n");
    printf("Para terminar digite o valor zero\n");
    for(;;){
    	scanf("%d",&x);
    	if(x==0){
    		break;
    	}
    	soma+=x;
    }
    printf("A soma dos números digitados e' %d\n",soma);
	return 0;
}
