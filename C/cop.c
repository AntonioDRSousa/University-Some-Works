#include<stdio.h>
#include<stdlib.h>

void copy(char*,char*);

int main(int argc,char* argv[]){
	char *s,*t;
	if((s=(char*) malloc(31*sizeof(char)))==NULL){
		printf("Erro.....\n");
	}
	if((t=(char*) calloc(31,sizeof(char)))==NULL){
		printf("Erro.....\n");
	}
	fprintf(stdout,"Digite uma string: ");
	fscanf(stdin,"%s",s);
	fprintf(stdout,"s -> %s",s);
	copy(s,t);
	fprintf(stdout,"\nt -> %s",t);
	free(s);
	free(t);
	return 0;
}

void copy(char*s,char*t){
	while(*(t++)=*(s++))
		;
}
	
