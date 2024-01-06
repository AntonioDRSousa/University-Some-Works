#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	float p;
	int l1,l2,c1,c2;
	register int i,j,k;
	float **m1=NULL,**m2=NULL,**m3;
	printf("Digite a dimensao da matriz 1: ");
	scanf("%d %d",&l1,&c1);
	printf("Digite a dimensao da matriz 2: ");
	scanf("%d %d",&l2,&c2);
	if(c1!=l2){
		fprintf(stderr,"Erro colunas de m1 devem ser = a linhas de m2\n");
		exit(2);
	}
	if((m1=(float**) malloc(l1*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((m2=(float**) malloc(l2*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((m3=(float**) malloc(l1*sizeof(float*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	//////////////////
	for(i=0;i<l1;i++){
		if((m1[i]=(float*) malloc(c1*sizeof(float)))==NULL){
			fprintf(stderr,"Erro no malloc\n");
			exit(1);
		}
		if((m3[i]=(float*) malloc(c2*sizeof(float)))==NULL){
			fprintf(stderr,"Erro no malloc\n");
		}
	}
	for(i=0;i<l2;i++){
		if((m2[i]=(float*) malloc(c2*sizeof(float)))==NULL){
			fprintf(stderr,"Erro no malloc\n");
			exit(1);
		}
	}
	//leitura
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			printf("A[%d,%d] = ",i+1,j+1);
			scanf("%f",&m1[i][j]);
		}
	}
	for(i=0;i<l2;i++){
		for(j=0;j<c2;j++){
			printf("B[%d,%d] = ",i+1,j+1);
			scanf("%f",&m2[i][j]);
		}
	}
	//calculo do produto
	for(i=0;i<l1;i++){
		for(j=0;j<c2;j++){
			m3[i][j]=0;
			printf("\n%d %d -> ",i,j);
			for(k=0;k<c1;k++){
				m3[i][j]+=m1[i][k]*m2[k][j];
				printf("%f ",m3[i][j]);
			}
		}
	}
	//imprime matrizes
	printf("\n\nMatriz A\n");
	for(i=0;i<l1;i++){
		for(j=0;j<c1;j++){
			printf("%f ", m1[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatriz B\n");
	for(i=0;i<l2;i++){
		for(j=0;j<c2;j++){
			printf("%f ", m2[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatriz C\n");
	for(i=0;i<l1;i++){
		for(j=0;j<c2;j++){
			printf("%f ", m3[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
	
