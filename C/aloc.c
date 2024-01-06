#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
	int *a, *b, *c;
	register int i;
	if((a=(int*) malloc(5*sizeof(int)))==NULL){
		printf("Erro.....\n");
	}
	if((b=(int*) calloc(5,sizeof(int)))==NULL){
		printf("Erro.....\n");
	}
	for(i=0;i<5;i++){
		*(a+i)=i;
		*(b+i)=2*i;
	}
	c=a;
	printf("C = ");
	for(i=0;i<5;i++){
		printf("%d ",*(c+i));
	}
	a=(int*) realloc(a,10*sizeof(int));
	for(i=5;i<10;i++){
		*(a+i)=i;
	}
	printf("\n\na = ");
	for(i=0;i<10;i++){
		printf("%d ",*(a+i));
	}
	printf("\n\nb = ");
	for(i=0;i<5;i++){
		printf("%d ",*(b+i));
	}
	printf("\n\nc = ");
	for(i=0;i<5;i++){
		printf("%d ",*(c+i));
	}
	free(a);
	free(b);
	//free(c);
	return 0;
}
