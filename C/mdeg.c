#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int *m=NULL;
	register int i,j;
	if((m=(int*) malloc(10*5*sizeof(int)))==NULL){
		fprintf(stderr,"Erro no malloc\n");
		exit(1);
	}
	//leitura
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			*(m+(i*5+j))=i+j;
		}
	}
	//imprime
	for(i=0;i<10;i++){
		for(j=0;j<5;j++){
			printf("%02d ",*(m+(i*5+j)));
		}
		printf("\n");
	}
	free(m);
	return 0;
}
