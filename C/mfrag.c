#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int **m=NULL;
	register int i,j;
	//aloca
	if((m=(int**) malloc(10*sizeof(int*)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	for(i=0;i<10;i++){
		if((*(m+i)=(int*) calloc(5,sizeof(int)))==NULL){
			fprintf(stderr,"Erro no calloc\n");
			exit(1);
		}
	}
	//leitura
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			*(*(m+i)+j)=i+j;
		}
	}
	//imprime
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			printf("%02d ",*(*(m+i)+j));
		}
		printf("\n");
	}
	//libera
	for(i=0;i<10;i++){
		free(*(m+i));
	}
	free(m);
	return 0;
}	
