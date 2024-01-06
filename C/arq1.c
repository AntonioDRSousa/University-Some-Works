#include<stdio.h>
#include<stdlib.h>

void erro(FILE *);
void insere(FILE *);
//void remove(FILE *);
void impr(FILE *);

int main(){
	FILE * fp;
	if((fp=fopen("palavras.txt","w+"))==NULL){
		printf("Erro ao abrir o arquivo.....\n");
		exit(1);
	}
	insere(fp);
	//remove(fp);
	impr(fp);
	if(fflush(fp)==0){
		printf("Erro. fflush.....\n");
		exit(3);
	}
	if(fclose(fp)){
		printf("Erro ao fechar arquivo.....\n");
		exit(4);
	}
	return 0;
}

void erro(FILE * fp){
	if(ferror(fp)){
		printf("Erro.....\n");
		exit(2);
	}
}

void insere(FILE *fp){
	register int i;
	char s[30];
	int pos;
	for(i=0;i<10;i++){
		printf("Digite o nome e a posicao: ");
		for(;;){
			if((scanf("%s",s))==0){
				printf("Erro. Digite novamente.....\n");
				continue;
			}
			if((scanf("%d",&pos))==0){
				printf("Erro. Digite novamente.....\n");
				continue;
			}
			break;
		}
		for(;pos>0;--pos){
			fprintf(fp,"\n");
			erro(fp);
		}
		fprintf(fp,"%s",s);
		erro(fp);
	}
}

/*void remove(FILE * fp){
	int pos;
	printf("Digite a posicao a remover: ");
	for(;;){
		if((scanf("%d",&pos))==0){
			printf("Erro.....");
			continue;
		}
		break;
	}
	rewind(fp);
	for(;pos>0;--pos){
		fseek(fp,30,SEEK_CUR);
	}*/

void impr(FILE * fp){
	char s[30];
	rewind(fp);
	while(!feof(fp)){
		fgets(s,30,fp);
		erro(fp);
		fprintf(stdout,"%s\n",s);
	}
}
		
	
		
		
	
