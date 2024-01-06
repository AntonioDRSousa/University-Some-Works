#include<stdio.>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE * fp;
	int p;
	char s[30];
	printf("Digite o nome do arquivo: ");
	scanf("%s",s);
	strcat(s,".pgm");
	if((fp=fopen(s,"r"))==NULL){
		printf("Erro: arquivo inexistente\n");
		exit(1);
	}
	do{
		fscanf(fp,"%d",&p);
		if(p=='\n'){
			printf("\n");
		}
		else{
			printf("%x ",p);
		}
	} while(!feof(fp));
	return 0;
}
		
