#include<stdio.h>
#include<stdlib.h>

int len(char*);

int main(int argc,char* argv[]){
	char s[31];
	printf("Digite uma palavra: ");
	scanf("%s",s);
	printf("comprimento = %d\n", len(s));
	return 0;
}

int len(char *s){
	char *p=s;
	while(*(++p)!='\0')
		;
	return p-s;
}
