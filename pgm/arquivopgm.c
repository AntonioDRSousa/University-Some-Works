#include <stdio.h>
#include <stdlib.h>
void lerarq(char*c);
void imprimir (char*c);
int main(){
	char c[110];
	lerarq(c);
	imprimir(c);
	return 0;
}
void imprimir(char*c){
	printf("%s",c);
}
void lerarq(char*c){
	FILE *fp;
	register int i=0;
	fp=fopen("p2.pgm","r");
	if(fp==NULL){
		printf("ERRO AO ABRIR ARQUIVO\n");
		exit(0);
	}
	do{
		c[i]=fgetc(fp);
		i++;
	}while(c[i-1]!=EOF);
	
	if(fclose(fp)==EOF){
		printf("ERRO AO FECHAR ARQUIVO\n");
		exit(0);
	}
	
	
}

