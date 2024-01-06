#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int l1,l2,c1,c2;
	register int i,j;
	float **a2,**b2,**m2;
	float *a,*b,*m;
	printf("Digite as dimensões da matriz 1: ");
	scanf("%d %d",&l1,&c1);
	printf("Digite as dimensões da matriz 2: ");
	scanf("%d %d",&l2,&c2);
	if((l1!=l2) && (c1!=c2)){
		fprintf(stderr,"Dimensões devem ser iguais\n");
		exit(2);
	}
	//aloca
	if((a=(float*) malloc(l1*c1*sizeof(float)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((b=(float*) malloc(l2*c2*sizeof(float)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((m=(float*) malloc(l1*c1*sizeof(float)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((a2=(float**) malloc(l1*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((b2=(float**) malloc(l2*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((m2=(float**) malloc(l1*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	//construção
	for(i=0;i<l1;i++){
		a2[i]=&a[i*c1];
		b2[i]=&b[i*c2];
		m2[i]=&m[i*c1];
	}
	//leitura
	printf("\n\nMatriz A\n");
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			printf("A[%d,%d] = ",i,j);
			scanf("%f",*(a2+i)+j);
		}
	}
	printf("\n\nMatriz B\n");
	for(i=0;i<l2;i++){
		for(j=0;j<c2;j++){
			printf("B[%d,%d] = ",i,j);
			scanf("%f",*(b2+i)+j);
		}
	}
	printf("\n\n");
	//calculo
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			(*(*(m2+i)+j))=(*(*(a2+i)+j))+(*(*(b2+i)+j));
		}
	}
	//imprime
	printf("\n\nMatriz A\n");
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			printf("%f ",*(*(a2+i)+j));
		}
		printf("\n");
	}
	printf("\n\nMatriz B\n");
	for(i=0;i<l2;i++){
		for(j=0;j<c2;j++){
			printf("%f ",*(*(b2+i)+j));
		}
		printf("\n");
	}
	printf("\n\nMatriz M\n");
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			printf("%f ",*(*(m2+i)+j));
		}
		printf("\n");
	}
	free(a);
	free(b);
	free(m);
	free(a2);
	free(b2);
	free(m2);
	return 0;
}
	
