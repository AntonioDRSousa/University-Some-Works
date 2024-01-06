#include<stdio.h>
#include<stdlib.h>

void erro(FILE * fp); //verificar erros

int main(){
	FILE * fp;
	int i,x;
	char s[30];
	if((fp=fopen("p2.pgm","r"))==NULL){
		printf("Erro: arquivo inexistente\n");
		exit(1);
	}
	for(i=0;i<5;i++){ //pula as 4 primeiras linhas do arquivo
		fgets(s,30,fp);
		erro(fp);
	}
	for(i=0;;){	 
		fscanf(fp,"%d",&x);
		erro(fp);
		if(i==10){
			if(feof(fp)){
				break;
			}
			printf("\n");
			i=0;
		}
		printf(" %02X",x);
		i++;
	}
	if(fflush(fp)==EOF){
		printf("Erro no fflush.......\n");
		exit(2);
	}
	if(fclose(fp)){
		printf("Erro ao fechar arquivo.....\n");
		exit(3);
	}
	return 0;
}

void erro(FILE * fp){
	if(ferror(fp)){
		printf("erro...\n");
		exit(4);
	}
}		
