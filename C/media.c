#include<stdio.h>

int main(){
	float soma=0;
	int n;
	float x;
	float lista[10000];
	
	printf("Calculo da media aritemetica\n");
    printf("-------------------------------\n");
    printf("Digite uma sequencia de numeros (um por linha)\n");
    printf("Para terminar digite um valor negativo\n");

    for(n=0;;n++){
    	scanf("%f",&x);
    	if(x<0){
    		break;
    	}
    	lista[n]=x;
    }

	int i;
    for(i=0;i<n;i++){
    	soma+=lista[i];
    }
    
    if(n>0){
    	printf("media = %f\n",soma/n);   
    }
    else{
        printf("nao existe media\n");
    }

    return 0;
}
