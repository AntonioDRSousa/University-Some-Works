#include<stdio.h>

#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max=0; //inicialização do max
	while((len=getline(line, MAXLINE))>0){ //enquanto não tem uma linha com 0 caracteres
		if(len>max){ //operação para obter o tamanho maximo
			max=len;
			copy(longest,line);
		}
	}
	if(max>0){
		printf("%s", longest);
	}
	return 0;
}

int getline(char s[], int lim){
	int c, i;

	for(i=0;i<lim-1 && (c=getchar()) != ';' && c!='\n'; ++i){ //percorre o array até encontrar um ";" ou "\n". informa o tamanho do array
		s[i]=c;
	}
	if(c=='\n'){
		s[i]=c;
		++i;
	}
	s[i]='\0';
	return i;
}

void copy(char to[], char from[]){
	int i;
	i=0;
	while((to[i]=from[i]) != '\0'){
		++i;
	}
}
