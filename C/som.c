#include <stdio.h>
#include <stdlib.h>

float* getvect(int *);
float* sum(float*, float*, int);
void print (float*, int);

int main(){
	int size_v1, size_v2, size_v3;
	printf("V1\n");
	float *v1 = getvect(&size_v1);
	printf("V2\n");
	float *v2 = getvect(&size_v2);
	printf("\n\n\n");
	printf("V1 = ");
	print(v1, size_v1);
	printf("V2 = ");
	print(v2, size_v2);
	if (size_v1==size_v2){
		float *v3 = sum(v1,v2,size_v1);
		printf("Soma = ");
		print(v3, size_v1);
		free (v3);
	}
	else{
		printf("Erro: os vetores tem que ter o mesmo tamanho.\n");
	}
	free (v1);
	free (v2);
	return 0;
}
float* getvect(int*n){
	register int i;
	float* p=NULL;
	printf("Digite n: ");
	scanf("%d",n);
	p=(float*) malloc((*n)*sizeof(float));
	for(i=0;i<(*n);i++){
		printf("V[%d] = ",i+1);
		scanf("%f",p+i);
	}
	return p;
}
float* sum(float* a,float* b,int n){
	register int i;
	float* p=NULL;
	p=(float*) malloc(n*sizeof(float));
	for(i=0;i<n;i++){
		*(p+i)=(*(a+i))+(*(b+i));
	}
	return p;
}
void print(float* v,int n){
	register int i;
	for(i=0;i<n;i++){
		printf("%f ",*(v+i));
	}
	printf("\n");
}
