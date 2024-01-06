#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int *m=NULL;
	int **m2=NULL;
	register int i,j;
	//aloca
	if((m=(int*) malloc(10*5*sizeof(int)))==NULL){ //1 vetorzão e um 1 vetor de ponteiros
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	if((m2=(int**) malloc(10*sizeof(int*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	//atrib
	for(i=0;i<10;i++){
		*(m2+i)=(m+i*5);//m2[i]=&m[i*5]
	}
	//leitura
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			*(*(m2+i)+j)=i+j;
		}
	}
	//imprime
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			printf("%02d ",*(*(m2+i)+j));
		}
		printf("\n");
	}
	//libera
	free(m);
	free(m2);
	return 0;
}
